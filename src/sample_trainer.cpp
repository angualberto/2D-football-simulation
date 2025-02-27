#include <Python.h>
// ...existing code...

void detect_and_sync_players() {
    Py_Initialize();
    PyObject* pName = PyUnicode_DecodeFSDefault("player_detection");
    PyObject* pModule = PyImport_Import(pName);
    Py_DECREF(pName);

    if (pModule != NULL) {
        PyObject* pFunc = PyObject_GetAttrString(pModule, "main");
        if (PyCallable_Check(pFunc)) {
            PyObject* pValue = PyObject_CallObject(pFunc, NULL);
            if (pValue != NULL) {
                Py_DECREF(pValue);
            } else {
                PyErr_Print();
            }
        } else {
            PyErr_Print();
        }
        Py_XDECREF(pFunc);
        Py_DECREF(pModule);
    } else {
        PyErr_Print();
    }
    Py_Finalize();
}

int main(int argc, char* argv[]) {
    // ...existing code...
    detect_and_sync_players();
    // ...existing code...
    return 0;
}
