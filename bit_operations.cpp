#include <bits/stdc++.h>

using namespace std;

void printBitRepresentation(int number){
    for(int i=31; i>=0; --i){
        if (number & (1<<i)){
            cout << "1";
        }
        else{
            cout << "0";
        }
    }
    cout << "\n";
}

void print_BinarySet(int number){
    for(int i = 0; i < 32; ++i){
        if (number & (1<<i)){
            cout << i << " ";
        }
    }
    cout << "\n";
}

int main(){
    int sample_number = 58;
    printBitRepresentation(sample_number);
    
    // Counting bits
    cout << __builtin_clz(sample_number) << endl; // Count zeroes at beginning of number
    cout << __builtin_ctz(sample_number) << endl; // Count zeroes at end of number
    cout << __builtin_popcount(sample_number) << endl; // Count number of ones in the number
    cout << __builtin_parity(sample_number) << endl; // Parity (even or odd) of number of ones

    // Set Implementation
    int variable = 0;
    variable |= (1<<1);
    variable |= (1<<3);
    variable |= (1<<4);
    variable |= (1<<8);
    cout << __builtin_popcount(variable) << endl;

    // Set Operations
    int x = (1 << 1) | (1 << 3) | (1 << 4) | (1 << 8); // set x = {1, 3, 4, 8}
    int y = (1 << 3) | (1 << 6) | (1 << 8) | (1 << 9); // set y = {3, 6, 8, 9}
    int z = x|y; // union of set x and set y
    cout << __builtin_popcount(z) << endl;

    // Print all elements of set
    print_BinarySet(z);

    return 0;
}