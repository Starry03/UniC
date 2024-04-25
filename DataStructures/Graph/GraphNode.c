#include "../../DataStructures/LinkedList/LinkedList.h"
#include "../../Utils/types.h"
#include "GraphNode.h"
#include <stdbool.h>
#include <stdlib.h>

#define ID_ERROR 0

typedef struct s_graphnode
{
	bool		visited;
	size_t		id;
	LinkedList	edges;
	Generic		info;
	void		(*dealloc)(Generic);
}				t_graphnode;

GraphNode	GraphNode_Init(size_t id, Generic info, void (*dealloc)(Generic))
{
	GraphNode	node;

	node = (GraphNode)malloc(sizeof(t_graphnode));
	if (!node)
		return (NULL);
	node->id = id;
	node->info = info;
	node->visited = false;
	node->dealloc = dealloc;
	return (node);
}

void	GraphNode_Free(Generic node)
{
	GraphNode	g_node;

	if (!node)
		return ;
	g_node = (GraphNode)node;
	if (g_node->dealloc)
		g_node->dealloc(g_node->info);
	LinkedList_Dealloc(g_node->edges, GraphNode_Free);
	free(node);
}

Generic	GraphNode_GetInfo(GraphNode node)
{
	if (!node)
		return (NULL);
	return (node->info);
}
size_t	GraphNode_GetId(GraphNode node)
{
	if (!node)
		return (ID_ERROR);
	return (node->id);
}

void	GraphNode_AddEdge(GraphNode from, GraphNode to)
{
	if (!from || !to)
		return ;
	LinkedList_Push(&from->edges, to);
}

void	GraphNode_RemoveEdge(GraphNode from, GraphNode to)
{
	LinkedList	node;
	GraphNode	edge;

	if (!from || !to)
		return ;
	node = from->edges;
	while (node)
	{
		edge = (GraphNode)node->info;
		if (edge->id == to->id)
		{
			LinkedList_Remove(&node, &GraphNode_Free);
			break ;
		}
		node = LinkedList_GetNext(node);
	}
}

void	Graph_AddDoubleEdge(GraphNode from, GraphNode to)
{
	GraphNode_AddEdge(from, to);
	GraphNode_AddEdge(to, from);
}
void	Graph_RemoveDoubleEdge(GraphNode from, GraphNode to)
{
	GraphNode_RemoveEdge(from, to);
	GraphNode_RemoveEdge(to, from);
}
