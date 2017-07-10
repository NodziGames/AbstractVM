#include <AbstractVM.hpp>
#include <Exception.class.hpp>

const char * Exceptions::StackTooSmall::what() const throw()
{
	return ("Invalid stack size. ‎(ﾉ ಥ □ ಥ)ﾉ ┻━┻");
}

const char * Exceptions::NoExit::what() const throw()
{
	return ("Program requires exit function as last command. (╯°□°)╯︵ ┻━┻");
}

const char * Exceptions::AssertFail::what() const throw()
{
	return ("Assert has returned false. (/¯ °‿°)/¯ ~ ┻━┻");
}

const char * Exceptions::PrintFail::what() const throw()
{
	return ("Print has failed. (/ .□.)\\  ︵╰(゜A゜)╯︵  /(.□. \\)");
}

const char * Exceptions::InvalidFile::what() const throw()
{
	return ("Invalid file has been passed through");
}

const char * Exceptions::EmptyFile::what() const throw()
{
	return ("File is empty!");
}

void        Exceptions::throwStackTooSmall()
{
	throw StackTooSmall;
}

void        Exceptions::throwNoExit()
{
	throw NoExit;
}

void        Exceptions::throwAssertFail()
{
	throw AssertFail;
}

void        Exceptions::throwPrintFail()
{
	throw PrintFail;
}

void		Exceptions::throwInvalidFile()
{
	throw InvalidFile;
}

void		Exceptions::throwEmptyFile()
{
	throw EmptyFile;
}