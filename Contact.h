#pragma once

#include <iostream>
#include <list>

class Contact{
	std::string firstName;
	std::string lastName;

	std::string primNum{};
	std::string secNum{};

	std::string email{};
	std::string address{};
	std::string company{};
	std::string relation{};

	//accepts a string of length 10 and inserts the needed characters: (xxx)xxx-xxxx
	void reformatNum(std::string& num);
	//auto caps the first letter of each name to standardize and make sorting/searching easier
	void autoCap(std::string& name);

public:
	//constructs a contact object; user must enter first name, last name and primary phone number
	//the rest is optional; however if not entered, automatically initializes with an empty string
	Contact(const std::string& f, const std::string& l, std::string& phNum, std::string& secPhNum, std::string& mail, std::string& add,
		std::string& comp, std::string& rel);
	~Contact();

	const std::string& getFirst();
	const std::string& getLast();
	const std::string getPrimNumber();
	const std::string getSecNumber();
	const std::string& getEmail();
	const std::string& getAddress();
	const std::string& getCompany();
	const std::string& getRelation();

	//allows user to edit firstName
	void setFirst(Contact& b);
	//allows user to edit lastName
	void setLast(Contact& b);
	//allows user to edit primNum
	void setPrim(Contact& b);
	//allows user to set / edit secNum
	void setSec(Contact& b);
	//allows user to set / edit email
	void setEmail(Contact& b);
	//allows user to set / edit address
	void setAddress(Contact& b);
	//allows user to set / edit company
	void setCompany(Contact& b);
	//allows user to set / edit relation
	void setRelation(Contact& b);

	//overload to allow cout << 
	friend std::ostream& operator << (std::ostream out, const Contact &c);
	

	/*
				***NOT NEEDED IN CURRENT BUILD OF PROGRAM***
	to allow the program to use std::find in searchFirst, searchLast, compCount, and relationCount functions
	without the need to store the string they need in a temp string
	possible optimization to come back to
	*/

	bool operator == (const Contact& c);
	bool operator != (const Contact& c);
};

