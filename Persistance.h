#pragma once
#include "Contact.h"
#include <iostream>
#include <string>
#include <list>
#include <fstream>


void save(std::list<Contact> b) {
	std::cin.ignore();

	std::string file{};
	std::ofstream out;
	bool valid = true;
	do{
		valid = true;
		std::cout << "Enter a file name to save your contacts to: ";
		std::getline(std::cin, file);

		if (file == "EXIT") {
		exit(2);
		}

		if (file.find(".txt") == std::string::npos || file.empty()) {
			valid = false;
			std::cout << "\nThe file name you entered is invalid.\n"
				<< "Make sure you add '.txt' at the end.\n\n"
				<< "If you do not want to save enter 'EXIT' to force exit.\n\n";
			std::cin.clear();
		}
	} while (!valid);

	out.open(file);
	if (out.fail()) {
		std::cout << "File failed to open.\n";
		save(b);
	}

	auto itr = b.begin();
	out << b.size() << '\n';
	while (itr != b.end()) {
		out << itr->getFirst() << "|" << itr->getLast() << "|" << itr->getPrimNumber() << "|" << itr->getSecNumber() << "|"
			<< itr->getEmail() << "|" << itr->getAddress() << "|" << itr->getCompany() << "|" << itr->getRelation() << '\n';
		itr++;
	}
	out.close();
	std::cout << "\nContacts saved successfully!\n\n";
}

void load(std::list<Contact>& b) {
	std::string file{};
	std::ifstream in;
	bool valid = true;

	do {
		valid = true;
		std::cout << "Enter a file name to retrieve you contacts. If you are new do not enter anything.\n"
			<< "File Name: ";
		std::getline(std::cin, file);
		if (file.empty()) {
			return;
		}
		else if (file.find(".txt") == std::string::npos) {
			valid = false;
			std::cout << "\nThe file name/format is incorrect.\n"
				<< "Make sure you add '.txt' to the end.\n\n";
			std::cin.clear();
		}
		in.open(file);
		if (!in.is_open()) {
			std::cout << "Couldn't open contact save file. Please try again.\n";
			std::cin.clear();
			in.close();
		}
		
	} while (!valid);

	std::string firstName;
	std::string lastName;

	std::string primNum{};
	std::string secNum{};

	std::string email{};
	std::string address{};
	std::string company{};
	std::string relation{};

	int count = 0;
	int size;
	in >> size;
	in.get();

	while (!in.eof()) {
		std::getline(in, firstName, '|');
		std::getline(in, lastName, '|');
		std::getline(in, primNum, '|');
		std::getline(in, secNum, '|');
		std::getline(in, email, '|');
		std::getline(in, address, '|');
		std::getline(in, company, '|');
		std::getline(in, relation, '\n');

		b.emplace_front(firstName, lastName, primNum, secNum, email, address, company, relation);
		count++;
		if (count == size) {
			break;
		}
	}
	in.close();
	std::cout << "\nContacts successfully loaded!\n\n";
}