/* Welcome to my credit card validator! */

#include <cs50.h>
#include <stdio.h>

int firsttwo (long digits);
int check (long digits);
int counter (long digits);

    int main(void)
    {
        /* Prompt for positive integer */
    
        long cardnum;
    
            do
            {
                cardnum = get_long("Credit/Debit:");
            }
            while (cardnum <= 0);
    
        /* Validate, check issuer */
    
        if ((check(cardnum) % 10) == 0)
        {
            /* Visa */
            if (((counter(cardnum) == 16)||(counter(cardnum) == 13)) && ((firsttwo(cardnum) / 10) == 4))
            {
                printf("VISA\n");
            }
            /* Mastercard */
            else if ((counter(cardnum) == 16) && ((firsttwo(cardnum) == 51) || (firsttwo(cardnum) == 52) || ( firsttwo(cardnum) == 53) || (firsttwo(cardnum) == 54) || (firsttwo(cardnum) == 55)))
            {
                printf("MASTERCARD\n");
            }
            /* AMEX */
            else if((counter(cardnum) == 15) && ((firsttwo(cardnum) == 34) || (firsttwo(cardnum) == 37)))
            {
                printf("AMEX\n");
            }
            else
            {
                printf("INVALID\n");
            }
        }
        else
        {
            printf("INVALID\n");
        }
    }

    int firsttwo(long digits)
    {
        int result;
        while (digits > 99)
        {
              result = digits / 10;
              digits /= 10;
        }
        return result;
    }

    int check(long digits)
    {
        long cardcopy = digits;
        int checksum = 0;
        
            while (cardcopy > 9)
            {
                int checksumcur = (((cardcopy / 10) % 10) * 2);
                    if (checksumcur > 9)
                    {
                        checksum += ((checksumcur % 10) + (checksumcur / 10));
                    }
                    else 
                    {
                    checksum += checksumcur;
                    }
                cardcopy = cardcopy/100;
            }
            
            cardcopy = digits;
            
            while (cardcopy > 0)
            {
                checksum += (cardcopy % 10);
                cardcopy = cardcopy/100;
            }
        return checksum;
    }
    
    int counter (long digits)
    {
        int count = 0;
        while (digits > 0)
        {
            count++;
            digits /= 10;
        }
        return count;
    }