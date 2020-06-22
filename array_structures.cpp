#include <bits/stdc++.h>

using namespace std;

// Sum of arr[0 --> index]
int BinaryTreeSum(int BITree[], int index){
    int sum = 0;
    index += 1; // index in Binary Tree is 1 more than index in array
    
    while(index > 0){
        sum += BITree[index]; // Add element to sum
        index -= index & (-index); // Get parent nodes of the index
    }
    return sum;
}

int SegmentTreeSum(int SEGTree[], int start_index, int end_index, int length_array){
    start_index += length_array;
    end_index += length_array;
    int sum = 0;
    
    while(start_index <= end_index){
        if(start_index % 2 == 1){
            sum += SEGTree[start_index++];
        }
        if(end_index % 2 == 0){
            sum += SEGTree[end_index--];
        }

        start_index /= 2;
        end_index /= 2;
    }
    return sum;
}

void updateSegmentTree(int SEGTree[], int length_arr, int index, int value){
    index += length_arr;
    SEGTree[index] += value;

    for(index /= 2; index >= 1; index /= 2){
        SEGTree[index] = SEGTree[2*index] + SEGTree[2*index+1];
    }
}

int *constructSegmentTree(int arr[], int length_arr){
    int length_SEGTree = 2*length_arr;
    int *SEGTree = new int[length_SEGTree];
    for (int i = 1; i < length_SEGTree; i++)
    {
        SEGTree[i] = 0;
    }

    for(int i = 0; i < length_arr ; ++i){
        updateSegmentTree(SEGTree, length_arr, i, arr[i]);
    }

    for (int i = 1; i < length_SEGTree; i++)
    {
        cout << SEGTree[i] << " ";
    }

    cout << "\n";
    return SEGTree;
}

// Update Binary Tree at specified Index
void updateBinaryTree(int BITree[], int length_arr, int index, int value){
    index += 1; // index in Binary Tree is 1 more than index in array

    while(index <= length_arr){
        BITree[index] += value;
        index += index & (-index); // Get parent nodes of the index
    }
}

int *constructBinaryTree(int arr[], int length_arr){
    int *BITree = new int[length_arr+1];
    for (int i = 1; i <= length_arr; i++)
    {
        BITree[i] = 0;
    }

    for(int i = 0; i < length_arr ; ++i){
        updateBinaryTree(BITree, length_arr, i, arr[i]);
    }

    for (int i = 1; i <= length_arr; i++)
    {
        cout << BITree[i] << " ";
    }

    cout << "\n";
    return BITree;
}

int main(){
    int arr[8] = {5, 8, 6, 3, 2, 7, 2, 6};
    int size_arr = sizeof(arr)/sizeof(arr[1]);
    int *BITree = constructBinaryTree(arr, size_arr);
    //updateBinaryTree(BITree, size_arr, 3, 100);
    cout << "Sum until and including including index 5 is " << BinaryTreeSum(BITree, 5) << endl;

    int *SEGTree = constructSegmentTree(arr, size_arr);
    cout << "Sum until and including index 5 is " << SegmentTreeSum(SEGTree, 0, 5, size_arr) << endl;
    return 0;
}