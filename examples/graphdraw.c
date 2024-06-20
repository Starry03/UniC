#include "DataStructures/Graph/Graph.h"
#include "DataStructures/Heap/Heap.h"
#include "Utils/Compare/comparators.h"
#include "examples.h"

#include "Utils/Dealloc/Dealloc.h"

void	test_graph(void)
{
	Graph graph;

	graph = get_example_graph();
	Graph_GenerateMermaid(graph, "examples/graph.md", MERMAID_HORIZONAL);
	Graph_Free(graph);
}

int	main(int argc, char const *argv[])
{
	(void)argc;
	(void)argv;
	test_graph();
	return (0);
}
