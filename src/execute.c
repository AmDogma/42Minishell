/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execute.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jovertki <jovertki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/09 20:42:11 by jovertki          #+#    #+#             */
/*   Updated: 2021/07/31 16:17:35 by jovertki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static void	setup_output(t_commandtable *ct, t_execute *all, int i)
{
	int	fdpipe[2];

	if (i == ct->num_of_commands - 1)
	{
		if (ct->cmd[i].output)
		{
			all->fdout = ct->cmd[i].output;
		}
		else
		{
			all->fdout = dup(all->default_out);
		}
	}
	else
	{
		pipe(fdpipe);
		all->fdout = fdpipe[1];
		all->fdin = fdpipe[0];
	}
	if (ct->cmd[i].output)
		dup2(ct->cmd[i].output, 1);
	else
		dup2(all->fdout, 1);
	close(all->fdout);
}

static void	\
	create_child(t_commandtable *ct, t_execute *all, int i, char ***envp)
{
	if (ct->cmd[i].argv == NULL)
		;
	else if (is_not_builtin(ct->cmd[i].argv[0]))
	{
		all->ret = fork();
		if (all->ret == 0)
		{
			signal(SIGINT, inthandler_cd);
			signal(SIGQUIT, quithandler_cd);
			search_right_bin(ct->cmd[i].argv, *envp, &ct->last_exit_status);
			exit(ct->last_exit_status);
		}
	}
	else
		execbuiltin(&ct->last_exit_status, \
		ct->cmd[i].argv, ct->cmd[i].argc, envp);
}

static void	restore_default_streams(t_execute *all)
{
	dup2(all->default_in, 0);
	dup2(all->default_out, 1);
	close(all->default_in);
	close(all->default_out);
}

static void	catch_children(t_execute *all, t_commandtable *ct)
{
	int	status;
	int	out;

	out = -123;
	if (all->ret != 0)
	{
		signal(SIGINT, inthandler_p);
		signal(SIGQUIT, quithandler_p);
		waitpid(all->ret, &status, 0);
		signal(SIGINT, inthandler);
		signal(SIGQUIT, SIG_IGN);
		if (WIFEXITED(status))
		{
			out = WEXITSTATUS(status);
			if (out != 0 && out != 127 && out != 126)
				out += 128;
		}
		else
			out = WTERMSIG(status) + 128;
		ct->last_exit_status = out;
	}
}

void	execute(t_commandtable *ct, char ***envp)
{
	t_execute	all;
	int			i;

	pipes_init(&all, ct);
	i = 0;
	while (i < ct->num_of_commands)
	{
		redirect_input(&all, ct, i);
		setup_output(ct, &all, i);
		create_child(ct, &all, i, envp);
		i++;
	}
	restore_default_streams(&all);
	catch_children(&all, ct);
}
