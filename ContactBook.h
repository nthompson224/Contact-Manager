#pragma once

#include "Contact.h"
#include "MainMenu.h"
#include <iostream>
#include <string>
#include <list>
#include <set>
#include <vector>
#include <algorithm>


int getEdit() {
	int choice{};
	bool valid = true;
	do {
		valid = true;
		std::cin >> choice;
		if (std::cin.fail() || choice < 0 || choice > 9) {
			std::cout << "\n\nThe choice you entered was invalid; please try again.\n"
				<< "Choice: ";
			valid = false;
			std::cin.clear();
			std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
		}
	} while (!valid);

	return choice;
}

int getSort() {
	int choice{};
	bool valid = true;
	do {
		valid = true;
		std::cin >> choice;
		if (std::cin.fail() || choice < 0 || choice > 9) {
			std::cout << "\n\nYour input was invalid. Please try again\n"
				<< "Choice: ";

			valid = false;
			std::cin.clear();
			std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
		}
	} while (!valid);

	return choice;
}


void addContact(std::list<Contact>& book) {
	std::cin.ignore();

	bool quit = false, valid = true;
	char choice{};

	do {
		std::cout << "\n\n\n";
		std::cout << "Add Contact\n\n";

		std::cout << "[A] Add Contact\n"
			<< "[Q] Go Back.\n\n\n";

		do {
			valid = true;
			std::cout << "Choice: ";
			std::cin >> choice;
			if (std::cin.fail() || (toupper(choice) != 'Q' && (toupper(choice) != 'A'))) {
				valid = false;
				std::cout << "\n\nThe choice you entered was not valid\n"
					<< "Enter 'A' to add a new contact or 'Q' to go back\n";
				std::cin.clear();
				std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
			}
		} while (!valid);

		if (toupper(choice) == 'Q') {
			return;
		}

		std::cin.ignore();

		std::string firstName;
		std::string lastName;

		std::string primNum{};
		std::string secNum{};

		std::string email{};
		std::string address{};
		std::string company{};
		std::string relation{};

		std::cout << "*: Field Required\n\n";

		std::cout << "First Name:* ";
		do {
			valid = true;
			std::getline(std::cin, firstName);
			if (std::cin.fail() || firstName == "") {
				valid = false;
				std::cout << "You must enter a first name. Please re-enter: ";
				std::cin.clear();
			}
				
		} while (!valid);

		std::cout << '\n'
			<< "Last Name:* ";
		do {
			valid = true;
			std::getline(std::cin, lastName);
			if (std::cin.fail() || lastName == "") {
				valid = false;
				std::cout << "You must enter a last name. Please re-enter: ";
				std::cin.clear();
			}
				
		} while (!valid);


		std::cout << '\n'
			<< "Primary Phone Number:* ";
		do {
				
			valid = true;
			std::getline(std::cin, primNum);

			if (std::cin.fail() || primNum == "" || primNum.size() != 10) {
				std::cout << "You must enter a valid Primary number. Please re-enter: ";
				valid = false;
				std::cin.clear();
			}
				
		} while (!valid);

		std::cout << '\n'
			<< "Secondary Phone Number: ";
		std::getline(std::cin, secNum);

		std::cout << '\n'
			<< "Email: ";
		std::getline(std::cin, email);

		std::cout << '\n'
			<< "Address: ";
		std::getline(std::cin, address);

		std::cout << '\n'
			<< "Company: ";
		std::getline(std::cin, company);

		std::cout << '\n'
			<< "Relation: ";
		std::getline(std::cin, relation);

		book.emplace_front(firstName, lastName, primNum, secNum, email, address, company, relation);
	
	} while (!quit);
}

struct FirstComp {
	bool operator()(Contact& lhs, Contact& rhs) {
		int compResult = lhs.getFirst().compare(rhs.getFirst());

		if (compResult == 0) {
			compResult = lhs.getLast().compare(rhs.getLast());
		}

		return compResult < 0;
	}
};

struct LastComp {
	bool operator()(Contact& lhs, Contact& rhs) {

		int compResult = lhs.getLast().compare(rhs.getLast());

		if (compResult == 0) {
			compResult = lhs.getFirst().compare(rhs.getFirst());
		}

		return compResult < 0;
	}
};

