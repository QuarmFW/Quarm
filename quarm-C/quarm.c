#include "quarm.h"

extern struct agent_node g_agent;

/**
 * init_quarm	: initialise quarm agent
 * return	: Error code at error, 0 if success
 */
int init_quarm(void)
{
	Py_Initialize();
	g_agent.agent = fopen(AGENT_PYTHON_FILE, "r");
	if(!g_agent.agent) {
		fprintf(stderr, "Error: Unable to open agent file\n");
		return -EINVAL;
	}

	/* importing libraries */
	g_agent.sys_path = PyImport_ImportModule("sys");
	g_agent.sys_path_list = PyObject_GetAttrString(g_agent.sys_path, "path");
	if (PyList_Check(g_agent.sys_path_list)) {
		PyList_Append(g_agent.sys_path_list, PyUnicode_FromString(AGENTS_LIB_PATH));
	}
	g_agent.pModule = PyImport_ImportModule("agents");
	if(g_agent.pModule == NULL) {
		PyErr_Print();
		Py_Finalize();
		fprintf(stderr,"install cli_shell to continue");
		return -EINVAL;
	}

	return 0;
}

/**
 * start_quarm	: kick start the agent
 * return	: no return
 */
void start_quarm(void)
{
	PyRun_SimpleFile(g_agent.agent, "main.py");
	fclose(g_agent.agent);
}

/**
 * cleanup_quarm : cleanup the agent files
 * return	 : no return
 */
void cleanup_quarm(void)
{
	g_agent.pValue = PyObject_CallObject(g_agent.pFunc, NULL);
	if(g_agent.pValue != NULL) {
		Py_XDECREF(g_agent.pValue);
	} else {
		PyErr_Print();
	}
	Py_XDECREF(g_agent.pFunc);
	Py_XDECREF(g_agent.pModule);
	Py_Finalize();
}
