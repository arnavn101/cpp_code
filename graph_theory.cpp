#include <bits/stdc++.h>

using namespace std;

// Initialize Variables
vector<int> adj[10];
queue<int> queue_nodes;
bool visited[10];
int list_distance[10];

// Basic Depth First Search
void dfs(int current_node){
	if (visited[current_node])
	{
		return; 
	}
	visited[current_node] = true;

	// process the next nodes
	for (auto u : adj[current_node]){
		cout << to_string(u) << " ";
		dfs(u);
	}
}

void initialize_false(){
	for (int i = 0; i < 10; i++)
	{
		visited[i] = false;
	}
	
}

// Intricate Breadth First Search
void bfs(int current_node){
	visited[current_node] = true;
	list_distance[current_node] = 0;
	queue_nodes.push(current_node);

	while(!queue_nodes.empty()){
		int s = queue_nodes.front();
		queue_nodes.pop();

		// Process node s (get nodes seperate by an edge from it)
		for(auto u : adj[s])
		{
			if(visited[u]){
				continue;
			}
			visited[u] = true;
			list_distance[u] = list_distance[s] + 1;
			queue_nodes.push(u);
			cout << to_string(u) << " ";
		}

	}
}


// Main function
int main(){
	// Sample Graph  4 --> 1 --> 2 --> 3 --> 5  (Start at 1)
    adj[1].push_back(2);
    adj[1].push_back(4);
    adj[2].push_back(3);
    adj[2].push_back(5);
	
	// Run DFS
	dfs(1);

	// Reset Variables
	initialize_false();
	cout << "\n";

	// Run BFS
	bfs(1);

	return 0; 	
	
}	

