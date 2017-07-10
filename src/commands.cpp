#include <AbstractVM.hpp>
#include <TOperand.class.hpp>

Exceptions excep;

void    push_int8(std::string command, std::deque<IOperand const *> & stack, OperandFactory factory)
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
}

void    push_int16(std::string command, std::deque<IOperand const *> & stack, OperandFactory factory)
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
	stack.push_front(factory.createOperand(INT16, num));


}

void    push_int32(std::string command, std::deque<IOperand const *> & stack, OperandFactory factory)
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
}

void    push_float(std::string command, std::deque<IOperand const *> & stack, OperandFactory factory)
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
}

void    push_double(std::string command, std::deque<IOperand const *> & stack, OperandFactory factory)
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
}

void   pop(std::deque<IOperand const *> & stack)
{
	if (stack.size() == 0)
		excep.throwStackTooSmall();
	stack.pop_front();
}

void    dump(std::deque<IOperand const *> & stack)
{
		for (size_t i = 0; i < stack.size(); i++)
		{
			std::cout << stack[i]->toString() << std::endl;
		}
}

void    assert(std::string command, std::deque<IOperand const *> & stack)
{

	if (stack.size() == 0)
		excep.throwStackTooSmall();

	int type;
	
	if (command.find("int8") != std::string::npos)
		type = INT8;
	else if (command.find("int16") != std::string::npos)
		type = INT16;
	else if (command.find("int32") != std::string::npos)
		type = INT32;
	else if (command.find("float") != std::string::npos)
		type = FLOAT;
	else if (command.find("double") != std::string::npos)
		type = DOUBLE;

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

	if (stack[0]->getType() == type && std::strcmp(stack[0]->toString().c_str(),num.c_str()) == 0)
	{
		//Verbose trash
	}
	else
	{
		excep.throwAssertFail();
	}
}

void    add(std::deque<IOperand const *> & stack)
{
	if (stack.size() < 2)
		excep.throwStackTooSmall();
	stack[0] = *stack[0] + *stack[1];
	stack.erase(stack.begin() + 1);
}

void   sub(std::deque<IOperand const *> & stack)
{
	if (stack.size() < 2)
		excep.throwStackTooSmall();
	stack[0] = *stack[0] - *stack[1];
	stack.erase(stack.begin() + 1);
}

void   mul(std::deque<IOperand const *> & stack)
{
	if (stack.size() < 2)
		excep.throwStackTooSmall();
	stack[0] = *stack[0] * *stack[1];
	stack.erase(stack.begin() + 1);
}

void    div(std::deque<IOperand const *> & stack)
{
	if (stack.size() < 2)
		excep.throwStackTooSmall();
	stack[0] = *stack[0] / *stack[1];
	stack.erase(stack.begin() + 1);
}

void     mod(std::deque<IOperand const *> & stack)
{
	if (stack.size() < 2)
		excep.throwStackTooSmall();
	stack[0] = *stack[0] % *stack[1];
	stack.erase(stack.begin() + 1);
}

void    print(std::deque<IOperand const *> & stack)
{
	if (stack.size() == 0)
		excep.throwStackTooSmall();
	if (stack[0]->getType() == INT8)
	{
		std::cout << static_cast<const char>(std::atoi(stack[0]->toString().c_str())) << std::endl;
	}
	else
	{
		excep.throwPrintFail();
	}
}

void	exit(std::deque<IOperand const *> & stack)
{
	for (size_t i = 0; i != stack.size(); i++)
		delete stack[i];
	stack.clear();
	exit(EXIT_SUCCESS);
}