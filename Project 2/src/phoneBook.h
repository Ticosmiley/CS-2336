#ifndef PHONEBOOK_H_
#define PHONEBOOK_H_

#include <vector>
#include "phoneBookEntry.h"

class phoneBook{
	public:
		//default constructor
		phoneBook();

		//insert functions
		void insert(const phoneBookEntry &entry);
		void insert(const std::string &name, const std::string &number, const std::string &email);
		void insert(const std::string &name, const std::string &number);

		//erase function
		bool erase(std::string name);

		//find function
		bool find(std::string name);

		//print functions
		void print() const;
		void print(std::ostream &out) const;

		//debug function
		void debug(std::ostream &out) const;

		//size function
		std::size_t size() const;

		//type definitions
		typedef std::vector<phoneBookEntry> phoneBookEntryList;
		typedef phoneBookEntryList::iterator iterator;
		typedef phoneBookEntryList::const_iterator const_iterator;

		//iterators
		iterator begin();
		iterator end();
	private:
		phoneBookEntryList phoneBookList;
};

#endif
