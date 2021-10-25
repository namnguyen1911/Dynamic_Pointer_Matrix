#include "loadFile.h"

bool loadFile(float **  matrix1, float **  matrix2, int &rowOfMatrix1, int &colOfMatrix1, int &rowOfMatrix2, int &colOfMatrix2) {
    int outOfLoop = 0, row = 0, col = 0;
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
                rowOfMatrix1 = stof(input);
                //Read the number of columns
                myfile >> input;
                colOfMatrix1 = stof(input);     

                for (int i = 0; i < rowOfMatrix1; i++)
                {
                    for (int j = 0; j < colOfMatrix1; j++)
                    {
                        myfile >> input;
                        matrix1[i][j] = stof(input);                   
                    }
                }                                
            }
            else if (outOfLoop == 1) {
                //Read the number of rows
                myfile >> input;
                rowOfMatrix2 = stof(input);
                //Read the number of columns
                myfile >> input;
                colOfMatrix2 = stof(input);

                for (int i = 0; i < rowOfMatrix2; i++)
                {
                    for (int j = 0; j < colOfMatrix2; j++)
                    {
                        myfile >> input;
                        matrix2[i][j] = stof(input);                   
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