# The development steps 

## Creating makefile
Make is an awesome tool that will automate the building process by only compiling the files whic have the change. Here we can set a command in this case ```gcc file.c -o out.o```. So the makescript will be:
```makefile
CC = gcc

bookpenguin:test.c filehandling.c
	$(CC) &? -o $@.run
```

to clear the build outputs we can define a process:
```makefile
clean:
	rm *.run
```

## Data management
### Defining datatypes 
We have to use data types as structs for the creation of database.
First we can add a datatype for books. 

The ```Book``` datatype must contain these datas.
- BookID ( A long integer )
- Title ( A maximum 100 charecter array ) 
- Author ( A maximum 30 charecter array )
- ISBN number ( A size 13 charcter array )
- Quantity ( A long integer )

The ```User``` datatype must contain these datas.

- Name ( A maximum 30 charecter array )
- User ID ( A long integer )
- Email ID ( A maximum 100 charecter array )

### Implementing file handling
In this case it is best to use CSV ( Coma Seperated Values ) to save our data. CSV is ASCII Based so that it can be easily managed by strings and builtin functions inside C.

#### addBook and addUser
The add user will take a single ```Book``` or ```User``` struct and then add them into a csv file.
```c
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
```
#### setupFile
The ```setupFile``` function will set a fresh file if there is no file exists. And also it addes the headings for csv file.
```c
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
``` 
