#include <stdio.h>
#include <stdlib.h>

#include <Python.h>

/* Define your agents library path.
 * This path is w.r.t to the directory of cloned source. */
#define AGENTS_LIB_PATH	"../"

#define AGENT_PYTHON_FILE	"../main.py"

/**
 * struct agent_node : holds agent data
 */
struct agent_node {
	FILE* agent;
	PyObject *pModule;
	PyObject *pFunc;
	PyObject *pValue;
	PyObject *sys_path;
	PyObject *sys_path_list;
};


int init_quarm(void);
void start_quarm(void);
void cleanup_quarm(void);
