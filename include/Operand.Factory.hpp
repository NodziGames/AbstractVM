#pragma once

#include <AbstractVM.hpp>

class   OperandFactory
{
	public:

		OperandFactory();
		OperandFactory(OperandFactory const & src);
		virtual ~OperandFactory();


		IOperand const *        createOperand(eOperandType type, std::string const & value);

	private:

		IOperand const * createInt8( std::string const & value ) const;
		IOperand const * createInt16( std::string const & value ) const;
		IOperand const * createInt32( std::string const & value ) const;
		IOperand const * createFloat( std::string const & value ) const;
		IOperand const * createDouble( std::string const & value ) const;
};