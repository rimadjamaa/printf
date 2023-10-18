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
