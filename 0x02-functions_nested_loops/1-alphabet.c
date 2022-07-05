#include "main.h"

/**
 * print_alphabet - prints lowercase alphabet
 * Return: 0
 */

int main(void)
{
	char alpha;

	alpha = 'a';

	while (alpha <= 'z')
	{
		_putchar(alpha);
		alpha++;
	}
	_putchar('\n');
}
