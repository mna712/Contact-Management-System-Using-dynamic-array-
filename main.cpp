
#include "person.h"
#include "Address.h"
#include "Array.h"
#include <iostream>
#include <string>
using namespace std;

int main() {
    Array<person> contactBook;
    int choice;
    string First_name, Last_name, classification;
    size_t id;

    while (true) {
        cout << "\t\t\t\t\t\t_________________________________" << endl;
        cout << "\t\t\t\t\t\t     Your Contacts" << endl;
        cout << "\t\t\t\t\t\t_________________________________" << endl;

        cout << "\t\t\t\t\t\t1. Add Contact\n"
             << "\t\t\t\t\t\t2. Remove Contact\n"
             << "\t\t\t\t\t\t3. Search Contact By first name\n"
             << "\t\t\t\t\t\t4. Display All Contacts\n"
             << "\t\t\t\t\t\t5. Display Favorite Contacts\n"
             << "\t\t\t\t\t\t6. Search Contact By last name\n"
             << "\t\t\t\t\t\t7. Search Contact By classification\n"
             << "\t\t\t\t\t\t8. Update contact's details\n"
             << "\t\t\t\t\t\t9. Reverse contact book\n"
             << "\t\t\t\t\t\t10. Save Contacts to File\n"
             << "\t\t\t\t\t\t11. Load Contacts from File\n"
             << "\t\t\t\t\t\t12. Exit\n"
             << "\t\t\t\t\t\t___________________________________";
        cout << endl;
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1: {
                // Add contact logic
                cout << "Enter ID: ";
                cin >> id;
                cout << "Enter First Name: ";
                cin >> First_name;
                cout << "Enter Last Name: ";
                cin >> Last_name;
                cout << "Enter Classification: ";
                cin >> classification;
                cout << "Enter Email: ";
                string Email;
                cin >> Email;
                cout << "Enter Phone: ";
                string phone;
                cin >> phone;
                cout << "Enter Address (Street Number, Street, City, Country): ";
                int streetNum;
                string street, city, country;
                cin >> streetNum >> street >> city >> country;
                 bool favorite=false;
                 cout << "Is this contact favorite to you (1 for yes, 0 for no): "; cin >> favorite;
                Address address(city, country, street, streetNum);
                person newPerson(id, First_name, Last_name, classification, Email, phone, address);
                contactBook.add(newPerson);
                break;

                 if (favorite) {
                newPerson.setFavorite(true);  // Assuming you add a setter for favorite
            }
            else
            {
                newPerson.setFavorite(false);
            }

            }
            case 2: {
                cout << "Enter First Name of the contact to remove: ";
                cin >> First_name;
                contactBook.remove(First_name);
                break;
            }
            case 3: {
                cout << "Enter First Name to search: ";
                cin >> First_name;
                contactBook.search(First_name);
                break;
            }
            case 4: {
                contactBook.displayAll();
                break;
            }
            case 5: {
                contactBook.displayFavorites();
                break;
            }
            case 6: {
                cout << "Enter Last Name to search: ";
                cin >> Last_name;
                contactBook.searchlast(Last_name);
                break;
            }
            case 7: {
                cout << "Enter Classification to search: ";
                cin >> classification;
                contactBook.searchByClassification(classification);
                break;
            }
            case 8: {
                cout << "Enter ID of the contact to update: ";
                cin >> id;
                contactBook.updatecontact(id);
                break;
            }
            case 9: {
                contactBook.Reverse();
                break;
            }
            case 10: {
                contactBook.saveToFile("contacts.txt");
                break;
            }
            case 11: {
                contactBook.readFromFile("contacts.txt");
                break;
            }
            case 12: {
                cout << "Exiting..." << endl;
                return 0;
            }
            default: {
                cout << "Invalid choice! Please try again." << endl;
                break;
            }
        }
        cout << ".............................................................................................................................................." << endl;
        cout << endl;
    }


}
