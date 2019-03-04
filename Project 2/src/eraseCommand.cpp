#include "eraseCommand.h"

eraseCommand::eraseCommand(phoneBook &bookIn, std::istream &inStream, std::ostream &outStream)
  :  bookCommand(inStream, outStream), book(bookIn){
}

void eraseCommand::execute(){
	std::string name = read("Enter name to erase");
	if(book.find(name)){
		book.erase(name);
		print("Phone book entry for " + name + " was erased");
	}
	else{
		print("Phone book entry for " + name + " was not erased");
	}

	return;
}
