#include "monty.h"

/**
 * fErr - Prints error messages for each case
 * @errorNum: The error case num
 * (1) => case 1 - no file or more than one file
 * (2) => case 2 - can't opene or read the file
 * (3) => case 3 - invalid instruction in file
 * (4) => case 4 - can't malloc more memory
 * (5) => case 5 - errorNum is not an int
 * (6) => case 6 - stack empty pint
 * (7) => case 7 - stack empty pop
 * (8) => case 8 - stack is short
 */
void fErr(int errorNum, ...)
{
va_list agmt;
char *oper;
int l_num;
va_start(agmt, errorNum);
switch (errorNum)
{
case 1:
fprintf(stderr, "USAGE: monty file\n");
break;
case 2:
fprintf(stderr, "Error: Can't open file %s\n",
va_arg(agmt, char *));
break;
case 3:
l_num = va_arg(agmt, int);
oper = va_arg(agmt, char *);
fprintf(stderr, "L%d: unknown instruction %s\n", l_num, oper);
break;
case 4:
fprintf(stderr, "Error: malloc failed\n");
break;
case 5:
fprintf(stderr, "L%d: usage: push integer\n", va_arg(agmt, int));
break;
default:
break;
}
nFree();
exit(EXIT_FAILURE);
}
