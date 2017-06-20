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
    int n; // number of elements
    int d = 1;
    double se;
    double q1,q2,q3;   
    cin >> n;
    double x[n]; // array X
    
    for(int i = 0; i < n; i++){
       cin >> x[i];
    }
    
    // bubble sort
    while (d > 0) { 
        d = 0;
        for (int i = 1; i < n; i++) {
            if (x[i-1] > x[i]) {
                se = x[i-1];
                x[i-1] = x[i];
                x[i] = se;
                d = d + 1;
            }
        }
    }
    double l[n]; // array L
    double u[n]; // array U
    
    if (n % 2 == 0) {
        q2 = median(n,x);
        for (int i = 0; i < (n/2); i++) {
            l[i] = x[i];
        }
        q1 = median((n/2),l);
        d = 0;
        for (int i = (n/2); i < n; i++) {
            u[d] = x[i];
            d++;
        }
        q3 = median((n/2),u);
    } else {
        q2 = x[n/2];
        for (int i = 0; i < floor(n/2); i++) {
            l[i] = x[i];
        }
        q1 = median((n/2),l);
        d = 0;
        for (int i = (n/2)+1; i < n; i++) {
            u[d] = x[i];
            d++;
        }
        q3 = median((n/2),u);
    }
    
    cout << q1 << endl;
    cout << q2 << endl;
    cout << q3 << endl;
    
    return 0;
}
