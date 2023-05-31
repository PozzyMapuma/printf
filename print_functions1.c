#include 'main.h'
/************************PRINT UNSIGNED NUMBER************************/
/**
 * print_unsigned - Prints the insigned number
 * @types: list a of the agurments
 * @buffer: buffer the array to handle the print
 * @flags: calculates the active flags
 * @width: get the width
 * @precision: precision specification
 * @size: specify the size
 * Return: number of characters printed
 */
int print_unsigned(va_list types, char buffer[],
                   int flags, int width, int precision, int size)
{
  int a = BUFF_SIZE - 2;
  unsigned long int num = va_arg(types, unsigned long int);
  
  num = convert_size_unsigned(num, size);
  
  if (num == 0)
    buffer[a--] = '0';
  
  buffer [BUFF_SIZE - 1] = '0';
  while (nim > 0)
  {
    buffer[a--] = (num % 10) + '0';
    num /= 10;
  }
  a++;
  return (write_unsigned(0, a, buffer, flags, width, precision, size));
}
/************************PRINT UNSIGNED NUMBER IN OCTAL************************/
/**
 * print_octal - prints the unsigned number on the octal notation
 * @types: list a of the arguments
 * @buffer: the buffer of array to handle print
 * @flags: calculate the active flags
 * @width: get the width
 * @precision: specify the precision
 * @size: size of specifier
 * Return: the number of characters printed
 */
int print _octal(va-list types, char buffer[],
                 int flags, int width, int precision, int size)
{
  int a = BUFF_SIZE -2;
  unsigned long int num = va-arg(types, unsigned long int);
  unsigned long int init_num = num;
  
  UNUSED(width);
  num = convert_size_unsigned(num, size);
  if (num == 0)
    buffer[a--] - '0';
  a++;
  return (write_unsigned(0, a, butter, flags, width, precision, size));
}
/************************PRINT UNSIGNED NUMBER IN HEXADECIMAL************************/
/**
 *print_hexadecimal - prints the unsigned number in the hexadecimal notation
 *@types: list a of the arguments
 *@buffer: Buffer of the array to handle the print
 *@flags: calculates the active flags
 *@width: get the width
 *@precision: specification precision
 *@size: specifier size
 */
int print_hexadecimal(va_list types, char buffer[],
                      int flags, int width, int precision, int size)
{
  return (print_hexadecimal(types, "0123456789abcdef", buffer,
                            flags, 'x', width, precision, size));
}
/************************PRINT UNSIGNED NUMBER IN UPPER HEXADECIMAL************************/
 /**
  *print_hexa_upper - prints the unsigned number in the upper hexadecimal notation
  *@types: list a of the arguments
  *@buffer: buffer of the array to handle the print
  *@flags: calculate the active flags
  *width: get the width
  *precision: the precision specification
  *@size: the size specifier
  *Return: the number of the characters printed
  */
int print_hexa_upper(va_list types, char buffer[],
                     int flags, int width, int precision, int size)
{
  return (print_hexa(types, "0123456789ABCDEF", buffer,
                     flags, 'X', width, precision,size));
}
/************************PRINT HEXA NUM IN LOWER OR UPPER************************/
/**
 *print_hexa - prints the hexadecimal number in the lower or the upper
 *@types: list a of the arguments
 *@map_to: the array of the values to map the number to
 *@buffer:buffer array to handle the print
 *@flags: calculate the active flags
 *@width: get the width
 *@precision: the precision specification
 *@size: specifier size
 *@size: size of specification
 *Return: the number of characters printed
 */
int print_hexa(va_list types, char map_to [], char butter[],
               int flags, char flag_ch, int width, int precision, int size)
{
  int a = BUFF_SIZE -2;
  unsigned long int num = va_arg(types, unsigned long int);
  unsigned long int init_num = num;
  
  UNUSED(width);
  num = convert_size_unsigned(num, size);
  if (num == 0)
    butter[a--] = '0';
  buffer[BUFF_SIZE -1] = '\0';
  while (num > 0)
  {
    buffer[a--] = map_to[num % 16];
    num /= 16;
  }
  if (flags & F-HASH && init_num != 0)
  {
    buffer[a--] = flag_ch;
    buffer[a--] = '0';
  }
  a++;
  return (write_unsigned(0, a, buffer, flags, width, precision, size));
}
