#include "main.h"

/**
 * print_last_digit - print the last digit
 * @n: the number
 * Return: value of the last digit
*/
int print_last_digit(int n)
{
	in ls = n % 10;

	if (ls < 0)
		ls += -1;
	_putchar(ls + '0');

	return (0);
