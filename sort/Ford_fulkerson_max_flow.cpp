#include <limits.h>
#include <iostream>
#include <vector>
#include <queue>

int const V = 6;


bool bfs(int rGraph[V][V], int s, int t, int parent[])
{
    // create a visited array
    std::vector<bool> visited(V, false);

    std::queue<int> q;
    q.push(s);
    visited[s] = true;
    parent[s] = -1;


    while(!q.empty())
    {
        int u = q.front();
        q.pop();

        for(int v = 0; v < V; v++)
        {
            if(!visited[v] && rGraph[u][v] > 0)
            {
                q.push(v);
                parent[v] = u;
                visited[v] = true;
            }
        }
    }

    //reached sink in BFS
    return visited[t] == true;
}
int fordFulkerson(int graph[V][V], int s, int t)
{
    int u, v;

    //residual graph
    int rGraph[V][V];

    for (int row = 0; row < V; row++)
        for(int col = 0; col < V; col++)
            rGraph[row][col] = graph[row][col];
    
    //store the vertex of the path we found
    int parent[V];

    int max_flow = 0;

    while(bfs(rGraph, s, t, parent))
    {
        //find the max_flow in path 
        //through the path we found
        int path_flow = INT_MAX;
        //find max_flow from the end
        //which is parent[v]
        for(int v = t; v!=s; v=parent[v])
        {
           int u = parent[v];
           path_flow = std::min(rGraph[u][v], path_flow);
        }

        for (int v = t; v!=s; v=parent[v])
        {
            int u = parent[v];
            rGraph[u][v] -= path_flow;
            rGraph[v][u] += path_flow;
        }

        max_flow += path_flow;

    }

    return max_flow;
}

int main()
{

    int graph[V][V] = {{0, 16, 13, 0, 0, 0},
                       {0, 0, 10, 12, 0, 0},
                       {0, 4, 0, 0, 14, 0},
                       {0, 0, 9, 0, 0, 20},
                       {0, 0, 0, 7, 0, 4},
                       {0, 0, 0, 0, 0, 0}};
    
    int h[3] = {33, 33, 33};
    std::cout << fordFulkerson(graph, 0, 5) << std::endl;
}