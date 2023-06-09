#ifndef algos
#define algos
#include <chrono>
#include <vector>
#include <queue>
#include "graph_util.h"
#define INF INT_MAX

// Helper Functions and Definitions
typedef pair<int, int> intpair;

std::vector<int> get_adj_vert(Graph& graph, int v, vector<bool> &visited) {
    std::vector<int> adj_vert;
    for (int i = 0; i < graph.get_count(); i++) {
        if (graph.get_edge(v, i) < INF && !visited[i]) adj_vert.push_back(i);
    }
    return adj_vert;
}

// Algorithms
// Dijkstra's start
void dijkstra (Graph& graph, const short source) { 
    cout << "Dijkstra's Algorithm started!\n";
    auto start = std::chrono::high_resolution_clock::now();
    //  setup
    vector<int> dist(graph.get_count(), INT_MAX); std::priority_queue<intpair, std::vector<intpair>, std::greater<>> q;
    vector<bool> visited(graph.get_count(), false);
    q.emplace(0, source);
    dist[source] = 0;

    while (!q.empty()) {    // O(logn)
        int u = q.top().second; // u is selected vertex
        visited[u] = true;
        std::vector<int> adj_vert_list = get_adj_vert(graph, u, visited); // create a list of vertices that are adjacent to the selected one O(n)

        for (int v: adj_vert_list) {   // for each vertex listed in adj_vert_list O(n)
            int weight = graph.get_edge(u, v);

            if (dist[u] + weight < dist[v]) {   // if the distance from the source to the vertex at the top of the queue, plus the weight of the edge spanning that vertex and the currently selected vertex in the loop is less than the distance from the source to the currently selected vertex
                dist[v] = dist[u] + weight;     // update the dist from source to selected to that ^
                q.emplace(dist[v],v);          // insert vertex v and its distance from the source into the priority queue
            }
        }
        q.pop();
    }
    for (int i = 0; i < graph.get_count(); i++) {
        cout << "Distance from source to vertex " << i << " is " << dist[i] << '\n';
    }
    auto stop = std::chrono::high_resolution_clock::now();
    auto duration = std::chrono::duration_cast<std::chrono::microseconds>(stop - start);
    cout << "Time taken: "<< duration.count() << " microseconds." << endl;
}
// END Dijkstra's

// Bellman-Ford Start
void bellman_ford(Graph& graph, const short source) { // O(VE) aka "n^2"
    cout << "Bellman-Ford Algorithm started!\n";
    auto start = std::chrono::high_resolution_clock::now();
    // setup
    vector<long long> dist(graph.get_count(), LLONG_MAX); // Initialize all vertices as infinitely far from source
    dist[source] = 0; // Set source's distance from the source to 0

    for (int u = 0; u < graph.get_count(); u++) { // For every vertex u in graph
        for (int v = 0; v < graph.get_count(); v++) { // For every edge connected to the currently selected vertex u,
            int weight = graph.get_edge(u, v);  // set weight equal to current edge length
            if ((dist[u] != LLONG_MAX) && (dist[u] + weight < dist[v])) {
                dist[v] = dist[u] + weight;
            }
        }
    }

    // Check for negative cycles
    for (int u = 0; u < graph.get_count(); u++) { // For every vertex u in graph
        for (int v = 0; v < graph.get_count(); v++) { // For every edge connected to the currently selected vertex u,
            int weight = graph.get_edge(u, v);  // set weight equal to current edge length
            if ((dist[u] != LLONG_MAX) && (dist[u] + weight < dist[v])) { // If there are further reductions in edge length
                cout << "Negative cycle detected!\n"; // Then a negative cycle has been detected.
                return;
            }
        }
    }
    // Output
    for (int i = 0; i < graph.get_count(); i++) {
        cout << "Distance from source to vertex " << i << " is " << dist[i] << '\n';
    }
    auto stop = std::chrono::high_resolution_clock::now();
    auto duration = std::chrono::duration_cast<std::chrono::microseconds>(stop - start);
    cout << "Time taken: "<< duration.count() << " microseconds." << endl;
}
// END Bellman-Ford


#endif //algos