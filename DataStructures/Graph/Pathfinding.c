#include "../Dictionary/Dictionary.h"
#include "../Heap/Heap.h"
#include "Graph.h"
#include <stdlib.h>

static int	cmp_dist(Generic a, Generic b)
{
	return (*(int *)(a) - *(int *)(b));
}

/**
 * @brief Dikstra's algorithm for finding the shortest path in a graph.
 * @note min_heap_entry: {distance: uint64_t, vertex: Vertex}
 */
LinkedList	Dikstra(Graph graph, Vertex src, Vertex dest)
{
	LinkedList		path;
	t_heap			min_heap;
	t_heap_entry	min_heap_entry;
	t_dict			hash_map;
	LinkedList		vertices;
	LinkedList		edges;
	Vertex			min_vertex;
	Edge			edge;
	uint64_t		*k;

	vertices = graph->adjacency_list;
	min_heap = Heap_init(LinkedList_Size(vertices), &cmp_dist, &free_heap_entry,
			true);
	hash_map = Dict_Init(LinkedList_Size(vertices));
	if (!min_heap)
		return (NULL);
	Vertex_InitSingleSource(graph, src);
	while (vertices)
	{
		k = malloc(sizeof(uint64_t));
		*k = ((Vertex)LinkedList_GetInfo(vertices))->distance;
		min_heap_entry = HeapEntry_init(k, LinkedList_GetInfo(vertices));
		Heap_Insert(min_heap, min_heap_entry);
		Dict_Add(&hash_map, ((Vertex)LinkedList_GetInfo(vertices)),
			min_heap_entry, &Vertex_Hash, NULL, NULL, &Vertex_CmpId);
		vertices = LinkedList_GetNext(vertices);
	}
	vertices = graph->adjacency_list;
	while ((min_vertex = (Vertex)Heap_GetMin(min_heap)))
	{
		edges = min_vertex->edges;
		while (edges)
		{
			edge = (Edge)(LinkedList_GetInfo(edges));
			Edge_Relax(min_vertex, edge->dest, edge->weight);
			min_heap_entry = (t_heap_entry)Dict_Get(hash_map, edge->dest,
					&Vertex_Hash, &Vertex_CmpId);
			// TODO: end
		}
	}
	Heap_Free(min_heap);
	Dict_Free(hash_map);
	while (dest)
	{
		LinkedList_Push(&path, dest);
		dest = dest->predecessor;
	}
	return (path);
}
