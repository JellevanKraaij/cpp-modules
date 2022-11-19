#include "PhoneBook.hpp"

#include <cstdlib>
#include <iomanip>

PhoneBook::PhoneBook(std::istream &inputStream, std::ostream &outputStream)
    : _inputStream(inputStream), _outputStream(outputStream), _contactIdx(0) {}

PhoneBook::PhoneBook() : _inputStream(std::cin), _outputStream(std::cout), _contactIdx(0) {}

PhoneBook::~PhoneBook() {}

void PhoneBook::_welcome(void) const {
    _outputStream << "*******************************************" << std::endl;
    _outputStream << "* Welcome to My Awesome Phone Book        *" << std::endl;
    _outputStream << "* Following commands are available:       *" << std::endl;
    _outputStream << "*  - ADD    save new contact              *" << std::endl;
    _outputStream << "*  - SEARCH search for a contact          *" << std::endl;
    _outputStream << "*  - EXIT   exit phonebook                *" << std::endl;
    _outputStream << "*******************************************" << std::endl;
}

void PhoneBook::_goodBye(void) const {
    _outputStream << std::endl << "Thanks for using My Awesome Phone Book" << std::endl;
}

void PhoneBook::_addContact(const Contact &contact) {
    _contacts[_contactIdx] = contact;
    _contactIdx++;
    if (_contactIdx > 7)
        _contactIdx = 0;
}

bool PhoneBook::_fillContact() {
    Contact contact;
    for (int i = 0; i < Contact::getFieldCount(); i++) {
        Contact::fieldName name = static_cast<Contact::fieldName>(i);
        std::string input;
        do {
            _outputStream << "Enter (" << Contact::getFieldName(name) << "): ";

            if (!std::getline(_inputStream, input))
                return (false);
        } while (input.empty());
        contact.setField(name, input);
    }
    _addContact(contact);
    return (true);
}

void PhoneBook::_printContactsTableStart(const Contact::fieldName names[], int namesCnt) const {
    _outputStream << "+" << std::setw((namesCnt + 1) * 11) << std::setfill('=') << "+" << std::setfill(' ') << std::endl;
    _outputStream << "|" << std::setw(10) << "Index"
                  << "|";

    for (int i = 0; i < namesCnt; i++) {
        _outputStream << std::setw(10) << Contact::getFieldName(names[i]) << "|";
    }
    _outputStream << std::endl;

    _outputStream << "+" << std::setw((namesCnt + 1) * 11) << std::setfill('=') << "+" << std::setfill(' ') << std::endl;
}

void PhoneBook::_printContactsTableEnd(int namesCnt) const {
    _outputStream << "+" << std::setw((namesCnt + 1) * 11) << std::setfill('=') << "+" << std::setfill(' ') << std::endl;
}

void PhoneBook::_printContactLine(const Contact &contact, int idx, const Contact::fieldName names[], int namesCnt) const {
    _outputStream << "|" << std::setw(10) << idx << "|";
    for (int i = 0; i < namesCnt; i++) {
        std::string value = contact.getField(names[i]);

        if (value.length() > 10)
            value = value.substr(0, 8) + '.';
        _outputStream << std::setw(10) << value << "|";
    }
    _outputStream << std::endl;
}

void PhoneBook::_printContactsTable() const {
    const Contact::fieldName fields[] = {Contact::Address, Contact::firstName, Contact::lastName, Contact::nickName};
    const int fieldCnt = sizeof(fields) / sizeof(Contact::fieldName);

    _printContactsTableStart(fields, fieldCnt);
    for (int i = 0; i < _contactCount; i++) {
        _printContactLine(_contacts[i], i + 1, fields, fieldCnt);
    }
    _printContactsTableEnd(fieldCnt);
}

void PhoneBook::_printContactDetails(const Contact &contact) const {
    for (int i = 0; i < Contact::getFieldCount(); i++) {
        {
            Contact::fieldName name = static_cast<Contact::fieldName>(i);
            ;
            _outputStream << contact.getFieldName(name) << ": " << contact.getField(name) << std::endl;
        }
    }
}

bool PhoneBook::_searchContacts() const {
    _printContactsTable();

    _outputStream << "(1-8)> ";
    std::string input;
    if (!std::getline(_inputStream, input))
        return (false);

    int num = std::atoi(input.c_str());
    if (num < 1 || num > 9)
        return (true);
    _printContactDetails(_contacts[num - 1]);
    return (true);
}

void PhoneBook::_menu(void) {
    while (1) {
        std::string line;
        _outputStream << "> ";

        if (!std::getline(_inputStream, line))
            return;
        if (line == "EXIT")
            return;
        else if (line == "ADD") {
            if (!_fillContact())
                return;
        } else if (line == "SEARCH")
            _searchContacts();
    }
}

void PhoneBook::run(void) {
    _welcome();
    _menu();
    _goodBye();
}
