
#include <vector>
#include <utility>
#include <queue>
#include <iostream>
#include <functional>
#include <limits.h>

typedef std::pair<int, int> iPair;
// for each vertext, we have a adj_list
typedef std::vector<iPair> adj_list;

class Graph
{
    int V_num;

    std::vector<adj_list> adj_lists;

  public:
    Graph(int V);
    void addEdge(int v, int u, int w);
    void shortestPath(int s);
};

Graph::Graph(int V_num)
{
    this->V_num = V_num;
    adj_lists = std::vector<adj_list>(V_num);
}

void Graph::addEdge(int u, int v, int w)
{
    adj_lists[u].push_back(std::make_pair(v, w));
    adj_lists[v].push_back(std::make_pair(u, w));
}

void Graph::shortestPath(int src)
{
    std::priority_queue<iPair, adj_list, std::greater<iPair>> pq;

    // to store the distance from src to each vertext
    // int the graph
    std::vector<int> dist(V_num, INT_MAX);

    // first element is distance
    // second element is vertex index
    pq.push(std::make_pair(0, src));
    dist[src] = 0;

    while (!pq.empty())
    {
        //sort the distance form vertex src
        // to each vertex in the graph

        // u is a vertex which has the shortest
        //distance  from src in the queue.
        int u = pq.top().second;
        pq.pop();

        // iter through adjacent vertex to u
        // find the shortest distance from
        // u to its adjancent vertex, and update
        // dist array
        for (adj_list::iterator iter = adj_lists[u].begin(); iter != adj_lists[u].end(); iter++)
        {
            int vertex = (*iter).first;
            int weight = (*iter).second;

            if (dist[vertex] > dist[u] + weight)
            {
                dist[vertex] = dist[u] + weight;
                pq.push(std::make_pair(dist[vertex], vertex));
            }
        }
    }
    for (int i = 0; i < V_num; ++i)
        std::cout << i << "\t\t" << dist[i] << std::endl;
}

int main()
{
    // create the graph given in above fugure
    int V = 9;
    Graph g(V);

    //  making above shown graph
    g.addEdge(0, 1, 4);
    g.addEdge(0, 7, 8);
    g.addEdge(1, 2, 8);
    g.addEdge(1, 7, 11);
    g.addEdge(2, 3, 7);
    g.addEdge(2, 8, 2);
    g.addEdge(2, 5, 4);
    g.addEdge(3, 4, 9);
    g.addEdge(3, 5, 14);
    g.addEdge(4, 5, 10);
    g.addEdge(5, 6, 2);
    g.addEdge(6, 7, 1);
    g.addEdge(6, 8, 6);
    g.addEdge(7, 8, 7);

    g.shortestPath(0);

    return 0;
}