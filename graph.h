#include "edge.h"
#include <vector>

typedef std::vector<Edge*> AdjacencyList;

//Skiena implementation
class Graph {
public:
    Graph(bool directed, unsigned int novertices);
    ~Graph();
    void insert_edge(vertex from, vertex to, weight w=0);
    void BFS(vertex root);
    void DFS(vertex root);
    class TraversalCallbacks 
    {
    public:
        virtual void pre_process_vertex(vertex v) = 0;
        virtual void post_process_vertex(vertex v) = 0;
        virtual void process_edge(vertex from, vertex to) = 0;
    };
    void set_callback(TraversalCallbacks* cb) {
        cb_ = cb;
    }
private:
    enum class State {
        undiscovered,
        discovered,
        processed
    };
    unsigned int novertices_;
    unsigned int noedges_;
    AdjacencyList edges_;
    bool directed_;
    TraversalCallbacks *cb_;

    inline void pre_process_vertex(vertex v) {
        if (cb_) cb_->pre_process_vertex(v);
    }
    inline void post_process_vertex(vertex v) {
        if (cb_) cb_->post_process_vertex(v);
    }
    inline void process_edge(vertex from, vertex to) {
        if (cb_) cb_->process_edge(from, to);
    }

    void insert_edge_util(vertex from, vertex to, weight w, bool directed);
    void DFSutil(vertex v, std::vector<State>& state);
};