#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define SIZE 1000
typedef struct
{
    char street[50];
    char flat[40];
    char city[40];
} address;
typedef struct
{
    char firstname[50];
    char lastname[50];
    address adrs;
    char phonenumber[20];
    char email[40];
} phonebook;
phonebook contacts[SIZE];
int noOfContacts;
void LOAD();
void QUERY(phonebook *contacts);
void ADD(phonebook *contacts);
void MODIFY(phonebook *contacts);
void DELETE(phonebook *contacts);
void PRINT(phonebook *contacts);
void SAVE(phonebook *contacts);
int QUIT();
int main()
{
    int option;

    do
    {
        printf("choose an option\n");
        printf("1:LOAD\n2:QUERY\n3:ADD\n4:MODIFY\n5:DELETE\n6:PRINT\n7:SAVE\n8:QUIT\n");
        scanf("%d",&option);
        switch(option)
        {
        case 1:
            LOAD();
            break;
        case 2:
            QUERY(contacts);
            break;
        case 3:
            ADD(contacts);
            break;
        case 4:
            MODIFY(contacts);
            break;
        case 5:
            DELETE(contacts);
            break;
        case 6:
            PRINT(contacts);
            break;
        case 7:
            SAVE(contacts);
            break;
        case 8:
            QUIT();
            break;
        }
    }while(option==1||option==2||option==3||option==4||option==5||option==6||option==7||option==8);
    return 0;
}
void LOAD()
{
    FILE *f;
    char filename[20];
    int i=0;
    printf("Enter the file name:");
   scanf("%s",filename);
    f=fopen(filename,"r");
    if(f!=NULL)
    {
        while(!feof(f))
        {
            fscanf(f,"%[^,],%[^,],%[^,],%[^,],%[^,],%[^,],%s\n",contacts[i].firstname,contacts[i].lastname,contacts[i].adrs.street,contacts[i].adrs.flat,contacts[i].adrs.city,contacts[i].phonenumber,contacts[i].email);
            noOfContacts++;
            i++;
        }
    }
    else
        printf("error file not found\n");
}
void QUERY(phonebook *contacts)
{
    char firstname[30];
    int i,found=0,j=0,counter;
    phonebook searchbyfirstname[100];
    printf("Please enter the first name: ");
    scanf("%s",firstname);
  for(i=0;i<noOfContacts;i++)
    {
        if(strcmp(firstname,contacts[i].firstname)==0)
        {
            searchbyfirstname[j]=contacts[i];
            j++;
            found=1;
            counter=j;
        }
    }
    if(found==0)
        printf("contact not found\n");
        else
            for(i=0;i<counter;i++)
            printf("%s\t%s\t%s\t%s\t%s\t%s\n",searchbyfirstname[i].firstname,searchbyfirstname[i].lastname,searchbyfirstname[i].adrs.street,searchbyfirstname[i].adrs.flat,searchbyfirstname[i].adrs.city,contacts[i].phonenumber);
}
void ADD(phonebook *contacts)
{
    if(noOfContacts==SIZE)
        printf("Memory full can't add more contacts\n");
    printf("Enter the first name:");
    getchar();
    gets(contacts[noOfContacts+1].firstname);
    printf("Enter the last name:");
     getchar();
    gets(contacts[noOfContacts+1].lastname);
    printf("Enter the address\n");
    printf("street:");
     getchar();
    gets(contacts[noOfContacts+1].adrs.street);
    printf("flat:");
     getchar();
    gets(contacts[noOfContacts+1].adrs.flat);
    printf("city:");
     getchar();
    gets(contacts[noOfContacts].adrs.city);
    printf("Enter the phone number :");
     getchar();
    gets(contacts[noOfContacts+1].phonenumber);
    printf("Enter the E_mail:");
     getchar();
    gets(contacts[noOfContacts+1].email);
    printf("contact is added\n");
    noOfContacts++;
        }
