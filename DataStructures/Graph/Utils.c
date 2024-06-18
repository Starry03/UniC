#include "../Heap/Heap.h"
#include "Graph.h"
#include <limits.h>

void	Vertex_InitSingleSource(Graph graph, Vertex src)
{
	LinkedList	vertices;
	Vertex		vertex;

	vertices = graph->adjacency_list;
	while (vertices)
	{
		vertex = (Vertex)(vertices->info);
		vertex->distance = UINT64_MAX;
		vertex->time = 0;
		vertex->status = VERTEX_UNVISITED;
		vertex->predecessor = NULL;
		vertices = LinkedList_GetNext(vertices);
	}
	src->distance = 0;
}

bool	Edge_Relax(Vertex src, Vertex dest, uint64_t weight)
{
	if (dest->distance <= src->distance + weight)
		return (false);
	dest->distance = src->distance + weight;
	dest->predecessor = src;
	return (true);
}

int	cmp_vertex_distance(Generic a, Generic b)
{
	Vertex	vertex_a;
	Vertex	vertex_b;

	vertex_a = (Vertex)a;
	vertex_b = (Vertex)b;
	if (vertex_a->distance < vertex_b->distance)
		return (-1);
	if (vertex_a->distance > vertex_b->distance)
		return (1);
	return (0);
}

inline void	free_heap_entry(Generic entry)
{
	free((t_heap_entry)entry);
}
