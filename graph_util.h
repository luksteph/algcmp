#ifndef INC_230FINAL_GRAPH_UTIL_H
#define INC_230FINAL_GRAPH_UTIL_H
#define INF INT_MAX
#include <iomanip>
using namespace std;

class Graph {
private:
    int vertex_count = 1;
    vector <vector <int>> adj_mtx; //declare a 2d adjacency matrix
public:
    explicit Graph(int n);                      // Constructor with parameters
    explicit Graph();                           // Default constructor
    void set_count(short n);                    // Set vertex count
    bool adjmtx_init();                         // Fill adjacency matrix with infinite edge lengths
    bool adjmtx_rand(int seed);                 // Fill adjacency matrix with random values
    bool set_edge(int length, int r, int c);    // Setter for edge length
    int get_count() const;                      // Get vertex count
    int get_edge(int r, int c);                 // Get edge length
    void print_graph();                         // Print graph
    ~Graph();                                   // Destructor
};

Graph::Graph(int n) { // Constructor with parameters
    vertex_count = n;
    adjmtx_init();
}

Graph::Graph() = default; // Default constructor

void Graph::set_count(short n) { // setter for vtx count
    if (n>0) {
        vertex_count = n;
        adjmtx_init();
    }
    else cout << "Invalid value for vertex count.\n";
}

int Graph::get_count() const { // getter for vertex count
    return vertex_count;
}

bool Graph::set_edge(int length, int r, int c) {
    // format length var
    if (length > 999) length = 999;
    if (length < -999) length = -999;
    // set edge, return true if it worked
    if (c >= 0 && r >= 0 && c < vertex_count && r < vertex_count) {
        adj_mtx[r][c] = length;
        adj_mtx[c][r] = length;
        return true;
    }
    else return false;
}

bool Graph::adjmtx_init() { // Initialize adjacency matrix with all values infinite, return true if worked
    vector <int> inf_vector;
    for (int i = 0; i < vertex_count; i++) {
        inf_vector.push_back(INF);
    }
    for (int j = 0; j < vertex_count; j++) {
        adj_mtx.push_back(inf_vector);

    }
    if (adj_mtx[vertex_count-1][vertex_count-1] == INF) return true;
    else return false;
}

bool Graph::adjmtx_rand(int seed) { // Fill adjacency matrix with all values randomized
    srand(seed);
    for (int i = 0; i < vertex_count; i++) {
        for (int j = i; j < vertex_count; j++) {
            if (i == j) { // no loops (diagonal = 0)
                adj_mtx[i][j] = 0;
            }
            else if (rand() % 2 == 0) { // 50% chance of being INF
                adj_mtx[i][j] = INF;
                adj_mtx[j][i] = INF;
            }
            else { // 50% chance of being a random number between 0 and 30
                adj_mtx[i][j] = rand() % 31;
                adj_mtx[j][i] = adj_mtx[i][j];
            }
        }
    }
    return true;
}

void Graph::print_graph() {
    cout << "\nAdjacency Matrix: \n";
    for (int i = 0; i < vertex_count; ++i) {
        for (int j = 0; j < vertex_count; ++j) {
            if (adj_mtx[i][j] == INF) cout << "INF ";
            else cout << std::setw(3) << left << adj_mtx[i][j] << ' ';
        }
        cout << endl;
    }
}

int Graph::get_edge(int r, int c){
    if (c >= 0 && r >= 0 && c < vertex_count && r < vertex_count) return adj_mtx[r][c];
    else return NULL;
}

Graph::~Graph() {
    cout << "\nGraph Destroyed!\n";
}

#endif //INC_230FINAL_GRAPH_UTIL_H