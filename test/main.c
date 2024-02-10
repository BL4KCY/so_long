
#include <stdio.h>
// #include <errno.h>
#include <stdlib.h>
#include <fcntl.h>
#include <mlx.h>
#include "so_long.h"




int main(void)
{
	t_list	*queue;
	int		current[2];
	int		right[2];
	int		lift[2];
	int		up[2];
	int		down[2];



	current[0] = 1;
	current[1] = 2;
	right[0] = 3;
	right[1] = 4;
	lift[0] = 5;
	lift[1] = 6;
	up[0] = 7;
	up[1] = 8;
	down[0] = 9;
	down[1] = 10;
	queue = ft_lstnew(&current);
	ft_lstadd_back(&queue, ft_lstnew(&right));
	ft_lstadd_back(&queue, ft_lstnew(&lift));
	ft_lstadd_back(&queue, ft_lstnew(&up));
	ft_lstadd_back(&queue, ft_lstnew(&down));
	printf("%d\n", *(int *)queue->content);
	printf("%d\n", *(int *)queue->next->content);
	printf("%d\n", *(int *)queue->next->next->content);
	printf("%d\n", *(int *)queue->next->next->next->content);
	printf("%d\n", *(int *)queue->next->next->next->next->content);
	return (0);
}
