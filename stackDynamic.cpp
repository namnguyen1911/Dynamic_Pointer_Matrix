#include <iostream>
#include <stdlib.h>
#include <fstream>

using namespace std;

void addition (int arr1[][100], int arr2[][100], int n, int m);
void subtraction (int arr1[][100], int arr2[][100], int n, int m);
void multiplication(int arr1[][100], int arr2[][100], const int n1, const int n2, const int m1, const int m2);


int main() {
    
    //Initilization
    bool outOfLoop = true;
    int option = 0, rowOfMatrix1 = 0, colOfMatrix1 = 0, rowOfMatrix2 = 0, colOfMatrix2 = 0;
    float arr1[100][100], arr2[100][100];

    //Load file or input from key board
    cout << "=============================\n";
    cout << "Input menu\n";
    cout << "=============================\n";
    cout << "0. Exit\n";
    cout << "1. Load a file\n";
    cout << "2. Input from keyboard\n";
    cout << "=============================\n";
    cout << "Enter your option: ";
    cin >> option;

    switch(option) {
        case 0: return 0;
        case 1: 
            ifstream fp("file.txt");
            if (! fp) {
                cout << "Error, file couldn't be opened" << endl; 
                return 1; 
            }    
            for(int row = 0; row < 100; row++) {  // stop loops if nothing to read
            for(int column = 0; column < 100; column++){
                    fp >> arr1[row][column];
                    if ( ! fp ) {
                    cout << "Error reading file for element " << row << "," << column << endl; 
                    return 1; 
                    }
                }
            };
            break;
        case 2: 
            break;
        default: 
            cout << "Wrong input. Exit\n";
            exit(1); 
    }

    //Remove input buffer
    cin.clear();
    cin.ignore(999, '\n');

    //Menu
    while(outOfLoop) {
        cout << "=============================\n";
        cout << "Operation menu\n";
        cout << "=============================\n";
        cout << "0. Exit\n";
        cout << "1. Addition\n";
        cout << "2. Subtraction\n";
        cout << "3. Multiplication\n";
        cout << "4. Create other two matrices\n";
        cout << "=============================\n";
        cout << "Enter your option: ";
        cin >> option;

        //Remove input buffer
        cin.clear();
        cin.ignore(999, '\n');


        switch(option) {
            //Exit if user entere 0
            case 0: outOfLoop = false; break;
            //Addition
            case 1: 
                result = add(matrix1, matrix2, rowOfMatrix1, colOfMatrix1, rowOfMatrix2, colOfMatrix2);
                if(result != nullptr) {
                    cout <<"The addition's result is:\n";
                    display(result, rowOfMatrix1, colOfMatrix2);
                }
                else 
                    cout << "Cannot add\n";
                break;
            //Subtraction
            case 2:
                result = sub(matrix1, matrix2, rowOfMatrix1, colOfMatrix1, rowOfMatrix2, colOfMatrix2);
                if(result != nullptr) {
                    cout <<"The subtraction's result is:\n";
                    display(result, rowOfMatrix1, colOfMatrix2);
                }
                else 
                    cout << "Cannot subtract\n";
                break;
            //Multiplication
            case 3:
                result = multiply(matrix1, matrix2, rowOfMatrix1, colOfMatrix1, rowOfMatrix2, colOfMatrix2);
                if(result != nullptr) {
                    cout <<"The multiplication's result is:\n";
                    display(result, rowOfMatrix1, colOfMatrix2);
                }
                else 
                    cout << "Cannot multiply\n";
                break;
            case 4:
                //Remove the old matrices
                remove(matrix1, rowOfMatrix1);
                remove(matrix2, rowOfMatrix2);
                remove(result, rowOfMatrix1);

                //Create new matrices
                //Load file or input from key board
                cout << "=============================\n";
                cout << "Input menu\n";
                cout << "=============================\n";
                cout << "0. Exit\n";
                cout << "1. Load a file\n";
                cout << "2. Input from keyboard\n";
                cout << "=============================\n";
                cout << "Enter your option: ";
                cin >> option;

                switch(option) {
                    case 0: return 0;
                    case 1: loadFile(matrix1, matrix2, rowOfMatrix1, colOfMatrix1, rowOfMatrix2, colOfMatrix2); break;
                    case 2: 
                        //Create the first 2D dynamic array
                        matrix1 = createMatrix("Enter the size of the first matrix (a b): ", rowOfMatrix1, colOfMatrix1);

                        //Create the second 2D dynamic array
                        matrix2 = createMatrix("Enter the size of the second matrix (a b): ", rowOfMatrix2, colOfMatrix2); 
                        break;
                    default: continue; 
                }
                break;
            //Come back to menu if user enter something else
            default: continue;
        }
    }
    return 0;
}

void addition (float arr1[][100], float arr2[][100], int n, int m){
    for(int i = 0; i < n; i++){
        for(int s = 0; s < m; s++){
            arr1[n][m] += arr2[n][m];
        }
    }
}

void subtraction (float arr1[][100], float arr2[][100], int n, int m){
    for(int i = 0; i < n; i++){
        for(int s = 0; s < m; s++){
            arr1[n][m] -= arr2[n][m];
        }
    }
}

void multiplication(float arr1[][100], float arr2[][100], const int n1, const int n2, const int m1, const int m2){
    int result[100][100];
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