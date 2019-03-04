#include "phoneBookEntry.h"

phoneBookEntry::phoneBookEntry(){
}

phoneBookEntry::phoneBookEntry(const std::string &name, const std::string &number){
	nameVal = name;
	phoneNumberVal = number;
}

phoneBookEntry::phoneBookEntry(const std::string &name, const std::string &number,  const std::string &email){
	nameVal = name;
	phoneNumberVal = number;
	emailVal = email;
}

phoneBookEntry::phoneBookEntry(const phoneBookEntry &from){
	nameVal = from.nameVal;
	phoneNumberVal = from.phoneNumberVal;
	emailVal = from.emailVal;
}

std::string phoneBookEntry::name() const{ // @suppress("Ambiguous problem")
	return nameVal;
}

std::string phoneBookEntry::phoneNumber() const{
	return phoneNumberVal;
}

std::string phoneBookEntry::email() const{
	return emailVal;
}

void phoneBookEntry::phoneNumber(const std::string &newNumber){
	phoneNumberVal = newNumber;
	return;
}

void phoneBookEntry::email(const std::string &newEmail){
	emailVal = newEmail;
	return;
}




