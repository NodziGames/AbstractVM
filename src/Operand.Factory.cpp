#include <AbstractVM.hpp>
#include <TOperand.class.hpp>

typedef IOperand const *	(OperandFactory::*Create)(std::string const & value) const;

OperandFactory::OperandFactory()
{
	return ;
}

OperandFactory::OperandFactory(OperandFactory const & src)
{
	*this = src;
}

OperandFactory::~OperandFactory()
{
	return ;
}

IOperand const *		OperandFactory::createOperand(eOperandType type, std::string const & value)
{
	/* CHANGE TO ARRAY */
	Create iop[5] = {&OperandFactory::createInt8, &OperandFactory::createInt16,
	&OperandFactory::createInt32, &OperandFactory::createFloat, &OperandFactory::createDouble};
	return ((this->*iop[type])(value));
}

IOperand const * 		OperandFactory::createInt8(std::string const & value) const
{
	return (new TOperand<INT8, int8_t>(value));
}

IOperand const * 		OperandFactory::createInt16(std::string const & value) const
{
	return (new TOperand<INT16, int16_t>(value));
}

IOperand const * 		OperandFactory::createInt32(std::string const & value) const
{
	return (new TOperand<INT32, int32_t>(value));
}

IOperand const * 		OperandFactory::createFloat(std::string const & value) const
{
	return (new TOperand<FLOAT, float>(value));
}

IOperand const * 		OperandFactory::createDouble(std::string const & value) const
{
	return (new TOperand<DOUBLE, double>(value));
}