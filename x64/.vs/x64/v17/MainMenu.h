#pragma once

#include "Contact.h"
#include "ContactBook.h"
#include "Persistance.h"

#include <iostream>
#include <iomanip>
#include <limits>
#include <list>


using std::cout;
using std::cin;

int getChoice();

void MainMenu() {
	static std::list<Contact> contactBook;

	load(contactBook);

	do {
		contactBook.sort(LastComp());
		cout << "Contact Manager\n"
			<< '\n'
			<< "Please select a choice:\n"
			<< "     [1] Add Contact\n\n"
			<< "     [2] View Contacts\n\n"
			<< "     [3] Edit Contact\n\n"
			<< "     [4] Clear Contacts\n\n"
			<< "     [5] Exit\n\n"
			<< "Choice: ";

		int choice = getChoice();

		switch (choice) {

		case 1: addContact(contactBook);
			break;
		case 2: viewContacts(contactBook);
			break;
		case 3: editContact(contactBook);
			break;
		case 4: clearContacts(contactBook);
			break;
		case 5: save(contactBook);
			exit(69);
			break;
		}
	} while (true);
}

int getChoice() {
	int choice{};
	bool valid = true;
	do {
		valid = true;
		cin >> choice;
		if (cin.fail() || choice > 5 || choice < 1) {
			cout << "The choice you entered was invalid\n"
				<< "Please enter\n"
				<< "[1] to add a contact\n"
				<< "[2] to view your contacts\n"
				<< "[3] to edit a contact or\n"
				<< "[4] to exit\n"
				<< "Choice: ";
			valid = false;
			cin.clear();
			cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
		}
	} while (!valid);

	return choice;
}