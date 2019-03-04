#include "addUpdateCommand.h"

addUpdateCommand::addUpdateCommand(phoneBook &bookIn, std::istream &inStream, std::ostream &outStream)
  :  bookCommand(inStream, outStream), book(bookIn){
}

void addUpdateCommand::execute(){
	std::string name = read("Enter name to add/update");
	std::string number = read("Enter phone number");
	std::string email = read("Enter e-mail address");
	phoneBookEntry temp(name, number, email);
	bool update = false;

	if (book.find(temp.name())){ // @suppress("Ambiguous problem") // @suppress("Invalid arguments")
		update = true;
	}

	if(update){
		print("Updating phone book entry for " + temp.name()); // @suppress("Ambiguous problem") // @suppress("Invalid arguments")
	}
	else{
		print("Adding phone book entry for " + temp.name()); // @suppress("Ambiguous problem") // @suppress("Invalid arguments")
	}
	book.insert(temp);

	return;
}
