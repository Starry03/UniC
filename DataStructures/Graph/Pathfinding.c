#include "../../Utils/Dealloc/Dealloc.h"
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
}
