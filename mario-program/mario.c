// This is my mario block program for CS50. Enjoy! //
#include <cs50.h>
#include <stdio.h>

int main(void)
{
    int blockheight = 0;
    int prompt = 0;
/* Loop prompt until satisfied */
    do
    {
        if (prompt != 0)
        {
            printf("Please enter an integer from 1 to 8.\n");
        }
        else {}
            blockheight = get_int("Height?: ");
            prompt++;
    }
    while( 0 >= blockheight || blockheight > 8 );
/* Print blocks */
    for (int i = 1; i <= blockheight; i++)
    {
        for (int space = blockheight - i; space > 0; space--)
        {
            printf(" ");
        }
            for (int lhash = 0; lhash < i; lhash++)
            {
                printf("#");
            }
            printf("  ");
            for (int rhash = 0; rhash < i; rhash++)
            {
                printf("#");
            }
        printf("\n");
    }
}