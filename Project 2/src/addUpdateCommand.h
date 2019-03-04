#ifndef ADDUPDATECOMMAND_H_
#define ADDUPDATECOMMAND_H_

#include "bookCommand.h"
#include "phoneBook.h"

class addUpdateCommand : public bookCommand{
	public:
		addUpdateCommand(phoneBook &bookIn, std::istream &inStream, std::ostream &outStream);

		void execute();
	private:
		phoneBook &book;
};

#endif
