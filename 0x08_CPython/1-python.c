#include <Python.h>


/**
* print_python_list - prints some basic info about Python lists.
* @p: PyObject given ny bytebode Python
*/
void print_python_list(PyObject *p)
{
	int i;

	printf("[*] Python list info\n"
			 "[*] Size of the Python List = %ld\n"
			 "[*] Allocated = %ld\n",
			 Py_SIZE(p), ((PyListObject *)p)->allocated);
	for (i = 0; i < Py_SIZE(p) ; i++)
	{
		printf("Element %d: %s\n", i, Py_TYPE((PyList_GetItem(p, i)))->tp_name);
	}
}

