/*
---------------------------------------------------------------------------------------------------
 File Name        : file.h
 File Description : Header file for the file operations in the Address Book. 
                    It Provides function declarations to save and load contacts.(in CSV format)
 Name             : Rudragond Hegadi
 Date             : 15-09-2025
 --------------------------------------------------------------------------------------------------
 */

#ifndef FILE_H
#define FILE_H

#include "contact.h"

void saveContactsToFile(AddressBook *addressBook);
void loadContactsFromFile(AddressBook *addressBook);

#endif
