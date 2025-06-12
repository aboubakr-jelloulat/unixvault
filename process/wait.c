/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wait.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ajelloul <ajelloul@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/12 16:47:28 by ajelloul          #+#    #+#             */
/*   Updated: 2025/06/12 19:19:12 by ajelloul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <unistd.h>
#include <sys/wait.h>

/*
 * Demonstrates the wait() system call
 * Shows how parent waits for child process to complete
 */
int main(void)
{
    pid_t pid;

    pid = fork();
    if (pid == -1)
    {
        perror("fork failed");
        return (1);
    }

    if (pid == 0)
    {
        printf("Child process: Starting work...\n");
        sleep(2); // Simulate work
        printf("Child process: Work complete!\n");
    }
    else
    {
        printf("Parent process: Waiting for child (PID: %d)...\n", pid);
        wait(NULL); // Wait for any child to finish
        printf("Parent process: Child finished, continuing...\n");
    }

    return (0);
}
