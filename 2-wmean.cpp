#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;


int main() {
    double m; // weighted mean
    double m1, m2;
    int n; // number of elements
    cin >> n;
    vector<int> x(n); // array
    for(int x_i = 0; x_i < n; x_i++){
       cin >> x[x_i];
    }
    vector<int> w(n); // weights
    for(int w_i = 0; w_i < n; w_i++){
       cin >> w[w_i];
    }
    m1 = 0; m2 = 0;
    for(int i = 0; i < n; i++){
        m1 = m1 + x[i]*w[i];
        m2 = m2 + w[i];        
    }
    m = (m1/m2);
    
    printf("%.1lf",m);
    return 0;
}
