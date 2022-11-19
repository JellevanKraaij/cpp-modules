#pragma once
#include <string>

class Contact {
   public:
    enum fieldName { firstName, lastName, nickName, phoneNumber, DarkestSecrect, END };

   private:
    std::string _fields[Contact::END];
    static const std::string _names[Contact::END];

   public:
    Contact();
    ~Contact();

    std::string getField(const Contact::fieldName name) const;
    static const std::string &getFieldName(const Contact::fieldName name);
    static int getFieldCount(void);

    void setField(const Contact::fieldName name, const std::string &value);
};
