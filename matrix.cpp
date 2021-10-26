#include <iostream>
#include <fstream>
#include <string>
using namespace std;

const int SIZE = 100;

class Matrix {
    private:
        float **matrix;   
        int row;
        int col;
    public:
        Matrix();
        Matrix(int newRow, int newCol);
        int getRow();
        int getCol();
        float valueAt(int newRow, int newCol);
        void setRow(int newRow);
        void setCol(int newCol);
        void setValue(int newRow, int newCol, float newValue);
        friend Matrix operator+(Matrix matrix1, Matrix matrix2);
        friend Matrix operator-(Matrix matrix1, Matrix matrix2);
        friend Matrix operator*(Matrix matrix1, Matrix matrix2);
        void display();
        ~Matrix();

};

bool loadFile(Matrix  &matrix1, Matrix  &matrix2);
Matrix createMatrix(const char * str);

int main() {
    //Initialize
    int option = 0;
    bool outOfLoop = true;

    //Create matrices
    Matrix matrix1;
    Matrix matrix2;

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
        case 0: {return 0;}
        case 1: 
        {
            if(!loadFile(matrix1, matrix2)) {
                return 0;
            }
            break;
        }
        case 2: 
        {
            //Create the first 2D dynamic array
            matrix1 = createMatrix("Enter the size of the first matrix (a b): ");

            //Create the second 2D dynamic array
            matrix2 = createMatrix("Enter the size of the second matrix (a b): ");
            break;
        }
        default: 
        {
            cout << "Wrong input. Exit\n";
            exit(1); 
        }
            
    }

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
                if(matrix1.getRow() == matrix2.getRow() && matrix1.getCol() == matrix2.getCol()) {
                    cout <<"The addition's result is:\n";
                    Matrix result = matrix1 + matrix2;
                    result.display();
                }
                else 
                    cout << "Cannot add\n";
                break;
            //Subtraction
            case 2:
                if(matrix1.getRow() == matrix2.getRow() && matrix1.getCol() == matrix2.getCol()) {
                    cout <<"The subtraction's result is:\n";
                    Matrix result = matrix1 - matrix2;
                    result.display();
                }
                else 
                    cout << "Cannot subtract\n";
                break;
            //Multiplication
            case 3:
                if(matrix1.getCol() == matrix2.getRow()) {
                    cout <<"The subtraction's result is:\n";
                    Matrix result = matrix1 * matrix2;
                    result.display();
                }
                else 
                    cout << "Cannot multiply\n";
                break;
            case 4:
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
                    case 0: {return 0;}
                    case 1: 
                    {
                        if(!loadFile(matrix1, matrix2)) {
                            return 0;
                        }
                        break;
                    }
                        
                    case 2: 
                    {
                        //Create the first 2D dynamic array
                        matrix1 = createMatrix("Enter the size of the first matrix (a b): ");

                        //Create the second 2D dynamic array
                        matrix2 = createMatrix("Enter the size of the second matrix (a b): ");
                        break;
                    }
                        
                    default: 
                    {
                        cout << "Wrong input. Exit\n";
                        return 0; 
                    }
                }
                break;    
            //Come back to menu if user enter something else
            default: continue;
        }
    }


    return 0;
}

bool loadFile(Matrix &matrix1, Matrix &matrix2) {
    int outOfLoop = 0;
    string path, input;
    cin.clear();
    cin.ignore(999,'\n');
    cout << "Enter the path to your file (EX: C:/Pomona/Equations.txt): ";
    getline(cin, path, '\n');
    
    //Read from file
    ifstream myfile;
    myfile.open(path);
    if (myfile.is_open())
    {
        while(outOfLoop < 2) {
            if(outOfLoop == 0) {
                //Read the number of rows
                myfile >> input;
                matrix1.setRow(stof(input));
                //Read the number of columns
                myfile >> input;
                matrix1.setCol(stof(input));     

                for (int i = 0; i < matrix1.getRow(); i++)
                {
                    for (int j = 0; j < matrix1.getCol(); j++)
                    {
                        myfile >> input;
                        matrix1.setValue(i,j,stof(input));                   
                    }
                }                                
            }
            else if (outOfLoop == 1) {
                //Read the number of rows
                myfile >> input;
                matrix2.setRow(stof(input));
                //Read the number of columns
                myfile >> input;
                matrix2.setCol(stof(input));  

                for (int i = 0; i < matrix2.getRow(); i++)
                {
                    for (int j = 0; j < matrix2.getCol(); j++)
                    {
                        myfile >> input;
                        matrix2.setValue(i,j,stof(input));                   
                    }
                } 
                
            }

            outOfLoop++;
        }
        
        myfile.close();
        return true;
    }

    else return false;
}

