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

	/*
		
	*/
	void reformatNum(std::string& num);
	
	void autoCap(std::string& name);

public:
	Contact(const std::string& f, const std::string& l, std::string& phNum, std::string& secPhNum, std::string& mail, std::string& add,
		std::string& comp, std::string& rel);
	~Contact();

	const std::string& getFirst();
	const std::string& getLast();
	const std::string& getName();
	const std::string getPrimNumber();
	const std::string getSecNumber();
	const std::string& getEmail();
	const std::string& getAddress();
	const std::string& getCompany();
	const std::string& getRelation();

	void setFirst(Contact& b);
	void setLast(Contact& b);
	void setPrim(Contact& b);
	void setSec(Contact& b);
	void setEmail(Contact& b);
	void setAddress(Contact& b);
	void setCompany(Contact& b);
	void setRelation(Contact& b);

	bool compFirst(Contact& lhs, Contact& rhs);
	bool compLast(Contact& lhs, Contact& rhs);

	friend std::ostream& operator << (std::ostream out, const Contact &c);
	bool operator == (const Contact& c);
	bool operator != (const Contact& c);
};

