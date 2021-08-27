#include <Python.h>
#include <stdio.h>
#include <string.h>
/**
 * print_python_bytes - prints some basic info about Python bytes.
 * @p: Python object
 */
void print_python_bytes(PyObject *p)
{
	int i;
	Py_ssize_t size, printed_bytes;
	char *array_as_string = NULL;

	printf("[.] bytes object info\n");
	if (!PyBytes_Check(p))
	{
		printf("  [ERROR] Invalid Bytes Object\n");
		return;
	}

	size = ((PyVarObject *)(p))->ob_size;
	printf("  size: %li\n", size);

	array_as_string = ((PyBytesObject *)(p))->ob_sval;
	printf("  trying string: %s\n", array_as_string);

	printed_bytes = (size + 1 >= 10) ? 10 : size + 1;
	printf("  first %li bytes:", printed_bytes);
	for (i = 0; i < printed_bytes; i++)
		printf(" %02x", (unsigned char)(array_as_string[i]));
	putchar('\n');
}
/**
 * print_python_list - prints some basic info about Python lists
 * @p: Python object
 */
void print_python_list(PyObject *p)
{
	PyObject *item;
	Py_ssize_t size = PyList_Size(p);
	Py_ssize_t i;

	if (!p)
		return;

	printf("[*] Python list info\n");
	printf("[*] Size of the Python List = %lu\n", size);
	printf("[*] Allocated = %lu\n", ((PyListObject *)p)->allocated);

	for (i = 0; i < size; i++)
	{
		item = ((PyListObject *)(p))->ob_item[i];
		printf("Element %ld: %s\n", i, item->ob_type->tp_name);
		if (PyBytes_Check(item))
			print_python_bytes(item);
	}
}
/**
 * print_python_float - prints some basic info about Python lists
 * @p: Python object
 */
void print_python_float(PyObject *p)
{
	char *s;
	double value;

	setbuf(stdout, NULL);

	printf("[.] float object info\n");
	if (!p || !PyFloat_Check(p))
	{
		printf("  [ERROR] Invalid Float Object\n");
		return;
	}

	value = (((PyFloatObject *)(p))->ob_fval);
	s = PyOS_double_to_string(value, 'r', 0, Py_DTSF_ADD_DOT_0, NULL);
	printf("  value: %s\n", s);
}
