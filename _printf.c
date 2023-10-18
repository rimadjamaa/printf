#include <stdarg.h>
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
{
char c = va_arg(args, int);
count += write(1, &c, 1);
break;
}
case 's':
count += write(1, va_arg(args, char *), 1);
break;
case '%':
count += write(1, "%", 1);
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
