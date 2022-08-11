#ifndef PROGRAM_INPUT_HH
#define PROGRAM_INPUT_HH

#include "Table.hh"

class ProgramInput
{
private:
        std::vector<std::string> parameters;
        Table loaded_table;
        bool checkIfType(std::string str);
public:
    void setParameters(std::string input);
    std::vector<std::string> getParameters();
    void run();
};

#endif