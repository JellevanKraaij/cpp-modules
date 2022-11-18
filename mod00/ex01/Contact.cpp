#include "Contact.hpp"

Contact::Contact() {}
Contact::~Contact() {}

const std::string Contact::_names[] = {"First Name", "Last Name", "Nick Name", "Phone Number", "Darkest Secret", "Address"};

const std::string &Contact::getField(const Contact::fieldName name) const {
    return (_fields[name]);
}

const std::string &Contact::getFieldName(const Contact::fieldName name) const {
    return (_names[name]);
}

int Contact::getFieldCount(void) const {
    return (Contact::END);
}

void Contact::setField(const fieldName name, const std::string &value) {
    _fields[name] = value;
}
