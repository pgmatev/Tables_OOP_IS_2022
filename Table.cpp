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
        int row_count = 0;
        while(getline(file, str))
        {
            int col_count = 0;
            row_count++;
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
                    col_count++;
                    clean(cell);
                    // std::cout << "Cell: " << cell << " Row: " << row_count << " Col: " << col_count << std::endl;
                    Type* t = r.validateCell(cell, row_count, col_count);
                    r.getCells().push_back(t); //here i push back the cell but i first gotta differentiate the type
                    cell = "";
                }
            }
            col_count++;
            clean(cell);
            Type* t = r.validateCell(cell, row_count, col_count);
            r.getCells().push_back(t); //here i push back the cell but i first gotta differentiate the type

            rows.push_back(r);
        }
    }
    file.close();
}

std::string& Table::clean(std::string& str)
{
    bool is_front_clean = false;
    for(int i = 0; str[i] != '\0'; i++)
    {
        if(!isspace(str[i]) && !is_front_clean)
        {
            str.erase(0, i);
            is_front_clean = true;
        }
    }
    if (!is_front_clean)
    {
        str.erase();
    }
    for(int i = str.length() - 1; i >= 0; i--)
    {
        if(!isspace(str[i]))
        {
            str.erase(i + 1, str.length() - i);
            break;
        }
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
                if (dynamic_cast<StringType*>(rows[i].getCells()[j]))
                {
                    if (padding[j] < static_cast<StringType*>(rows[i].getCells()[j])->trim().length())
                    {
                        padding[j] = static_cast<StringType*>(rows[i].getCells()[j])->trim().length();
                    }
                }
                else 
                {
                    if (padding[j] < rows[i].getCells()[j]->getValue().length())
                    {
                        padding[j] = rows[i].getCells()[j]->getValue().length();
                    }
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
                    for(int k = 0; k < padding[j] - dynamic_cast<StringType*>(rows[i].getCells()[j])->trim().length(); k++)
                    {
                        std::cout << " ";
                    }
                }
                else
                {
                    rows[i].getCells()[j]->print();
                    for(int k = 0; k < padding[j] - rows[i].getCells()[j]->getValue().length(); k++)
                    {
                        std::cout << " ";
                    }
                }
                std::cout << " | ";
            }
            else
            {
                for(int k = 0; k < padding[j]; k++)
                {
                    std::cout << " ";
                }
                std::cout << " | ";
            }
        }
        std::cout << std::endl;
    }
}

void Table::save(std::ofstream& file)
{
    for (int i = 0; i < rows.size(); i++)
    {
        for (int j = 0; j < rows[i].getCells().size(); j++)
        {
            if (rows[i].getCells()[j] != nullptr)
            {
                if (j == 0)
                {
                    file << rows[i].getCells()[j]->getValue();
                }
                else
                {
                    file << ", " << rows[i].getCells()[j]->getValue();
                }

            }
            else 
            {
                if (j == 0)
                {
                    file << " ";
                }
                else
                {
                    file << ", ";
                }

            }
        }
        file << std::endl;
    }
    file.close();
}

void Table::edit(std::string& str, int row, int col)
{
    clean(str);
    Type* t = getRows()[row - 1].validateCell(str, row, col);
    if (t)
    {
        getRows()[row - 1].getCells()[col - 1] = t;
    }
}

void Table::remove(int row, int col)
{
    getRows()[row - 1].getCells()[col - 1] = nullptr;
}