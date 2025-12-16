/*
----------------------------------------------------------------------------------------------------------------
 File Name        : contact.h
 File Description : Header file for the main operations in the Address Book (create,Edit,Delete Contact etc..). 
                    It Provides function declarations for the operations menu's as mentioned in main.c,
                    It also consists of the structures of size to store the 100 contacts.
 Name             : Rudragond Hegadi
 Date             : 08-09-2025
 ---------------------------------------------------------------------------------------------------------------
 */

#ifndef CONTACT_H
#define CONTACT_H

#define MAX_CONTACTS 100

typedef struct
{
    char name[50];
    char phone[20];
    char email[50];
} Contact;

typedef struct
{
    int contactCount;
    Contact contacts[100];
} AddressBook;

void createContact(AddressBook *addressBook);
void searchContact(AddressBook *addressBook);
void editContact(AddressBook *addressBook);
void deleteContact(AddressBook *addressBook);
void listContacts(AddressBook *addressBook);
void initialize(AddressBook *addressBook);
void saveContactsToFile(AddressBook *addressBook);



//create contact own defined functions
int validate_Name(char *name);                                    //Returns 1 if valid
int validate_phone(char *phone);                                  
int validate_email(char *email);

int unique_Name(char *name,AddressBook *addressbook);            //check unique name functions
int unique_phone(char *phone,AddressBook *addressbook); 
int unique_email(char *email,AddressBook *addressbook);

//search contact own defined functions 

int search_Name(char *name,AddressBook *addressBook);
int search_phone(char *phone,AddressBook *addressBook);
int search_email(char *email,AddressBook *addressBook);

//edit contact own defined functions

int edit_Name(int index,AddressBook *addressBook);
int edit_phone(int index,AddressBook *addressBook);
int edit_email(int index,AddressBook *addressBook);

//delete contact own defined functions

int delete_contactby_index(int index,AddressBook *addressBook);


#endif