void firstNameDisplay(std::list<Contact> b) {
	std::cin.ignore();

	b.sort(FirstComp());
	auto itr = b.begin();
	int i = 1;
	while (itr != b.end()) {
		std::cout << "[" << i << "] " << itr->getFirst() << " " << itr->getLast() << ":\n\n"
			<< "     Primary Number: " << itr->getPrimNumber() << '\n'
			<< "     Secondary Number: " << itr->getSecNumber() << '\n'
			<< "     Email Address: " << itr->getEmail() << '\n'\
			<< "     Address: " << itr->getAddress() << '\n'
			<< "     Company: " << itr->getCompany() << '\n'
			<< "     Relation: " << itr->getRelation() << "\n\n\n";
		itr++;
		i++;
	}
	std::cout << "Press enter to continue...";
	std::cin.get();
}

void lastNameDisplay(std::list<Contact> b) {
	std::cin.ignore();

	auto itr = b.begin();
	int i = 1;
	while (itr != b.end()) {
		std::cout << "[" << i << "] " << itr->getLast() << ", " << itr->getFirst() << ":\n\n"
			<< "     Primary Number: " << itr->getPrimNumber() << '\n'
			<< "     Secondary Number: " << itr->getSecNumber() << '\n'
			<< "     Email Address: " << itr->getEmail() << '\n'\
			<< "     Address: " << itr->getAddress() << '\n'
			<< "     Company: " << itr->getCompany() << '\n'
			<< "     Relation: " << itr->getRelation() << "\n\n\n";
		itr++;
		i++;
	}
}

void simpleView(std::list<Contact> b) {
	std::cin.ignore();

	b.sort(FirstComp());

	auto itr = b.begin();
	int i = 1;
	while (itr != b.end()) {
		std::cout << "[" << i << "] " << itr->getFirst() << ": " << itr->getPrimNumber() << "\n\n";
		itr++;
		i++;
	}
	std::cout << "Press enter to continue...";
	std::cin.get();
}

void companyView(std::list<Contact> b) {
	std::cin.ignore();

	std::vector<std::string> comp;
	std::vector<Contact*> contactPtr;

	auto itr = b.begin();

	while (itr != b.end()) {
		std::string temp = itr->getCompany();
		if (std::find(comp.begin(), comp.end(), temp) == comp.end() && !temp.empty()) {
			comp.push_back(temp);
			contactPtr.push_back(&*itr);
		}
		else if (std::find(comp.begin(), comp.end(), temp) != comp.end() && !temp.empty()) {
			contactPtr.push_back(&*itr);
		}
		itr++;
	}
	if (comp.empty()) {
		std::cout << "You have no contacts with companies linked to them.\n";
		return;
	}
	do {
		auto compItr = comp.begin();
		int i = 1;

		std::cout << "Companies:\n";
		while (compItr != comp.end()) {
			std::cout << "[" << i << "] " << *compItr << "\n\n";
			compItr++;
			i++;
		}
		std::cout << "[" << i << "] to go back\n\n";

		std::cout << "Select which contacts you would like to view: ";
		int choice{};
		bool valid = true;
		do {
			valid = true;
			std::cin >> choice;
			if (choice == i) {
				return;
			}
			if (std::cin.fail() || choice < 1 || choice > i) {
				valid = false;
				std::cout << "The company you chose was invalid; please try again: ";
				std::cin.clear();
				std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
			}
		} while (!valid);

		compItr = comp.begin();
		std::advance(compItr, choice - 1);

		std::string contact = *compItr;
		i = 1;

		std::cout << "Contact: " << contact << "\n\n";
		for (auto& x : contactPtr) {
			if (x->getCompany() == contact) {
				std::cout << "[" << i << "] " << x->getLast() << ", " << x->getFirst() << ":\n\n"
					<< "     Primary Number: " << x->getPrimNumber() << '\n'
					<< "     Secondary Number: " << x->getSecNumber() << '\n'
					<< "     Email Address: " << x->getEmail() << '\n'\
					<< "     Address: " << x->getAddress() << '\n'
					<< "     Relation: " << x->getRelation() << "\n\n\n";

				i++;
			}
		}
		std::cin.ignore();
		std::cout << "Press enter to continue...";
		std::cin.get();
	} while (true);
}

