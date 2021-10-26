#ifndef LOADFILE_H
#define LOADFILE_H

#include <iostream>
#include <fstream>
#include <string>
#include "matrix.h"
using namespace std;

bool loadFile(float **  matrix1, float ** matrix2, int &rowOfMatrix1, int &colOfMatrix1, int &rowOfMatrix2, int &colOfMatrix2);
bool loadFile(Matrix &matrix1, Matrix &matrix2);
#endif //end LOADFILE_H

