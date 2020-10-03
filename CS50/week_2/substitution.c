#include <stdio.h>
#include <cs50.h>
#include <string.h>
#include <ctype.h>
#include <stdbool.h>

int check_key(string);
int get_index(char);
int main(int argc, string argv[])
{
    if (argc != 2)
    {
        printf("Usage: ./substitution key\n");
        return 1;
    }

    if (check_key(argv[1]) == 10)
    {
        printf("Key must contain 26 characters.\n");
        return 1;
    }
    else if (check_key(argv[1]) == 20)
    {
        printf("Key must only contain alphabetic characters.\n");
        return 1;
    }
    else if (check_key(argv[1]) == 30)
    {
        printf("Key must not contain repeated characters.\n");
        return 1;
    }

    string plain_text = get_string("plaintext: ");
    char cipher_text[strlen(plain_text)];
    string key = argv[1];

    for (int i = 0, n = strlen(plain_text); i < n; i++)
    {
        if (isalpha(plain_text[i]))
        {
            int index = get_index(plain_text[i]);
            if (isupper(plain_text[i]))
            {
                cipher_text[i] = toupper(key[index]); // putting uppercase letter in the cipher text
            }

            else
            {
                cipher_text[i] = tolower(key[index]); // putting lowercase letter in the cipher text
            }
        }
        else
        {
            cipher_text[i] = plain_text[i]; // putting the non-alphabetic character to the cipher text from the plain text
        }
    }
    cipher_text[strlen(plain_text)] = '\0'; // assigning the last character of the string to null
    printf("ciphertext: %s\n", cipher_text);
}
int check_key(string key)
{
    //returns 10 if key does not contain 26 characters
    //returns 20 if key contains any non-alphabetic characters
    //returns 30 if key contains any repeated characters
    int m = strlen(key);
    if (m != 26)
    {
        return 10;
    }
    else
    {
        for (int i = 0; i < m; i++)
        {
            for (int j = i + 1; j < m; j++)
            {
                if (key[i] == key[j])
                {
                    return 30;
                }
            }
        }

        for (int i = 0; i < m; i++)
        {
            if (!isalpha(key[i]))
            {
                return 20;
            }
        }
    }
}

int get_index(char letter)
{
    //returns the index of the given character in the text string
    string text = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
    for (int i = 0, n = strlen(text); i < n; i++)
    {
        if (text[i] == letter || tolower(text[i]) == letter)
        {
            return i;
        }
    }
}