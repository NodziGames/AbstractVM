#include <vector>
#include <iostream>
#include <fstream>
#include <regex>
#include <stdint.h>
#include <iomanip>
#include <Operand.Factory.hpp>
#include <IOperator.class.hpp>

class OperandFactory;
class IOperand;

std::vector<std::string> parse(std::string filename);
std::string check_command_type(std::string command);
std::deque<IOperand const *>    push_int8(std::string command, std::deque<IOperand const *> stack, OperandFactory factory);
std::deque<IOperand const *>    push_int16(std::string command, std::deque<IOperand const *> stack, OperandFactory factory);
std::deque<IOperand const *>    push_int32(std::string command, std::deque<IOperand const *> stack, OperandFactory factory);
std::deque<IOperand const *>    push_float(std::string command, std::deque<IOperand const *> stack, OperandFactory factory);
std::deque<IOperand const *>    push_double(std::string command, std::deque<IOperand const *> stack, OperandFactory factory);
std::deque<IOperand const *>    pop(std::deque<IOperand const *>);
void    dump(std::deque<IOperand const *> stack);
void    assert(std::string command);
std::deque<IOperand const *>    add(std::deque<IOperand const *> stack);
void    sub(void);
void    mul(void);
void    div(void);
void    mod(void);
void    print(void);
void    exit(void);