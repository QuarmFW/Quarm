#include "quarm.h"

struct agent_node g_agent;

int main (void)
{
	int ret;

	printf("QUARM: The First C-Language supported AI agent\n");

	ret = init_quarm();
	if(ret) {
		fprintf(stderr, "Agent initilaisation failed! %d\n", ret);
		return ret;
	}

	start_quarm();
	cleanup_quarm();

	return 0;
}
