#include "ProgramInput.hh"

void ProgramInput::setParameters(std::string input)
{
    parameters.clear();
    // parameters = new std::vector<std::string>;
    int pos = 0;
    std::string token;
    while ((pos = input.find(" ")) != std::string::npos)
    {
        token = input.substr(0, pos);
        parameters.push_back(token);
        input.erase(0, pos + 1);
        if (checkIfType(input))
        {
            break;
        }
    }
    parameters.push_back(input);
}

std::vector<std::string> ProgramInput::getParameters()
{
    return parameters;
}

bool ProgramInput::checkIfType(std::string str)
{
    if (str[0] == '{' && str[str.size()-1] == '}')
    {
        return true;
    }
    Type* it = new IntegerType(str);
    if (it->validate())
    {
        return true;
    }
    Type* ft = new FloatType(str);
    if (ft->validate())
    {
        return true;
    }
    Type *ct = new CurrencyType(str);
    if (ct->validate())
    {
        return true;
    }
    Type* st = new StringType(str);
    if (st->validate())
    {
        return true;
    }
    return false;
}


void ProgramInput::run()
{
    std::string input;
    std::cout << "Type \"exit\" to exit the program." << std::endl;
    do
    {
        std::cout << "> ";
        std::getline(std::cin, input);
        setParameters(input);
        if (parameters[0] == "load")
        {
            if (parameters.size() != 2)
            {
                std::cout << "Wrong input. Load takes only 1 parameter." << std::endl; 
            }
            std::ifstream file(parameters[1]);
            std::cout << "loading..." << std::endl;
            loaded_table = Table(file);
        }

        else if (parameters[0] == "save")
        {
            if (loaded_table.getRows().size() == 0)
            {
                std::cout << "Load a table first." << std::endl;
            }
            else
            {
                if (parameters.size() != 2)
                {            
                    std::cout << "Wrong input. Save takes only 1 parameter." << std::endl;
                }
                std::ofstream file(parameters[1]);
                std::cout << "saving..." << std::endl;
                loaded_table.save(file);
            }

        }

        else if (parameters[0] == "print")
        {
            if (loaded_table.getRows().size() == 0)
            {
                std::cout << "Load a table first." << std::endl;
            }
            else
            {
                if (parameters.size() != 1)
                {
                    std::cout << "Wrong input. Print does not take parameters." << std::endl;
                    
                }
                std::cout << "printing..." << std::endl;
                loaded_table.print(); 
            }
        }
        // parameters is of type vector<string> and holds the user input
        else if (parameters[0] == "edit")
        {
            // validation that the table exists
            if (loaded_table.getRows().size() == 0)
            {
                std::cout << "Load a table first." << std::endl;
            }
            else
            {
                // validation that the edit input is correct
                if (parameters.size() != 4)
                {
                    std::cout << "Wrong input. Edit takes 3 parameters." << std::endl;  
                }
                try
                {
                    // the input is a string, but the function takes integers
                    int x = stoi(parameters[1]);
                    x = stoi(parameters[2]);
                }
                catch(std::invalid_argument& e)
                {
                    std::cout << "Wrong input. The first 2 parameters should be integers." << std::endl;
                }
                std::cout << "editing..." << std::endl;
                try
                {
                    // calling the function
                    loaded_table.edit(parameters[3], stoi(parameters[1]), stoi(parameters[2]));
                }
                // error handling of the function
                catch(std::invalid_argument& e)
                {
                    std::cout << e.what() << std::endl;
                }
            }
        }

        else if (parameters[0] == "remove")
        {
            if (loaded_table.getRows().size() == 0)
            {
                std::cout << "Load a table first." << std::endl;
            }
            else
            {
                if (parameters.size() != 3)
                {
                    std::cout << "Wrong input. Remove takes 2 parameters." << std::endl; 
                }
                try
                {
                    int x = stoi(parameters[1]);
                    x = stoi(parameters[2]);
                }
                catch(std::invalid_argument& e)
                {
                    std::cout << "Wrong input. The parameters should be integers." << std::endl;
                }
                std::cout << "removing..." << std::endl;
                try
                {
                    loaded_table.remove(stoi(parameters[1]), stoi(parameters[2]));
                }
                catch (std::invalid_argument& e)
                {
                    std::cout << e.what() << std::endl;
                }
            }
        }

        else if (parameters[0] == "extract")
        {
            if (loaded_table.getRows().size() == 0)
            {
                std::cout << "Load a table first." << std::endl;
            }
            else
            {
                if (parameters.size() == 3)
                {
                    try
                    {
                        if(parameters[1].find(":") == std::string::npos || parameters[1].find(":") == std::string::npos)
                        {
                            std::cout << "Intervals are set with a \":\" symbol." << std::endl;
                        }
                        else
                        {
                            std::vector<int> arguments;
                            int pos = 0;
                            std::string token;
                            for (int i = 1; i < parameters.size(); i++)
                            {
                                bool is_checked = false;
                                while ((pos = parameters[i].find(":")) != std::string::npos) {
                                    if (!is_checked)
                                    {
                                        token = parameters[i].substr(0, pos);
                                        arguments.push_back(stoi(token));
                                        parameters[i].erase(0, pos + 1);
                                        is_checked = true;
                                    }
                                    else
                                    {
                                        std::cout << "Invalid cell adress." << std::endl;
                                        return;
                                    }
                                }
                                arguments.push_back(stoi(parameters[i]));
                            }
                            std::cout << "extracting..." << std::endl;
                            try
                            {
                                Table t = loaded_table.subTable(arguments[0], arguments[1], arguments[2], arguments[3]);
                                t.print();
                            }
                            catch (std::invalid_argument& e)
                            {
                                std::cout << e.what() << std::endl;
                            }
                        }
                    }
                    catch(std::invalid_argument& e)
                    {
                        std::cout << "Extract only accepts integers." << std::endl;
                    }
                }
                else if (parameters.size() == 2)
                {
                    try
                    {
                        std::vector<int> arguments;
                        parameters[1].erase(0, 1);
                        parameters[1].erase(parameters[1].length() - 1, 1);
                        int pos = 0;
                        std::string token;
                        for (int i = 1; i < parameters.size(); i++)
                        {
                                while ((pos = parameters[i].find(", ")) != std::string::npos)
                                {
                                    token = parameters[i].substr(0, pos);
                                    arguments.push_back(stoi(token));
                                    parameters[i].erase(0, pos + 1);
                                }
                                arguments.push_back(stoi(parameters[i]));
                        }
                        std::cout << "extracting..." << std::endl;
                        try
                        {
                            Table t = loaded_table.subTable(arguments);
                            t.print();
                        }
                        catch (std::invalid_argument& e)
                        {
                            std::cout << e.what() << std::endl;
                        }
                    }
                    catch(std::invalid_argument& e)
                    {
                        std::cout << "Extract only accepts integers." << std::endl;
                    }
                }
                else
                {
                    std::cout << "Wrong input. Extract takes either 2 arguments -> beggining and end adress or 1 argument -> vector with column numbers." << std::endl;
                }
            }
        }
        else if(parameters[0] != "exit")
        {
            std::cout << "Wrong input. Operation " << parameters[0] << " does not exist." << std::endl;
        }
    }while(input != "exit");
}
