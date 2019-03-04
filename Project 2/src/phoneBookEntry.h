#ifndef PHONEBOOKENTRY_H_
#define PHONEBOOKENTRY_H_

#include <string>

class phoneBookEntry{
	public:
		//constructors
		phoneBookEntry();
		phoneBookEntry(const std::string &name, const std::string &number);
		phoneBookEntry(const std::string &name, const std::string &number,  const std::string &email);
		phoneBookEntry(const phoneBookEntry &from);

		//accessors
		std::string name() const;
		std::string phoneNumber() const;
		std::string email() const;

		//mutators
		void phoneNumber(const std::string &newNumber);
		void email(const std::string &newEmail);
	private:
		std::string nameVal;
		std::string phoneNumberVal;
		std::string emailVal;
};

#endif
