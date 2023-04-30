#ifndef algos
#define algos
#include <vector>
#include <queue>
#include "graph_util.h"
#define INF INT_MAX


// Helper Functions and Definitions
typedef pair<int, int> intpair;

std::vector<int> get_adj_vert(Graph graph, int v) {
    std::vector<int> adj_vert;
    for (int i = 0; i < graph.get_count(); i++) {
        if (graph.get_edge(v, i) < INF) adj_vert.push_back(i);
    }


    return adj_vert;
}

void printArr(vector<int> dist, int n)
{
    printf("Vertex   Distance from Source\n");
    for (int i = 0; i < n; ++i)
        printf("%d \t\t %d\n", i, dist[i]);
}

// Algorithms
// Dijkstra's start
void dijkstra (Graph& graph, const int source) { // O(nlogn)
    cout << "Dijkstra's Algorithm started!\n";
    //  setup
    vector<int> dist(graph.get_count(), INT_MAX); std::priority_queue<intpair, std::vector<intpair>, std::greater<intpair>> q;
    q.emplace(0, source);
    dist[source] = 0;

    // while the queue is not empty
    // for each reachable vertex from the current top of the queue (aka vtx with the shortest distance from src) {
    // if (distance from source to current + current to the selected (current reachable vertex) < dist from source to reach)
    // source to reach = distance from source to current + current to the selected

    while (!q.empty()) {    // O(logn)
        int u = q.top().second; // u is selected vertex
        std::vector<int> adj_vert_list = get_adj_vert(graph,u); // create a list of vertices that are adjacent to the selected one O(n)

        for (int v: adj_vert_list) {   // for each vertex listed in adj_vert_list O(n)
            int weight = graph.get_edge(u, v);

            if (dist[u] + weight < dist[v]) {   // if the distance from the source to the vertex at the top of the queue, plus the weight of the edge spanning that vertex and the currently selected vertex in the loop is less than the distance from the source to the currently selected vertex
                dist[v] = dist[u] + weight;     // update the dist from source to selected to that ^
                q.emplace(dist[v],v);          // insert vertex v and its distance from the source into the priority queue
            }
        }
        q.pop();
    }
    printArr(dist, graph.get_count());
}
// END Dijkstra's

// A* Start
void a_star(const std::vector<std::vector<int>>& graph, const std::vector<int>& heuristic, const int n, const int source) {
    cout << "A* placeholder\n";
}
// END A*

// Bellman-Ford Start
void bellman_ford(const std::vector<std::vector<int>>& graph, const int v, const int e, const int source) {
    // Declare and initialize distance and shortest path set
    vector<int> distance(v);
    bool shortest_pt_set[v];
    for (int i = 0; i < v; i++) {
        distance[i] = INF;
        shortest_pt_set[i] = false;
    }
    distance[source] = 0;
    int u=0; // TEMP TEMP TEMP
    // select u somehow

    for (int i = 0; i < (v-1); i++) {
        for (int j = 0; j < e; j++) {
            if (distance[u] != INF && distance[u] + graph[v][u] < distance[v])
                distance[v] = distance[u] + graph[v][u];
        }
    }
    printArr(distance, v);
}
// END Bellman-Ford

/* previous dijkstra implementations
#include <iostream>
#include <vector>
#include <queue>
#include <climits>

using namespace std;

typedef pair<int, int> pii; // typedef for readability

vector<int> dijkstra(vector<vector<pii>>& graph, int start) {
    vector<int> dist(graph.size(), INT_MAX);
    dist[start] = 0;

    priority_queue<pii, vector<pii>, greater<pii>> pq; // min-heap priority queue
    pq.push({0, start});

    while (!pq.empty()) {
        int u = pq.top().second;    // set u equal to the index of the vertex at the top of the queue
        pq.pop();                   // remove from top of the queue (ignorable tbh)

        for (auto& edge : graph[u]) { // for every vertex in the column assigned to the vertex at the top of the queue
            int v = edge.first;             // set v equal to the index of the vertex
            int weight = edge.second;       // set weight equal to the length of the edge between the vertex at the top of the queue and the currently selected vertex in the loop

            if (dist[u] + weight < dist[v]) {   // if the distance from the source to the vertex at the top of the queue, plus the weight of the edge spanning that vertex and the currently selected vertex in the loop is less than the distance from the source to the currently selected vertex
                dist[v] = dist[u] + weight;     // update the dist from source to selected to that ^
                pq.push({dist[v], v});          // insert vertex v and its distance from the source into the priority queue
            }
        }
    }

    return dist; // return the vector of distances from the source, in 'alphabetical' order of vertices (vtx 0 first, vtx n last)
}

 int find_closest_pt(const int distance[], const bool shortest_pt_set[], const int n) {

    // Initialize min value
    int min = INF, min_index;

    for (int v = 0; v < n; v++)
        if (!shortest_pt_set[v] && distance[v] <= min)
            min = distance[v], min_index = v;

    return min_index;
}

void dijkstra(const std::vector<std::vector<int>>& graph, const int n, const int source) {
    // Declare and initialize distance and shortest path set
    int distance[n]; bool shortest_pt_set[n];
    for (int i = 0; i < n; i++) {
        distance[i] = INF; shortest_pt_set[i] = false;
    }
    distance[source] = 0;

    for (int i = 0; i < (n-1); i++) {
        // Pick the minimum distance vertex from the set of
        // vertices not yet processed. u is always equal to
        // src in the first iteration.
        int closest_pt = find_closest_pt(distance, shortest_pt_set, n);

        // Mark the picked vertex as processed
        shortest_pt_set[closest_pt] = true;

        // Update dist value of the adjacent vertices of the
        // picked vertex.
        for (int j = 0; j < n; j++)

            // Update dist[v] only if is not in sptSet,
            // there is an edge from u to v, and total
            // weight of path from src to  v through u is
            // smaller than current value of dist[v]
            if (!shortest_pt_set[j] && graph[closest_pt][j]
                && distance[closest_pt] != INF
                && distance[closest_pt] + graph[closest_pt][j] < distance[j])
                distance[j] = distance[closest_pt] + graph[closest_pt][j];
    }
    printArr(distance, n);
}

*/

#endif //algos