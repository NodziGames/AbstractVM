#include <vector>
#include <iostream>
#include <fstream>
#include <regex>
#include <stdint.h>
#include <iomanip>
#include <cmath>
#include <Operand.Factory.hpp>
#include <IOperator.class.hpp>
#include <Exception.class.hpp>

class OperandFactory;
class IOperand;
class Exceptions;

std::vector<std::string> parse(std::string filename, Exceptions & excep);
std::string check_command_type(std::string command);
void                        	push_int8(std::string command, std::deque<IOperand const *> & stack, OperandFactory factory);
void							push_int16(std::string command, std::deque<IOperand const *> & stack, OperandFactory factory);
void							push_int32(std::string command, std::deque<IOperand const *> & stack, OperandFactory factory);
void							push_float(std::string command, std::deque<IOperand const *> & stack, OperandFactory factory);
void							push_double(std::string command, std::deque<IOperand const *> & stack, OperandFactory factory);
void							pop(std::deque<IOperand const *> & stack);
void    						dump(std::deque<IOperand const *> & stack);
void    						assert(std::string command, std::deque<IOperand const *> & stack);
void							add(std::deque<IOperand const *> & stack);
void							sub(std::deque<IOperand const *> & stack);
void							mul(std::deque<IOperand const *> & stack);
void						    div(std::deque<IOperand const *> & stack);
void						    mod(std::deque<IOperand const *> & stack);
void                            print(std::deque<IOperand const *> & stack);
void                            exit(std::deque<IOperand const *> & stack);
void							clearStack(std::deque<IOperand const *> & stack);

int     syntax_check(std::string line);
std::string remove_whitespace_front(std::string line);
std::string trim(std::string line);