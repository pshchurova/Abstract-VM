#ifndef FACTORY_HPP
# define FACTORY_HPP

#include "IOperand.hpp"

class Factory
{
	private:
		static IOperand const * createInt8( std::string const & value );
		static IOperand const * createInt16( std::string const & value );
		static IOperand const * createInt32( std::string const & value );
		static IOperand const * createFloat( std::string const & value );
		static IOperand const * createDouble( std::string const & value );

	public:
		Factory();
		~Factory();
		static IOperand const * createOperand( eOperandType type, std::string const & value );

};

#endif
