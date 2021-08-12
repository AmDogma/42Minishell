#include "minishell.h"

char	*quote(char *str, int *i, t_commandtable *main)
{
	if (str + *i + 1 && str[*i + 1] == '\'' && str + *i + 2
		&& (str[*i + 2] == ' ' || str[*i + 2] == '\0'))
	{
		cmd_malloc(main);
		if (main->cmd[main->curr_cmd].argc == 0)
			malloc_argv(main->cmd + main->curr_cmd, str);
		main->cmd[main->curr_cmd].argv[main->cmd[main->curr_cmd].argc]
			= join_free("", NULL, NULL);
		main->cmd[main->curr_cmd].argc += 1;
	}
	str = del_one_char(str, *i);
	while (str[*i] && str[*i] != '\'')
		(*i)++;
	str = del_one_char(str, *i);
	return (str);
}

char	*d_quote(char *str, t_commandtable	*main, int *i)
{
	if (str + *i + 1 && str[*i + 1] == '\"' && str + *i + 2
		&& (str[*i + 2] == ' ' || str[*i + 2] == '\0'))
	{
		cmd_malloc(main);
		if (main->cmd[main->curr_cmd].argc == 0)
			malloc_argv(main->cmd + main->curr_cmd, str);
		main->cmd[main->curr_cmd].argv[main->cmd[main->curr_cmd].argc]
			= join_free("", NULL, NULL);
		main->cmd[main->curr_cmd].argc += 1;
	}
	str = del_one_char(str, *i);
	while (str[*i] && str[*i] != '\"')
	{
		if (str[*i] == '$')
			str = dollar(str, main, i);
		else if (str[*i] == '\\')
			str = del_one_char(str, *i);
		else
			(*i)++;
	}
	str = del_one_char(str, *i);
	return (str);
}

char	*exit_stat(char *str, t_commandtable *main, int *i)
{
	char	*ex_num;
	char	*temp;

	ex_num = ft_itoa(main->last_exit_status);
	if (!ex_num)
		malloc_err_exit();
	temp = join_free(str + *i + 1, NULL, NULL);
	str[*i - 1] = '\0';
	*i += ft_strlen(ex_num) - 2;
	str = join_free(str, ex_num, &str);
	str = join_free(str, temp, &str);
	free(ex_num);
	free(temp);
	return (str);
}

char	*dollar(char *str, t_commandtable	*main, int *i)
{
	int		beg;
	char	*key;
	char	*temp;

	beg = ++(*i);
	if (str[beg] == '?')
		return (exit_stat(str, main, i));
	while (ft_isalnum(str[*i]) || str[*i] == '_')
		(*i)++;
	if (beg == *i)
		return (str);
	key = ft_substr(str, beg, *i - beg);
	if (!key)
		malloc_err_exit();
	temp = join_free(key, "=", &key);
	key = key_find(main->env, temp);
	str[beg - 1] = '\0';
	temp = join_free(str + *i, NULL, &temp);
	*i = beg + (int)ft_strlen(key) - 2;
	str = join_free(str, key, &str);
	str = join_free(str, temp, &str);
	free(temp);
	free(key);
	return (str);
}
