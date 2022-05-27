#include "Contact.h"
#include <iostream>
#include <string>

void Contact::reformatNum(std::string& num){
	if (num.length() == 10) {
		auto itr = num.begin();
		num.insert(itr, '(');
		num.insert((itr + 4), ')');
		num.insert((itr + 8), '-');
	}
}

void Contact::autoCap(std::string& name){
	name[0] = toupper(name[0]);
}

Contact::Contact(const std::string& f, const std::string& l, std::string& phNum, std::string& secPhNum, std::string& mail, std::string& add,
	std::string& comp, std::string& rel) :
	firstName(f), lastName(l), primNum(phNum), 
	secNum(secPhNum), email(mail), address(add),
	company(comp), relation(rel) {

	reformatNum(primNum);
	reformatNum(secNum);
	autoCap(firstName);
	autoCap(lastName);
}

Contact::~Contact() {
}

const std::string& Contact::getFirst()
{
	return firstName;
}

const std::string& Contact::getLast()
{
	return lastName;
}


const std::string Contact::getPrimNumber(){
	return primNum;
}

const std::string Contact::getSecNumber(){
	return secNum;
}

const std::string& Contact::getEmail(){
	return email;
}

const std::string& Contact::getAddress(){
	return address;
}

const std::string& Contact::getCompany(){
	return company;
}

const std::string& Contact::getRelation(){
	return relation;
}

void Contact::setFirst(Contact& b){
	std::cin.ignore();

	std::string newFirst{};
	bool valid = true;

	std::cout << "Current First Name: " << b.getFirst() << '\n';
	std::cout << "Edit: ";
	do {
		valid = true;
		std::getline(std::cin, newFirst);
		if (std::cin.fail() || newFirst == "") {
			valid = false;
			std::cout << "You must enter a first name. Please re-enter: ";
			std::cin.clear();
		}
	} while (!valid);

	autoCap(newFirst);
	b.firstName = newFirst;
}

void Contact::setLast(Contact& b){
	

	std::string newLast{};
	bool valid = true;

	std::cout << "Current Last Name: " << b.getLast() << '\n';
	std::cout << "Edit: ";
	do {
		valid = true;
		std::getline(std::cin, newLast);
		if (std::cin.fail() || newLast == "") {
			valid = false;
			std::cout << "You must enter a last name. Please re-enter: ";
			std::cin.clear();
			std::cin.ignore();
		}
	} while (!valid);

	autoCap(newLast);
	b.lastName = newLast;
}

void Contact::setPrim(Contact& b){
	std::cin.ignore();

	std::string newNum{};
	bool valid = true;

	std::cout << "Current Primary Number: " << b.getPrimNumber() << '\n';
	std::cout << "Edit: ";
	do {
		valid = true;
		std::getline(std::cin, newNum);

		if (std::cin.fail() || newNum == "" || newNum.size() < 10) {
			std::cout << "You must enter a valid Primary number. Please re-enter: ";
			valid = false;
			std::cin.clear();
		}
	} while (!valid);

	reformatNum(newNum);
	b.primNum = newNum;
}

void Contact::setSec(Contact& b){
	std::cin.ignore();

	std::string newNum{};

	std::cout << "Current Secondary Number: " << b.getSecNumber() << '\n';
	std::cout << "Edit: ";
	std::getline(std::cin, newNum);

	reformatNum(newNum);
	b.secNum = newNum;
}

void Contact::setEmail(Contact& b){
	std::cin.ignore();

	std::string newEmail{};
	
	std::cout << "Current E-mail Address Number: " << b.getEmail() << '\n';
	std::cout << "Edit: ";
	std::getline(std::cin, newEmail);
	
	b.email = newEmail;
}

void Contact::setAddress(Contact& b){
	std::cin.ignore();

	std::string newAddress{};
	
	std::cout << "Current Address: " << b.getAddress() << '\n';
	std::cout << "Edit: ";
	std::getline(std::cin, newAddress);
	
	b.address = newAddress;
}

void Contact::setCompany(Contact& b){
	std::cin.ignore();

	std::string newCompany{};
	
	std::cout << "Current Company: " << b.getCompany() << '\n';
	std::cout << "Edit: ";
	std::getline(std::cin, newCompany);
	
	b.company = newCompany;
}

void Contact::setRelation(Contact& b){
	std::cin.ignore();

	std::string newRelation{};
	
	std::cout << "Current Relation: " << b.getRelation() << '\n';
	std::cout << "Edit: ";
	std::getline(std::cin, newRelation);
	
	b.relation = newRelation;
}

bool Contact::compLast(Contact& lhs, Contact& rhs){
	int compResult = lhs.lastName.compare(rhs.lastName);

	if (compResult == 0) {
		compResult = lhs.firstName.compare(rhs.firstName);
	}
	return compResult < 0;
}

bool Contact::operator==(const Contact& c)
{
	return ((firstName == c.firstName) && (lastName == c.lastName));
}

bool Contact::operator!=(const Contact& c)
{
	return !operator == (c);
}

std::ostream& operator<<(std::ostream out, const Contact& c){
	out << c.firstName << " " << c.lastName << ": " << c.primNum;
	return out;
}




