# PWGenerator

This project is a simple random password generator, created in C++. With this program, you can create an 8-24 character password that contains the following characters:
* Capital and lowercase letters (A-Z, a-z)
* Numbers (0-9)
* Special characters (!, #, $, %, &, *, <, >, ?, @, ^, _)

There are special characters that are excluded from generation. These characters are `()-=+[]\;:'",./ and they may be included in generation in the future. If the random generator does generate an excluded character, it will reassign the character to be something else.

After the password is generated, it is then printed to the console. From the console, you can copy your generated password and use it where ever you like.
