#include "main.h"
/**
 * puts2 - function should print only one character out of two
 * starting with the first one
 * @str: input
 * Return: print
*/
void puts2(char *str)
{
	int m = 0;
	int i = 0;
	char *b = str;
	int o;

	while (*b != ;\0')
	{
		b++;
		m++;
	}
	i = m -1;
	for (o = 0; 0 <= i; o++)
	{
		if (o % 2 == 0)
		{
			_putchar(str[o]);
		}
	}
	_putchar('\n');
}
