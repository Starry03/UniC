#ifndef GRAPHNODE_H
# define GRAPHNODE_H

# include <stddef.h>

typedef struct s_graphnode	t_graphnode;
typedef t_graphnode			*GraphNode;

GraphNode					GraphNode_Init(size_t id, Generic info, void (*dealloc)(Generic));
void						GraphNode_Free(Generic node);

Generic						GraphNode_GetInfo(GraphNode node);
size_t						GraphNode_GetId(GraphNode node);

void						GraphNode_AddEdge(GraphNode from, GraphNode to);
void						GraphNode_RemoveEdge(GraphNode from, GraphNode to);

void						Graph_AddDoubleEdge(GraphNode from, GraphNode to);
void                        Graph_RemoveDoubleEdge(GraphNode from, GraphNode to);

#endif