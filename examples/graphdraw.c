#include "unic/comparators.h"
#include "unic/dealloc.h"
#include "unic/examples.h"
#include "unic/graph.h"
#include "unic/heap.h"
#include "unic/logging.h"

void	test_graph(void)
{
	t_graph	graph;

	graph = get_example_graph();
	graph_generate_mermaid(graph,
		"../examples/graph.md",
		MERMAID_HORIZONAL);
	logging_log(LOG_INFO, "Graph generated in examples/graph.md");
	graph_free(graph);
}

int	main(void)
{
	test_graph();
	return (0);
}
