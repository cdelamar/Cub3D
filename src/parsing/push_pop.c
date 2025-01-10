#include "cub3d.h"

t_queue	*init_queue(void)
{
	t_queue	*q;

	q = malloc(sizeof(t_queue));
	if (!q)
		return (NULL);
	q->front = 0;
	q->back = 0;
	q->capacity = CAPACITY;
	q->queue_y = malloc(sizeof(int) * q->capacity);
	if (!q->queue_y)
		return (NULL);
	q->queue_x = malloc(sizeof(int) * q->capacity);
	if (!q->queue_x)
		return (NULL);
	return (q);
}

int	expand_queue(t_queue *q)
{
	int	*new_y;
	int	*new_x;
	int	i;
	int	new_capacity;

	new_capacity = q->capacity * 2;
	new_y = malloc(sizeof(int) * new_capacity);
	if (!new_y)
		return (0);
	new_x = malloc(sizeof(int) * new_capacity);
	if (!new_x)
		return (0);
	i = 0;
	while (i < q->capacity)
	{
		new_y[i] = q->queue_y[i];
		new_x[i] = q->queue_x[i];
		i++;
	}
	free(q->queue_y);
	free(q->queue_x);
	q->queue_y = new_y;
	q->queue_x = new_x;
	q->capacity = new_capacity;
	return (1);
}

void	push_queue(t_queue *q, int y, int x)
{
	if (q->back >= q->capacity)
	{
		if (!expand_queue(q))
			return ;
	}
	q->queue_y[q->back] = y;
	q->queue_x[q->back] = x;
	q->back++;
}

int	pop_queue(t_queue *q, int *y, int *x)
{
	if (q->front == q->back)
		return (0);
	*y = q->queue_y[q->front];
	*x = q->queue_x[q->front];
	q->front++;
	return (1);
}

void	free_queue(t_queue *q)
{
	if (q->queue_y)
		free(q->queue_y);
	if (q->queue_x)
		free(q->queue_x);
	free(q);
}
