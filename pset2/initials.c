/* Implement a program that, given a person’s name, prints a person’s initials, per the below.

$ ./initials
Regulus Arcturus Black
RAB

$ ./initials
robert thomas bowden
RTB

*/

// Take name as input
// Output first letter of each name

#include <cs50.h>
#include <stdio.h>
#include <ctype.h>
#include <string.h>

void get_first(string str);

int main(void)
{

    printf("Name: ");
    string s = get_string();
    printf("%s\n", s);
    get_first(s);
}

void get_first(string str)
{
    // print first letter and caps
    printf("%c", toupper(str[0]));
    for (int i = 0, n = strlen(str); i < n; i++)
    {
        // if counter gets to a space AND char after the space is NOT a space
        if (str[i] == ' ' && str[i+1] != ' ')
        {
            // print first letter of char after space
            printf("%c", toupper(str[i+1]) );
        }
    }
    printf("\n");
}