#include <stdarg.h>
11;rgb:0000/0000/0000#include "main.h"
/**
 * printf_int - prints integer
 * This function takes an integer argument, converts it to its decimal
 * representation
 * @args: argument to print
 * Return: number of characters printed
 */
int printf_int(va_list args)
{
int n = va_arg(args, int);
int num, last = n % 10, digit, exp = 1;
int  i = 1;
n = n / 10;
num = n;
if (last < 0)
{
_putchar('-');
num = -num;
n = -n;
last = -last;
i++;
}
if (num > 0)
{
while (num / 10 != 0)
{
exp = exp * 10;
num = num / 10;
}
num = n;
while (exp > 0)
{
digit = num / exp;
_putchar(digit + '0');
num = num - (digit *exp);
exp = exp / 10;
i++;
}
}
_putchar(last + '0');

return (i);
}

/**
 * printf_dec - prints decimal
 * his function is an alias for `printf_int'
 * @args: The argument to be converted and printe
 * Return: number of characters printed
 */

int printf_dec(va_list args)
{
int n = va_arg(args, int);
int num, last = n % 10, digit;
int  i = 1;
int exp = 1;
n = n / 10;
num = n;

if (last < 0)
{
_putchar('-');
num = -num;
n = -n;
last = -last;
i++;
}
if (num > 0)
{
while (num / 10 != 0)
{
exp = exp * 10;
num = num / 10;
}
num = n;
while (exp > 0)
{
digit = num / exp;
_putchar(digit + '0');
num = num - (digit *exp);
exp = exp / 10;
i++;
}
}
_putchar(last + '0');

return (i);
}
#include <stdarg.h>
#include <unistd.h>
#include <stdio.h>
/**
 * print_char - Helper function to print a single character
 * @args: va_list containing the arguments
 * @count: Pointer to the count of printed characters
 */
void print_char(va_list args, int *count)
{
char c = va_arg(args, int);
write(1, &c, 1);
(*count)++;
}

/**
 * print_string - Helper function to print a string
 * @args: va_list containing the arguments
 * @count: Pointer to the count of printed characters
 */
void print_string(va_list args, int *count)
{
char *str = va_arg(args, char *);
if (str == NULL)
str = "(null)";
while (*str != '\0')
{
write(1, str, 1);
str++;
(*count)++;
}
}
