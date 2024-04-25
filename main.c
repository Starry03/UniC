#include "DataStructures/Graph/Graph.h"
#include "./Utils/Dealloc/Dealloc.h"

int	main(int argc, char const *argv[])
{
	Graph	graph;

	graph = Graph_Init();

	Graph_AddVertex(graph, 100, NULL);

	Graph_Free(graph);

	return (0);
}
