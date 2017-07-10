#include <AbstractVM.hpp>
#include <cfloat>
#include <float.h>

template <eOperandType operandType, typename T>
class TOperand : public IOperand
{
	public:

		class		Div0Exception : public std::exception
		{
			virtual const char * what() const throw()
			{
				return ("Dividing || Mod by zero is undefined.");
			}
		} Div0E;
		class		OverflowException : public std::exception
		{
			virtual const char * what() const  throw()
			{
				return ("Overflow || Underflow reached on type");
			}
		} Oexep;

		//Constructor
		TOperand(std::string value) : _value(value)
		{
			checkOverflow(std::stold(this->_value), this->getType());
			return ;
		}

		TOperand(TOperand const & rhs)
		{
			*this = rhs;
		}

		virtual ~TOperand(void)
		{
			return ;
		}

		IOperand const	* createInstance(long double value, eOperandType type) const
		{
			// Convert value to string and pass it to new class instance.
			std::string newStr = std::to_string(value);
			std::string newValue = std::to_string(value);
			int i;
			for (i = newStr.length() - 1; newStr[i] == '0'; i--)
				;
			if (newStr[i] != '.')
				i++;
			newValue = newStr.substr(0, i);
			if (type == INT8)
				return (new TOperand<INT8, int8_t>(newValue));
			else if (type == INT16)
				return (new TOperand<INT16, int16_t>(newValue));
			else if (type == INT32)
				return (new TOperand<INT32, int32_t>(newValue));
			else if (type == FLOAT)
				return (new TOperand<FLOAT, float>(newValue));
			else if (type == DOUBLE)
				return (new TOperand<DOUBLE, double>(newValue));
			return (new TOperand<INT8, int8_t>(newValue));
		}
		TOperand const * 	operator=(IOperand const & rhs) const // Set rhs value = to lhs value
		{
				long double value;
				// Convert value to number from string
				value = std::stold(rhs.toString()); 
				checkOverflow(value, rhs.getType());
				return (createInstance(value, rhs.getType()));
		}

		TOperand const * 	operator+(IOperand const & rhs) const
		{
			//	Add two numbers together via converting value to the string
			//	Check the max overflow if the two numbers added doesn't overflow.
			//	Check precision of the added numbers highest precision should always be taken.
			//	double > int
			
			long double value;

			value = std::stold(this->_value) + std::stold(rhs.toString());

			if (this->getPrecision() < rhs.getPrecision())
			{
				checkOverflow(value, rhs.getType());
				return (reinterpret_cast<TOperand const *>(createInstance(value, rhs.getType())));
			}
			checkOverflow(value, this->getType());
			return (dynamic_cast<TOperand const *>(createInstance(value, this->getType())));
		}

		TOperand const * 	operator-(IOperand const & rhs) const
		{
			// Unsure if it should be this - rhs or rhs - this

			long double value;

			value = std::stold(this->_value) - std::stold(rhs.toString());

			if (this->getPrecision() < rhs.getPrecision())
			{
				checkOverflow(value, rhs.getType());
				return (reinterpret_cast<TOperand const *>(createInstance(value, rhs.getType())));
			}
			checkOverflow(value, this->getType());
			return (dynamic_cast<TOperand const *>(createInstance(value, this->getType())));
		}

		TOperand const * 	operator*(IOperand const & rhs) const
		{
			long double value;

			value = std::stold(this->_value) * std::stold(rhs.toString());

			if (this->getPrecision() < rhs.getPrecision())
			{
				checkOverflow(value, rhs.getType());
				return (reinterpret_cast<TOperand const *>(createInstance(value, rhs.getType())));
			}
			checkOverflow(value, this->getType());
			return (dynamic_cast<TOperand const *>(createInstance(value, this->getType())));

		}

		TOperand const *	operator/(IOperand const & rhs) const
		{
			// In addition to the other overloads % && / need to have a check on div/mod == 0

			long double value;
			
			checkDiv0(std::stold(rhs.toString()));
			value = std::stold(this->_value) / std::stold(rhs.toString());
			if (this->getPrecision() < rhs.getPrecision())
			{
				checkOverflow(value, rhs.getType());
				return (reinterpret_cast<TOperand const *>(createInstance(value, rhs.getType())));
			}
			checkOverflow(value, this->getType());
			return (dynamic_cast<TOperand const *>(createInstance(value, this->getType())));
		}

		TOperand const * 	operator%(IOperand const & rhs) const
		{
			long double value;

			checkDiv0(std::stold(rhs.toString()));
			value = std::fmod(std::stold(this->_value), std::stold(rhs.toString()));
			if (this->getPrecision() < rhs.getPrecision())
			{
				checkOverflow(value, rhs.getType());
				return (reinterpret_cast<TOperand const *>(createInstance(value, rhs.getType())));
			}
			checkOverflow(value, this->getType());
			return (dynamic_cast<TOperand const *>(createInstance(value, this->getType())));
		}

		void checkDiv0(long double value) const
		{
			// Check if val is 0
			if (value == 0)
				throw Div0E;
		}

		void checkOverflow(long double value, eOperandType type) const
		{
			if (type == INT8 && (value < INT8_MIN || value > INT8_MAX))
				throw Oexep;
			else if (type == INT16 && (value < INT16_MIN || value > INT16_MAX))
				throw Oexep;
			else if (type == INT32 && (value < INT32_MIN || value > INT32_MAX))
				throw Oexep;
			else if (type == FLOAT && (value < -1.175494e+37 || value > 3.40282e+38))
				throw Oexep;
			else if (type == DOUBLE && (value < -2.22507e+307 || value > 1.79769e+308))
				throw Oexep;
		}

		std::string const & toString(void) const
		{
			return (this->_value);
		}

		int					getPrecision(void) const
		{
			return (operandType);
		}

		eOperandType		getType(void) const
		{
			if (typeid(this->_type) == typeid(int8_t))
				return (INT8);
			else if (typeid(this->_type) == typeid(int16_t))
				return (INT16);
			else if (typeid(this->_type) == typeid(int))
				return (INT32);
			else if (typeid(this->_type) == typeid(float))
				return (FLOAT);
			return (DOUBLE);
		}

	private:

		T					_type;
		std::string			_value;
};