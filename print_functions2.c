#include 'main.h'
/*************************PRINT POINTER************************/
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
int print_pointer(va_list types, char buffer[],
                  int flags, int width, int precision, int size)
{
  char extra_c = 0, padd = ' ';
  int ind =
