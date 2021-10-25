#include <iostream>
#include "loadFile.h"
using namespace std;

float ** createMatrix(const char * str, int &rowOfMatrix, int &colOfMatrix);
void display(float ** matrix, int row, int col);
float ** add(float ** matrix1, float ** matrix2, int rowOfMatrix1, int colOfMatrix1, int rowOfMatrix2, int colOfMatrix2);
float ** sub(float ** matrix1, float ** matrix2, int rowOfMatrix1, int colOfMatrix1, int rowOfMatrix2, int colOfMatrix2);
float ** multiply(float ** matrix1, float ** matrix2, int rowOfMatrix1, int colOfMatrix1, int rowOfMatrix2, int colOfMatrix2);
void remove(float ** matrix, int rowOfMatrix);

int main() {
    
    //Initilization
    bool outOfLoop = true;
    int option = 0, rowOfMatrix1 = 0, colOfMatrix1 = 0, rowOfMatrix2 = 0, colOfMatrix2 = 0;
    float ** matrix1, ** matrix2, ** result;

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
            //Create matrix1 of size 100
            matrix1 = new float *[100];
            //Create matrix2 of size 100
            matrix2 = new float *[100];
            for(int i = 0; i < 100; i++) {
                matrix1[i] = new float[100];
                matrix2[i] = new float[100];
            }

            if(!loadFile(matrix1, matrix2, rowOfMatrix1, colOfMatrix1, rowOfMatrix2, colOfMatrix2)) {
                remove(matrix1,100);
                remove(matrix2,100);
                return 0;
            }

            break;
        case 2: 
            //Create the first 2D dynamic array
            matrix1 = createMatrix("Enter the size of the first matrix (a b): ", rowOfMatrix1, colOfMatrix1);

            //Create the second 2D dynamic array
            matrix2 = createMatrix("Enter the size of the second matrix (a b): ", rowOfMatrix2, colOfMatrix2); 
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

    //Deallocate memories
    remove(matrix1, rowOfMatrix1);
    remove(matrix2, rowOfMatrix2);
    remove(result, rowOfMatrix1);

    return 0;
}

float ** createMatrix(const char * str, int &rowOfMatrix, int &colOfMatrix) {
    //Initialization
    float ** matrix;

    //Remove input buffer
    cin.clear();
    cin.ignore(999, '\n');

    cout << str;
    cin >> rowOfMatrix >> colOfMatrix;


    //Create 2D dynamic array
    matrix = new float*[rowOfMatrix];
    for(int i = 0; i < rowOfMatrix; i++) {
        matrix[i] = new float[colOfMatrix]{};
    }

    //Take value from users
    for(int i = 0; i < rowOfMatrix; i++) {
        cout <<"Enter the " << i + 1 << " row: ";
        for(int j = 0; j < colOfMatrix; j++) {
            cin >> matrix[i][j]; 
        }
    }

    return matrix;
}

void display(float ** matrix, int row, int col) {
    for(int i = 0; i < row; i++) {
        for(int j = 0; j < col; j++) {
            cout << matrix[i][j] << " "; 
        }
        cout << '\n';
    }
}

float ** add(float ** matrix1, float ** matrix2, int rowOfMatrix1, int colOfMatrix1, int rowOfMatrix2, int colOfMatrix2) {
    if(colOfMatrix1 != colOfMatrix2 || rowOfMatrix1 != rowOfMatrix2)
        return nullptr;
    else {
        float ** result;
        result = new float *[rowOfMatrix1];

        for(int i = 0; i < rowOfMatrix1; i++) {
            result[i] = new float[colOfMatrix2];
        }

        for(int i = 0; i < rowOfMatrix1; i++) {
            for(int j = 0; j < colOfMatrix2; j++) {
                result[i][j] = matrix1[i][j] + matrix2[i][j];
            }
        }
        return result;
    }
}

float ** sub(float ** matrix1, float ** matrix2, int rowOfMatrix1, int colOfMatrix1, int rowOfMatrix2, int colOfMatrix2) {
    if(colOfMatrix1 != colOfMatrix2 || rowOfMatrix1 != rowOfMatrix2)
        return nullptr;
    else {
        float ** result;
        result = new float *[rowOfMatrix1];

        for(int i = 0; i < rowOfMatrix1; i++) {
            result[i] = new float[colOfMatrix2];
        }

        for(int i = 0; i < rowOfMatrix1; i++) {
            for(int j = 0; j < colOfMatrix2; j++) {
                result[i][j] = matrix1[i][j] - matrix2[i][j];
            }
        }
        return result;
    }
}

float ** multiply(float ** matrix1, float ** matrix2, int rowOfMatrix1, int colOfMatrix1, int rowOfMatrix2, int colOfMatrix2) {
    int sum = 0;
    if(colOfMatrix1 != rowOfMatrix2)
        return nullptr;
    else {
        float ** result;
        result = new float *[rowOfMatrix1];

        for(int i = 0; i < rowOfMatrix1; i++) {
            result[i] = new float[colOfMatrix2];
        }

        for(int i = 0; i < rowOfMatrix1; i++) {
            for(int j = 0; j < colOfMatrix2; j++) {
                sum = 0;
                for(int k = 0; k < colOfMatrix1; k++) {
                    sum += (matrix1[i][k] * matrix2[k][j]);
                }
                result[i][j] = sum;
            }
        }

        return result;
    }
}

void remove(float ** matrix, int rowOfMatrix) {
    for(int i = 0; i < rowOfMatrix; i++) {
        delete[] matrix[i];
    }
    delete[] matrix;
}