void relationView(std::list<Contact> b) {
	std::cin.ignore();

	std::vector<std::string> relation;
	std::vector<Contact*> relationPtr;

	auto itr = b.begin();

	while (itr != b.end()) {
		std::string temp = itr->getRelation();
		if (std::find(relation.begin(), relation.end(), temp) == relation.end() && !temp.empty()) {
			relation.push_back(temp);
			relationPtr.push_back(&*itr);
		}
		else if (std::find(relation.begin(), relation.end(), temp) != relation.end() && !temp.empty()) {
			relationPtr.push_back(&*itr);
		}
		itr++;
	}
	if (relation.empty()) {
		std::cout << "You have no contacts with relations linked to them.\n";
		return;
	}

	do {
		auto relItr = relation.begin();
		int i = 1;

		std::cout << "Relations:\n";
		while (relItr != relation.end()) {
			std::cout << "[" << i << "] " << *relItr << "\n\n";
			relItr++;
			i++;
		}
		std::cout << "[" << i << "] to go back\n\n";
		std::cout << "Select which contacts you would like to view: ";
		int choice{};
		bool valid = true;
		do {
			valid = true;
			std::cin >> choice;
			if (choice == i) {
				return;
			}
			if (std::cin.fail() || choice < 1 || choice > i) {
				valid = false;
				std::cout << "The relation you chose was invalid; please try again: ";
				std::cin.clear();
				std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
			}
		} while (!valid);
		
		std::cout << '\n';

		relItr = relation.begin();
		std::advance(relItr, choice - 1);

		std::string rel = *relItr;
		i = 1;

		std::cout << "Relation: " << rel << "\n\n";
		for (auto& x : relationPtr) {
			if (x->getRelation() == rel) {
				std::cout << "[" << i << "] " << x->getLast() << ", " << x->getFirst() << ":\n\n"
					<< "     Primary Number: " << x->getPrimNumber() << '\n'
					<< "     Secondary Number: " << x->getSecNumber() << '\n'
					<< "     Email Address: " << x->getEmail() << '\n'\
					<< "     Address: " << x->getAddress() << '\n'
					<< "     Company: " << x->getCompany() << "\n\n";

				i++;
			}
		}
		std::cin.ignore();
		std::cout << "Press enter to continue...";
		std::cin.get();
	} while (true);
}

void searchFirst(std::list<Contact> b) {
	std::cin.ignore();

	b.sort(FirstComp());

	std::string nameSearch{};
	int i = 1;
	bool valid = true;

	do {
		std::cout << "First Name to search (caps sensitive) or press '0' to go back: ";
		do {
			valid = true;
			std::getline(std::cin, nameSearch);
			
			if (nameSearch == "0") {
				return;
			}
			else if (std::cin.fail() || nameSearch == "") {
				valid = false;
				std::cout << "You must enter a valid first name to search. Please re-enter or press '0' to go back: ";
				std::cin.clear();
				std::cin.ignore();
			}

		} while (!valid);

		std::cout << '\n';

		bool found = false;
		auto itr = b.begin();
		while (itr != b.end()) {
			if (itr->getFirst().find(nameSearch) != std::string::npos) {
				found = true;
				std::cout << "[" << i << "] " << itr->getFirst() << " " << itr->getLast() << ":\n\n"
					<< "     Primary Number: " << itr->getPrimNumber() << '\n'
					<< "     Secondary Number: " << itr->getSecNumber() << '\n'
					<< "     Email Address: " << itr->getEmail() << '\n'\
					<< "     Address: " << itr->getAddress() << '\n'
					<< "     Company: " << itr->getCompany() << '\n'
					<< "     Relation: " << itr->getRelation() << "\n\n\n";
				i++;
			}
			itr++;
		}
		if (!found) {
			std::cout << "The name you entered was not found; check the capitalization.\n";
		}
		std::cout << "Press enter to continue...";
		std::cin.get();
	} while (true);
}

