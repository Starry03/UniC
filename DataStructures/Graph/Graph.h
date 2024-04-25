#ifndef GRAPH_H
# define GRAPH_H

# include "../../Utils/types.h"
# include <stddef.h>

typedef struct s_graph	t_graph;

typedef t_graph			*Graph;

Graph					Graph_Init(void);
void					Graph_AddVertex(Graph graph, Generic value,
							void (*dealloc)(Generic));
void					Graph_Free(Graph graph);

#endif // !GRAPH_H
