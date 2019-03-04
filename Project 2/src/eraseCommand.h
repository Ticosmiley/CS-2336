#ifndef ERASECOMMAND_H_
#define ERASECOMMAND_H_

#include "bookCommand.h"
#include "phoneBook.h"

class eraseCommand : public bookCommand{
	public:
		eraseCommand(phoneBook &bookIn, std::istream &inStream, std::ostream &outStream);

		void execute();
	private:
		phoneBook &book;
};

#endif
