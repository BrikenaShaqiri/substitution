#include <cs50.h>
#include <ctype.h>
#include <stdio.h>
#include <string.h>

int main(int argc, string argv[])
{
    if (argc != 2)
    {
        printf("Usage: ./substitution key\n");
        return 1;
    }

    string key = argv[1];

    if (strlen(key) != 26)
    {
        printf("Key must contain 26 characters.\n");
        return 1;
    }

    for (int i = 0; i < strlen(key); i++)
    {
        if (!isalpha(key[i]))
        {
            printf("Key must only contain alphabetic characters.\n");
            return 1;
        }
        if (islower(key[i]))
        {
            key[i] = toupper(key[i]); // Convert the key character to uppercase
        }
    }

    string plaintext = get_string("Plaintext: ");

    printf("Ciphertext: ");

    for (int i = 0; i < strlen(plaintext); i++)
    {
        if (isalpha(plaintext[i]))
        {
            int letter = isupper(plaintext[i]) ? plaintext[i] - 'A' : plaintext[i] - 'a';
            if (isupper(plaintext[i]))
            {
                printf("%c", key[letter]);
            }
            else
            {
                printf("%c", tolower(key[letter]));
            }
        }
        else
        {
            printf("%c", plaintext[i]);
        }
    }
    printf("\n");
}
