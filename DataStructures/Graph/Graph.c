#include "DataStructures/LinkedList/LinkedList.h"
#include "Graph.h"
#include "GraphNode.h"
#include <stdlib.h>

typedef struct s_graph
{
	LinkedList	adjacency_list;
}				t_graph;

/**
 * @brief Initializes a graph with a given number of vertices.
 *
 * @return Graph A pointer to the graph.

*/
Graph	Graph_Init(void)
{
	Graph	graph;

	graph = (Graph)malloc(sizeof(t_graph));
	if (!graph)
		return (NULL);
	graph->adjacency_list = EmptyList();
	return (graph);
}

/**
 * @brief Frees the memory allocated for the graph.
 *
 * @param graph The graph to be freed.
 */
void	Graph_Free(Graph graph)
{
	LinkedList_Dealloc(graph->adjacency_list, &GraphNode_Free);
	free(graph);
}

void	Graph_AddVertex(Graph graph, Generic value, void (*dealloc)(Generic))
{
	static size_t	id = 1;
	GraphNode		node;

	if (!graph || !value)
		return ;
	node = GraphNode_Init(id++, value, dealloc);
	LinkedList_Push(graph->adjacency_list, node);
}
