/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aleite-b <aleite-b@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/20 14:15:25 by aleite-b          #+#    #+#             */
/*   Updated: 2023/11/21 13:42:49 by aleite-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <fcntl.h>
# include <sys/wait.h>

void	execute_command(int in_fd, int out_fd, char *command, char **envp);
int		main(int ac, char **av, char **envp);

int		free_words(char **str, int size);
int		count_str(char const *s, char c);
void	write_word(char *dest, const char *from, char charset);
int		split_words(char **split, const char *str, char charset);
char	**ft_split(const char *s, char c);

#endif