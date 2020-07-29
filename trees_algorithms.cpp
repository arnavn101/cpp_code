#include <bits/stdc++.h>

using namespace std;

// Initialize Variables
vector<int> adj[10];
vector<int> adj2[10];
bool visited[10] = { false };
bool visited2[10] = { false };
int number_subtreeNodes[10];
int furthest_distance , furthest_distance2;
int furthest_node, furthest_node2;

// Similar to DFS
void traverse_tree(int start_node, int previous_node){

    for(auto next_node : adj[start_node]){
        if (next_node != previous_node){
            cout << next_node << " ";
            traverse_tree(next_node, previous_node);
        }
    }

}

void count_subtreeNodes(int start_node, int previous_node){
    number_subtreeNodes[start_node] = 1;

    for(auto next_node : adj[start_node]){
        if (start_node == next_node){
            continue;
        }

        count_subtreeNodes(next_node, start_node);
        number_subtreeNodes[start_node] += number_subtreeNodes[next_node];
    }
}

void print_list(){
    cout << "\n";
    for (int i = 1; i < 7; i++)
    {
        cout << "Node: " << to_string(i) << ", Children: " << to_string(number_subtreeNodes[i]) << endl;
    }
    cout << "\n";
}

void firstDFS(int current_node, int count_node){
    if (visited[current_node]){
        return;
    }

    visited[current_node] = true;

    for (auto next_node : adj2[current_node]){
        firstDFS(next_node, count_node + 1);
    }

    if (count_node > furthest_distance){
        furthest_distance = count_node;
        furthest_node = current_node;
    }

}

void secondDFS(int current_node, int count_node){
    if (visited2[current_node]){
        return;
    }

    visited2[current_node] = true;

    for (auto next_node : adj2[current_node]){
        secondDFS(next_node, count_node + 1);
    }

    if (count_node > furthest_distance){
        furthest_distance2 = count_node;
        furthest_node2 = current_node;
    }
}

// DFS Approach (2 DFS --> A to B, then B to C)
void determine_diameter(){
    // Initialize some variables
    furthest_distance = 0;
    furthest_node = 0;

    // Find Node B
    firstDFS(3, 0);
    cout << "Node B: " << to_string(furthest_node) << endl;
    cout << "Diameter: " << to_string(furthest_distance) << endl;

    // Re-Initialize some variables
    furthest_distance2 = 0;
    furthest_node2 = 0;

    // Find Node C
    secondDFS(furthest_node, 0);
    cout << "Node C: " << to_string(furthest_node2) << endl;
    cout << "Diameter: " << to_string(furthest_distance2) << endl;
}

int main(){
    // Initialize Tree
    adj[2].push_back(5);
    adj[2].push_back(6);
    adj[6].push_back(8);

    // 0 refers to a lack of previous node
    traverse_tree(2, 0); 
    
    // Initialize all nodes' children to 0
    for (int i = 0; i < 10; i++)
    {
        number_subtreeNodes[i] = 0;
    }
    
    // count and print children
    count_subtreeNodes(2, 0);
    print_list();

    // Initialize Second Tree
    adj2[6].push_back(2);
    adj2[2].push_back(6);
    adj2[5].push_back(2);
    adj2[2].push_back(5);
    adj2[2].push_back(1);
    adj2[1].push_back(2);
    adj2[1].push_back(3);
    adj2[3].push_back(1);
    adj2[1].push_back(4);
    adj2[4].push_back(1);
    adj2[4].push_back(7);
    adj2[7].push_back(4);

    // Diameter of tree
    determine_diameter();

    return 0;
}