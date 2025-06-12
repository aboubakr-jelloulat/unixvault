/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dup2.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ajelloul <ajelloul@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/12 16:47:28 by ajelloul          #+#    #+#             */
/*   Updated: 2025/06/12 19:18:50 by ajelloul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>

/*
 * Demonstrates the dup2() system call
 * Redirects stdout to a file
 */
int main(void)
{
    int fd;

    fd = open("output.txt", O_CREAT | O_WRONLY | O_TRUNC, 0644);
    if (fd == -1)
    {
        perror("Failed to open file");
        return (1);
    }

    if (dup2(fd, STDOUT_FILENO) == -1)
    {
        perror("dup2 failed");
        close(fd);
        return (1);
    }

    printf("This will be written to output.txt instead of terminal\n");
    printf("Because stdout has been redirected to the file\n");
    
    close(fd);
    return (0);
}
