#ifndef IGRAPH_H_
#define IGRAPH_H_

#include <iostream>
#include <vector>
#include <unordered_set>

struct IGraph {
    virtual ~IGraph() {}

    // ���������� ����� �� from � to.
    virtual void AddEdge(int from, int to) = 0;

    virtual int VerticesCount() const = 0;

    virtual std::vector<int> GetNextVertices(int vertex) const = 0;
    virtual std::vector<int> GetPrevVertices(int vertex) const = 0;
};

#endif // IGRAPH_H_