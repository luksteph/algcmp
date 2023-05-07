#include <iostream>
#include "algos.h"
#include "graph_util.h"
using std::cout; using std::cin;

void welcome();
void validate_graph_input(Graph &g, char &input_choice, char &mode);
void validate_algo_input(char &algo_choice, char &mode);
void call_graph_function(Graph &g, char &algo_choice);
void handle_next_choice(char &next_choice, char &mode);
void fill_graph(Graph &g);
enum a {INIT, INPUT_TYPE, ALGO_TYPE, HANDLE_INPUT, NEXT_ACTION, EXIT, CONFIRM_EXIT}; // define types of input

int main() {
    char mode, input_choice, algo_choice, next_choice; // define variables for user selected input
    Graph base_graph; // base graph
    mode = INIT;

    // Main state machine
    while (mode != CONFIRM_EXIT) {
        switch (mode) {

            case INIT: {
                welcome(); // print welcome text
                cout << "Welcome! Please follow the prompts to compare different graph traversal algorithms.\n";
                cout << "(You may use 'x' at any prompt to go back.)\n"; // technically not true
                mode = INPUT_TYPE;
                break;
            }

            case INPUT_TYPE: { // Get user preference for graph input
                cout << "Would you like to generate or input a graph?\n";
                cout << "i = Input Your Own\n" << "g = Generate a Graph\n";
                cout << "> ";
                cin >> input_choice;
                validate_graph_input(base_graph, input_choice, mode);
                break;
            }

            case ALGO_TYPE: { // Get user preference for algorithm
                cout << "Which algorithm would you like to use?\n";
                cout << "d = Dijkstra's\n" << "b = Bellman-Ford\n";
                cout << "> ";
                cin >> algo_choice;
                validate_algo_input(algo_choice, mode);
                break;
            }

            case HANDLE_INPUT: { // Call traversal function based on user selections
                call_graph_function(base_graph, algo_choice);
                mode = NEXT_ACTION;
                break;
            }

            case NEXT_ACTION: { // Prompt user for next action
                cout << "What would you like to do next?\n";
                cout << "g = Change the Graph\n" << "a = Choose an Algorithm\n" << "x = Exit\n";
                cout << "> ";
                cin >> next_choice;
                handle_next_choice(next_choice, mode);
                break;
            }

            case EXIT: { // Handle exit
                cout << "Type x to confirm exit, or any other character to return.\n";
                cout << "> ";
                cin >> mode;

                if (tolower(mode) == 'x') mode = CONFIRM_EXIT;
                else mode = NEXT_ACTION;
                break;
            }
        }
    }
    exit(0);
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

void validate_graph_input(Graph &g, char &input_choice, char &mode) {
    input_choice = tolower(input_choice); short vtc; // vertex count

    switch (input_choice) {
        case 'i': cout << "Input mode selected!\n"; break;
        case 'g': cout << "Generate mode selected!\n"; break;
        case 'x': mode = EXIT; return;
        default: cout << "Invalid selection. Try again with i or g.\n"; return;
    }

    cout << "How many vertices should the graph have?\n> ";
    cin >> vtc;
    g.set_count(vtc);

    if (input_choice == 'g') {
        int seed = 0;
        cout << "Please provide a seed of type int for the graph.\n";
        cout << "> ";
        cin >> seed;
        g.adjmtx_rand(seed);
        g.print_graph();

    }
    else fill_graph(g);
    mode = ALGO_TYPE;
}

void validate_algo_input(char &algo_choice, char &mode) {
    algo_choice = tolower(algo_choice);

    switch (algo_choice) {
        case 'd': cout << "Dijkstra's algorithm selected!\n"; break;
        case 'b': cout << "Bellman-Ford algorithm selected!\n"; break;
        case 'x': mode = INPUT_TYPE; return;
        default: cout << "Invalid selection. Try again with d or b.\n"; return;
    }

    mode = HANDLE_INPUT;
}

void call_graph_function(Graph &g, char &algo_choice) {
    short src; // source node
    cout << "What would you like the source to be? (0-" << g.get_count() - 1 << ")\n> ";
    cin >> src;

    switch (algo_choice) {
        case 'd': dijkstra(g, src); break;
        case 'b': bellman_ford(g, src); break;
    }
}

void fill_graph(Graph &g) {
    string command; int u, v, w;
    cout << "\nCommand-line interface:\n";
    // Command Loop
    while (command != "exit") {
        cout << "> ";
        cin >> command;

        if (command == "se") {
            cin >> u >> v >> w;
            if (g.set_edge(w, u, v)) cout << "Edge (" << u << ", " << v << ") set to " << w << " successfully.\n";
            else cout << "Edge failed to set.\n";
        }

        else if (command == "ge") {
            cin >> u >> v;
            cout << g.get_edge(u, v) << '\n';
        }

        else if (command == "pg") g.print_graph();
        else if (command != "exit") cout << "Unknown command.\n";
        else cout << "Exiting command prompt.\n";
    }
}

void handle_next_choice(char &next_choice, char &mode) {
    if (next_choice == 'g') mode = INPUT_TYPE;
    else if (next_choice == 'a') mode = ALGO_TYPE;
    else if (next_choice == 'x') mode = EXIT;
    else {
        cout << "Invalid action.\n";
        mode = NEXT_ACTION; // may be redundant
        next_choice = '\0'; // reset from invalid entered char
    }
}