/*
---------------------------------------------------------------------------------------------------------------------------
 File Name        : contact.c
 File Description : It consists of functions with main operations in the Address Book like create,Edit,Delete Contact etc. 
                    It Provides function definitions and logic's for the operations menu's as mentioned in main.c.
 Name             : Rudragond Hegadi
 Date             : 08-09-2025
 --------------------------------------------------------------------------------------------------------------------------
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "contact.h"
#include "file.h"
#include <ctype.h>


void listContacts(AddressBook *addressBook)
{
    if(addressBook->contactCount==0)                                                     //if contact count is equals to 0 
    {
        printf("Contact Not Found\n");                                                    //contact not found
    }
    
    for(int i=0; i < addressBook->contactCount; i++)                                       //run the loop until it reaches contactcount 
    {
        printf("Index  : %d\n",i);                                                        //index of the contact
        printf("Name   : %s\n",addressBook->contacts[i].name);                             //printf the name into display or terminal
        printf("Phone  : %s\n",addressBook->contacts[i].phone);
        printf("Email  : %s\n",addressBook->contacts[i].email);
        printf("-----------------------------------------------\n");

    }
    // Sort contacts based on the chosen criteria
}


void initialize(AddressBook *addressBook)
{
    addressBook->contactCount = 0;
  // Load contacts from file during initialization (After files)
    loadContactsFromFile(addressBook);
}

void saveAndExit(AddressBook *addressBook)
{
    saveContactsToFile(addressBook);          // Save contacts to file
    exit(EXIT_SUCCESS);                        // Exit the program
}

void createContact(AddressBook *addressBook)
{
        char name[50];
        char phone[20];
        char email[50];
        char ch;
        int valid=0,i,count=0,ret;
        //name entering
        do
        {
        printf("Enter your name : ");
        scanf(" %[^\n]", name);

        valid=validate_Name(name);                                     //function call for valid name
        ret = unique_Name(name,addressBook);                           //function call for check unique name and not necessary

        if(valid==0)
         printf("Enter Valid name\n");
        if(ret==0)
        {
         printf("Name already Exists.Do you want to proceed with this (y/n)\n");
         scanf(" %c",&ch);
         if(ch=='n'||ch=='N')                                                //if proceed with same name or not
         {
            ret=0;
         }
         else
         {
            ret=1;
         }
        }
        }while(valid==0||ret==0);

        //entering phone number
        do
        {
            printf("Enter phone number : ");
            scanf("%s",phone);
            valid=validate_phone(phone);                             //function call for valid number
            ret=unique_phone(phone,addressBook);                     //function call for check unique number
                                  
            if(valid==0)
            {
                printf("Enter valid phone number\n");
            }

            if(ret==0) 
            {
                printf("phone number already exists. enter valid phone number\n");
            }
           
        }while(valid==0 || ret==0); 

     //create email id
        do
        {
            printf("Enter your email ID : ");
            scanf("%s",email);

            valid = validate_email(email);                               //function call  for check valid email
            ret=unique_email(email,addressBook);                        //function call  for check unique email
                                                                                      
            if(valid==0)
            {
                printf("Enter valid email ID\n");
            }

            if(ret==0)
            {
                printf("Email already exists. enter valid email\n");
            }
        }
        while(valid==0 || ret==0);

        strcpy(addressBook->contacts[addressBook->contactCount].name,name);                        //copying the name to display
        strcpy(addressBook->contacts[addressBook->contactCount].phone,phone);                       //copying the phone number to display
        strcpy(addressBook->contacts[addressBook->contactCount].email,email);                       //copying the email to display
        addressBook->contactCount++;                                                                //increase the contact count 
        printf("Contact Added Successfully\n");
}
    //search contact number
void searchContact(AddressBook *addressBook)
{
    /* Define the logic for search */
    char name[50];
    char phone[20];
    char email[50];
    int choice,valid;
    do
    {
        printf("\n╔══════════════════════════════════╗\n");
        printf("║        Search Contact Menu       ║\n");
        printf("╠══════════════════════════════════╣\n");
        printf("║ 1. Search By Name                ║\n");
        printf("║ 2. Search By Phone               ║\n");
        printf("║ 3. Search By Email               ║\n");
        printf("║ 4. Exit                          ║\n");
        printf("╚══════════════════════════════════╝\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

         switch (choice)                                                                          //using switch case
         {
            case 1:
            valid=search_Name(name,addressBook);
            break;

            case 2:
            valid=search_phone(phone,addressBook);
            break;

            case 3:
            valid=search_email(email,addressBook);
            break;

            case 4:
            return ;
            break;

            default:
            printf("Invalid choice. Please try again.\n");

         }
         
   }while(valid==0);
}

