#include <AbstractVM.hpp>
#include <cfloat>

void do_commands(std::string line);

OperandFactory factory;
std::deque<IOperand const *> stack;
std::vector<std::string> commands;
Exceptions excep2;

void    clearStack(std::deque<IOperand const *> & stack)
{
    for (size_t i = 0; i != stack.size(); i++)
        delete stack[i];
    stack.clear();
    exit(EXIT_FAILURE);
}

int     main(int argc, char **argv)
{
    if (argc > 2)
    {
        std::cout << "Invalid usage! Ex: " << argv[0] << " optional[commands.avm]" << std::endl;
        return (0);
    }

    try
    {
        if (argc == 2)
        {
            commands = parse(argv[1], excep2);

            if (commands[0] == "failed")
            {
                std::cout << "One or more Syntax errors has been detected. Please resolve these and try running again!" << std::endl;
                return (0);
            }

            size_t i;
            //Iterate Through Commands And Execute Them!
            for (i = 0; i < commands.size(); i++)
            {
                std::cout << commands[i] << std::endl;
                do_commands(commands[i]);
            }
            if (check_command_type(commands[i - 1]) != "exit")
                excep2.throwNoExit();
        }

        if (argc == 1) //If VM is run without commands
        {
            std::string line;
            std::cout << "Enter command: ";
            while (getline(std::cin, line))
            {
                line = remove_whitespace_front(line);
                if (syntax_check(line) == 1)
                {
                    do_commands(line);
                    std::cout << "Enter command: ";
                }
                else
                {
                    std::cout << "Failed: Syntax Error!" << std::endl;
                    std::cout << "Enter command: ";
                }
            }
        }
    }
    catch (std::exception & e)
    {
        std::cout << "Exception: " << e.what() << std::endl;
        clearStack(stack);
    }

    return (0);
}



void    do_commands(std::string line)
{
    if (check_command_type(line) == "push int8")
        push_int8(line, stack, factory);
    else if (check_command_type(line) == "push int16")
        push_int16(line, stack, factory);
    else if (check_command_type(line) == "push int32")
        push_int32(line, stack, factory);
    else if (check_command_type(line) == "push float")
        push_float(line, stack, factory);
    else if (check_command_type(line) == "push double")
        push_double(line, stack, factory);
    else if (check_command_type(line) == "pop")
        pop(stack);
    else if (check_command_type(line) == "dump")
        dump(stack);
    else if (check_command_type(line) == "assert")
        assert(line, stack);
    else if (check_command_type(line) == "add")
        add(stack);
    else if (check_command_type(line) == "sub")
        sub(stack);
    else if (check_command_type(line) == "mul")
        mul(stack);
    else if (check_command_type(line) == "div")
        div(stack);
    else if (check_command_type(line) == "mod")
        mod(stack);
    else if (check_command_type(line) == "print")
        print(stack);
    else if (check_command_type(line) == "exit" || check_command_type(line) == ";;")
        exit(stack);
}