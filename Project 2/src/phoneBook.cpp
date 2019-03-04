#include <algorithm>
#include <iomanip>
#include <ios>
#include <iostream>
#include "phoneBook.h"

phoneBook::phoneBook(){
}

void phoneBook::insert(const phoneBookEntry &entry){
	bool found = false;
	for (unsigned int i = 0; i < phoneBookList.size(); i++){
		if (phoneBookList.at(i).name() == entry.name()){
			phoneBookList.at(i) = entry;
			found = true;
			break;
		}
	}
	if (!found){
		phoneBookList.push_back(entry);
	}
	return;
}

void phoneBook::insert(const std::string &name, const std::string &number, const std::string &email){
	bool found = false;
	phoneBookEntry temp(name, number, email);
	for (unsigned int i = 0; i < phoneBookList.size(); i++){
		if (phoneBookList.at(i).name() == name){
			phoneBookList.at(i) = temp;
			found = true;
			break;
		}
	}
	if (!found){
		phoneBookList.push_back(temp);
	}
	return;
}

void phoneBook::insert(const std::string &name, const std::string &number){
	bool found = false;
	phoneBookEntry temp(name, number);
	for (unsigned int i = 0; i < phoneBookList.size(); i++){
		if (phoneBookList.at(i).name() == name){
			phoneBookList.at(i) = temp;
			found = true;
			break;
		}
	}
	if (!found){
		phoneBookList.push_back(temp);
	}
	return;
}

bool phoneBook::erase(std::string name){
	for (unsigned int i = 0; i < phoneBookList.size(); i++){
		if (phoneBookList.at(i).name() == name){
			phoneBookList.erase(phoneBookList.begin() + i);
			return true;
		}
	}
	return false;
}

bool phoneBook::find(std::string name){
	for (unsigned int i = 0; i < phoneBookList.size(); i++){
		if (phoneBookList.at(i).name() == name){
			return true;
		}
	}
	return false;
}

void phoneBook::print() const{
	std::cout << std::left << std::setw(31) << "Name:" << std::setw(16) << "Phone Number:" << "E-Mail:" << std::endl;
	for (unsigned int i = 0; i < phoneBookList.size(); i++){
		std::cout << std::setw(31) << phoneBookList.at(i).name() << std::setw(16) << phoneBookList.at(i).phoneNumber() << phoneBookList.at(i).email() << std::endl;
	}
	return;
}

void phoneBook::print(std::ostream &out) const{
	out << std::left << std::setw(31) << "Name:" << std::setw(16) << "Phone Number:" << "E-Mail:" << std::endl;
	for (unsigned int i = 0; i < phoneBookList.size(); i++){
		out << std::setw(31) << phoneBookList.at(i).name() << std::setw(16) << phoneBookList.at(i).phoneNumber() << phoneBookList.at(i).email() << std::endl;
	}
	return;
}

void phoneBook::debug(std::ostream &out) const{
	unsigned int i;
	out << std::left << std::setw(9) << "Index:" << std::setw(31) << "nameVal:" << std::setw(16) << "phoneNumberVal:" << "emailVal:" << std::endl;
	for (i = 0; i < phoneBookList.size(); i++){
		out << std::left << std::setw(9) << i << std::setw(31) << phoneBookList.at(i).name() << std::setw(16) << phoneBookList.at(i).phoneNumber() << phoneBookList.at(i).email() << std::endl;
	}
	out << "Total entries: " << i << std::endl;
	return;
}

std::size_t phoneBook::size() const{
	return phoneBookList.size();
}

phoneBook::iterator phoneBook::begin(){
	return phoneBookList.begin();
}

phoneBook::iterator phoneBook::end(){
	return phoneBookList.end();
}
