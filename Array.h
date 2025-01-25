#ifndef ARRAY_H
#define ARRAY_H
#include <iomanip>
#include <iostream>
#include <string>
#include "Array.h"
#include "person.h"
#include "Address.h"
#include <string>
#include <iostream>
#include <fstream>
#include <sstream>
#include <iomanip>
using namespace std;
template <typename T>
class Array {
private:
    T* persons;
    size_t capacity;
    size_t Size;

public:
Array() {
    Size = 0;
    capacity = 2;
    persons = new T[capacity];
}


void resize(size_t newcapacity) {
    T* newlist = new T[newcapacity];
    for (size_t i = 0; i < Size; i++) {
        newlist[i] = persons[i];
    }
    delete[] persons;
    persons = newlist;
    capacity = newcapacity;
}


void add(T& Person) {
    if (Size >= capacity) {
        resize(capacity * 2);
    }
    persons[Size++] = Person;
}


void remove(string First_name) {
    bool found = false;
    for (size_t i = 0; i < Size; ++i) {
        if (persons[i].getfname() == First_name) {
            for (size_t j = i; j < Size - 1; ++j)
            {
                persons[j] = persons[j + 1];
            }
            Size--;
            found = true;
            break;
        }
    }
    if (!found) {
        cout << "Contact not found!" << endl;
    }
}


void search(string First_name) {
    int flag=0;
    persons->printHeader();
    cout << "..............................................................................................................................................." << endl;

    for (size_t i = 0; i < Size; ++i) {
        if (persons[i].getfname() == First_name) {
            persons[i].printcontacts();
           // continue;
            flag=1;
        }
        else
            {
                continue;
            }
    }
    if(flag==0)
    {
        cout << "Contact not found!" << endl;
    }
}

void searchlast(string Last_name) {
    persons->printHeader();
    cout << "..............................................................................................................................................." << endl;
     int flag=0;
    for (size_t i = 0; i < Size; ++i) {
        if (persons[i].getlname() == Last_name) {
            persons[i].printcontacts();
            flag=1;
        }
        else
            {
                continue;
            }
    }
    if(flag==0)
    {
        cout << "Contact not found!" << endl;
    }
}


void searchByClassification(string clas) {
   persons->printHeader();
        cout<<"..............................................................................................................................................."<<endl;
    int flag=0;
    for (int i = 0; i < Size; ++i) {
        if (persons[i].getClassification() == clas) {
            persons[i].printcontacts();
            //return;
            flag=1;
        }
         else{

         continue;
    }
    }
    if(flag==0)
    {
        cout<<"No contacts with this classification "<<endl;
    }
}


void displayAll() {
    persons->printHeader();
    cout << "..............................................................................................................................................." << endl;

    for (size_t i = 0; i < Size; ++i) {
        persons[i].printcontacts();
    }
}


void displayFavorites() {
    bool hasFavorites = false;
     cout<<endl;
     //cout<<"..............................................................................................................................................."<<endl;
     persons->printHeader();
     cout<<"..............................................................................................................................................."<<endl;
     for (int i = 0; i < Size; ++i)
     {
            if (persons[i].getFavorite())
             {
                  persons[i].printcontacts();
                  hasFavorites = true;
             }
     }
     if(!hasFavorites)
     {
         cout<<"No favorite contacts "<<endl;
     }
}

void updatecontact(size_t id) {
    for (size_t i = 0; i < Size; i++) {
        if (persons[i].getId() == id) {
            string First_name, Last_name, classification, Email, phone;
            int streetNum;
            string street, city, country;
            Address newAddress;

             bool Isfavorite;

            cout << "Enter new First Name: ";
            cin >> First_name;
            persons[i].setfname(First_name);

            cout << "Enter new Last Name: ";
            cin >> Last_name;
            persons[i].setlname(Last_name);

            cout << "Enter new Classification: ";
            cin >> classification;
            persons[i].setClassification(classification);

            cout << "Enter new Email: ";
            cin >> Email;
            persons[i].setEmail(Email);

            cout << "Enter new Phone: ";
            cin >> phone;
            persons[i].setPhone(phone);

            cout << "Enter new Address (Street Number, Street, City, Country): ";
            cin >> streetNum >> street >> city >> country;
            newAddress = Address(city, country, street, streetNum);
            persons[i].setAddress(newAddress);
            cout << "Is this contact a favorite? (1 for yes, 0 for no): ";
            cin >> Isfavorite;
            persons[i].setFavorite(Isfavorite);

            cout << "Contact updated successfully!" << endl;
            return;
        }
    }
    cout << "Contact not found!" << endl;
}


void Reverse() {
    persons->printHeader();
     cout<<"..............................................................................................................................................."<<endl;
    size_t start=0;
    size_t End=Size-1;
    while(start<End)
    {
        person temp=persons[start];
        persons[start]=persons[End];
        persons[End]=temp;

        start++;
        End--;
    }
    for (int i = 0; i < Size; ++i) {
            persons[i].printcontacts();
            //return;
        }
}


void saveToFile(const string& filename) {
    ofstream outFile(filename);
    if (outFile.is_open()) {
        for (size_t i = 0; i < Size; ++i) {
            outFile << persons[i].getId() << ","
                    << persons[i].getfname() << ","
                    << persons[i].getlname() << ","
                    << persons[i].getClassification() << ","
                    << persons[i].getEmail() << ","
                    << persons[i].getPhone() << ","
                    << persons[i].getAddress().getstreetnum() << ","
                    << persons[i].getAddress().getstreet() << ","
                    << persons[i].getAddress().getcity() << ","
                    << persons[i].getAddress().getcountry() << ","
                    << persons[i].getFavorite() << endl;
        }
        outFile.close();
        cout << "Contacts saved successfully to " << filename << endl;
    } else {
        cout << "Unable to open file for writing!" << endl;
    }
}


void readFromFile(const string& filename) {
    ifstream inFile(filename);
    if (inFile.is_open()) {
        while (!inFile.eof()) {
            size_t id;
            string First_name, Last_name, classification, Email, phone;
            int streetNum;
            string street, city, country;
            bool isfavorite;

            string line;
            getline(inFile, line);
            if (line.empty()) continue; // Skip empty lines

            stringstream ss(line);
            string temp;
            getline(ss, temp, ','); id = stoi(temp);
            getline(ss, First_name, ',');
            getline(ss, Last_name, ',');
            getline(ss, classification, ',');
            getline(ss, Email, ',');
            getline(ss, phone, ',');
            getline(ss, temp, ',');
            streetNum = stoi(temp);
            getline(ss, street, ',');
            getline(ss, city, ',');
            getline(ss, country, ',');
            getline(ss, temp, ',');
             isfavorite = (temp == "1");

            Address newAddress(city, country, street, streetNum);
            T newPerson(id, First_name, Last_name, classification, Email, phone, newAddress);
            newPerson.setFavorite(isfavorite);
            add(newPerson);
        }
        inFile.close();
        cout << "Contacts loaded successfully from " << filename << endl;
    } else {
        cout << "Unable to open file for reading!" << endl;
    }
}

~Array() {
    delete[] persons;
}
};
#endif
