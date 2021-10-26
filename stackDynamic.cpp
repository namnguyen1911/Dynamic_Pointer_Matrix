#include <iostream>
#include <stdlib.h>

using namespace std;

void addition (int arr1[][100], int arr2[][100], int n, int m){
    for(int i = 0; i < n; i++){
        for(int s = 0; s < m; s++){
            arr1[n][m] += arr2[n][m];
        }
    }
}

void subtraction (int arr1[][100], int arr2[][100], int n, int m){
    for(int i = 0; i < n; i++){
        for(int s = 0; s < m; s++){
            arr1[n][m] -= arr2[n][m];
        }
    }
}

void multiplication(int arr1[][100], int arr2[][100], const int n1, const int n2, const int m1, const int m2){
    int result[n1][m2];
    if( n1 != m2) cout << "The number of column in matrix 1 does not match the number of row in matrix 2, so that the operation cannot be done./n" ;
    else{
        for (int i = 0; i < n1; i++) {
            for (int j = 0; j < m2; j++) {
                result[i][j] = 0;
                for (int k = 0; k < n2; k++) {result[i][j] += arr1[i][k] * arr2[k][j];}
                cout << result[i][j] << "\t";
            }
            cout << endl;
        }
    }
}