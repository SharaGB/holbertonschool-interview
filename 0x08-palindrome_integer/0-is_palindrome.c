#include "palindrome.h"
/**
 * is_palindrome - checks whether or not a given unsigned integer is a palindrome
 * @n: Nunber to be checked
 *
 * Return: 1 if n is a palindrome, and 0 otherwise
 */

int is_palindrome(unsigned long n)
{
    unsigned long rev = 0, orig = n;

    while (n != 0)
    {
        rev = rev * 10 + n % 10;
        n /= 10;
    }

    return (orig == rev);
}