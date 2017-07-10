#include "AbstractVM.hpp"

std::string check_command_type(std::string command)
{
    if (command.find("push") != std::string::npos && command.find("int8") != std::string::npos)
        return ("push int8");
    else if (command.find("push") != std::string::npos && command.find("int16") != std::string::npos)
        return ("push int16");
    else if (command.find("push") != std::string::npos && command.find("int32") != std::string::npos)
        return ("push int32");
    else if (command.find("push") != std::string::npos && command.find("float") != std::string::npos)
        return ("push float");
    else if (command.find("push") != std::string::npos && command.find("double") != std::string::npos)
        return ("push double");
    else if (command.find("pop") != std::string::npos)
        return ("pop");
    else if (command.find("dump") != std::string::npos)
        return ("dump");
    else if (command.find("assert") != std::string::npos)
        return ("assert");
    else if (command.find("add") != std::string::npos)
        return ("add");
    else if (command.find("sub") != std::string::npos)
        return ("sub");
    else if (command.find("mul") != std::string::npos)
        return("mul");
    else if (command.find("div") != std::string::npos)
        return ("div");
    else if (command.find("mod") != std::string::npos)
        return ("mod");
    else if (command.find("print") != std::string::npos)
        return ("print");
    else if (command.find("exit") != std::string::npos || command.find(";;") != std::string::npos)
        return ("exit");
    else
        return ("Nothing");
}