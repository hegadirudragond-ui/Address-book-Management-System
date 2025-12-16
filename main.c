/*
 Project Name         : Address Book Using C Programming.
 Project Description  : A terminal based application to create, 
                        search, edit, delete, list(with sort and with out sort),
                        and save contacts & load contacts.(using .csv file)
-------------------------------------------------------------------------------------
 File Name        : main.c
 File Description : It's like an Entry point for the Address Book,
                    Provides a menu options like to create,search, 
                    edit, delete, list, and save contacts.
 Name             : Rudragond Hegadi
 Date             : 06-09-2025
 -------------------------------------------------------------------------------------
 */

#include <stdio.h>
#include "contact.h"

int main()
{
    int choice;
    AddressBook addressBook;
    initialize(&addressBook); // Initialize the address book

    do
    {
        printf("\n╔══════════════════════════════════╗\n");
        printf("║         Address Book Menu        ║\n");
        printf("╠══════════════════════════════════╣\n");
        printf("║ 1. Create Contact                ║\n");
        printf("║ 2. Search Contact                ║\n");
        printf("║ 3. Edit Contact                  ║\n");
        printf("║ 4. Delete Contact                ║\n");
        printf("║ 5. List All Contacts             ║\n");
        printf("║ 6. Save Contacts                 ║\n");
        printf("║ 7. Exit                          ║\n");
        printf("╚══════════════════════════════════╝\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice)
        {
        case 1:
            createContact(&addressBook);
            break;
        case 2:
            searchContact(&addressBook);
            break;
        case 3:
            editContact(&addressBook);
            break;
        case 4:
            deleteContact(&addressBook);
            break;
        case 5:
            listContacts(&addressBook);
            break;
        case 6:
            printf("Saving...\n");
            saveContactsToFile(&addressBook);
            break;
        case 7:
            break;
        default:
            printf("Invalid choice. Please try again.\n");
        }
    } while (choice != 7);

    return 0;
}
