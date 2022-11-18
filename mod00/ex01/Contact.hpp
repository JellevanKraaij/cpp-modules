#pragma once
#include <string>

class Contact {
   public:
    enum fieldName { firstName, lastName, nickName, phoneNumber, DarkestSecrect, Address, END };

   private:
    std::string _fields[Contact::END];
    static const std::string _names[Contact::END];

   public:
    Contact();
    ~Contact();

    const std::string &getField(const Contact::fieldName name) const;
    const std::string &getFieldName(const Contact::fieldName name) const;
    int getFieldCount(void) const;

    void setField(const Contact::fieldName name, const std::string &value);
};
