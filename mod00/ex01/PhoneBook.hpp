#pragma once

#include <iostream>

#include "Contact.hpp"

class PhoneBook {
   private:
    std::istream &_inputStream;
    std::ostream &_outputStream;
    int _contactIdx;
    static const int _contactCount = 8;
    Contact _contacts[_contactCount];

    void _welcome(void) const;
    void _goodBye(void) const;
    void _menu(void);
    void _printContactsTableStart(const Contact::fieldName names[], int namesCnt) const;
    void _printContactsTableEnd(int namesCnt) const;
    void _printContactLine(const Contact &contact, int idx, const Contact::fieldName names[], int namesCnt) const;
    void _printContactsTable(void) const;
    void _printContactDetails(const Contact &contact) const;
    bool _searchContacts(void) const;
    bool _fillContact(void);
    void _addContact(const Contact &contact);

   public:
    PhoneBook(std::istream &inputStream, std::ostream &outputStream);
    PhoneBook();
    ~PhoneBook();

    void run(void);
};
