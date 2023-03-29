#include <Python.h>


/**
* print_python_int - prints Python integers
* @p: PyObject
*/
void print_python_int(PyObject *p)
{
	unsigned long number;
	int i, size;
	uint32_t *digit;

	if (!PyLong_Check(p))
	{
		fprintf(stderr, "Invalid Int Object\n");
		return;
	}

	size = ((PyVarObject *) p)->ob_size;
	digit = ((PyLongObject *) p)->ob_digit;

	if (size > 3 || (size == 3 && digit[2] > 15))
	{
		fprintf(stderr, "C unsigned long int overflow\n");
		return;
	}

	number = 0;

	for (i = 0; i < (size < 0 ? size * -1 : size); i++)
		number += digit[i] * (1L << (PyLong_SHIFT * i));

	if (size < 0)
		putchar('-');

	printf("%lu\n", number);
}
