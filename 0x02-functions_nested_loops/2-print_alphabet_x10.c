#include "main.h"

/**
 * print_alphabet_x10 - prints alpha 10 times
*/
void print_alphabet_x10(void)
{
	int nums;
	char le;

	for (nums = 0; nums <= 9; nums++)
	{
		for (le = 'a'; le <= 'z'; le++)
			putchar(le);
		putchar('\n');
	}
}
