#ifndef BOOKCOMMAND_H_
#define BOOKCOMMAND_H_

#include <iostream>
#include "command.h"

class bookCommand : public command{
	public:
		bookCommand(std::istream &in, std::ostream &out);
	protected:
		std::istream &in;
		std::ostream &out;

		//helper functions
		void print(std::string str);
		std::string read(std::string prompt);
};

#endif
