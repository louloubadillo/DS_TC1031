#ifndef _GRAPH_H_
#define _GRAPH_H_

#include<iostream> 
#include <list>
#include <vector>
#include <queue>
#include <stack>

template <class T>
class GraphVertex
{
private:
    T val;
    std::vector<int> adj;
public: 
    ~GraphVertex() {};
    GraphVertex() {};
    GraphVertex(T _val) {val = _val;};

    T get_val() {return val;};
    void set_val(T _val) {val = _val;};

    std::vector<int> get_adj() {return adj;};
    void add_to_adj(int idx) {adj.push_back(idx);};
};

template <class T>
class Graph
{
private:
    std::vector<GraphVertex<T>> nodes;
    bool is_directed;

public:
    ~Graph() {};
    Graph() {is_directed=false;};

    void add_node(T val)
    {
        GraphVertex<T> node(val);
        nodes.push_back(node);
    };

    void add_edge(int src, int dst)
    {
        nodes[src].add_to_adj(dst);
        if (!is_directed)
            nodes[dst].add_to_adj(src);
    };

    void BFS(int start_vertex)
    {
        std::vector<int> visited(nodes.size(), 0); 
        std::queue<int> neighbors; 
        visited.at(start_vertex) = 1; 
        std::cout << nodes.at(start_vertex).get_val() << " "; 
        std::vector<int> adjacents; 
        adjacents = nodes.at(start_vertex).get_adj(); 
        for(int i = 0; i < adjacents.size(); i++){
            neighbors.push(adjacents.at(i)); 
        }
        while(!neighbors.empty()){
            int temp = neighbors.front(); 
            if(visited.at(temp) == 0){
                visited.at(temp) = 1; 
                std::cout << nodes.at(temp).get_val() << " "; 
                std::vector<int> adjacents;
                adjacents = nodes.at(temp).get_adj();
                for(int i=0; i<adjacents.size();i++){
                    neighbors.push(adjacents.at(i));
                }
            }
            neighbors.pop();
        }

        std::cout << std::endl;
    };

    void DFS(int start_vertex)
    {
        std::vector<int> visited(nodes.size(), 0);
        std::stack<int> neighbors;
        visited.at(start_vertex)=1;
        std::cout << nodes.at(start_vertex).get_val() << " ";
        std::vector<int> adjacents;
        adjacents=nodes.at(start_vertex).get_adj();
        for(int i=0; i<adjacents.size();i++)
        {
            neighbors.push(adjacents.at(i));
        }
        while(!neighbors.empty())
        {
            int temp = neighbors.top();
            neighbors.pop();
            if(visited.at(temp)==0)
            {
                visited.at(temp)=1;
                std::cout << nodes.at(temp).get_val() << " ";
                std::vector<int> adjacents;
                adjacents=nodes.at(temp).get_adj();
                for(int i=0; i<adjacents.size();i++)
                {
                    neighbors.push(adjacents.at(i));
                }
            }   
        }
        std::cout << std::endl;
    }
};

#endif