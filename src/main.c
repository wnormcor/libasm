/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wnormcor <wnormcor@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/30 09:37:28 by wnormcor          #+#    #+#             */
/*   Updated: 2020/10/31 19:58:00 by wnormcor         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdio.h>
#include <fcntl.h>
#include <stdlib.h>
#include <errno.h>
#include "libasm.h"

int		main(void)
{
	int		i		= 0;
	int		j		= 0;
	char	*str[]	= {
		"",
		"short str",
		"midlle .................... string",
		"long .............................................................. string"
	};

	// test ft_strlen
	printf("\nFT_STRLEN:\n");
	size_t	res_strlen		= 0;
	size_t	res_ft_strlen	= 0;
	i = 0;
	while (i < 4)
	{
		res_strlen		= strlen(str[i]);
		res_ft_strlen	= ft_strlen(str[i]);
		printf("ft_strlen: var %d. strlen: %4lu, ft_strlen: %4lu. Res: ",	i,
																			res_strlen,
																			res_ft_strlen);
		(res_strlen != res_ft_strlen) ? printf("ERROR\n") : printf("OK\n");
		i++;
	}

	// test ft_strcpy
	printf("\nFT_STRCPY\n");
	char	*res_strcpy	= NULL;
	char	*res_ft_strcpy	= NULL;
	i = 0;
	while (i < 4)
	{
		res_strcpy		= malloc(strlen(str[i]) + 1);
		res_ft_strcpy	= malloc(strlen(str[i]) + 1);
		strcpy(res_strcpy, str[i]);
		ft_strcpy(res_ft_strcpy, str[i]);
		printf("ft_strcpy: var %d. strcpy: %4lu, ft_strcpy: %4lu. Res: ",	i,
																			strlen(res_strcpy),
																			strlen(res_ft_strcpy));
		(strcmp(res_ft_strcpy, res_strcpy) != 0) ? printf("ERROR\n") : printf("OK\n");
		free (res_strcpy); res_strcpy = NULL;
		free (res_ft_strcpy); res_strcpy = NULL;	
		i++;
	}

	// test ft_strcmp
	printf("\nFT_STRCMP\n");
	i = 0;
	int res_strcmp = 0;
	int res_ft_strcmp = 0;
	while (i < 4)
	{
		j = i;
		while (j < 4)
		{
			res_strcmp = strcmp(str[i], str[j]);
			res_ft_strcmp = ft_strcmp(str[i], str[j]);
			printf("ft_strcmp: var %d-%d. strcmp: %4d, ft_strcmp: %4d.\tRes: ",	i,
																				j,
																				res_strcmp,
																				res_ft_strcmp);
			(res_strcmp != res_ft_strcmp) ? printf("ERROR\n") : printf("OK\n");
			j++;
		}
		i++;
	}

	// test ft_write
	printf("\nFT_WRITE\n");
	int fd[] = {
		1, -1, 
	};
	int write_errno;
	int ft_write_errno;
	i = 0;
	while (i < 2)
	{
		errno = 0;
		write(fd[i], "test write\n", 11);
		printf("errno: %d. Status: %s\n", errno, strerror(errno));
		write_errno = errno;
		errno = 0;
		ft_write(fd[i], "test ft_write\n", 14);
		printf("errno: %d. Status: %s\n", errno, strerror(errno));
		ft_write_errno = errno;
		printf("ft_write: var %d. write_errno: %4d, ft_strlen: %4d. Res: ",	i,
																			write_errno,
																			ft_write_errno);
		(write_errno != ft_write_errno) ? printf("ERROR\n") : printf("OK\n");
		i++;
	}
	printf("\ntrying write into file\n");
	int file_d = 0;
	file_d = open("write.txt", O_CREAT| O_WRONLY, 0755);
	errno = 0;
	ft_write(file_d, "test stirng in file", 19);
	printf("errno: %d. Status: %s\n", errno, strerror(errno));
	close(file_d);

	file_d = open("write.txt", O_CREAT | O_EXCL | O_WRONLY, 0755);
	errno = 0;
	ft_write(file_d, "test stirng in file", 19);
	printf("errno: %d. Status: %s\n", errno, strerror(errno));
	close(file_d);

	// test ft_read
	printf("\nFT_READ\n");
	int fd2[] = {
		0, -1, 
	};
	int read_errno;
	int ft_read_errno;
	char *tmp_buf = NULL;
	tmp_buf = malloc(100);
	i = 0;
	while (i < 2)
	{
		errno = 0;
		read(fd2[i], tmp_buf, 100);
		printf("errno: %d. Status: %s\n", errno, strerror(errno));
		read_errno = errno;
		errno = 0;
		ft_read(fd[i], tmp_buf, 100);
		printf("errno: %d. Status: %s\n", errno, strerror(errno));
		ft_read_errno = errno;
		printf("ft_write: var %d. write_errno: %4d, ft_strlen: %4d. Res: ",	i,
																			read_errno,
																			ft_read_errno);
		(read_errno != ft_read_errno) ? printf("ERROR\n") : printf("OK\n");
		i++;
	}
	printf("\ntrying read from file:\n");
	file_d = open("read.txt", O_RDONLY);
	int ret_read = 0;
	errno = 0;
	ret_read = ft_read(file_d, tmp_buf, 100);
	if (ret_read > 0)
	{
		tmp_buf[ret_read] = '\0';
		printf("read from file: %s\n", tmp_buf);
	}
	printf("errno: %d. Status: %s\n", errno, strerror(errno));
	close(file_d);

	file_d = open("wrong.txt", O_RDONLY);
	errno = 0;
	ret_read = ft_read(file_d, tmp_buf, 100);
	printf("errno: %d. Status: %s\n", errno, strerror(errno));
	close(file_d);
	free(tmp_buf); tmp_buf = NULL;
	tmp_buf = NULL;

	// test ft_strdup
	printf("\nFT_STRDUP\n");
	i = 0;
	char *res_strdup = NULL;
	char *res_ft_strdup = NULL;
	while (i < 4)
	{
		res_strdup = strdup(str[i]);
		res_ft_strdup = ft_strdup(str[i]);
		printf("ft_strdup: var %d. strdup: %4lu, ft_strdup: %4lu. Res: ",	i,
																			strlen(res_strdup),
																			strlen(res_ft_strdup));
		(strcmp(res_strdup, res_ft_strdup) != 0) ? printf("ERROR\n") : printf("OK\n");
		free(res_strdup); res_strdup = NULL;
		free(res_ft_strdup); res_strdup = NULL;
		i++;
	}

	return (0);
}
