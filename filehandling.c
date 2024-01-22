#include <stdio.h>
#include "datatypes.h"

const char* BOOK_FORMAT_IN = "%d,%s,%s,%s,%d\n";
const char* USER_FORMAT_IN = "%s,%d,%s\n";

extern int addBook(struct Book * b){
    FILE * fp;
    fp = fopen("data/books.csv","a+");
    if (fp == NULL) 
    {
        return 1;
    }
    fprintf(fp,BOOK_FORMAT_IN,b->bookid,b->title,b->author,b->ISBN,b->quantity);
    fclose(fp);
    return 0;
}

extern int addUser(struct User * u){
    FILE * fp;
    fp = fopen("data/users.csv","a+");
    if (fp == NULL) 
    {
        return 1;
    }
    fprintf(fp,USER_FORMAT_IN,u->username,u->userid,u->email);
    fclose(fp);
    return 0;
}

void setupFile(void){
    FILE * sfbookp;
    FILE * sfuserp;
    sfbookp = fopen("data/books.csv","r");
    sfuserp = fopen("data/users.csv","r");
    if (sfbookp == NULL)
    {
        sfbookp = fopen("data/books.csv","w+");
        fprintf(sfbookp,"Book ID,Title,Author,ISBN,Quantity\n");
    }
    if (sfuserp == NULL)
    {
        sfuserp = fopen("data/users.csv","w+");
        fprintf(sfuserp,"Name,User ID,Email\n");
    }
    fclose(sfbookp);
    fclose(sfuserp);
}