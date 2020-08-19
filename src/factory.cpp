#include "factory.hpp"
#include "error.hpp"
#include "NumClass.hpp"

Factory::Factory()
{
	return ;
}

Factory::~Factory()
{
	return ;
}

IOperand const * Factory::createOperand( eOperandType type, std::string const & value )
{
	switch(type) {
		case eOperandType::e_int8 : return createInt8(value);
		case eOperandType::e_int16 : return createInt16(value);
		case eOperandType::e_int32 : return createInt32(value);
		case eOperandType::e_float : return createFloat(value);
		case eOperandType::e_double : return createDouble(value);
		case eOperandType::e_invalid : return NULL;
	}
	return NULL;
}

IOperand const * Factory::createInt8( std::string const & value )
{
	int			val = std::stoi(value);
	if (val <= -128 || val >= 127) throw OverflowError(); 
	return (new Num<int8_t>(val,eOperandType::e_int8));
}

IOperand const * Factory::createInt16( std::string const & value )
{
	short int	val; 
	try {
		val = std::stoi(value);
	} catch (std::exception & e) {
		throw OverflowError();
	}
	if (val <= std::numeric_limits<short int>::min() || val >= std::numeric_limits<short int>::max()) throw OverflowError(); 
	return (new Num<int16_t>(val,eOperandType::e_int16));
}

IOperand const * Factory::createInt32( std::string const & value )
{
	int32_t		val;
	try {
		val = std::stoi(value);
	} catch (std::exception & e) {
		throw OverflowError();
	}
	return (new Num<int32_t>(val,eOperandType::e_int32));
}

IOperand const * Factory::createFloat( std::string const & value )
{
	float		val;
	try {
		val = std::stof(value);
	} catch (std::exception & e) {
		throw OverflowError();
	}
	if (val <= std::numeric_limits<float>::min() || val >= std::numeric_limits<float>::max()) throw OverflowError(); 
	return (new Num<float>(val,eOperandType::e_float));
}

IOperand const * Factory::createDouble( std::string const & value )
{
	double		val;
	try {
		val = std::stod(value);
	} catch (std::exception & e) {
		throw OverflowError();
	}
	if (val <= std::numeric_limits<double>::min() || val >= std::numeric_limits<double>::max()) throw OverflowError(); 
	return (new Num<double>(val,eOperandType::e_double));
}
