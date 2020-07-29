#include <bits/stdc++.h>

using namespace std;

void x_derivatives(int exponent_x){
    // Based on second term in polynomial multiplication (x+h)^a
    int power_term = exponent_x - 1;
    int coeficient_term = exponent_x;
    cout << to_string(coeficient_term) << "x^" << to_string(power_term) << endl;
}

int main(){
    x_derivatives(2);
    x_derivatives(3);
    x_derivatives(5);
    return 0;
}