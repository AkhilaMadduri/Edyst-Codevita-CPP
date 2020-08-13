#include <iostream>
#include <cmath>
#include<cstdio>
#include <vector>
#include<iomanip>
using namespace std;
vector<double> gauss(vector< vector<double> > A) {
    int n = A.size();
    for (int i=0; i<n; i++) {
        double maxEl = abs(A[i][i]);
        int maxRow = i;
        for (int k=i+1; k<n; k++) {
            if (abs(A[k][i]) > maxEl) {
                maxEl = abs(A[k][i]);
                maxRow = k;
            }
        }
        for (int k=i; k<n+1;k++) {
            double tmp = A[maxRow][k];
            A[maxRow][k] = A[i][k];
            A[i][k] = tmp;
        }
        for (int k=i+1; k<n; k++) {
            double c = -A[k][i]/A[i][i];
            for (int j=i; j<n+1; j++) {
                if (i==j) {
                    A[k][j] = 0;
                } else {
                    A[k][j] += c * A[i][j];
                }
            }
        }
    }
    vector<double> x(n);
    for (int i=n-1; i>=0; i--) {
        x[i] = A[i][n]/A[i][i];
        for (int k=i-1;k>=0; k--) {
            A[k][n] -= A[k][i] * x[i];
        }
    }
    return x;
}
int main() {
    int n,f,h;
    cin>>f;
    for(h=0;h<f;h++){
    cin >> n;
    vector<double> line(n+1,0);
    vector< vector<double> > A(n,line);
    for (int i=0; i<n; i++) {
        for (int j=0; j<n; j++) {
            cin >> A[i][j];
        }
        cin >> A[i][n];
    }
    vector<double> x(n);
    x = gauss(A);
    for (int i=0; i<n; i++) {
        if (x[i]>=0){
            if (i==0) printf("%.2f",x[i]);
            else
        printf("\n%.2f",x[i]);
        }
        else{
            cout<<"Unsolvable";
            break;}
    }
    cout << endl;}
}




