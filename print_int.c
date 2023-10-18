/**
 * power - Calculate the power of a number.
 * @base: The base.
 * @exponent: The exponent.
 *
 * Return: The result of base raised to the power of exponent.
 */
int power(int base, int exponent)
{
int result = 1;

while (exponent > 0)
{
result *= base;
exponent--;
}

return (result);
}
/**
 * print_int - print an int.
 * @args: The base.
 * @count: The exponent.
 *
 * Return: The result of base raised to the power of exponent.
 */
void print_int(va_list args, int *count)
{
int num = va_arg(args, int);
int temp = num;
int length = 0;

while (temp != 0)
{
temp /= 10;
length++;
}

if (num < 0)
{
write(1, "-", 1);
(*count)++;
num = -num;
}
while (length > 0)
{
int digit = num / power(10, length - 1);
char digit_char = digit + '0';
write(1, &digit_char, 1);
(*count)++;
num %= power(10, length - 1);
length--;
}
}
