#ifndef INC_230FINAL_GRAPH_UTIL_H
#define INC_230FINAL_GRAPH_UTIL_H
#define INF INT_MAX
using namespace std;

class Graph {
private:
    int vertex_count = 0;
    vector <vector <int>> adj_mtx; //declare a 2d adjacency matrix
public:
    explicit Graph(int n);                               // constructor
    bool adjmtx_init();                         // fill adjacency matrix with infinite edge lengths
    bool adjmtx_rand(int seed) const;
    bool set_edge(int length, int x, int y);    // setter for edge length
    int get_count();                            // retrieve vertex count
    int get_edge(int r, int c);
    void print_graph();                         // Print out generalized graph
    ~Graph();
};

Graph::Graph(int n) { // Constructor with parameters
    vertex_count = n;
    adjmtx_init();
    cout << "test1";
}

int Graph::get_count() { // getter for vertex count
    cout << "test4";
    return vertex_count;
}

bool Graph::set_edge(int length, int x, int y) { // x is which col, y is which row
    // format length var
    if (length > 999) length = 999;
    else if (length < 0) length = 0;

    // set edge, return true if it worked
    if (x >= y && x < vertex_count && y < vertex_count) {
        adj_mtx[y][x] = length;
        return true;
    }
    else return false;
}

bool Graph::adjmtx_init() { // Initialize adjacency matrix with all values infinite, return true if worked
    vector <int> inf_vector;
    cout << "test2";
    for (int i = 0; i < vertex_count; i++) {
        inf_vector.push_back(INF);
        cout << i;
    }
    for (int j = 0; j < vertex_count; j++) {
        adj_mtx.push_back(inf_vector);
        cout << j;
    }
    cout << "test3";
    if (adj_mtx[vertex_count-1][vertex_count-1] == INF) return true;
    else return false;
}

bool Graph::adjmtx_rand(int seed) const { // Fill adjacency matrix with all values randomized
    srand(seed);
    int random = rand();
    cout << random;
    for (int i = 0; i < vertex_count; i++) {
        for (int j = 0; j <= i; j++) {
        }
    }
    return true;
}

void Graph::print_graph() {
    cout << "\nAdjacency Matrix: \n";
    for (int i = 0; i < vertex_count; ++i) {
        for (int j = 0; j < vertex_count; ++j) {
            if (adj_mtx[i][j] == INF) cout << "INF ";
            else cout << setw(3) << left << adj_mtx[i][j] << ' ';
        }
        cout << endl;
    }
}

int Graph::get_edge(int r, int c){
    return adj_mtx[r][c];
}

Graph::~Graph() {
    cout << "\ndestructor placeholder\n";
}

#endif //INC_230FINAL_GRAPH_UTIL_H
