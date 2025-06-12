/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   access.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ajelloul <ajelloul@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/12 16:47:28 by ajelloul          #+#    #+#             */
/*   Updated: 2025/06/12 19:18:24 by ajelloul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <unistd.h>

/*
 * Demonstrates the access() system call
 * Checks file permissions and existence
 */
int main(void)
{
    int acc;

    acc = access("file.txt", F_OK | R_OK | W_OK);
    if (acc == 0)
    {
        printf("File exists and has read/write permissions\n");
    }
    else
    {
        perror("Access failed");
        return (1);
    }
    return (0);
}
