/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mschmit <mschmit@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/04/28 14:50:15 by mschmit           #+#    #+#             */
/*   Updated: 2015/04/28 16:58:24 by mschmit          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"
#include <pthread.h>
#include <stdio.h>


typedef struct s_philo
{
	int			life;
	pthread_t 	thread;
	char		status[10];

	int			starving_lvl;
}				t_philo;

mutex			baguette[NB_PHILO];

void	*testmythread(void *param)
{

	ft_printf("[%s]\n", param);
	return (param);
}

int		main(void)
{
	pthread_t	thread;
	int			ret;


	ret = pthread_create(&thread, NULL, testmythread, "Salut");
	ft_printf("ret (create)>> %d\n", ret);

	if ((ret = pthread_join(thread, NULL)) != 0)
		perror("pthread_join");
	ft_printf("ret (join)>> %d\n", ret);

	ret = pthread_detach(thread);
	ft_printf("ret (detach)>> %d\n", ret);



	return (0);
}
