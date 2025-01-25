Contact Management System
This project is a Contact Management System implemented in C++. It allows users to manage their contacts efficiently by providing various functionalities such as adding, removing, updating, and searching contacts. The system also supports saving and loading contacts from a text file, making it easy to persist data between sessions.

Features
Add Contact: Add a new contact with details such as first name, last name, classification, email, phone number, and address.

Remove Contact: Remove a contact by specifying the first name.

Search Contact: Search for contacts by first name, last name, or classification.

Display All Contacts: View all contacts in the system.

Display Favorite Contacts: View only the contacts marked as favorites.

Update Contact: Update the details of an existing contact by specifying the contact's ID.

Reverse Contact List: Reverse the order of the contact list.

Save to File: Save all contacts to a text file (contacts.txt).

Load from File: Load contacts from a previously saved text file (contacts.txt).

Project Structure
The project is organized into the following files:

Address.h / Address.cpp: Contains the Address class, which manages the address details (street, city, country, etc.) of a contact.

person.h / person.cpp: Contains the person class, which represents a contact with attributes like name, email, phone, address, and favorite status.

Array.h / Array.cpp: Contains the Array template class, which manages a dynamic array of contacts and provides functionalities like adding, removing, searching, and updating contacts.

main.cpp: The main program that provides a menu-driven interface for interacting with the contact management system.

contacts.txt: A text file used to store and load contact data.

How to Use
Clone the repository to your local machine.

Compile the project using a C++ compiler (e.g., g++).

Run the executable to start the contact management system.

Use the menu options to add, remove, search, update, and manage your contacts.

Contacts can be saved to and loaded from the contacts.txt file.

Example Usage 
Add a Contact: Enter the contact's details (ID, first name, last name, classification, email, phone, and address).

Search for a Contact: Search by first name, last name, or classification.

Update a Contact: Update a contact's details by specifying their ID.

Save Contacts: Save all contacts to contacts.txt.

Load Contacts: Load contacts from contacts.txt.

Dependencies :
Standard C++ libraries (<iostream>, <string>, <fstream>, <iomanip>, etc.).

Future Enhancements :
Add support for multiple address formats.

Implement a graphical user interface (GUI) for better user interaction.

Add sorting functionality to sort contacts by name, classification, etc.

Support for exporting contacts to other formats (e.g., CSV, JSON).
