#include "Table.hh"

Table::Table(std::vector<Row> rows) : rows(rows)
{}

Table::Table()
{}

Table::Table(std::ifstream& file) : rows()
{
    if(file.is_open())
    {
        std::string str;
        while(getline(file, str))
        {
            Row r;
            std::string cell = "";
            for(int i=0; i<(int)str.size(); i++)
            {
            // If cur char is not del, then append it to the cur "word", otherwise
                // you have completed the word, print it, and start a new word.
                if(str[i] != ',')
                {
                cell += str[i];
                }
                else{
                    clean(cell);
                    Type* t = r.validateCell(cell);
                    r.getCells().push_back(t); //here i push back the cell but i first gotta differentiate the type
                    cell = "";
                }
            }
            clean(cell);
            Type* t = r.validateCell(cell);
            r.getCells().push_back(t); //here i push back the cell but i first gotta differentiate the type

            rows.push_back(r);
        }
    }
    file.close();
}

std::string& Table::clean(std::string& str)
{
    for(int i = 0; str[i] != '\0'; i++)
    {
        if(str[i] != ' ')
        {
            str.erase(0, i);
            break;
        }
    }
    for(int i = str.length(); i >= 0; i--)
    {
        if(str[i] != ' ')
        str.erase(i, str.length());
        break;
    }
    return str;
}

std::vector<Row>& Table::getRows()
{
    return this->rows;
}

void Table::print()
{
    std::vector<int> padding;
    for(int i = 0; i < rows.size(); i++)
    {
        for (int j = 0; j < rows[i].getCells().size(); j++)
        {
            if (rows[i].getCells().size() > padding.size())
            {
                for (int k = padding.size(); k < rows[i].getCells().size(); k++)
                {
                    padding.push_back(0);
                }
            }
            if (rows[i].getCells()[j] != nullptr)
            {
                if (padding[j] < rows[i].getCells()[j]->getValue().length())
                {
                    padding[j] = rows[i].getCells()[j]->getValue().length();
                }
            }
        }
    }
    for (int i = 0; i < rows.size(); i++)
    {
        if (rows[i].getCells().size() < padding.size())
        {
            for (int l = rows[i].getCells().size(); l < padding.size(); l++)
            {
                rows[i].getCells().push_back(nullptr);
            }
        }
        // std::cout << rows[i].getCells().size() << " -> size" << std::endl;
        for (int j = 0; j < rows[i].getCells().size(); j++)
        {
            if(rows[i].getCells()[j] != nullptr)
            {
                if(dynamic_cast<StringType*>(rows[i].getCells()[j]))
                {
                    dynamic_cast<StringType*>(rows[i].getCells()[j])->print();
                }
                else
                {
                    rows[i].getCells()[j]->print();
                }
                for(int k = 0; k < padding[j] - rows[i].getCells()[j]->getValue().length(); k++)
                {
                    std::cout << " ";
                }
                std::cout << "|";
            }
            else
            {
                for(int k = 0; k < padding[j]; k++)
                {
                    std::cout << " ";
                }
                std::cout << "|";
            }
        }
        std::cout << std::endl;
    }
}