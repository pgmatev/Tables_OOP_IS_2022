#include "Table.hh"

Table::Table(std::vector<Row> rows) : rows(rows)
{
    resize();
}

Table::Table()
{
    resize();
}

Table::Table(const Table& other)
{
    this->rows = other.rows;
    resize();
}

Table::Table(std::ifstream& file) : rows()
{
    if(file.is_open())
    {
        std::string str;
        int row_count = 0;
        // Takes each row from the file
        while(getline(file, str)) 
        {
            int col_count = 0;
            row_count++;
            Row r;
            std::string cell = "";
            // Takes each cell from the rows
            for(int i=0; i<(int)str.size(); i++) 
            {
                // Checks for the delimiter
                if(str[i] != ',') 
                {
                cell += str[i];
                }
                else{
                    col_count++;
                    // Cleans the cell from whitespaces
                    clean(cell); 
                    // Validates whether the cell contains a valid type
                    Type* t = r.validateCell(cell, row_count, col_count);
                    r.getCells().push_back(t);
                    cell = "";
                }
            }
            col_count++;
            // The addition process has to be repeated for the cell after the last delimiter
            clean(cell);
            Type* t = r.validateCell(cell, row_count, col_count);
            r.getCells().push_back(t);
            // The row is inserted, and the cycle repeats with the next line of the file
            rows.push_back(r);
        }
    }
    else
    {
        throw std::invalid_argument("Non-existent file.");
    }
    file.close();
    //The rows have different sizes, so they have to be resized
    resize();
}

Table& Table::operator=(const Table& other)
{
    if (this != &other)
    {
        this->rows = other.rows;
    }
    return *this;
}

void Table::resize()
{
    int resizer = 0;
    for(int i = 0; i < rows.size(); i++)
    {
        if (rows[i].getCells().size() > resizer)
        {
            while(resizer < rows[i].getCells().size())
            {
                resizer++;
            }
        }
    }
    for(int i = 0; i < rows.size(); i++)
    {
        if (rows[i].getCells().size() < resizer)
        {
            while(rows[i].getCells().size() < resizer)
            {
                rows[i].getCells().push_back(nullptr);
            }
        }
    }
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
    if (row > getRows().size() || col > getRows()[0].getCells().size())
    {
        throw std::invalid_argument("Adress exceeds Table's boundaries.");
    }
    clean(str);
    Type* t = getRows()[row - 1].validateCell(str, row, col);
    if (t)
    {
        getRows()[row - 1].getCells()[col - 1] = t;
    }
}

void Table::remove(int row, int col)
{
    if (row > getRows().size() || col > getRows()[0].getCells().size())
    {
        throw std::invalid_argument("Adress exceeds Table's boundaries.");
    }
    getRows()[row - 1].getCells()[col - 1] = nullptr;
}

Table Table::subTable(int beg_row, int beg_col, int end_row, int end_col)
{
    if (beg_row < 1 || end_row > getRows().size())
    {
        throw std::invalid_argument("Sub-Table row interval out of bounds.");
    }
    for (int i = 0; i < getRows().size(); i++)
    {
        if (beg_col < 1 || end_col > getRows()[i].getCells().size())
        {
            throw std::invalid_argument("Sub-Table column interval out of bounds.");
        }
    }
    std::vector<Row> subRows;
    for (int i = beg_row - 1; i < end_row; i++)
    {
        Row r;
        for (int j = beg_col - 1; j < end_col; j++)
        {
            r.getCells().push_back(getRows()[i].getCells()[j]);
        }
        subRows.push_back(r);
    }
    return Table(subRows);
}

Table Table::subTable(std::vector<int> columns)
{
    resize();
	int miniPos;

	for (int i = 0; i < columns.size(); i++)
	{
		miniPos = i;
		for (int j = i + 1; j < columns.size(); j++)
		{
			if (columns[j] < columns[miniPos])
			{
				miniPos = j;
			}
		}

		int temp = columns[miniPos];
		columns[miniPos] = columns[i];
		columns[i] = temp;
	}
    std::vector<Row> subRows;
    for (int i = 0; i < getRows().size(); i++)
    {
        Row r;
        for (int j = 0; j < columns.size(); j++)
        {
            r.getCells().push_back(getRows()[i].getCells()[columns[j] - 1]);
            if (columns[j] > getRows()[i].getCells().size())
            {
                throw std::invalid_argument("Column doesn't exist");
            }
        }
        subRows.push_back(r);
    }
    return Table(subRows);
}
// Table Table::subTable(int a, std::function<bool(bool, bool)> func)
// {
//     std::vector<Row> subRows;
//     for (int i = 0; i < rows.size(); i++)
//     {
//         for (int j = 0; j < rows[i].getCells().size(); j++)
//         {
//             if (dynamic_cast<IntegerType*>(rows[i].getCells()[j]))
//             {
//                 if 
//             }
//         }
//     }
// }