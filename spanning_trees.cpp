#include <bits/stdc++.h>

using namespace std;

// Initialize Variables
vector<tuple<int, int, int>> edges;
vector<pair<int, int>> final_edges;
int link_list[7]; // Contains next element in chain or representative element
int size_list[7]; // Corresponds to the size of the set

// Functor to compare by the Mth element
template<int M, template<typename> class F = std::less>
struct TupleCompare
{
    template<typename T>
    bool operator()(T const &t1, T const &t2)
    {
        return F<typename tuple_element<M, T>::type>()(std::get<M>(t1), std::get<M>(t2));
    }
};

// Union Find Structure
void initialize_sets(){
    for(int i = 1; i <= 6; i++) {
        link_list[i] = i;
    }

    for(int i = 1; i <= 6; i++){
        size_list[i] = 1;
    }
}

// Find top element in set
int find_representative(int x){
    while (x != link_list[x]){
        x = link_list[x];
    }
    return x;
}

// Check if both elements belong to same set
bool same_set(int a, int b){
    return find_representative(a) == find_representative(b);
}

// Join set that container the two elements
void unite_sets(int a, int b){
    a = find_representative(a);
    b = find_representative(b);

    if(size_list[a] < size_list[b]){
        swap(a, b);
    }
    size_list[a] += size_list[b];
    link_list[b] = a;
}

// Sort Edges Based on its weight
void sortEdges(){
    sort(begin(edges), end(edges), TupleCompare<2>());
}

// Kruskal's algorithm
void kr_algo(){
    // Create set with final edges
    for(const auto &i : edges) {
        int a = get<0>(i);
        int b = get<1>(i);
        if(!same_set(a, b)){
            printf("uniting %d and %d\n", a, b); 
            unite_sets(a, b);
        }
    }
}

int main(){
    // Initialize Graph
    edges.push_back(make_tuple(1,2,3));
    edges.push_back(make_tuple(2,3,5));
    edges.push_back(make_tuple(3,4,9));
    edges.push_back(make_tuple(3,6,3));
    edges.push_back(make_tuple(4,6,7));
    edges.push_back(make_tuple(6,5,2));
    edges.push_back(make_tuple(1,5,5));

    // Sort Edges
    sortEdges();

    // Initialize Sets
    initialize_sets();

    // Kruskal's Algorithm
    kr_algo();

    // Print Final Edges
}