void searchLast(std::list<Contact> b) {
	std::cin.ignore();

	b.sort(LastComp());

	std::string nameSearch{};
	int i = 1;
	bool valid = true;

	do {
		std::cout << "Last Name to search (caps sensitive) or press '0' to go back: ";
		do {
			valid = true;
			std::getline(std::cin, nameSearch);

			if (nameSearch == "0") {
				return;
			}
			else if (std::cin.fail() || nameSearch == "") {
				valid = false;
				std::cout << "You must enter a valid last name to search. Please re-enter or press '0' to go back: ";
				std::cin.clear();
				std::cin.ignore();
			}

		} while (!valid);

		std::cout << '\n';

		bool found = false;
		auto itr = b.begin();
		while (itr != b.end()) {
			if (itr->getLast().find(nameSearch) != std::string::npos) {
				found = true;
				std::cout << "[" << i << "] " << itr->getLast() << ", " << itr->getFirst() << ":\n\n"
					<< "     Primary Number: " << itr->getPrimNumber() << '\n'
					<< "     Secondary Number: " << itr->getSecNumber() << '\n'
					<< "     Email Address: " << itr->getEmail() << '\n'\
					<< "     Address: " << itr->getAddress() << '\n'
					<< "     Company: " << itr->getCompany() << '\n'
					<< "     Relation: " << itr->getRelation() << "\n\n\n";
				i++;
			}
			itr++;
		}
		if (!found) {
			std::cout << "The name you entered was not found; check the capitalization.\n";
		}
		std::cout << "Press enter to continue...";
		std::cin.get();
	} while (true);
}

void companyCount(std::list<Contact> b) {
	std::cin.ignore();

	std::vector<std::string> comp;
	std::vector<std::string> compCount;


	auto itr = b.begin();

	while (itr != b.end()) {
		std::string temp = itr->getCompany();
		if (std::find(comp.begin(), comp.end(), temp) == comp.end() && !temp.empty()) {
			comp.push_back(temp);
		}
		compCount.push_back(temp);
		itr++;
	}
	auto compItr = comp.begin();

	std::cout << "You have: \n";
	while (compItr != comp.end()) {
		std::cout << "     " << std::count(compCount.begin(), compCount.end(), *compItr) << " contact(s) from: " << *compItr << '\n';
		compItr++;
	}
	std::cout << "\nPress enter to continue...\n";
	std::cin.get();
}

void relationCount(std::list<Contact> b) {
	std::cin.ignore();

	std::vector<std::string> rel;
	std::vector<std::string> relCount;


	auto itr = b.begin();

	while (itr != b.end()) {
		std::string temp = itr->getRelation();
		if (std::find(rel.begin(), rel.end(), temp) == rel.end() && !temp.empty()) {
			rel.push_back(temp);
		}
		relCount.push_back(temp);
		itr++;
	}
	auto relItr = rel.begin();

	std::cout << "You have:\n";
	while (relItr != rel.end()) {
		std::cout << "     " << std::count(relCount.begin(), relCount.end(), *relItr) << " contact(s) that are: " << *relItr << '\n';
		relItr++;
	}
	std::cout << "\nPress enter to continue...\n";
	std::cin.get();
}

void viewContacts(std::list<Contact> b) {
	std::cin.ignore();

	std::cout << "\n\nCONTACT VIEW\n\n";

	if (b.empty()) {
		std::cout << "You currently have no contacts. Press enter to continue\n\n";
		std::cin.get();
		return;
	}


	do {

		std::cout << "Sort Options: \n"
			<< "     [1] Default: Last Name (A-Z)\n"
			<< "     [2] First Name (A-Z)\n\n"
			<< "View Options:\n"
			<< "     [3] Simple (Sorted by First Name)\n"
			<< "     [4] View by Company\n"
			<< "     [5] View by Relation\n\n"
			<< "Search:\n"
			<< "     [6] By First Name\n"
			<< "     [7] By Last Name\n\n"
			<< "Other:\n"
			<< "     [8] Count of Contacts (Company)\n"
			<< "     [9] Count of Contacts (Relation)\n\n"
			<< "[0] Go Back\n\n"
			<< "Choice: ";

		int choice = getSort();

		if (choice == 0) {
			return;
		}

		switch (choice) {
		case 1: lastNameDisplay(b);
			std::cout << "Press enter to continue...";
			std::cin.get();
			break;
		case 2: firstNameDisplay(b);
			break;
		case 3: simpleView(b);
			break;
		case 4: companyView(b);
			break;
		case 5: relationView(b);
			break;
		case 6: searchFirst(b);
			break;
		case 7: searchLast(b);
			break;
		case 8: companyCount(b);
			break;
		case 9: relationCount(b);
			break;
		case 0: return;
		}
	} while (true);
 }

