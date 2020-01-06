#include "monty.h"

/**
 * push - Entry Point
 * @element: is the element to be added to new node if needed
 * @head: head node of linked list
 * Description: the new added element.)?
 */

void push(stack_t **head, unsigned int line)
{

	stack_t *new;
	char *digit;
	int num = 0;

	digit = strtok(NULL, " \n\t");

	if (isdigit(digit) == 0)
	{
		dprintf(STDERR_FILENO, "L<%u>: usage: push integer\n", line);
		exit(EXIT_FAILURE);
	}
	num = atoi(digit);

	new = (stack_t *) malloc(sizeof(stack_t));

	if (new == NULL)
	{
		dprintf(STDERR_FILENO, "Error: malloc failed\n");
		exit(EXIT_FAILURE);
	}

	new->n = num;

	new->next = (*head);
	new->prev = NULL;

	if ((*head) != NULL)
	{
		(*head)->prev = new;
	}

	(*head) = new;

}

/* seperate function for error calls */
