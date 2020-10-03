#include <cs50.h>
#include <stdio.h>

int main(void)
{
    int height;
    do
    {
        height = get_int("Height: ");
    } while (height < 1 || height > 8); // validating height

    // printing mario here
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j <= (height + 2 + i); j++)
        {
            if (j >= height + 2)
            {
                printf("#");
            }

            else if (j >= height - (i + 1) && j < height)
            {
                printf("#");
            }

            else
            {
                printf(" ");
            }
        }
        printf("\n");
    }
    return 0;
}