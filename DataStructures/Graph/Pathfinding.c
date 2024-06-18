#include "../Heap/Heap.h"
#include "Graph.h"

/**
 * @brief Dikstra's algorithm for finding the shortest path in a graph.
 * @note min_heap_entry: {distance: uint64_t, vertex: Vertex}
 */
LinkedList	Dikstra(Graph graph, Vertex src, Vertex dest)
{
	t_heap		min_heap;
	LinkedList	vertices;
	LinkedList	edges;
	Vertex		min_vertex;
	Edge		edge;
	LinkedList	path;

	vertices = graph->adjacency_list;
	min_heap = Heap_init(LinkedList_Size(vertices), &cmp_vertex_distance,
			&free_heap_entry, true);
	if (!min_heap)
		return (NULL);
	while (vertices)
	{
		Heap_Insert(min_heap, 0, vertices->info);
		vertices = LinkedList_GetNext(vertices);
	}
	Vertex_InitSingleSource(graph, src);
	vertices = graph->adjacency_list;
	while (min_vertex = (Vertex)Heap_GetMin(min_heap))
	{
		edges = min_vertex->edges;
		while (edges)
		{
			edge = (Edge)(LinkedList_GetInfo(edges));
			Edge_Relax(min_vertex, edge->dest, edge->weight);
		}
	}
	Heap_Free(min_heap);
	while (dest)
	{
		LinkedList_Push(&path, dest);
		dest = dest->predecessor;
	}
	return (path);
}
