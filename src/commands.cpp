#include <AbstractVM.hpp>

std::deque<IOperand const *>    push_int8(std::string command, std::deque<IOperand const *> stack, OperandFactory factory)
{
    std::string num;
    int i = 10;
    while (command[i] != ')')
    {
        num += command[i];
        i++;
    }
    stack.push_front(factory.createOperand(INT8, num));
    //arg = atoi(num.c_str());
    return (stack);
}

std::deque<IOperand const *>    push_int16(std::string command, std::deque<IOperand const *> stack, OperandFactory factory)
{
    std::string num;
    //int arg;
    int i = 11;
    while (command[i] != ')')
    {
        num += command[i];
        i++;
    }
    //arg = atoi(num.c_str());
    stack.push_front(factory.createOperand(INT16, num));
    return (stack);

}

std::deque<IOperand const *>    push_int32(std::string command, std::deque<IOperand const *> stack, OperandFactory factory)
{
    std::string num;
    int i = 11;
    //int arg;
    while (command[i] != ')')
    {
        num += command[i];
        i++;
    }
    //arg = atoi(num.c_str());
    stack.push_front(factory.createOperand(INT32, num));
    return (stack);
}

std::deque<IOperand const *>    push_float(std::string command, std::deque<IOperand const *> stack, OperandFactory factory)
{
    std::string num;
    int i = 11;
    //float arg;
    while (command[i] != ')')
    {
        num += command[i];
        i++;
    }
    //arg = atof(num.c_str());
    stack.push_front(factory.createOperand(FLOAT, num));
    return (stack);
}

std::deque<IOperand const *>    push_double(std::string command, std::deque<IOperand const *> stack, OperandFactory factory)
{
    std::string num;
    int i = 12;
    //double arg;
    while (command[i] != ')')
    {
        num += command[i];
        i++;
    }
   // arg = stod(num);
    stack.push_front(factory.createOperand(DOUBLE, num));
    return (stack);
}

void    pop(void)
{

}

void    dump(std::deque<IOperand const *> stack)
{
        for (size_t i = 0; i < stack.size(); i++)
        {
            std::cout << stack[i]->toString() << std::endl;
        }
}

void    assert(std::string command)
{
    if (command == "DERP")
    {

    }
}

void    add(void)
{

}

void    sub(void)
{

}

void    mul(void)
{

}

void    div(void)
{

}

void    mod(void)
{

}

void    print(void)
{

}

void    exit(void)
{

}