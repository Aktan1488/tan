!ATTENTION! This code was created for educational purposes


This code (contacts.c) uses functions from the standard C library.
The code is cross-platform, in my case the GCC 9.2.0 compiler is used.

How does it work? If you compile (say via gcc) with the command:
  gcc contacts.c -o contacts.exe
  /contacts.exe

Then a console application will start, with a choice in the menu (1, 2, 3, 0).
    With the ability to add a name and contact number (1);
    Display all contacts (including their numbers)(2);
    Search for a name or phone number via input(3)
       P.S. INPUT SEARCHES ONLY FOR THE FIRST LINE WITH A SIMILAR SUBSTRING;
    And you can exit this program(0)
