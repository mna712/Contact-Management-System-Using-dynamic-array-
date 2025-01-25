#ifndef PERSON_H
#define PERSON_H
#include <iomanip>
#include "address.h"
#include <string>
using namespace std;

class person {
private:
    size_t Id;
    string classification;
    string First_name;
    string Last_name;
    string Email;
    string phone;
    Address address;
    bool isfavorite;

public:
    person();
    person(size_t Id, string First_name, string Last_name, string classification, string Email, string phone, Address& address);
    void printHeader();
    void printcontacts();
    void setfname(string First_name);
    void setlname(string Last_name);
    void setId(size_t Id);
    size_t getId();
    void setPhone(string phone);
    string getPhone();
    string getClassification();
    void setAddress(Address address);
    string getfname();
    string getlname();
    string getEmail();
    void setFavorite(bool favorite);
    bool getFavorite() const;
    void setClassification(string classification);
    void setEmail(string Email);
    Address& getAddress();
};

#endif
