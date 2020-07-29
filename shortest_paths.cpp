#include <bits/stdc++.h>

using namespace std;

// Initialize Variables
vector<tuple<int, int, int>> adj;
vector <pair<int, int>> adjL [6];
int adjM[6][6];

int list_distances[5]; 
int list_distances2[6]; 
int list_distances3[6][6]; 
bool processed[5] = { false };

// Bellman-Ford Algorithm
void BF_algo(int starting_node, int number_nodes){
    for (int i = 1; i <= number_nodes; i++)
    {
        list_distances[i] = INFINITY;
    }
    list_distances[starting_node] = 0;

    for (int i = 1; i <= number_nodes-1; i++)
    {
        for(auto e : adj){
            int a, b, w;
            tie(a, b, w) = e;
            list_distances[b] = min(list_distances[b], list_distances[a] + w); 
        }
    }
    

}

// Dijkstra Algorithm
void DJK_algo(int starting_node, int number_nodes){
    for (int i = 1; i <= number_nodes; i++)
    {
        list_distances2[i] = INFINITY;
    }

    for (int i = 0; i <= number_nodes; i++)
    {
        processed[i] = false;
    }

    list_distances2[starting_node] = 0;
    priority_queue <pair<int, int>> q;
    q.push({0, starting_node});
    
    while(!q.empty()){
        int a = q.top().second;
        q.pop();

        if (processed[a]){
            continue;
        }
        processed[a] = true;

        for(auto u : adjL[a]){
            int b = u.first;
            int w = u.second;

            if(list_distances2[a]+w < list_distances2[b]){
                list_distances2[b] = list_distances2[a] + w;
                q.push({-list_distances2[b], b}); // distance is - to ensure closer nodes on top
            }       
        }
    }
}

// Floyd-Warshall Algo
void FW_algo(int starting_node, int number_nodes){
    for(int i = 1; i <= number_nodes; ++i){
        for(int j = 1; j <= number_nodes; ++j){
            if(i == j){
                list_distances3[i][j] = 0;
            }
            else if (adjM[i][j])
            {
                list_distances3[i][j] = adjM[i][j];
            }
            else{
                list_distances3[i][j] = INFINITY;
            }
            
        }
    }

    for(int k = 1; k <= number_nodes; ++k){
        for(int i = 1; i <= number_nodes; ++i){
            for (int j = 1; j < number_nodes; ++j)
            {
                list_distances3[i][j] = min(list_distances3[i][j], list_distances3[i][k] + list_distances3[k][j]);
            }
        }
    }
}

// Print Distances list
void printDistances(int number_nodes){
    for (int i = 1; i <= number_nodes; i++)
    {
        cout << "Node: " << to_string(i) << ", Distance: " << to_string(list_distances[i]) << endl;
    }
}

// Print Distances2 list
void printDistances2(int number_nodes){
    for (int i = 1; i <= number_nodes; i++)
    {
        cout << "Node: " << to_string(i) << ", Distance: " << to_string(list_distances2[i]) << endl;
    }
}

int main(){
    // Initialize Graph
    adj.push_back(make_tuple(1,2,5));
    adj.push_back(make_tuple(1,3,3));
    adj.push_back(make_tuple(1,4,7));
    adj.push_back(make_tuple(3,4,1));
    adj.push_back(make_tuple(2,5,2));
    adj.push_back(make_tuple(4,5,2));

    // Execute Algos
    BF_algo(1, 5);
    printDistances(5);

    // Initialize second graph
    adjL[1].push_back(make_pair(5, 1));
    adjL[1].push_back(make_pair(2, 5));
    adjL[1].push_back(make_pair(4, 9));
    adjL[2].push_back(make_pair(1, 5));
    adjL[2].push_back(make_pair(3, 2));
    adjL[3].push_back(make_pair(2, 2));
    adjL[3].push_back(make_pair(4, 6));
    adjL[4].push_back(make_pair(3, 6));
    adjL[4].push_back(make_pair(1, 9));
    adjL[4].push_back(make_pair(5, 2));
    adjL[5].push_back(make_pair(4, 2));
    adjL[5].push_back(make_pair(1, 1));

    // Execute more Algos
    cout << "\n\n";
    DJK_algo(1, 5);
    printDistances2(5);

    // Initialize Third Graph
    return 0;
}