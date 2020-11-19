#ifndef _GRAPH_H_
#define _GRAPH_H_

#include <iostream> 
#include <utility> 
#include <limits.h>
#include <vector>
#include <list>
#include <queue>
#include <stack>
#include <set>

using namespace std;

template <class T>
class GraphVertexWeighted
{
private:
    T val;
    std::vector<std::pair<int, float> > adj;
public: 
    ~GraphVertexWeighted() {};
    GraphVertexWeighted() {};
    GraphVertexWeighted(T _val) {val = _val;};

    T get_val() {return val;};
    void set_val(T _val) {val = _val;};

    std::vector<std::pair<int, float> > get_adj() {return adj;};
    void add_to_adj(int idx, float weight) {adj.push_back(std::make_pair(idx, weight));};
};


template <class T>
class GraphWeighted
{
private:
    std::vector<GraphVertexWeighted<T> > nodes;
    bool is_directed;

public:
    ~GraphWeighted() {};
    GraphWeighted() {is_directed=false;};

    void add_node(T val)
    {
        GraphVertexWeighted<T> node(val);
        nodes.push_back(node);
    };

    void add_edge(int src, int dst, float weight)
    {
        nodes[src].add_to_adj(dst, weight);
        if (!is_directed)
            nodes[dst].add_to_adj(src, weight);
    };

    T get_node_val(int i)
    {
        return nodes[i].get_val();
    };

    std::vector<float> shortest_path(int s)
    {
        vector<float> distance(nodes.size(), INT_MAX);
        set<pair<int, float>> node_length;

        distance[s] = 0;
        node_length.insert(make_pair(0, s));

        while (!node_length.empty())
        {
            pair<int, float> top = *node_length.begin();
            node_length.erase(node_length.begin());

            int source_node = top.second;
            for (auto& it: nodes[source_node].get_adj())
            {
                int adj_node = it.first;
                int length_to_adjnode = it.second;

                if (distance[adj_node] > length_to_adjnode + distance[source_node])
                {
                    if (distance[adj_node] != INT_MAX)
                    {
                        node_length.erase(node_length.find(make_pair(distance[adj_node], adj_node)));
                    }
                    distance[adj_node] = length_to_adjnode + distance[source_node];
                    node_length.insert(make_pair(distance[adj_node], adj_node));
                }
            }
        }

        return distance;
    };
};



#endif