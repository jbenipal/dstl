#pragma once

namespace dstl {
    typedef unsigned int vertex;
    typedef int weight;

    class Edge {
    public:
        Edge(vertex n, weight w, Edge *next = nullptr)
            : node(n)
            , weight(w)
            , next(next) {}

        vertex node;
        weight weight;
        Edge* next;

        Edge* operator++() {
            return next;
        }
    };
}