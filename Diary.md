# The development steps 

## Data management
### Defining datatypes 
We have to use data types as structs for the creation of database.
First we can add a datatype for books. 

The ```Book``` datatype must contain these datas.
- Title ( A maximum 100 charecter array ) 
- Author ( A maximum 30 charecter array )
- ISBN number ( A size 13 charcter array )
- Quantity ( A long integer )

The ```User``` datatype must contain these datas.

- Name ( A maximum 30 charecter array )
- User ID ( A long integer )
- Email ID ( A maximum 100 charecter array )

### Implementing file handling
In this case it is best to use JSON ( JavaScript Object Notation ) to save our data. JSON is ASCII Based so that it can be easily managed by strings and builtin functions inside C.

