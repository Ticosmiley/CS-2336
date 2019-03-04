#include <iostream>
#include "phoneBook.h"
#include "addUpdateCommand.h"
#include "eraseCommand.h"
#include "printCommand.h"
#include "menuList.h"

int main(){
	phoneBook book;
	menuList menu("Phone book menu:");
	addUpdateCommand addUpdate(book, std::cin, std::cout);
	eraseCommand erase(book, std::cin, std::cout);
	printCommand print(book, std::cin, std::cout);
	menuItem a('a', "add/update", addUpdate);
	menuItem e('e', "erase", erase);
	menuItem p('p', "print", print);

	menu.add(a);
	menu.add(e);
	menu.add(p);

	std::cout << "Starting the Phone Book" << std::endl << std::endl;

	menu.start();

	return 0;
}


