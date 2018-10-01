# C-Interpreter
An interpreter for C language

Reference -->  C, fourth edition by Herbert Schildt.








Interprets the following features of C:-



•Parameterized functions with local variables.

•Recursion.

•The if statement.

•The do-while, while, and for loops.

•Local and global variables of type int and char.

•Function parameters of type int and char.

•Integer and character constants.

•String constants (limited implementation).

•The return statement, both with and without a value.

•A limited number of standard library functions.

•These operators: +, –, *, /, %, <, >, <=, >=, ==, !=, unary –, and unary + •Functions returning integers.
•/* . . . */-style comments.







Constraints:-



•The code blocks of if, while, do, and for must surrounded by beginning and ending curly braces.Single statement can't be used.

•Prototypes are not supported. All functions are assumed to return an integer type (char return types are allowed, but elevated to int).

•No parameter type checking is performed.

•All local variables must be declared at the start of a function, immediately after the opening brace.






Steps to execute:

The entire code has been contained in three files namely LITTLE_C.c, PARSER.C and LCLIB.c.They need to be linked and then executed.This step depends on the compiler that we are using.A small google search is suffient to know the steps.

Reference :- https://www.cs.utah.edu/~zachary/isp/tutorials/separate/separate.html
