#include "datastructures/graph/graph.h"
#include "datastructures/heap/heap.h"
#include "Utils/compare/comparators.h"
#include "examples.h"

#include "utils/dealloc/dealloc.h"

void	test_graph(void)
{
	t_graph graph;

	graph = get_example_graph();
	graph_generate_mermaid(graph, "examples/graph.md", MERMAID_HORIZONAL);
	graph_free(graph);
}

int	main(void)
{
	test_graph();
	return (0);
}
