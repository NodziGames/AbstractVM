#include <AbstractVM.hpp>
#include <cfloat>

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
    bool verbose = false;

    if (argc == 3)
    {
        if (strcmp("-v", argv[2]) == 0)
            verbose = true;
    }
    else
        verbose = false;

    if (argc < 2)
    {
        std::cout << "Invalid usage! Ex: " << argv[0] << " commands.avm optional[-v]" << std::endl;
        return (0);
    }

    try
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
            if (check_command_type(commands[i]) == "push int8")
            {
                if (verbose == true)
                    std::cout << "//Adding 8-bit Int To Stack" << std::endl;
                push_int8(commands[i], stack, factory);
            }
            else if (check_command_type(commands[i]) == "push int16")
            {
                if (verbose == true)
                    std::cout << "//Adding 16-bit Int To Stack" << std::endl;
                push_int16(commands[i], stack, factory);
            }
            else if (check_command_type(commands[i]) == "push int32")
            {
                if (verbose == true)
                    std::cout << "//Adding 32-bit Int To Stack" << std::endl;
                push_int32(commands[i], stack, factory);
            }
            else if (check_command_type(commands[i]) == "push float")
            {
                if (verbose == true)
                    std::cout << "//Adding Float To Stack" << std::endl;
                push_float(commands[i], stack, factory);
            }
            else if (check_command_type(commands[i]) == "push double")
            {
                if (verbose == true)
                    std::cout << "//Adding Double To Stack" << std::endl;
                push_double(commands[i], stack, factory);
            }
            else if (check_command_type(commands[i]) == "pop")
            {
                if (verbose == true)
                    std::cout << "//Popping Top Value From Stack" << std::endl;
                pop(stack);
            }
            else if (check_command_type(commands[i]) == "dump")
            {
                if (verbose == true)
                    std::cout << "//Dumping All Stack Values To Screen" << std::endl;
                dump(stack);
            }
            else if (check_command_type(commands[i]) == "assert")
            {
                if (verbose == true)
                    std::cout << "//Asserting Top Value Of Stack" << std::endl;
                assert(commands[i], stack);
            }
            else if (check_command_type(commands[i]) == "add")
            {
                if (verbose == true)
                    std::cout << "//Adding Top Two Values Of Stack" << std::endl;
                add(stack);
            }
            else if (check_command_type(commands[i]) == "sub")
            {
                if (verbose == true)
                    std::cout << "//Subtracting Top Two Values Of Stack" << std::endl;
                sub(stack);
            }
            else if (check_command_type(commands[i]) == "mul")
            {
                if (verbose == true)
                    std::cout << "//Multiplying Top Two Values Of Stack" << std::endl;
                mul(stack);
            }
            else if (check_command_type(commands[i]) == "div")
            {
                if (verbose == true)
                    std::cout << "//Dividing Top Two Values Of Stack" << std::endl;
                div(stack);
            }
            else if (check_command_type(commands[i]) == "mod")
            {
                if (verbose == true)
                    std::cout << "//Modulus-ing Top Two Values Of Stack" << std::endl;
                mod(stack);
            }
            else if (check_command_type(commands[i]) == "print")
            {
                if (verbose == true)
                    std::cout << "//Using Print On Top Value Of Stack" << std::endl;
                print(stack);
            }
            else if (check_command_type(commands[i]) == "exit" || check_command_type(commands[i]) == ";;")
            {
                if (verbose == true)
                    std::cout << "//Exiting VM" << std::endl;
                exit(stack);
            }
        }
        if (check_command_type(commands[i - 1]) != "exit")
            excep2.throwNoExit();
    }
    catch (std::exception & e)
    {
        std::cout << "Exception: " << e.what() << std::endl;
        clearStack(stack);
    }

    return (0);
}