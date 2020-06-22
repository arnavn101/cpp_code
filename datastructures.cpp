#include <bits/stdc++.h>

using namespace std;


int main() {
    // Vectors are dynamically allocated arrays
    vector<int> v = {1, 2, 3}; 
    v.push_back(5);
    v.pop_back();
    v.push_back(2);
    cout << v.back() << endl;

    // Sets maintain collection of elements (unique elements)
    set<int> s = {2, 5, 6, 9};
    s.insert(1);
    cout << s.count(5) << endl;
    s.erase(5); // all instances
    s.erase(s.find(2)); // only 1 instances
    cout << s.size() << endl;

    // Map contains key-value pairs
    map<string, int> m;
    m["A"] = 1;
    m["B"] = 5;
    cout << m["A"] << endl;
    cout << m.count("random") << endl;

    // Print All keys and values of a map
    for(auto x : m){
        cout << x.first << " " << x.second << endl;
    }

    // Iterators : point to element in specific range
    set<int>::iterator it = s.begin();

    // Print All elements of set in Increasing order
    for(auto it = s.begin(); it != s.end(); ++it){
        cout << *it << endl;
    }

    // Check if element exists in a Set
    if(s.find(50) == s.end()){
        cout << "Does not Exist" << endl;
    }

    // Find value that is closest to x
    int x = 3;
    auto it_new = s.lower_bound(x);

    if(it_new == s.begin()){
        cout << *it_new << endl;
    }
    else if(it == s.end()){
        --it_new;
        cout << *it_new << endl;
    }
    else{
        int a = *it_new;
        it_new--;
        int b = *it_new;
    
        // Assumption --> b < x < a
        if(x-b < a-x){
            cout << b << endl;
        }
        else{
            cout << a << endl;
        }
    }

    // BitSet --> Array with values of 0 and 1
    bitset<10> b(string("0010010100"));
    bitset<10> b2(string("0010001010"));
    cout << b[4] << endl;
    cout << b2.count() << endl; // returns number of ones in array
    cout << (b&b2) << "\n" << (b|b2) << "\n";

    // Dequeue : insert and remove elements from both ends
    deque<int> d;
    d.push_back(5);
    d.push_front(4);
    d.pop_back();

    // Stack --> Add Element to top and remove element from top
    stack<int> stck;
    stck.push(5);
    stck.push(3);
    stck.pop();
    cout << stck.top() << endl;

    // Queue :  adding an element to the end and removing the first element
    queue<int> que;
    que.push(1);
    que.push(9);
    que.pop();
    cout << que.front() << endl;

    // Priority Queue : get or remove maximum or minimum element
    priority_queue<int> q1; // retrieve maximum element
    q1.push(7);
    q1.push(40);
    q1.push(-5);
    cout << q1.top() << endl;

    priority_queue<int, vector<int>, greater<int>> q2; // retrieve minimum element
    q2.push(7);
    q2.push(40);
    q2.push(-5);
    cout << q2.top() << endl;
}   