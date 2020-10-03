#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <stdbool.h>

bool checkDigit(char *);
int getIndex(char *, char);
int main(int argc, char *argv[])
{
    char *value;
    value = argv[1];

    if (argc == 2 && checkDigit(value))
    {
        int key;
        int ci, pi, i, j = 0;
        key = atoi(value);
        char alphabets[] = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
        char plain_text[50];
        char cipher_text[50];
        printf("plaintext: ");
        scanf("%[^\n]%*c", plain_text);

        for (i = 0; i < strlen(plain_text); i++)
        {
            if (isalpha(plain_text[i]))
            {
                pi = getIndex(alphabets, plain_text[i]);

                if (pi > 25)
                {
                    ci = ((pi - 26) + key) % 26;
                    cipher_text[j] = alphabets[ci];
                    j++;
                }
                else if (pi <= 25)
                {
                    ci = (pi + key) % 26;
                    cipher_text[j] = tolower(alphabets[ci]);
                    j++;
                }
            }
            else
            {
                cipher_text[j] = plain_text[i];
                j++;
            }
        }
        cipher_text[j] = '\0';

        printf("ciphertext: %s\n", cipher_text);
    }
    else
    {
        printf("Usage: ./caesar key\n");
        return 1;
    }
}
bool checkDigit(char *value)
{
    for (int i = 0; i < strlen(value); i++)
    {
        if (!isdigit(value[i]))
            return false;
    }
    return true;
}
int getIndex(char *alphabets, char letter)
{
    int index = 0;
    for (int i = 0; i < strlen(alphabets); i++)
    {
        if (alphabets[i] == letter)
        {
            index = i + 26;
            return index;
        }
        else if (tolower(alphabets[i]) == letter)
        {
            index = i;
            return index;
        }
    }
}