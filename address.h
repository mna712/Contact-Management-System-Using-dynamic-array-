#ifndef ADDRESS_H
#define ADDRESS_H
#include <iomanip>
#include <string>
using namespace std;

class Address {
private:
    string city;
    string country;
    string street;
    int streetNumber;

public:
    Address();
    Address(string city, string country, string street, int streetNumber);
    string getcity();
    string getcountry();
    string getstreet();
    int getstreetnum();
    void setcity(string city);
    void setcountry(string country);
    void setstreet(string street);
    void setstreetnum(int streetNumber);
    void display();
};
#endif
