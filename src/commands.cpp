#include <AbstractVM.hpp>
#include <TOperand.class.hpp>

std::deque<IOperand const *>    push_int8(std::string command, std::deque<IOperand const *> stack, OperandFactory factory)
{
	std::string num;
	int i = 0;
	while (command[i] != '(')
		i++;
	i++;
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
	int i = 0;
	while (command[i] != '(')
		i++;
	i++;
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
	int i = 0;
    while (command[i] != '(')
        i++;
    i++;
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
	int i = 0;
    while (command[i] != '(')
        i++;
    i++;
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
	int i = 0;
    while (command[i] != '(')
        i++;
    i++;
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

std::deque<IOperand const *>    pop(std::deque<IOperand const *> stack)
{
	stack.pop_front();
	return (stack);
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

std::deque<IOperand const *>    add(std::deque<IOperand const *> stack)
{
	stack[0] = *stack[0] + *stack[1];
	stack.erase(stack.begin() + 1);
	return (stack);
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