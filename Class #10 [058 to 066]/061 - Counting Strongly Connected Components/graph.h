// -------------------------------------------------------------
// Algorithms and Data Structures 2024/2025 - LEIC (FCUP/FEUP)
// http://www.dcc.fc.up.pt/~pribeiro/aulas/aed2425/
// -------------------------------------------------------------
// A simple lightweight graph class
// Last update: 24/11/2024
// -------------------------------------------------------------

#ifndef GRAPH_H
#define GRAPH_H

#include <iostream>
#include <string>
#include <vector>
#include <list>
#include <queue>
#include <stack>

class Graph {
  struct Edge {
    int dest;   // Destination node 
    int weight; // An integer weight
  };
	
  struct Node {
    std::list<Edge> adj; // The list of outgoing edges (to adjacent nodes)
    bool visited;        // Has the node been visited in a graph traversal?
  };
	
  int n;                   // Graph size (vertices are numbered from 1 to n)
  bool hasDir;             // false: undirected; true: directed
  std::vector<Node> nodes; // The list of nodes being represented
	
public:  
  // Constructor: nr nodes and direction (default: undirected)
  Graph(int num, bool dir = false) : n(num), hasDir(dir), nodes(num+1) {}
  
  // Add edge from source to destination with a certain weight
  void addEdge(int src, int dest, int weight = 1) {
    if (src<1 || src>n || dest<1 || dest>n) return;
    nodes[src].adj.push_back({dest, weight});
    if (!hasDir) nodes[dest].adj.push_back({src, weight});
  }
  
  // --------------------------------------------------------------
  
  // Read a graph in the format:
  // nr_nodes directed/undirected weighted/unweighted
  // nr_edges
  // src_1 dest_1 <weight_1>
  // src_2 dest_2 <weight_2>
  // ...
  // src_n dest_n <weight_n>
  static Graph *readGraph() {
    int n;
    std::string sdirection, sweight;
    std::cin >> n >> sdirection >> sweight;  
    bool directed = (sdirection == "directed")?true:false;
    bool weighted = (sweight == "weighted")?true:false;
  
    Graph *g = new Graph(n, directed);
    int e;
    std::cin >> e;
    for (int i=0; i<e; i++) {
      int u, v, w = 1;
      std::cin >> u >> v;
      if (weighted) std::cin >> w;
      g->addEdge(u, v, w);
    }
    return g;
  }

  // --------------------------------------------------------------
  // Depth-First Search (DFS): example implementation
  // --------------------------------------------------------------
  void dfs(int v) {
    std::cout << v << " "; // show node order
    nodes[v].visited = true;
    for (auto e : nodes[v].adj) {
      int w = e.dest;
      if (!nodes[w].visited)
        dfs(w);
    }
  }
  
  // --------------------------------------------------------------
  // Breadth-First Search (BFS): example implementation
  // --------------------------------------------------------------
  void bfs(int v) {
    for (int i=1; i<=n; i++) nodes[i].visited = false;
    std::queue<int> q; // queue of unvisited nodes
    q.push(v);
    nodes[v].visited = true;
    while (!q.empty()) { // while there are still unvisited nodes
      int u = q.front(); q.pop();      
      std::cout << u << " ";  // show node order
      for (auto e : nodes[u].adj) {
        int w = e.dest;
        if (!nodes[w].visited) {
          q.push(w);
          nodes[w].visited = true;
        }
      }
    }
  }
  
  
  // --------------------------------------------------------------

  // ---------------------------------------------------------
  // TODO: put the functions you need to implement below this
  // ---------------------------------------------------------
    
    //ex1
    //When called on an unweighted graph, 
    //the function should return the distance 
    //from node a to node b, that is, 
    //the length of the shortest path between 
    //node a and b. If there is no path, 
    //the function should return -1.
    int distance(int a, int b)
    {
        for (int i=1; i<=n; i++) nodes[i].visited = false;
        std::queue<int> q; 
        std::vector<int> dist(n+1, -1); //<--
        q.push(a);
        dist[a] = 0;    //<--
        nodes[a].visited = true;
        while(!q.empty())
        {
            int u = q.front(); q.pop();
            for(auto e : nodes[u].adj)
            {
                int w = e.dest;
                if(!nodes[w].visited)
                {
                    dist[w] = dist[u] + 1; //<--
                    q.push(w);
                    nodes[w].visited = true;
                }
            }
        }
        return dist[b];
    }

    //ex61
    //When called on an unweighted and directed graph, the function should return the number of strongly connected components of the graph. A directed graph is called strongly connected if there is a path in each direction between each pair of vertices of the graph
    int countSCCs() {
        // Step 1: Perform a DFS and store nodes in a stack based on their finishing times
        std::vector<bool> visited(n + 1, false);
        std::stack<int> finishStack;

        auto dfsFinish = [&](int v, auto& dfsFinishRef) -> void {
            visited[v] = true;
            for (auto e : nodes[v].adj) {
                if (!visited[e.dest]) {
                    dfsFinishRef(e.dest, dfsFinishRef);
                }
            }
            finishStack.push(v);
        };

        for (int i = 1; i <= n; i++) {
            if (!visited[i]) {
                dfsFinish(i, dfsFinish);
            }
        }

        // Step 2: Transpose the graph (reverse all edges)
        Graph transposedGraph(n, true);
        for (int u = 1; u <= n; u++) {
            for (auto e : nodes[u].adj) {
                transposedGraph.addEdge(e.dest, u);
            }
        }

        // Step 3: Perform DFS on the transposed graph in the order of the stack
        std::fill(visited.begin(), visited.end(), false);
        int sccCount = 0;

        auto dfsSCC = [&](int v, auto& dfsSCCRef) -> void {
            visited[v] = true;
            for (auto e : transposedGraph.nodes[v].adj) {
                if (!visited[e.dest]) {
                    dfsSCCRef(e.dest, dfsSCCRef);
                }
            }
        };

        while (!finishStack.empty()) {
            int v = finishStack.top();
            finishStack.pop();
            if (!visited[v]) {
                sccCount++;
                dfsSCC(v, dfsSCC);
            }
        }

        return sccCount;
    }

    
};

#endif