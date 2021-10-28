#include <iostream>
#include <stdlib.h>
#include <fstream>
#include <string>
#include <chrono>

using namespace std;
using namespace std::chrono;

void addition (float arr1[][100], float arr2[][100], int n1, int n2, int m1, int m2);
void subtraction (float arr1[][100], float arr2[][100], int n1, int n2, int m1, int m2);
void multiplication(float arr1[][100], float arr2[][100], int n1, int n2, int m1, int m2);


int main() {
    
    //Initilization
    bool outOfLoop = true;
    int option = 0, rowOfMatrix1 = 0, colOfMatrix1 = 0, rowOfMatrix2 = 0, colOfMatrix2 = 0;
    string toFloat;
    string::size_type sz;
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
            {
                ifstream fp("file.txt");
                if (! fp) {
                    cout << "Error, file couldn't be opened" << endl; 
                    return 1; 
                }
                fp >> rowOfMatrix1;
                fp >> colOfMatrix1;
                for(int row = 0; row < rowOfMatrix1; row++) {  // stop loops if nothing to read
                    for(int column = 0; column < colOfMatrix1; column++){
                        fp >> toFloat;
                        arr1[row][column] = stof(toFloat, &sz);
                        if ( ! fp ) {
                            cout << "Error reading file for element " << row << "," << column << endl; 
                            return 1; 
                        }
                    }
                }
                fp >> rowOfMatrix2;
                fp >> colOfMatrix2;
                for(int row = 0; row < rowOfMatrix2; row++) {  // stop loops if nothing to read
                    for(int column = 0; column < colOfMatrix2; column++){
                        fp >> toFloat;
                        arr2[row][column] = stof(toFloat, &sz);
                        if ( ! fp ) {
                            cout << "Error reading file for element " << row << "," << column << endl; 
                            return 1; 
                        }
                    }
                }
            }
            break;
        case 2:
        {
            cout << "Enter number of row for matrix 1: ";
            cin >> rowOfMatrix1;
            cout << "Enter number of column for matrix 1: ";
            cin >> colOfMatrix1;
            for(int i = 0; i < rowOfMatrix1; i++){
                for(int n = 0; n < colOfMatrix1; n++){
                    cout << "Enter value for space " << rowOfMatrix1 + 1 << "x" << colOfMatrix1 + 1 << ": ";
                    cin >> arr1[i][n];
                }
            }
            cout << "Enter number of row for matrix 2: ";
            cin >> rowOfMatrix2;
            cout << "Enter number of column for matrix 2: ";
            cin >> colOfMatrix2;
            for(int i = 0; i < rowOfMatrix2; i++){
                for(int n = 0; n < colOfMatrix2; n++){
                    cout << "Enter value for space " << rowOfMatrix2 + 1 << "x" << colOfMatrix2 + 1 << ": ";
                    cin >> arr2[i][n];
                }
            }
            cout << "Matrix 1:\n";
            for(int i = 0; i < rowOfMatrix1; i++){
                for(int n = 0; n < colOfMatrix1; n++){
                    cout << arr1[i][n] << " ";
                }
                cout << endl;
            }
            cout << "Matrix 2:\n";
            for(int i = 0; i < rowOfMatrix2; i++){
                for(int n = 0; n < colOfMatrix2; n++){
                    cout << arr1[i][n] << " ";
                }
                cout << endl;
            }

        }
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
        cout << "4. Go Back\n";
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
                addition(arr1, arr2, rowOfMatrix1, colOfMatrix1, rowOfMatrix2, colOfMatrix2); break;
            //Subtraction
            case 2:
                subtraction(arr1, arr2, rowOfMatrix1, colOfMatrix1, rowOfMatrix2, colOfMatrix2); break;
            //Multiplication
            case 3:
                multiplication(arr1, arr2, rowOfMatrix1, colOfMatrix1, rowOfMatrix2, colOfMatrix2); break;
            case 4:
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
        case 1: 
            {
                ifstream fp("file.txt");
                if (! fp) {
                    cout << "Error, file couldn't be opened" << endl; 
                    return 1; 
                }    
                fp >> rowOfMatrix1;
                fp >> colOfMatrix2;
                for(int row = 0; row < rowOfMatrix1; row++) {  // stop loops if nothing to read
                    for(int column = 0; column < colOfMatrix1; column++){
                        fp >> toFloat;
                        arr1[row][column] = stof(toFloat, &sz);
                        if ( ! fp ) {
                            cout << "Error reading file for element " << row << "," << column << endl; 
                            return 1; 
                        }
                    }
                }
                fp >> rowOfMatrix2;
                fp >> colOfMatrix2;
                for(int row = 0; row < rowOfMatrix2; row++) {  // stop loops if nothing to read
                    for(int column = 0; column < colOfMatrix2; column++){
                        fp >> toFloat;
                        arr2[row][column] = stof(toFloat, &sz);
                        if ( ! fp ) {
                            cout << "Error reading file for element " << row << "," << column << endl; 
                            return 1; 
                        }
                    }
                }
                cout << "Matrix 1:\n";
                for(int i = 0; i < rowOfMatrix1; i++){
                    for(int n = 0; n < colOfMatrix1; n++){
                        cout << arr1[i][n] << " ";
                    }
                    cout << endl;
                }
                cout << "Matrix 2:\n";
                for(int i = 0; i < rowOfMatrix2; i++){
                    for(int n = 0; n < colOfMatrix2; n++){
                        cout << arr1[i][n] << " ";
                    }
                    cout << endl;
                }
            }
            break;
        case 2:
        {
            cout << "Enter number of row for matrix 1: ";
            cin >> rowOfMatrix1;
            cout << "Enter number of column for matrix 1: ";
            cin >> colOfMatrix1;
            for(int i = 0; i < rowOfMatrix1; i++){
                for(int n = 0; n < colOfMatrix1; n++){
                    cout << "Enter value for space " << rowOfMatrix1 + 1 << "x" << colOfMatrix1 + 1 << ": ";
                    cin >> arr1[i][n];
                }
            }
            cout << "Enter number of row for matrix 2: ";
            cin >> rowOfMatrix2;
            cout << "Enter number of column for matrix 2: ";
            cin >> colOfMatrix2;
            for(int i = 0; i < rowOfMatrix2; i++){
                for(int n = 0; n < colOfMatrix2; n++){
                    cout << "Enter value for space " << rowOfMatrix2 + 1 << "x" << colOfMatrix2 + 1 << ": ";
                    cin >> arr2[i][n];
                }
            }
            cout << "Matrix 1:\n";
            for(int i = 0; i < rowOfMatrix1; i++){
                for(int n = 0; n < colOfMatrix1; n++){
                    cout << arr1[i][n] << " ";
                }
                cout << endl;
            }
            cout << "Matrix 2:\n";
            for(int i = 0; i < rowOfMatrix2; i++){
                for(int n = 0; n < colOfMatrix2; n++){
                    cout << arr1[i][n] << " ";
                }
                cout << endl;
            }

        } 
            break;
        default: 
            cout << "Wrong input. Exit\n";
            exit(1); 
    }
                break;
            //Come back to menu if user enter something else
            default: continue;
        }
    }
    return 0;
}

