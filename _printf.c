#include <stdarg.h>
#include "main.h"
#include <unistd.h>
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
