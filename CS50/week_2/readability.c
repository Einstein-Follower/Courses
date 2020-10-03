// Run in terminal - gcc readability.c -lcs50 -lm -o readability
// ./readability
#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include <cs50.h>
#include <stdlib.h>
#include <math.h>

int count_letter(string text);
int count_word(string text);
int count_sentence(string text);
int main()
{
    int grade;
    float L, S;

    string text = get_string("Text: ");
    printf("Letters : %d\n", count_letter(text));
    printf("Words : %d\n", count_word(text));
    printf("Sentences : %d\n", count_sentence(text));

    L = ((float)count_letter(text) / count_word(text)) * 100.0;   //calculating number of letters per 100 words
    S = ((float)count_sentence(text) / count_word(text)) * 100.0; // calculating number of sentences per 100 words

    printf("Grade without rounding : %f\n", (float)((0.0588 * L) - (0.296 * S) - 15.8));
    grade = round((float)((0.0588 * L) - (0.296 * S) - 15.8)); // calculating grade here
    if (grade < 1)
    {
        printf("Before Grade 1\n");
    }
    else if (grade >= 16)
    {
        printf("Grade 16+\n");
    }
    else
    {
        printf("Grade %d\n", (int)grade);
    }

    return 0;
}

int count_letter(string text)
{
    //returns number of letters in a given string
    int count = 0;
    for (int i = 0; i < strlen(text); i++)
    {
        if (isalpha(text[i]))
        {
            count++;
        }
    }
    return count;
}

int count_word(string text)
{
    // returns number of words in a given string
    int count = 0;
    if (strlen(text) > 0)
    {
        if (isalpha(text[0]))
            count = 1;

        for (int i = 0; i < strlen(text) - 1; i++)
        {
            if (text[i] == ' ' && text[i + 1] != ' ')
            {
                count += 1;
            }
        }
    }
    return count;
}

int count_sentence(string text)
{
    // returns number of sentences in a given string
    int count = 0;
    for (int i = 0; i < strlen(text); i++)
    {
        if (text[i] == '.' || text[i] == '!' || text[i] == '?')
        {
            count += 1;
        }
    }
    return count;
}