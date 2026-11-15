#define PY_SSIZE_T_CLEAN
#include <Python.h>

static PyObject *greet(PyObject *self, PyObject *args)
{
    const char *name;

    if (!PyArg_ParseTuple(args, "s", &name))
    {
        return NULL;
    }

    return PyUnicode_FromFormat(
        "Hello, %s!",
        name);
}

static PyMethodDef HelloMethods[] = {
    {"greet",
     greet,
     METH_VARARGS,
     "Return a greeting."},
    {NULL, NULL, 0, NULL}};

static struct PyModuleDef hellomodule = {
    PyModuleDef_HEAD_INIT,
    "hello",
    NULL,
    -1,
    HelloMethods};

PyMODINIT_FUNC PyInit_hello(void)
{
    return PyModule_Create(&hellomodule);
}