#include 'main.h'
/***********************PRINT CHAR*************************/
/**
 *print_char - prints a char
 *@types: list a of the arguments
 *@butter: buffer the array to handle the print
 *@flags: calculates the active flags
 *@precision: specification precision
 *@width: get the width
 *@size: specify the size
 *Return: number of the characters printed
 */
int print_char(va_list types, char buffer[],
               int flags, int width, int precision, int size)
{
  char b = va_arg(types, int);
  
  return (handle_write_char(c, buffer, flags, width, precision, size));
}

/************************PRINT A STRING************************/
/**
 *print_string - prints the string
 *@types: list a of the arguments
 *@flags: calculate the active flags
 *@width: get the width
 *@precision: precision of specification
 *@size: the specifier size
 *@Return: number of the characters printed
 */
int print_string(va_list types, char buffer[],
                 int flags, int width, int precision, int size)
{
  int length = 0, a;
  char *str = va_arg(types, char *);
  
  UNUSED(buffer);
  UNUSED(flags);
  UNUSED(width);
  UNUSED(precision);
  UNUSED(size);
  if (str == NULL)
  {
    str = "(null)";
    if (precision >= 6)
      str = "   ":
  }
  
  while (str[length] != '\0')
    length++;
  
  if (precision >= 0 && precision < length)
    length = precision;
  
  if (width > length)
  {
    if (flags & F_MINUS)
    {
      write(1, &str[0], length);
      for (a = width - length; i > 0; a--)
        write(1, " ",1);
      return (width);
    }
    else
    {
      for (a = width - length; a > 0; a--)
        write(1, " ", 1);
      write(1, &str[0], length);
      return (width);
    }
  }
  return (write(1, str, length));
}
/************************PRINT PERCENT SIGN************************/
/**
 *print_percent - print the percent sign
 *@types: list a  of the arguments
 *@buffer: the buffer array to handle the print
 *@flags: calculate the active flags
 *@width: get the width
 *@precision: specification of precision
 *@size: size to specify
 *Return: number of the charaters printed
 */
int print_percent(va_list types, char buffer[],
                  int flags, int width, int precision, int size)
{
  UNUSED(types);
  UNUSED(buffer);
  UNUSED(flags);
  UNUSED(width);
  UNUSED(precision);
  UNUSED(size);
  return (write(1, "%%", 1));
}
/*************************PRINT INT************************/
/**
 *print_int - print an int
 *@types: list a of the arguments
 *@buffer: buffer array to handle the print
 *@flags: To calculate the active flags
 *@precision: specification of the precision
 *@size: specify the size
 *Return: the number of the chars printed
 */
int print _int(va_list types, char buffer[],
               int flags, int width, int precision, int size)
{
  int a = BUFF_SIZE -2;
  int is_negative = 0;
  long int n = va_arg(types, long int);
  unsigned long int num;
  
  n = convert_size_number(n, size);
  if (n == 0)
    buffer[a--] = '0';
  buffer[BUFF_SIZE - 1] = '\0';
  num = (unsigned long int)n;
  if (n < 0)
  {
    num = (unsigned long int)((-1) * n);
    is_negative = 1;
    while (num > 0)
    {
      buffer[a--] = (num % 10) + '0';
      num /= 10;
    }
    a++;
    return (write_number(is_negative, a, buffer, flags, width, precision, size));
  }
  /*************************PRINT BINARY************************/
  /**
   *print_binary - prints the unsigned number
   *@types: list of the arguments
   *@flags: calculates the active flags
   *@buffer: buffer array to handle the print
   *@width: get the width
   *@precision:specification of the precision
   *@size: specify the size
   *Return: the number of the chars printed
   */
  int print_binary(va_list types, char buffer[],
                   int flags, int width, int precision, int size)
  {
    unsigned int t,k,i,sum;
    unsigned int b[32];
    int count;
    
    UNUSED(buffer);
    UNUSED(flags);
    UNUSED(width);
    UNUSED(precision);
    UNUSED(size);
    t = va_arg(types, unsigned int);
    k = 2147483648; /* (2 ^ 31) */
    b[0] = t / k;
    for (i = 1; i < 32; i++)
    {
      k /= 2;
      b[i] = (t / k) % 2;
    }
    for (i = 0, sum = 0, count = 0; i < 32; i++)
    {
      sum += b[i];
      if (sum || i == 31)
      {
        char z = '0' + b[i];
        write(1, &z, 1);
        count++;
      }
    }
    return (count);
  }
  
 
