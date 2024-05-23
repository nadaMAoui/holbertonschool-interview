#include "palindrome.h"
/**
 * is_palindrome - function that checks whether or not
 * a given unsigned integer is a palindrome.
 * @n: the unsigned int to be checked
 * Return: 1 if n is a palindrome, and 0 otherwise
 */
int is_palindrome(unsigned long n)
{

    int reversed = 0, remainder, original = n;

    while (n != 0)
    {
        remainder = n % 10;
        reversed = reversed * 10 + remainder;
        n /= 10;
    }
    if (original == reversed)
        return (1);
    else
        return (0);

    return (1);
}
