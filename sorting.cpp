#include <bits/stdc++.h>

using namespace std;
    void printArray(int v[], int n){
        for(int i=0; i<n; ++i){
            cout << v[i] << " ";
        }
        printf("\n");
    }

    // Bubble Sort O(n^2)
    void bubbleSort(int v[], int n){
        for(int i=0; i<n; ++i){
            for(int j=0; j<n-1; ++j){
                if(v[j] > v[j+1]){
                    swap(v[j], v[j+1]);
                }
            }
        }
    }

    // Merge Sorting Algorithm
    void initiate_mergeSort(int v[], int l_bound, int middle, int u_bound){
        int temp_array[25];
        
        // Initialize Variables
        int i, left_index(middle - 1), number_elements(u_bound - l_bound + 1), temp_position(l_bound);

        while((l_bound <= left_index) && (middle <= u_bound)){
            if (v[l_bound] <= v[middle]){
                temp_array[temp_position++] = v[l_bound++];
            }
            else{
                temp_array[temp_position++] = v[middle++];
            }
        }

        while(l_bound <= left_index){
            temp_array[temp_position++] = v[l_bound++];
        }

        while(middle <= u_bound){
            temp_array[temp_position++] = v[middle++];
        }
        
        for(i = 0; i < number_elements; ++i){
            v[u_bound--] = temp_array[u_bound];
        }

    }

    // Merge Sort O(nlogn)
    void MergeSort(int v[], int l_bound, int u_bound){
        if(u_bound > l_bound){
            int middle = l_bound + (u_bound - l_bound)/2;

            // Divide into Two Halves
            MergeSort(v, l_bound, middle);
            MergeSort(v, middle + 1, u_bound);

            // Sort
            initiate_mergeSort(v, l_bound, middle+1, u_bound);
        }
    }

    // Counting Sort O(n)
    void CountSort(int v[], int size_array){
        int out[10], count[100], max(v[0]);

        // find max
        for(int i = 1; i < size_array; ++i){
            if(v[i] > max){
                max = v[i];
            }
        }        

        // Store Count array with zeroes
        for(int i = 0; i <= max; ++i){
            count[i] = 0;
        }

        // Append elements in count array
        for(int i = 0; i < size_array; ++i){
            count[v[i]]++;
        }

        // Cumulative Sum
        for(int i = 1; i <= max; ++i){
            count[i] += count[i-1];
        }

        // Place elements in output array 
        for(int i = size_array - 1; i>=0; --i){
            out[count[v[i]] - 1] = v[i];
            count[v[i]]--;
        }

        for(int i = 0; i<size_array; ++i){
            v[i] = out[i];
        }

    }

    void sortList(int v[], int size_array){
        sort(v, v + size_array);
    }

    void sortVector(vector <int> v, int size_array){
        sort(v.begin(), v.end());
    }

    // Binary Search O(logn)
    void binarySearch(int v[], int size_array, int num_Find){
        int start = 0, end = size_array - 1;

        while(start <= end){
            int mid = (start+end)/2;
            if(v[mid] == num_Find){
                cout << mid << endl;
                break;
            }
            if(v[mid] > num_Find){
                end = mid - 1;
            }
            else{
                start = mid + 1;
            }
        }
    }

    //  C++ Implementation of binary search
    void quickBinarySearch(int v[], int size_array, int num_Find){
        auto result = equal_range(v, v+size_array, num_Find);
        cout << result.second-result.first << endl;
    }

    int main() {
        // Initialize array and N
        int n(10), v[7] = {5, 4, 9, 1, 0, 5, 7}, v_size(sizeof(v)/sizeof(v[0]));

        // Program
        quickBinarySearch(v, v_size, 1);

        // Print Array
        printArray(v, v_size);   
    }