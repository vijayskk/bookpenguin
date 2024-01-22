#include <stdio.h>
#include "datatypes.h"

int addBook(struct Book * b);
int addUser(struct User * u);
void setupFile(void);

int main(int argc, char const *argv[])
{
    setupFile();
    struct Book b1 = {
        .bookid = 1,
        .title = "The Art of War",
        .author = "Sun Tzu",
        .ISBN = "1234567890123",
        .quantity = 10000
    };
    int status;
    status = addBook(&b1);
    printf("%d",status);

    struct User u1 = {
        .username = "Vijay Satheesh",
        .email = "vijayskk007@gmail.com",
        .userid = 1
    };
    status = addUser(&u1);
    printf("%d",status);
    return 0;
    setupFile();
}
