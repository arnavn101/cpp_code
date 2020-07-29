#include <bits/stdc++.h>

using namespace std;

vector<int> adj[7];
int processed[7];
stack<int> topologically_sorted;

// DFS Algorithm
void DFS(int current_node){
    if (processed[current_node]){
        return;
    }

    processed[current_node] = true;

    for(auto next_nodes : adj[current_node]){
        DFS(next_nodes);
    }

    topologically_sorted.push(current_node);
}

// successor order of nodes
void topological_sort(){
    // Directed graph so DFS on all the nodes is required
    for(int i = 1; i < 7; i++){
        if (!processed[i]){
            DFS(i);
        }
    }

    while(!topologically_sorted.empty()){
        cout << topologically_sorted.top() << " ";
        topologically_sorted.pop();
    }
    cout << "\n";
}

// Find successor node (outdegree)
int successor_node(int this_node){
    return adj[this_node][0];
}

// Floyd's Algorithm (calculate length of cycle)
void fl_algo(int start_node){
    int pointer_a = successor_node(start_node);
    int pointer_b = successor_node(successor_node(start_node));

    // Sample Iteration through the graph
    while (pointer_a != pointer_b){
        pointer_a = successor_node(pointer_a);
        pointer_b = successor_node(successor_node(pointer_b));
    }

    // Begin at start_node to find the first node of the cycle
    pointer_a = start_node;

    while (pointer_a != pointer_b){
        pointer_a = successor_node(pointer_a);
        pointer_b = successor_node(pointer_b);
    }
    
    int first_node = pointer_a; // first node that belongs to the cycle
    cout << "First Node of the Cycle: " << to_string(pointer_a) << endl;

    pointer_b = successor_node(pointer_a);
    int length = 1;
    
    // Determine length of the cycle
    while (pointer_a != pointer_b){
        pointer_b = successor_node(pointer_b);
        length += 1;
    }
    
    cout << "Length of the Cycle: " << to_string(length) << endl;
}

int main(){
    adj[1].push_back(2);
    adj[2].push_back(3);
    adj[3].push_back(6);
    adj[4].push_back(1);
    adj[4].push_back(5);
    adj[5].push_back(2);
    adj[5].push_back(3);

    topological_sort();
    return 0;   
}
