#include <cs50.h>
#include <stdio.h>
#include <ctype.h>
#include <string.h>

int main(int argc, string argv[])
{
    int key = 0;
    if (argc >= 0)
    {
        // Get word to cipher from user
        string s = get_string();
        printf("%s shifted by %s...\n", s, argv[1]);

        key = atoi(argv[1]);

        // Loop through word
        for (int i = 0, n = strlen(s); i < n; i++)
        {
            // uppercase chars
            if (s[i] >= 'A' && s[i] <= 'Z' )
            {
                if (s[i] + key > 90)
                {
                    printf("%c", (s[i] + key) - 91 + 65);
                }
                else
                {
                    printf("%c", s[i] + key);
                }
            }
            // lowercase chars
            else if (s[i] >= 'a' && s[i] <= 'z' )
            {
                 if (s[i] + key > 122)
                {
                    printf("%c", (s[i] + key) - 123 + 97);
                }
                else
                {
                    printf("%c", s[i] + key);
                }
            }
            else
            {
                // for spaces/non alpha chars
                printf("%c", s[i]);
            }
        }
    }
    printf("\n");
}