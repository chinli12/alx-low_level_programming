#include "main.h"
/**
 * puts_half - a function that prints half of a string
 * if odd len, n = (length_of_the_string - 1) / 2
 * @str: input
 * Return: half of input
 */
void puts_half(char *str)
{
	int a, b, clog;

	clog = 0;

	for (a = 0; str[a] != '\0'; a++)
		clog++;
	b = (clog / 2);

	if((clog % 2) == 1)
		b = ((clog + 1) / 2);
	for (a = b; str[a] != '\0'; a++)
		_putchar(str[a]);
	_putchar('\n');
}
