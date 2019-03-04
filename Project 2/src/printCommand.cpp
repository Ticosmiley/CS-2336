#include "printCommand.h"

printCommand::printCommand(phoneBook &bookIn, std::istream &inStream, std::ostream &outStream)
  :  bookCommand(inStream, outStream), book(bookIn){
}

void printCommand::execute(){
	book.print(out);
	return;
}
