#include <vector>
#include <iostream>
#include <iomanip>
#include "algos.h"
#include "graph_util.h"
using namespace std;

struct userInput {
    char c, i, a, n;
    short short int s;
};
void welcome();
void test_cases(); // temp
void input_handler();

int main() {
    test_cases();
    
    userInput input;
    enum a {INIT, INPUT_TYPE, ALGO_TYPE, NEXT_ACTION, EXIT, CONFIRM_EXIT};
    
    input.c = INIT;
    while (input.c != CONFIRM_EXIT) {
        switch (input.c) {
            case INIT: {
                welcome();
                cout << "Welcome! Please follow the prompts to compare different graph traversal algorithms." << '\n';
                cout << "(You may use 'x' at any prompt to go back.)" << '\n';
                input.c = INPUT_TYPE;
                break;
            }

            case INPUT_TYPE: {
                cout << "Would you like to generate or input a graph?\n"
                cout << "i = Input Your Own\n" << "g = Generate a Graph\n";
                cout << "> ";
                cin >> input.i;
                if (toLower(input.i) == 'i') cout << "Input mode selected!";
                else if (toLower(input.i) == 'g') cout << "Generate mode selected!";
                else if (toLower(input.i) == 'x') input.c = EXIT;
                else {
                    cout << "Invalid input type selection.\n"
                    input.c = INPUT_TYPE; // may be redundant
                    input.i = '\0'; // reset
                    break;
                }
                input.c = ALGO_TYPE;
                break;
            }
            case ALGO_TYPE: {
                cout << "Which algorithm would you like to use?\n";
                cout << "d = Dijkstra's\n" << "a = A*\n" << "b = Bellman-Ford\n";
                cout << "> ";
                cin >> input.a;
                switch (toLower(input.a)) {
                    case 'd': {
                        cout << "Dijkstra's selected!\n";
                        input_handler(input);
                        break;
                    }
                    case 'a': {
                        cout << "A* selected!\n";
                        input_handler(input);
                        break;
                    }
                    case 'b': {
                        cout << "Bellman-Ford selected!\n";
                        input_handler(input);
                        break;
                    }
                    case 'x': {
                        input.c = INPUT_TYPE;
                        input.a = '\0'; // reset algo choice
                        break;
                    }
                    default: {
                        cout << "Invalid algorithm selection.\n"
                        input.c = ALGO_TYPE;
                        input.a = '\0'; // reset algo choice
                        break;
                    }
                }
                break;
            }
            case NEXT_ACTION: {
                cout << "What would you like to do next?\n";
                cout << "g = Change the Graph\n" << "a = Choose an Algorithm\n" << "x = Exit\n";
                cout << "> ";
                cin >> input.n;
                if (input.n == 'g') input.c = INPUT_TYPE;
                else if (input.n == 'a') input.c = ALGO_TYPE;
                else if (input.n == 'x') input.c = EXIT;
                else {
                    cout << "Invalid action.\n"
                    input.c = NEXT_ACTION; // may be redundant
                    input.n = '\0'; // reset
                    break;
                }
                break;
            }
            case EXIT: {
                cout << "Type x to confirm exit, or any other character to return.\n";
                cout << "> ";
                cin >> c;
                if (toLower(c) == 'x') {
                    input.c = CONFIRM_EXIT;
                }
                else {
                    input.c = NEXT_ACTION;
                }
                break;
            }
            default: cout << "default flag";
                break;
        }
    }
    return 0;
}

void welcome() {
    cout <<
    "───────────────────────────────────────────────────────────────────────────────────────────────────\n" <<
    "─██████████████─██████─────────██████████████─██████████████─██████──────────██████─██████████████─\n" <<
    "─██░░░░░░░░░░██─██░░██─────────██░░░░░░░░░░██─██░░░░░░░░░░██─██░░██████████████░░██─██░░░░░░░░░░██─\n" <<
    "─██░░██████░░██─██░░██─────────██░░██████████─██░░██████████─██░░░░░░░░░░░░░░░░░░██─██░░██████░░██─\n" <<
    "─██░░██──██░░██─██░░██─────────██░░██─────────██░░██─────────██░░██████░░██████░░██─██░░██──██░░██─\n" <<
    "─██░░██████░░██─██░░██─────────██░░██─────────██░░██─────────██░░██──██░░██──██░░██─██░░██████░░██─\n" <<
    "─██░░░░░░░░░░██─██░░██─────────██░░██──██████─██░░██─────────██░░██──██░░██──██░░██─██░░░░░░░░░░██─\n" <<
    "─██░░██████░░██─██░░██─────────██░░██──██░░██─██░░██─────────██░░██──██████──██░░██─██░░██████████─\n" <<
    "─██░░██──██░░██─██░░██─────────██░░██──██░░██─██░░██─────────██░░██──────────██░░██─██░░██─────────\n" <<
    "─██░░██──██░░██─██░░██████████─██░░██████░░██─██░░██████████─██░░██──────────██░░██─██░░██─────────\n" <<
    "─██░░██──██░░██─██░░░░░░░░░░██─██░░░░░░░░░░██─██░░░░░░░░░░██─██░░██──────────██░░██─██░░██─────────\n" <<
    "─██████──██████─██████████████─██████████████─██████████████─██████──────────██████─██████─────────\n" <<
    "───────────────────────────────────────────────────────────────────────────────────────────────────\n";
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
                    
void input_handler(userInput input) {
    cout << input.i << input.a; // c, n is unused in this handler

    if (input.i == 'g') {
        cout << "Input a number of vertices for the graph [1, 20].";
        cout << "Any values outside this range will randomize the size of the graph within [1, 20]."
        //handle that.
    }
    else {
        cout << "Input a number of vertices for the graph [1, 20].";
        //validate that
        cin >> input.s;
        Graph g(input.s);
        
    }
}
