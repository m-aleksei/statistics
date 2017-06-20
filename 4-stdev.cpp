#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;


int main() {
    int n; // number of elements
    double mean;
    double stdev;
    cin >> n;
    vector<int> x(n); // array
    for(int x_i = 0; x_i < n; x_i++){
       cin >> x[x_i];
    }
    mean = 0;
    for(int i = 0; i < n; i++){
       mean = mean + x[i];
    }
    mean = mean/n;
    stdev = 0;
    for(int i = 0; i < n; i++){
       stdev = stdev + pow((x[i]-mean),2);
    }
    stdev = sqrt(stdev/n);
    printf("%.1lf",stdev);
    return 0;
}
