/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fork.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ajelloul <ajelloul@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/12 16:47:28 by ajelloul          #+#    #+#             */
/*   Updated: 2025/06/12 19:19:01 by ajelloul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <unistd.h>
#include <sys/wait.h>

/*
 * Demonstrates basic fork() functionality
 * Shows parent and child process differentiation
 */
int main(void)
{
    pid_t pid;

    printf("Before fork()\n");
    pid = fork();
    
    if (pid == -1)
    {
        perror("fork failed");
        return (1);
    }

    if (pid == 0)
    {
        printf("Child process: PID = %d, Parent PID = %d\n", 
               getpid(), getppid());
    }
    else
    {
        printf("Parent process: PID = %d, Child PID = %d\n", 
               getpid(), pid);
        wait(NULL); // Wait for child to finish
    }

    printf("This message is from %s\n", (pid == 0) ? "child" : "parent");
    return (0);
}
