#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "Graph.h"

graph_t *createGraph(const uint32_t num_verticies, const uint32_t num_edges)
{
    graph_t *graph = (graph_t *)malloc(sizeof(graph_t));

    if (NULL == graph)
    {
        return NULL;
    }

    const size_t verticies_size = num_verticies * sizeof(node_t *);
    node_t **verticies = (node_t **)malloc(verticies_size);

    if (NULL == verticies)
    {
        free(graph);

        return NULL;
    }

    for (uint32_t i = 0u; i < num_verticies; i++)
    {
        verticies[i] = NULL;
    }

    graph->verticies = verticies;
    graph->num_edges = num_edges;
    graph->num_verticies = num_verticies;

    return graph;
}

graph_t *freeGraph(graph_t *graph)
{
    if (NULL != graph->verticies)
    {
        free(graph->verticies);
    }

    if (NULL != graph)
    {
        free(graph);
    }

    return NULL;
}

void printGraph(const graph_t *const graph)
{
    if (NULL == graph)
    {
        return;
    }
}