Matrix createMatrix(const char * str) {
    //Initialization
    int rowOfMatrix = 0, colOfMatrix = 0;
    float input = 0.0;

    //Remove input buffer
    cin.clear();
    cin.ignore(999, '\n');

    cout << str;
    cin >> rowOfMatrix >> colOfMatrix;

    Matrix matrix(rowOfMatrix,colOfMatrix);

    //Take value from users
    for(int i = 0; i < rowOfMatrix; i++) {
        cout <<"Enter the " << i + 1 << " row: ";
        for(int j = 0; j < colOfMatrix; j++) {
            cin >> input; 
            matrix.setValue(i,j,input);
        }
    }

    matrix.display();

    return matrix;
}

Matrix::Matrix() {
    matrix = new float * [SIZE];

    for(int i = 0; i < SIZE; i++) {
        matrix[i] = new float[SIZE];
    }

    row = 0;
    col = 0;
}

Matrix::Matrix(int newRow, int newCol) {
    matrix = new float * [newRow];

    for(int i = 0; i < newRow; i++) {
        matrix[i] = new float[newCol];
    }

    row = newRow;
    col = newCol;
}

int Matrix::getRow() {
    return row;
}

void Matrix::setRow(int newRow) {
    row = newRow;
}

int Matrix::getCol() {
    return col;
}

void Matrix::setCol(int newCol) {
    col = newCol;
}

float Matrix::valueAt(int newRow, int newCol) {
    return matrix[newRow][newCol];
}

void Matrix::setValue(int newRow, int newCol, float newValue) {
    matrix[newRow][newCol] = newValue;
}

Matrix operator+(Matrix matrix1, Matrix matrix2) {
    
    Matrix result(matrix1.getRow(), matrix2.getCol());

    for(int i = 0; i < result.getRow(); i++) {
        for(int j = 0; j < result.getCol(); j++) {
            result.setValue(i,j,matrix1.valueAt(i,j) + matrix2.valueAt(i,j));
        }
    }
    return result;
}

Matrix operator-(Matrix matrix1, Matrix matrix2) {
    
    Matrix result(matrix1.getRow(), matrix2.getCol());

    for(int i = 0; i < result.getRow(); i++) {
        for(int j = 0; j < result.getCol(); j++) {
            result.setValue(i,j,matrix1.valueAt(i,j) - matrix2.valueAt(i,j));
        }
    }
    return result;
}

Matrix operator*(Matrix matrix1, Matrix matrix2) {
    int sum = 0;
    Matrix result(matrix1.getRow(), matrix2.getCol());

    for(int i = 0; i < matrix1.getRow(); i++) {
        for(int j = 0; j < matrix2.getCol(); j++) {
            sum = 0;
            for(int k = 0; k < matrix1.getCol(); k++) {
                sum += (matrix1.valueAt(i,k) * matrix2.valueAt(k,j));
            }
            result.setValue(i,j,sum);
        }
    }

    return result;
}

void Matrix::display() {
    for(int i = 0; i < row; i++) {
        for(int j = 0; j < col; j++) {
            cout << matrix[i][j] << " ";
        }
        cout << '\n';
    }
}

Matrix::~Matrix() {
    for(int i = 0; i < row; i++) {
        delete[] matrix[i];
    }
    delete[] matrix;
}


