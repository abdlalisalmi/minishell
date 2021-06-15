#include "../minishell.h"

void start_execution(int n_commands, char **envp)
{
	if (n_commands == 1)
		exec_single_cmd(g_all.commands[0], envp);
	else
	{
		printf("Multiple commands : n_commands = %d\n", n_commands);
	}
}