void editContact(AddressBook *addressBook)
{
    /* Define the logic for Editcontact */
    char name[50];
    char phone[20];
    char email[50];
    int choice,valid,index;

    if(addressBook->contactCount==0)                                                // if contactcount is 0 ,it will end
    {
        printf("No contacts available to edit\n");             
        return;
    }

    // while (getchar()!='\n');                                                          // clears input buffer until Enter (newline) is found

    // printf("Enter index to edit the contact (0-%d) : ",addressBook->contactCount);    //printf index number  from0 to contact
    // scanf("%d",&index);

    // if(index<0 || index>=addressBook->contactCount)                                   //if index < 0 or index >= contact count
    // {
    //     printf("Invalid index!");                                                      //invalid index
    //     return ;
    // }
    do
    {
        printf("\n╔══════════════════════════════════╗\n");
        printf("║        Edit Contact Menu         ║\n");
        printf("╠══════════════════════════════════╣\n");
        printf("║ 1. Edit Name                     ║\n");
        printf("║ 2. Edit Phone                    ║\n");
        printf("║ 3. Edit Email                    ║\n");
        printf("║ 4. Exit                          ║\n");
        printf("╚══════════════════════════════════╝\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

         switch (choice)
         {
            case 1:
                index=search_Name(name,addressBook);                              //first call the function to search contact using name

                if(index!=-1)
                {
                    valid=edit_Name(index,addressBook);                             //function call to edit name  using index of contact
                }
                else
                {
                    return;  
                }                                         
                break;

            case 2:
                index=search_phone(phone,addressBook);                               //first call the function to search contact using phone number
                if(index!=-1)
                {
                valid=edit_phone(index,addressBook);                               //function call for edit phone using index of contact
                }
                else
                {
                    return;     
                }                   
                break;

            case 3:
                index=search_email(email,addressBook);                              //first call the function to search contact using email                     
                if(index!=-1)
                {
                    valid=edit_email(index,addressBook);                                 //function call for edit mail ID using index of contact
                }
                else
                {
                    return;           
                }                           
                break;

            case 4:
            return ;
            break;

            default:
            printf("Invalid choice. Please try again.\n");

         }
         
   }while(valid==0);

}

void deleteContact(AddressBook *addressBook)
{
    /* Define the logic for deletecontact */
    
        char name[50];
        int index=search_Name(name,addressBook);                     //first call the function to search contact
        
        if(index==-1)                                                // indexs -1 it will write contact not found and end the program
        {
         return;
        }
        printf("Enter the index to delete contact : ");
        scanf("%d",&index);
        delete_contactby_index(index,addressBook);                   //call the function to delete the contact by index
}
//......own defined function...//


//create contact
int validate_Name(char *name)
{
    int len=strlen(name);                         //finding length of name string
    for (int i = 0; i < len; i++)
    {
     if(!isalpha(name[i]) && name[i]!=' ')         //name is having only alphabests and one space is allowed
      {
        return 0; 
      }
    }
    return 1;
}
//unique name 
int unique_Name(char *name, AddressBook *addressBook)
{
    int count=0,i;
    for(i=0; i<addressBook->contactCount;i++)
    {
        if(strcmp(name,addressBook->contacts[i].name)==0)                        //comparing the user entered  name and already saved number in list
        {
            count++;                                                            
        }
    }
    if(count==0)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}
// validate phone number
int validate_phone(char *phone)
{
     int len=strlen(phone);
            //validation
            if(len!=10)                            //number is 10 digits or not
            {
                return 0;
            }                                        
            for (int i = 0; i<len; i++)                //check number is only digits or not
            {
                if(!isdigit(phone[i]))                 //if string is not having digit characters 
                {
                    return 0;                          //printf("Enter only  digits\n");
                }   
            }
            return 1;
}
//unique phone number
int unique_phone(char *phone,AddressBook *addressbook)
{
    int count=0,i;
    for(i=0; i<addressbook->contactCount;i++)
    {
        if(strcmp(phone,addressbook->contacts[i].phone)==0)                 //comparing the user entered phone number and already saved number in list
        {
            count++;
        }
    }
    if(count==0)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}
//validate email id 
int validate_email(char *email)
{       
         int at_count=0,dot_count=0;
         int count=0; 

            int len=strlen(email);
            if(email[0]=='@' || email[0]=='.')                    //check 1st index is having " @ " and " . " character
            {
                return 0;
            }
            for (int i = 0; i<len; i++)                            // check email has Upper case or not
            {
                if(email[i]>='A' && email[i]<='Z' )                  
                {
                    return 0;                                               
                }
            }
            for (int i = 0; i<len; i++)                           //check email has consist @ character 
            { 
                if(email[i]=='@')
                {
                    at_count++;
                }
            }
            if(at_count!=1)                                       //if @ char count is more than 1 it will not valid 
            {
                return 0;
            }
        
            //. for (int i = 0; i<len; i++)
            for (int i = 0; i<len; i++)
            {
                if(email[i]=='.' && email[0]!='.')              //checking " ." character count
                {
                    dot_count++;
                }
            }
            if(dot_count>2)                                     // if "." is more than 2 it will not valid email
            {
                return 0;
            }

            int cmp = strcmp(&email[len-4],".com");             // at the last 4 character are ".com" or not 
            if(cmp!=0)
            {
                return 0;                                       //last 4  characters are not ".com" it is not a valid email
            }
            //check email has all characters
            for (int i = 0; i<len; i++)
            {
                if(email[i]=='@')                                //checking '@' is present or not 
                {
                    continue;
                }
                if(email[i]=='.')                                 //checking '.' is present or not
                {
                    continue;
                }
                if(!isalnum(email[i]))                             //checking mail is having alphanumeric characters or not
                {
                    return 0;
                }   
            }
            //check from @ to .com middle character are alphabets or not
            for(int i=0; email[i]!='@'; i++)
            {
                count++;
            }

            for(int i = count+1; i < len; i++)                            //now length starts from @ sign 
            {  
                if(email[i]=='.')                                      //if ". " character is found skip that and continue
                {
                    continue;
                }

                if(!isalpha(email[i]))                                 //'@' and '.' middle alphabetic characters are present or not
                {
                    return 0;      
                }
            }
            return 1;
}
//check unique mail
int unique_email(char *email,AddressBook *addressbook)
{
    int count=0,i;
    for(i=0; i<addressbook->contactCount;i++)
    {
        if(strcmp(email,addressbook->contacts[i].email)==0)
        {
            count++;
        }
    }
    if(count==0)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

//......own defined function...//

//search contact by name

int search_Name(char *name,AddressBook *addressBook)
{
    int a = 1;
    int found=0,valid;
    do
    {
            printf("Enter name: ");
            scanf(" %[^\n]",name);

            valid=validate_Name(name);                              //function call validate  the number
            if(valid==0)
            {
                printf("Enter Valid name\n");
            }
    }while(valid==0);

    for(int i=0; i<addressBook->contactCount;i++)
    {
        if(strcasecmp(name,addressBook->contacts[i].name)==0)                      //comparing name with created name if there printf found                  
        {
        
            printf("Contact Found\n");                                          //if contact found by name ,print all contact details 
            printf("index  = %d\n",i);
            printf("name   = %s\n",addressBook->contacts[i].name);
            printf("phone  = %s\n",addressBook->contacts[i].phone);
            printf("email  = %s\n",addressBook->contacts[i].email);
            a++;
            return i;
        }
    }
    //else
    {                                                                               //contact not found in created contact list
        printf("Contact not found\n");
        return -1;
    }
return a;
    
}
//search contact by name
int search_phone(char *phone,AddressBook *addressBook)
{
    int valid,found=0;
    do
    {
        printf("Enter phone number: ");
        scanf("%s",phone);
        valid=validate_phone(phone);                         //function call to validate  the phone number
        if(valid==0)
        {
            printf("Enter valid phone number\n");
        }
    }while(valid==0); 

    for(int i=0; i<addressBook -> contactCount;i++)
    {
        if(strcmp(phone,addressBook->contacts[i].phone)==0)      //if contact found by phone number ,print all contact details 
        {
            
            printf("Contact Found\n");                                        //print to display the contact after found 
            printf("Index  = %d\n",i);
            printf("name   = %s\n",addressBook->contacts[i].name);
            printf("phone  = %s\n",addressBook->contacts[i].phone);
            printf("email  = %s\n",addressBook->contacts[i].email);
           

             return i;
        }
    }

    {
        printf("Contact not found\n");
        return 0;
    }

}

//search contact by email ID
int search_email(char *email,AddressBook *addressBook)
{
    int valid ,found=0;
     do
        {
            printf("Enter your email ID : ");
            scanf("%s",email);
            valid = validate_email(email);                                          //function call search email                    
            if(valid==0)
            {
                printf("Enter valid email ID\n");
            }
        }
        while(valid==0);

     for(int i=0; i<addressBook -> contactCount;i++)
        {
            if(strcmp(email,addressBook->contacts[i].email)==0)             //if contact found by email id ,print all contact details 
            {
                printf("Contact Found\n");
                printf("Index = %d\n",i);
                printf("name  = %s\n",addressBook->contacts[i].name);
                printf("phone = %s\n",addressBook->contacts[i].phone);
                printf("email = %s\n",addressBook->contacts[i].email);

                return i;
            }
        }

        {
            printf("Contact not found\n");
            return 0;
        }

}
   //edit contact functions
   //edit contact by name
int edit_Name(int index,AddressBook *addressBook)
{
    char newName[50];                                                            //taking new name string
    int valid,ret;
    do
    {
        printf("Enter new name : ");                                             //read new name from user
        scanf(" %[^\n]",newName);          
 
        valid=validate_Name(newName);                                            //function call to check valid name
        ret = unique_Name(newName,addressBook);                                  //function call to check unique name
         
            if(valid==0)                                                          
            {
                printf("Enter Valid name\n");                                     //check valid name or not                          
            }

            if(ret==0)
            {
                printf("Name already exists\n");                                  //check unique name or not
            }
    } while (valid==0 || ret==0);
    
    strcpy(addressBook->contacts[index].name,newName);                             //copied edited name into display or list
    printf("name updated successfully\n");       
    return 1;
               
}

//edit contact by phone number
int edit_phone(int index,AddressBook *addressBook)
{
    char new_phone[20];
    int valid,ret;
    do
    {
        printf("Enter new phone number : ");                                       //take name from user
        scanf(" %[^\n]",new_phone);

        valid=validate_phone(new_phone);                                           //function call for check valid phone
        ret = unique_phone(new_phone,addressBook);                                 //function call for check u unique phone

            if(valid==0)                                                            //check valid phone number                               
            {
                printf("Enter Valid phone number\n");
            }
            if(ret==0)                                                               //check unique phone number
            {
                printf("phone number already exists\n");
            }
    } while (valid==0 || ret==0);
    
    strcpy(addressBook->contacts[index].phone,new_phone);                           //copied the edited name into display or list
    printf("phone number updated successfully\n");
    return 1;
               
}

//edit contact by email id 
int edit_email(int index,AddressBook *addressBook)
{
    char new_email[50];
    int valid,ret;
    do
    {
        printf("Enter new email Id : ");                                        //take name from user
        scanf(" %[^\n]",new_email);

        valid=validate_email(new_email);                                        //function call for check valid email
        ret = unique_email(new_email,addressBook);                              //function call for check unique email

        if(valid==0)                                                            //check valid email
        {
            printf("Enter valid email Id\n");
            
        }  
        if(ret==0)                                                              //check unique email
        {
            printf("Email ID already exists\n");
        }                 
    } while (valid==0 || ret==0);

    strcpy(addressBook->contacts[index].email,new_email);                       //copy the updated email into display or list
    printf("Email ID updated successfully\n");
    return 1;

}

//own defined function to delete contact
int delete_contactby_index(int index,AddressBook *addressBook)
{
    if(index<0 || index>=addressBook->contactCount)                                   //if index is lessthan 0 or index ig greaterthan contact count
    {
            printf("Invalid Index\n");
            return -1;                                                                       //it will end of program
    }

    for(int i=index; i<addressBook->contactCount-1;i++)                               //loop starts from index to contact count
    {
            addressBook->contacts[i]=  addressBook->contacts[i+1];                       //swap the contacts 
    }

        addressBook->contactCount-- ;                                                    //reduce contact count,deleted the contact successfully                                               
        printf("Contact Deleted Successfully\n");
        return 1;
}


    





