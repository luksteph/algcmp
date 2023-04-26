#ifndef algos
#define algos
#include <vector>
#define INF INT_MAX

// Dijkstra's start
int find_closest_pt(const int distance[], const bool shortest_pt_set[], const int n) {

    // Initialize min value
    int min = INF, min_index;

    for (int v = 0; v < n; v++)
        if (!shortest_pt_set[v] && distance[v] <= min)
            min = distance[v], min_index = v;

    return min_index;
}
void printArr(int dist[], int n)
{
    printf("Vertex   Distance from Source\n");
    for (int i = 0; i < n; ++i)
        printf("%d \t\t %d\n", i, dist[i]);
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
// END Dijkstra's
//
// A* Start
void a_star(const std::vector<std::vector<int>>& graph, const std::vector<int>& heuristic, const int n, const int source) {

}
// END A*
//
// Bellman-Ford Start
void bellman_ford(const std::vector<std::vector<int>>& graph, const int v, const int e, const int source) {
    // Declare and initialize distance and shortest path set
    int distance[v];
    bool shortest_pt_set[v];
    for (int i = 0; i < v; i++) {
        distance[i] = INF;
        shortest_pt_set[i] = false;
    }
    distance[source] = 0;

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
//



#endif //algos