void deleteContact(std::list<Contact>& b, std::list<Contact>::iterator &itr) {
	std::cin.ignore();

	char choice{};
	bool valid = true;

	std::cout << "Are you sure you want to delete this contact?\n\n";
	
	do {
		valid = true;
		std::cout << "(Y/N): ";
		std::cin >> choice;

		if (std::cin.fail() || (toupper(choice) != 'Y' && toupper(choice) != 'N')) {
			valid = false;
			std::cout << "The input was invalid please choose 'Y' or 'N'.\n";
			std::cin.clear();
			std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
		}
	} while (!valid);

	if (toupper(choice) == 'Y') {
		b.erase(itr);
		std::cout << "Contact deleted\n\n";
	}
	else {
		std::cout << "Contact will not be deleted. Returning to Contact edit\n\n";
	}
}

void editContact(std::list<Contact>& b) {

	std::cout << "\n\nCONTACT EDIT\n\n";

	bool valid = true;
	
	if (b.empty()) {
		std::cout << "You currently have no contacts. Press enter to continue\n\n";
		std::cin.get();
		return;
	}

	do {
		lastNameDisplay(b);


		int choice{};

		do {
			valid = true;
			std::cout << "Select a contact to edit or press '0' to go back: ";
			std::cin >> choice;
			if (std::cin.fail() || choice < 0 || choice > b.size()) {
				valid = false;
				std::cout << "Invalid choice; please try again.\n";
				std::cin.clear();
				std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
			}
		} while (!valid);

		if (choice == 0) {
			return;
		}

		std::list<Contact>::iterator itr = b.begin();
		std::advance(itr, choice - 1);

		std::cout << "[" << choice << "]\n"
			<< "     [1] First Name: " << itr->getFirst() << '\n'
			<< "     [2] Last Name: " << itr->getLast() << '\n'
			<< "     [3] Primary Number: " << itr->getPrimNumber() << '\n'
			<< "     [4] Secondary Number: " << itr->getSecNumber() << '\n'
			<< "     [5] Email Address: " << itr->getEmail() << '\n'\
			<< "     [6] Address: " << itr->getAddress() << '\n'
			<< "     [7] Company: " << itr->getCompany() << "\n"
			<< "     [8] Relation: " << itr->getRelation() << "\n\n"
			<< "     [9] Delete\n\n"
			<< "[0] Go Back\n\n\n";

		std::cout << "Select what you would like to edit: ";
		int edit = getEdit();

		switch (toupper(edit))
		{
		case 1: itr->setFirst(*itr);
			break;
		case 2: itr->setLast(*itr);
			break;
		case 3: itr->setPrim(*itr);
			break;
		case 4: itr->setSec(*itr);
			break;
		case 5: itr->setEmail(*itr);
			break;
		case 6: itr->setAddress(*itr);
			break;
		case 7: itr->setCompany(*itr);
			break;
		case 8: itr->setRelation(*itr);
			break;
		case 9: deleteContact(b, itr);
			break;
		case 0: editContact(b);
			break;
		}
		std::cout << "\n\nPress enter to continue...\n";

	} while (true);
}

void clearContacts(std::list<Contact>& b) {
	std::cin.ignore();

	char choice{};
	bool valid = true;

	std::cout << "Are you sure you want to clear your contacts?\n\n";

	do {
		valid = true;
		std::cout << "(Y/N): ";
		std::cin >> choice;

		if (std::cin.fail() || (toupper(choice) != 'Y' && toupper(choice) != 'N')) {
			valid = false;
			std::cout << "The input was invalid please choose 'Y' or 'N'.\n";
			std::cin.clear();
			std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
		}
	} while (!valid);

	if (toupper(choice) == 'Y') {
		b.clear();
		std::cout << "\n\nContacts Cleared. Returning to main menu.\n\n";
	}
	else {
		std::cout << "\n\nContact will not be deleted. Returning to main menu.\n\n";
	}
}
