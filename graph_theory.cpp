#include <bits/stdc++.h>

using namespace std;

// Initialize variables
int N = 4;
vector<int> test_graph[4];
bool visited[4];
bool visited_[4];
int distance_list[4];
queue<int> q;

void initialize_DFS(int current_node){
    if(visited[current_node]){
        return;
    }
    visited[current_node] = true;
    
    // process the nodes in the path
    for(auto next_node : test_graph[current_node]){
        cout << next_node << " ";
        initialize_DFS(next_node);
    }
}

void initialize_BFS(int starting_node){
    visited_[starting_node] = true;
    distance_list[starting_node] = 0;
    q.push(starting_node);

    while (!q.empty())
    {
        int s = q.front();
        q.pop();

        // Process nodes in path
        for(auto u : test_graph[s]){
            if(visited_[u]){
                continue;
            }
            visited_[u] = true;
            distance_list[u] = distance_list[s] + 1;
            q.push(u);
        }  
    }
}

void graph_representation(){
    /* 
    Sample Graph

    (1) -> (2) -> (3) -> (4)
    */
    
    // Adjacency list representation
    vector<int> adj_list[N];
    adj_list[1].push_back(2);
    adj_list[2].push_back(3);
    adj_list[3].push_back(4);

    // Adjacency matrix represenation
    int adj_matrix[N][N];
    adj_matrix[0][0] = 0;
    adj_matrix[0][1] = 1; // So on....

    // Edge List Representation
    vector<pair<int, int>> edge_list;
    edge_list.push_back({1, 2});
    edge_list.push_back({2, 3});
    edge_list.push_back({3, 4});
}

int main(){ 
    test_graph[1].push_back(2);
    test_graph[1].push_back(4);
    test_graph[2].push_back(3);
    test_graph[2].push_back(5);
    test_graph[3].push_back(6);
    test_graph[5].push_back(6);
    
    //initialize_DFS(1);
    //initialize_BFS(1);
    
    return 0;
}