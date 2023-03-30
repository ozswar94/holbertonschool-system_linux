#include <Python.h>

/**
* print_python_bytes - print some basic info about Python
* lists and Python bytes object
* @p: PyObject
*/
void print_python_bytes(PyObject *p)
{
	Py_ssize_t i, size;
	char *bytes;

	puts("[.] bytes object info");
	if (!PyBytes_Check(p))
	{
		fprintf(stderr, "  [ERROR] Invalid Bytes Object\n");
		return;
	}

	size = PyBytes_Size(p);
	bytes = PyBytes_AsString(p);
	printf("  size: %ld\n"
			"  typing string: %s\n"
			"  first %ld bytes:",
			size, bytes,
			size < 10 ? size + 1 : 10);

	for (i = 0; i < size && i < 10; i++)
		printf(" %02hhx", bytes[i]);
	putchar('\n');
}


/**
* print_python_list - prints some basic info about Python lists.
* @p: PyObject given ny bytebode Python
*/
void print_python_list(PyObject *p)
{
	Py_ssize_t i;
	PyObject *item;

	printf("[*] Python list info\n"
			 "[*] Size of the Python List = %ld\n"
			 "[*] Allocated = %ld\n",
			 PyList_Size(p), ((PyListObject *)p)->allocated);

	for (i = 0; i < PyList_Size(p); i++)
	{
		item = PyList_GET_ITEM(p, i);
		printf("Element %ld: %s\n", i, item->ob_type->tp_name);
		if (PyBytes_Check(item))
			print_python_bytes(item);
	}
}

