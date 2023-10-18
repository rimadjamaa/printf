#include <stdarg.h>
#include <unistd.h>
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
