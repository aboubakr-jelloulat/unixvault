/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dup.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ajelloul <ajelloul@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/12 16:47:28 by ajelloul          #+#    #+#             */
/*   Updated: 2025/06/12 19:18:39 by ajelloul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>

/*
 * Demonstrates the dup() system call
 * Creates a duplicate file descriptor
 */
int main(void)
{
    int fd;
    int fd_dup;

    fd = open("file.txt", O_CREAT | O_RDWR, 0644);
    if (fd == -1)
    {
        perror("Failed to open file");
        return (1);
    }
    printf("Original file descriptor: %d\n", fd);

    fd_dup = dup(fd);
    if (fd_dup == -1)
    {
        perror("dup failed");
        close(fd);
        return (1);
    }

    printf("Duplicated file descriptor: %d\n", fd_dup);
    
    write(fd, "Written through original fd\n", 27);
    write(fd_dup, "Written through duplicated fd\n", 29);
    
    close(fd);
    close(fd_dup);
    return (0);
}
