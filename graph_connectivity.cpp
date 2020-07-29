#include <bits/stdc++.h>

using namespace std;

// Graph (Directed)
vector<int> adj[8];

// Reversed Graph (Directed)
vector<int> adj2[8];

// Final connected components
vector<set<int>> components;

// Two Visited Lists
bool visited[8];

// Count time
int count_time;

// Ordering the set
typedef pair<int, int> pd; 

// Structure of the condition for sorting the pair by its second elements 
struct myComp { 
    constexpr bool operator()( 
        pair<int, int> const& a, 
        pair<int, int> const& b) 
        const noexcept 
    { 
        return a.second < b.second; 
    } 
}; 

// Store Nodes & their processing time (Greatest to Least)
priority_queue<pd, vector<pd>, myComp> list_nodes; 

// Depth First Search Algorithm
void first_DFS(int current_node){
    if(visited[current_node]){
        return;
    }
    visited[current_node] = true;

    // Process preceding nodes
    for(auto next_node : adj[current_node]){
        count_time += 1;
        first_DFS(next_node);
    }
}

bool existsComponent(int this_node){
    // Ensure that element does not already exist in a component
    for(set<int> current_set : components){
        auto presense = current_set.find(this_node);
        if(presense != current_set.end()){
            return true;
        }
    }
    return false;
}

// Depth First Search Algorithm (#2)
void second_DFS(int current_node, int this_set_id){
    if(visited[current_node]){
        return;
    }
    visited[current_node] = true;

    if(!existsComponent(current_node)){
        components[this_set_id].insert(current_node);
    }

    // Process preceding nodes
    for(auto next_node : adj2[current_node]){
        second_DFS(next_node, this_set_id);
    }
}

// Reset visited List to all False
void reset_visited(){
    for(int i = 0; i < 8; i++){
        visited[i] = false;
    }
}

// Kosaraju's Algorithm (Find Strongest Connected Components)
void kos_algo(){
    // 1st DFS
    for(int i = 1; i < 8; i++){
        count_time = 0;
        reset_visited();
        first_DFS(i);
        list_nodes.push(make_pair(i, count_time));

        // Print List of Nodes and their corresponding Processing Time
        cout << "Node: " << to_string(i) << ", Processing Time: " << to_string(count_time) << endl;
    }

    // Reverse all Edges in the graph
    for(int i = 1; i < 8; i++){
        for(auto element : adj[i]){
            adj2[element].push_back(i);
        }
    }

    // Initialize some variables
    int this_set_id = 0;
    
    // 2nd & Final DFS
    while(!list_nodes.empty()){
        reset_visited();
        int current_node = list_nodes.top().first;
        list_nodes.pop();

        if(existsComponent(current_node)){
            continue;
        }
        
        set<int> this_set = {current_node};
        components.push_back(this_set);

        second_DFS(current_node, this_set_id);
        this_set_id += 1;
    }

    // Print Components
    cout << "\n" << "Strongly Connected Components" << endl;
    for(auto this_set : components){
        for(auto element : this_set){
            cout << to_string(element) << " ";
        }
        cout << "\n";
    }
}

int main(){
    // Create the graph
    adj[1].push_back(2);
    adj[1].push_back(4);
    adj[2].push_back(1);
    adj[2].push_back(5);
    adj[3].push_back(2);
    adj[3].push_back(7);
    adj[5].push_back(4);
    adj[6].push_back(5);
    adj[6].push_back(3);
    adj[7].push_back(6);

    // Run the Algorithm
    kos_algo();
    
}