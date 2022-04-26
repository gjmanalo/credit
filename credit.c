#include <cs50.h>
#include <stdio.h>
#include <math.h>
#include <string.h>
#include <stdlib.h>

int main(void)
{
    int g = 0;
    int p;
    int h;
    int m;
    char pls[20];
    int c;
    int total2 = 0;
    int total3;
    char b[50] = {'\0'};
    char d[50] = {'\0'};
    int total = 0;
    int a;
    char gar[20];
    char les[20];
    char mat[20];
    int y;
    long int num;
    long x;
    double z;
///////////////////////////////// Get credit card number from user and based on its value, set h and m
    {
        num = get_long("Number: "); //asks the user for the card number and assigns that to n
    }

    if ((num < 99999999999999 || num > 100000000000000))
    {
    m = 2;
    h = 1;
    }
    if ((num > 99999999999999 && num < 1000000000000000) || (num > 999999999999 && num < 10000000000000))
    {
    m = 1;
    h = 2;
    }

///////////////////////////////// Convert credit card number to a string and back to a number a few different times to implement luhns algorithm
sprintf(gar, "%li", num);         //convert number to string

y = strlen(gar);

for (int i = y-m; i >= 0; i--)
    {
    if (i % 2 != 0) continue;    //if not even (odd) then skip line 53-58 and continue the for loop
    sscanf(&gar[i], "%1d", &a);  //convert string to a number

    a = a*m;

    sprintf(&les[0], "%d", a);   //convert number to a string
    strcat(b, &les[0]);          //combine strings together to create one string
    }

    y = strlen(b);               //get the size of the string
    for (int i = 0; i < y; i++)
    {
    sscanf(&b[i], "%1d", &a);    //convert string to a number
    total = total + a;           //update total count
    }

////////////////////////////////////// Does the same as a above but for even numbers
    sprintf(gar, "%li", num);
    y = strlen(gar);

    for (int i = y-h; i >= 0; i--)
    {
    if (i % 2 == 0) continue;
    sscanf(&gar[i], "%1d", &c);

    c = c*h;

    sprintf(&mat[0], "%d", c);
    strcat(d, &mat[0]);
    }

    y = strlen(d);

    for (int i = 0; i < y; i++)
    {
    sscanf(&d[i], "%1d", &c);
    total2 = total2 + c;
    }

////////////////////////////////////////////// checks if the total sum has a 0 at the end
total3 = total2 + total;

    sprintf(&pls[0], "%d", total3);       //turns total into a string
    p = strlen(pls);                      //gets length of string

    for (int i = p-1; i < p; i++)
    {
    if (pls[i] != '0')                    //if the number at the end of the string is not 0 print invalid
    {
        printf("INVALID\n");
        g = 1;
    }
    }

if (g == 0)                                // when g == 0, then continue checking for the card type
{

    if (num > 999999999999 && num < 10000000000000) //if the number is 13 digits, convert to double and divide such that 2 digits are before the decimal and 8 digits are after the decimal
    {
        z = (double) num /1000000000000;
    }

    if (num > 99999999999999 && num < 1000000000000000) //if the number is 15 digits, convert to double and divide such that 2 digits are before the decimal and 8 digits are after the decimal
    {
        z = (double) num /10000000000000;
    }

    if (num > 999999999999999 && num < 10000000000000000) //if the number is 16 digits, convert to double and divide such that 2 digits are before the decimal and 8 digits are after the decimal
    {
        z = (double) num /100000000000000;
    }

    if ((z >= 4 && z < 5) || (z >=40 && z <50)) //if z is between 4 and 5 or 50 and 50, then print VISA
    {
        printf("VISA\n");
    }

    else if (z >= 51 && z < 56) //if z is between 51 and 55, then print MASTERCARD
    {
        printf("MASTERCARD\n");
    }

   else if ((z >= 34 && z < 35) || (z >= 37 && z < 38)) // if z is between 34 and 35 or 37 and 38, then print AMEX
    {
        printf("AMEX\n");
    }
    else
    {
        printf("INVALID\n");
    }
}
}