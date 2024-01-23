#include "monty.h"

/**
 * finder - find function
 * @opcode: opcode
 * @value: arg of opcode
 * @fmt: storage format
 * @lnum: number of line
 * Return: void
 */
void finder(char *opcode, char *value, int lnum, int fmt)
{
int i;
int n;
instruction_t func_list[] = {
{NULL, NULL}
};
if (opcode[0] == '#')
{
return;
}
for (n = 1, i = 0; func_list[i].opcode != NULL; i++)
{
if (strcmp(opcode, func_list[i].opcode) == 0)
{
callingFun(func_list[i].f, opcode, value, lnum, fmt);
n = 0;
}
}
if (n == 1)
fErr(3, lnum, opcode);
}


/**
 * callingFun - Calls the required function
 * @f: Pointer to function
 * @ops: string of opcode
 * @value: value
 * @lnum: line numeber
 * @fmt: Format
 */
void callingFun(op_func f, char *ops, char *value, int lnum, int fmt)
{
stack_t *nd;
int i;
int n;
n = 1;
if (strcmp(ops, "push") == 0)
{
if (value != NULL && value[0] == '-')
{
value = value + 1;
n = -1;
}
if (value == NULL)
fErr(5, lnum);
for (i = 0; value[i] != '\0'; i++)
{
if (isdigit(value[i]) == 0)
fErr(5, lnum);
}
nd = createNode(atoi(value) * n);
if (fmt == 0)
f(&nd, lnum);
if (fmt == 1)
addToQueue(&nd);
}
else
{
f(&head, lnum);
}
}
