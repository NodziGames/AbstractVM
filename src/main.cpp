#include <AbstractVM.hpp>

OperandFactory factory;
std::deque<IOperand const *> stack;
std::vector<std::string> commands;

int     main(int argc, char **argv)
{
    bool verbose = false;;
    if (argc >= 2)
    {
        if (strcmp("-v", argv[1]) == 0)
            verbose = true;
    }
    else
        verbose = false;
    
    commands = parse("all_test.avm");

    if (commands[0] == "failed")
    {
        std::cout << "One or more Syntax errors has been detected. Please resolve these and try running again!" << std::endl;
        return (0);
    }


    //Iterate Through Commands And Execute Them!
    for (size_t i = 0; i < commands.size(); i++)
    {
        std::cout << commands[i] << std::endl;
        if (check_command_type(commands[i]) == "push int8")
        {
            if (verbose == true)
                std::cout << "//Adding 8-bit Int To Stack" << std::endl;
            stack = push_int8(commands[i], stack, factory);
        }
        else if (check_command_type(commands[i]) == "push int16")
        {
            if (verbose == true)
                std::cout << "//Adding 16-bit Int To Stack" << std::endl;
            stack = push_int16(commands[i], stack, factory);
        }
        else if (check_command_type(commands[i]) == "push int32")
        {
            if (verbose == true)
                std::cout << "//Adding 32-bit Int To Stack" << std::endl;
            stack = push_int32(commands[i], stack, factory);
        }
        else if (check_command_type(commands[i]) == "push float")
        {
            if (verbose == true)
                std::cout << "//Adding Float To Stack" << std::endl;
            stack = push_float(commands[i], stack, factory);
        }
        else if (check_command_type(commands[i]) == "push double")
        {
            if (verbose == true)
                std::cout << "//Adding Double To Stack" << std::endl;
            stack = push_double(commands[i], stack, factory);
        }
        else if (check_command_type(commands[i]) == "pop")
        {
            if (verbose == true)
                std::cout << "//Popping Top Value From Stack" << std::endl;
            stack = pop(stack);
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
            assert(commands[i]);
        }
        else if (check_command_type(commands[i]) == "add")
        {
            if (verbose == true)
                std::cout << "//Adding Top Two Values Of Stack" << std::endl;
            stack = add(stack);
        }
        else if (check_command_type(commands[i]) == "sub")
        {
            if (verbose == true)
                std::cout << "//Subtracting Top Two Values Of Stack" << std::endl;
            sub();
        }
        else if (check_command_type(commands[i]) == "mul")
        {
            if (verbose == true)
                std::cout << "//Multiplying Top Two Values Of Stack" << std::endl;
            mul();
        }
        else if (check_command_type(commands[i]) == "div")
        {
            if (verbose == true)
                std::cout << "//Dividing Top Two Values Of Stack" << std::endl;
            div();
        }
        else if (check_command_type(commands[i]) == "mod")
        {
            if (verbose == true)
                std::cout << "//Modulus-ing Top Two Values Of Stack" << std::endl;
            mod();
        }
        else if (check_command_type(commands[i]) == "print")
        {
            if (verbose == true)
                std::cout << "//Using Print On Top Value Of Stack" << std::endl;
            print();
        }
        else if (check_command_type(commands[i]) == "exit")
        {
            if (verbose == true)
                std::cout << "//Exiting VM" << std::endl;
            exit();
        }

    }
    /*for (size_t i = 0; i < stack.size(); i++)
        std::cout << "On stack: " << stack[i]->toString() << std::endl;*/
    return (0);
}