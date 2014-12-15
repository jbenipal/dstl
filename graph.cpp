#include "graph.h"
#include <queue>

namespace dstl {
    Graph::Graph(bool directed, unsigned int novertices)
        : novertices_(novertices)
        , noedges_(0)
        , directed_(directed)
        , edges_(novertices + 1)
        , cb_(nullptr)
    {
        for (auto i = 1; i <= novertices_; ++i) {
            edges_[i] = nullptr;
        }
    }

    Graph::~Graph()
    {
        for (auto &edge : edges_) {
            Edge *p = edge;
            while (p) {
                Edge *temp = p->next;
                delete p;
                p = temp;
            }
        }
    }

    void
        Graph::insert_edge(vertex from, vertex to, weight w)
    {
            insert_edge_util(from, to, w, directed_);
        }

    void
        Graph::insert_edge_util(vertex to, vertex from, weight w, bool directed)
    {
            //TODO/Replace with smart_ptr?
            Edge* edge = new Edge(to, w, edges_[from]);
            edges_[from] = edge;

            if (!directed) {
                insert_edge_util(to, from, w, true);
            }
        }

    void
        Graph::BFS(vertex v)
    {
            std::vector<State> state(novertices_ + 1);
            std::vector<vertex> parents(novertices_ + 1);

            std::for_each(std::begin(state), std::end(state), [](State& state) {
                state = State::undiscovered;
            });

            std::for_each(std::begin(parents), std::end(parents), [](vertex& v) {
                v = 0;
            });

            std::queue<vertex> q;
            q.push(v);
            state[v] = State::discovered;
            while (!q.empty()) {
                vertex t = q.front();
                q.pop();
                pre_process_vertex(t);
                Edge *e = edges_[t];
                while (e) {
                    if (state[e->node] == State::processed || directed_) {
                        process_edge(t, e->node);
                    }
                    if (state[e->node] == State::undiscovered) {
                        state[e->node] = State::discovered;
                        parents[e->node] = t;
                        q.push(e->node);
                    }
                    e = e->next;
                }
                state[t] = State::processed;
                post_process_vertex(t)
            }
        }

    void
        Graph::DFS(vertex root)
    {
            std::vector<State> state(novertices_ + 1);
            std::for_each(std::begin(state), std::end(state), [](State& state) {
                state = State::undiscovered;
            });

            DFSutil(root, state);
        }

    void
        Graph::DFSutil(vertex v, std::vector<State>& state)
    {
            state[v] = State::discovered;
            pre_process_vertex(v);
            Edge *p = edges_[v];
            while (p) {
                if (state[p->node] == State::undiscovered)
                {
                    process_edge(v, p->node);
                    DFSutil(p->node, state);
                }
                if (state[p->node] != State::processed || directed_) {
                    //Related to back_edge. Do not completely understand.
                    //process_edge(v, p->node);
                }
                p = p->next;
            }
            state[v] = State::processed;
            post_process_vertex(v);
        }
}