#include <vector>
#include <iostream>
#include <iomanip>
#include <cmath>
#include "algos.h"
#include "graph_util.h"
#define INF INT_MAX // change back
using namespace std;

void test_cases();

int main() {
    test_cases();

    char c = 0;
    enum a {INIT, INPUT_TYPE, ALGO_TYPE, NEXT_ACTION, EXIT};
    while (c != 'e') {
        switch (c) {
            case INIT: {
                cout << "Graph Node Search" << '\n';
                c = INPUT_TYPE;
                break;
            }

            case INPUT_TYPE: {
                cout << "Generate or input a graph: ";
                cin >> c;
                if (c == 'i') cout << "input mode selected";
                if (c == 'g') cout << "generate mode selected";
                break;
            }
            case ALGO_TYPE: {
                cout << "Algorithm to use: ";
                cin >> c;
                if (c == 'd') cout << "Djikstras alg selected";
                if (c == 'a') cout << "A* selected";
                if (c == 'f') cout << "Bellman-Ford alg selected";
                if (c == 'b') cout << "bidirectional search selected";
                break;
            }
            case NEXT_ACTION: {
                cout << "Next action; g for new graph, a for new algo, e to exit";
                cin >> c;
                if (c == 'g') c = INPUT_TYPE;
                if (c == 'a') c = ALGO_TYPE;
                if (c == 'e') c = EXIT;
                break;
            }
            case EXIT: {
                cout << "Exiting!";
                break;
            }
            default:
                break;
        }
    }
    return 0;
}

void test_cases() {
    cout << "debugs:test0";
    Graph myFirstGraph = Graph(3);
    int t = myFirstGraph.get_count();
    cout << t;
    bool b = myFirstGraph.set_edge(5000, 0, 0);
    cout << b;
    myFirstGraph.print_graph();
    myFirstGraph.adjmtx_rand(3);
    myFirstGraph.print_graph();
}