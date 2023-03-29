#include <Python.h>
#include <string.h>


/**
* print_python_string - prints Python strings
* @p: PyObject
*/
void print_python_string(PyObject *p)
{
	char type[50];
	wchar_t *value;

	puts("[.] string object info");
	if (!PyUnicode_Check(p))
	{
		fprintf(stderr, "  [ERROR] Invalid String Object\n");
		return;
	}

	memset(type, '\0', 50);

	if (PyUnicode_IS_COMPACT_ASCII(p))
		strcpy(type, "compact ascii");
	else if (PyUnicode_IS_COMPACT(p) && !PyUnicode_IS_ASCII(p))
		strcpy(type, "compact unicode object");
	value = PyUnicode_AsWideCharString(p, NULL);
	printf("  type: %s\n"
			 "  lenght: %ld\n"
			 "  value: %ls\n",
			 type, PyUnicode_GET_LENGTH(p), value);
	PyMem_Free(value);
}
