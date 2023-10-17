#include <stdarg.h>
#include <unistd.h>

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

/**
 * print_int - Helper function to print an integer
 * @args: va_list containing the arguments
 * @count: Pointer to the count of printed characters
 */
void print_int(va_list args, int *count)
{
int num = va_arg(args, int);
char buffer[20];
int length = sprintf(buffer, "%d", num);

write(1, buffer, length);
*count += length;
}

/**
 * _printf - Custom printf function
 * @format: Format string
 *
 * Return: Number of characters printed (excluding null byte)
 */
int _printf(const char *format, ...)
{
va_list args;
int count = 0;
const char *ptr;
va_start(args, format);
for (ptr = format; *ptr != '\0'; ptr++)
{
if (*ptr == '%' && *(ptr + 1) != '\0')
{
ptr++;
switch (*ptr)
{
case 'c':
print_char(args, &count);
break;
case 's':
print_string(args, &count);
break;
case '%':
write(1, "%", 1);
count++;
break;
case 'd':
case 'i':
print_int(args, &count);
break;
default:
write(1, "%", 1);
write(1, ptr, 1);
count += 2;
}
}
else
{
write(1, ptr, 1);
count++;
}
}
va_end(args);
return (count);
}
