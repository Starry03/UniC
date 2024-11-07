//
// Created by andre on 8/8/2023.
//

#include "nodes.h"
#include <stdlib.h>

static t_node	EmptyNode(void)
{
	return ((t_node)NULL);
}

static t_node	Node_Allocate(void)
{
	return (t_node)malloc(sizeof(t_node_));
}

t_node	node_init(t_generic info)
{
	t_node	node;

	node = Node_Allocate();
	if (!node)
		return (EmptyNode());
	node->info = info;
	node->next = EmptyNode();
	return (node);
}

t_doublenode	DoubleNode_Init(t_generic info)
{
	t_doublenode	node;

	node = (t_doublenode)malloc(sizeof(t_doublenode_));
	if (!node)
		return ((t_doublenode)NULL);
	node->info = info;
	node->next = (t_doublenode)NULL;
	node->prev = (t_doublenode)NULL;
	return (node);
}