void addition (float arr1[][100], float arr2[][100], int n1, int n2, int m1, int m2){
    auto start = high_resolution_clock::now();
    if(n1 == n2 && m1 == m2){
        cout << "Result after addtion is:\n";
        for(int i = 0; i < n1; i++){
            for(int s = 0; s < m1; s++){
                arr1[i][s] += arr2[i][s];
                cout << arr1[i][s] << " ";
            }
            cout << endl;
        }
    }
    else cout << "Cannot perform addition due to wrong matrices dimension.\n";
    auto stop = high_resolution_clock::now();
    auto duration = duration_cast<nanoseconds>(stop - start);
    cout << "The operation runs in " << duration.count() << "nanoseconds" << endl;
}

void subtraction (float arr1[][100], float arr2[][100], int n1, int n2, int m1, int m2){
    auto start = high_resolution_clock::now();
    if(n1 == n2 && m1 == m2){
        cout << "Result after subtraction is:\n";
        for(int i = 0; i < n1; i++){
            for(int s = 0; s < m1; s++){
                arr1[i][s] -= arr2[i][s];
                cout << arr1[i][s] << " ";
            }
            cout << endl;
        }
    }
    else cout << "Cannot perform subtration due to wrong matrices dimension.\n";
    auto stop = high_resolution_clock::now();
    auto duration = duration_cast<nanoseconds>(stop - start);
    cout << "The operation runs in " << duration.count() << "nanoseconds" << endl;
}

void multiplication(float arr1[][100], float arr2[][100], int n1, int n2, int m1, int m2){
    auto start = high_resolution_clock::now();
    int result[100][100];
    if( n1 != m2) cout << "The number of column in matrix 1 does not match the number of row in matrix 2, so that the operation cannot be done.\n" ;
    else{
        cout << "Result after multiplication is:\n";
        for (int i = 0; i < n1; i++) {
            for (int j = 0; j < m2; j++) {
                result[i][j] = 0;
                for (int k = 0; k < n2; k++) {result[i][j] += arr1[i][k] * arr2[k][j];}
                cout << result[i][j] << " ";
            }
            cout << endl;
        }
    }
    auto stop = high_resolution_clock::now();
    auto duration = duration_cast<nanoseconds>(stop - start);
    cout << "The operation runs in " << duration.count() << "nanoseconds" << endl;
}