void MODIFY(phonebook *contacts)
{
    char firstname[20],ch[50];
    phonebook searchbyfirstname[100],temp;
    int i,j=0,counter=0,number,n=0,found=0;
    printf("Enter the first name:");
    scanf("%s",firstname);
    for(i=0;i<noOfContacts;i++)
    {
        if(strcmp(firstname,contacts[i].firstname)==0)
        {
            searchbyfirstname[j]=contacts[i];
            j++;
            found=1;
            counter++;
        }
    }
    if(found==0)
    {
        printf("contact not found\n");
        return;
    }
    for(i=0;i<counter;i++)
        printf("%d-%s\t%s\t%s\t%s\t%s\t%s\n",i+1,searchbyfirstname[i].firstname,searchbyfirstname[i].lastname,searchbyfirstname[i].adrs.street,searchbyfirstname[i].adrs.flat,searchbyfirstname[i].adrs.city,searchbyfirstname[i].phonenumber);
        printf("choose the  number of the contact you want to modify\n");
    scanf("%d",&number);
    while(number>counter)
    {
        printf("Incorrect numder\nEnter the correct number:");
        scanf("%d",&number);
    }
   while(n<counter)
   {
        if(number==n+1)
        {
            printf("Enter the new data you want to modify\n");
            printf("Enter the first name:");
            gets(contacts[n].firstname);
            printf("Enter the last name:");
            if(gets(contacts[n].lastname)=='\n')
                continue;
            printf("Enter the address\n");
            printf("street:");
            if(gets(contacts[n].adrs.street)=='\n')
                continue;
            printf("flat:");
            if(gets(contacts[n].adrs.flat)=='\n')
                continue;
            printf("city:");
            if(gets(contacts[n].adrs.city)=='\n')
                continue;
            printf("Enter the phone number:");
            if(gets(contacts[n].phonenumber)=='\n')
                continue;
            printf("Enter the E-mail:");
            if(gets(contacts[n].email)=='\n')
                continue;
                 printf("contact is modified\n");
                break;
        }
        else
            n++;
   }
   if(found==0)
   {
       printf("Incorrect number\n");
       return;
   }
}
void DELETE(phonebook *contacts)
{
    char firstname[20];
    phonebook searchbyfirstname[100];
    int i,j=0,found=0,n=0,number,counter=0;
    printf("Enter the contact's first name:");
    scanf("%s",firstname);
    for(i=0;i<noOfContacts;i++)
    {
        if(strcmp(firstname,contacts[i].firstname)==0)
        {
            searchbyfirstname[j]=contacts[i];
            j++;
            found=1;
            counter++;
        }
    }
        if(found==0)
        {
            printf("contact not found\n");
            return;
        }
         for(i=0;i<counter;i++)
        printf("%d-%s\t%s\t%s\t%s\t%s\t%s\n",i+1,searchbyfirstname[i].firstname,searchbyfirstname[i].lastname,searchbyfirstname[i].adrs.street,searchbyfirstname[i].adrs.flat,searchbyfirstname[i].adrs.city,searchbyfirstname[i].phonenumber);
        printf("choose the  number of the contact you want to modify\n");
    scanf("%d",&number);
        while(n<counter)
        {
            if(number==n+1)
                {
                    found=1;
                    break;
                }
                else
                    n++;
        }
        if(found==0)
        printf("contact not found\n");
        if(found==1)
        {
            printf("contact is deleted\n");
        for(i=0;i<noOfContacts;i++)
        {
               for(j=i;j<noOfContacts;j++)
               {
                   contacts[j]=contacts[j+1];
               }
               {
                  strcpy(contacts[j].firstname,"");
                strcpy(contacts[j].lastname,"");
                strcpy(contacts[j].adrs.street,"");
                strcpy(contacts[j].adrs.flat,"");
                strcpy(contacts[j].adrs.city,"");
                strcpy(contacts[j].phonenumber,"");
                strcpy(contacts[j].email,"");
               }
            noOfContacts--;
            }
        }
}
void PRINT(phonebook *contacts)
{
    int i,pass;
    phonebook temp;
    for(pass=0;pass<noOfContacts;pass++)
    {
        for(i=0;i<noOfContacts-1;i++)
        {
            if(strcmp(contacts[i].firstname,contacts[i+1].firstname)>0)
            {
                temp =contacts[i];
                contacts[i] =contacts[i+1];
                contacts[i+1] =temp;
            }
            else if(strcmp(contacts[i].firstname,contacts[i+1].firstname)==0)
            {
                if(strcmp(contacts[i].lastname,contacts[i+1].lastname)>0)
                {
                    temp = contacts[i];
                    contacts[i] = contacts[i+1];
                    contacts[i+1] = temp;
                }
            }
        }
    }
        for(i=0;i<noOfContacts;i++)
        printf("%s\t%s\t%s\t%s\t%s\t%s\t%s\n",contacts[i].firstname,contacts[i].lastname,contacts[i].adrs.street,contacts[i].adrs.flat,contacts[i].adrs.city,contacts[i].phonenumber,contacts[i].email);
}
void SAVE(phonebook *contacts)
{
   char filename[20],ch;
    int i;
    FILE *f;
    printf("Enter the new file name:");
    scanf("%s",filename);
    f=fopen(filename,"w");
    if(f==NULL)
    {
        printf("error\n");
        exit(1);
    }
    for(i=0;i<noOfContacts;i++)
    {
        fprintf(f,"%s,",contacts[i].firstname);
        fprintf(f,"%s,",contacts[i].lastname);
        fprintf(f,"%s,",contacts[i].adrs.street);
        fprintf(f,"%s,",contacts[i].adrs.flat);
        fprintf(f,"%s,",contacts[i].adrs.city);
        fprintf(f,"%s,",contacts[i].phonenumber);
        fprintf(f,"%s,",contacts[i].email);
        fprintf(f,"\n");
    }
    fclose(f);
    printf("contacts are saved at %s\n",filename);
}
int QUIT()
{
    char choice;
    do
    {
    printf("Do you want to save changes?\n'y'for save\n'n'for don't save\n'c'for cancel\n");
    scanf(" %c",&choice);
    if(choice== 'y')
    {
        SAVE(contacts);
        exit(1);
    }
    else if(choice=='n')
        exit(1);
        else if(choice=='c')
        return 1;
        else
            printf("Enter the correct letter\n");

    }while(choice!='y'||choice!='n'||choice!='c');
return 0;
}

