#include "ProgramInput.hh"

int main(int argc, char** argv)
{
    std::string input;
    ProgramInput pi;
    std::cout << "Type \"exit\" to exit the program." << std::endl;
    do
    {
        std::cout << "> ";
        std::getline(std::cin, input);
        pi.setParameters(input);
        pi.run();
    }while (input != "exit");
}