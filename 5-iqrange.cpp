#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

double median (int k, double arr[]) { // медиана
    int p, r;
    int t = 1; // число перестановок
    double es;  
    // bubble sort
    while (t > 0) { 
        t = 0;
        for (p = 1; p < k; p++) {
            if (arr[p-1] > arr[p]) {
                es = arr[p-1];
                arr[p-1] = arr[p];
                arr[p] = es;
                t++;
            }
        }
    }
    if (k % 2 == 0) {
        p = floor((k-1)/2);
        r = ceil(k/2);
        es = (arr[p]+arr[r])/2;
    } else {
        p = floor((k-1)/2);
        es = arr[p];
    }
    return es;
}

int main() {
    int n; // number of elements X,F
    int d;
    double se;
    double q1,q2,q3;   
    cin >> n;
    double x[n]; // array X
    double f[n]; // array F
    
    // elements
    for(int i = 0; i < n; i++){
       cin >> x[i];
    }
    // frequencies
    for(int i = 0; i < n; i++){
       cin >> f[i];
    }
    int m = 0; // number of elements Y
    for(int i = 0; i < n; i++){
       m = m + f[i];
    }
    double y[m]; // array Y
    d = 0;
    for(int i = 0; i < n; i++){
       for(int j = 0; j < f[i]; j++){
           y[d] = x[i];
           d++;
       }
    }
    
    // bubble sort
    d = 1;
    while (d > 0) { 
        d = 0;
        for (int i = 1; i < m; i++) {
            if (y[i-1] > y[i]) {
                se = y[i-1];
                y[i-1] = y[i];
                y[i] = se;
                d = d + 1;
            }
        }
    }
    double l[m]; // array L
    double u[m]; // array U
    
    if (m % 2 == 0) {
        for (int i = 0; i < (m/2); i++) {
            l[i] = y[i];
        }
        q1 = median((m/2),l);
        d = 0;
        for (int i = (m/2); i < m; i++) {
            u[d] = y[i];
            d++;
        }
        q3 = median((m/2),u);
    } else {
        for (int i = 0; i < floor(m/2); i++) {
            l[i] = y[i];
        }
        q1 = median((m/2),l);
        d = 0;
        for (int i = (m/2)+1; i < m; i++) {
            u[d] = y[i];
            d++;
        }
        q3 = median((m/2),u);
    }
    
    q2 = q3 - q1;
    printf("%.1lf",q2);

    
    return 0;
}
