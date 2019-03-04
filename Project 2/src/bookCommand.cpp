#include "bookCommand.h"

bookCommand::bookCommand(std::istream &inStream, std::ostream &outStream)
   :  in(inStream), out(outStream){
}

void bookCommand::print(std::string str){
	out << str << std::endl;
}

std::string bookCommand::read(std::string prompt){
	std::string input;
	out << prompt << std::endl;
	std::getline(in, input);
	return input;
}
