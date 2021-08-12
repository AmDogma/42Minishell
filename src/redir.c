#include "minishell.h"

char	*redir_type(t_commandtable *main, char *str, int *i)
{
	if (str[*i] == '<' && str[*i + 1] == '<')
		main->red_val = ft_strdup("2");
	else if (str[*i] == '>' && str[*i + 1] == '>')
		main->red_val = ft_strdup("4");
	else if (str[*i] == '<')
		main->red_val = ft_strdup("1");
	else if (str[*i] == '>')
		main->red_val = ft_strdup("3");
	if (main->red_val == NULL)
		malloc_err_exit();
	if (main->red_val[0] == '2' || main->red_val[0] == '4')
		str = join_free(str + 2, NULL, &str);
	else
		str = join_free(str + 1, NULL, &str);
	if (str[*i] == '\0' || str[*i] == '<' || str[*i] == '>' || str[*i] == '<')
	{
		printf("syntax error in '>' or '<'\n");
		return (clean_all(main, str, i));
	}
	*i = 0;
	return (str);
}

char	*redir_name(t_commandtable *main, char *str, int *i)
{
	char	*temp;

	while (str[*i] == ' ')
		str = del_one_char(str, *i);
	while (str[*i] != '\0' && str[*i] != '|' && str[*i] != ' ')
	{
		if (str[*i] == '\'')
			str = quote(str, i, main);
		else if (str[*i] == '\"')
			str = d_quote(str, main, i);
		else if (str[*i] == '<' || str[*i] == '>')
		{
			printf("syntax error in '>' or '<'\n");
			return (clean_all(main, str, i));
		}	
		else
			(*i)++;
	}
	temp = ft_substr(str, 0, *i);
	main->red_val = join_free(main->red_val, temp, &main->red_val);
	free(temp);
	str = join_free(str + *i, NULL, &str);
	*i = 0;
	return (str);
}

char	*redir(char *str, t_commandtable *main, int *i)
{
	cmd_malloc(main);
	str = redir_type(main, str, i);
	str = redir_name(main, str, i);
	if (main->cmd)
		str = redir_act(main->cmd + main->curr_cmd, main, str, i);
	if (main->red_val)
		free(main->red_val);
	main->red_val = NULL;
	return (str);
}
