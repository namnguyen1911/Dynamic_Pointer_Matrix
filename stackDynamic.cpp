
float ** addition(float matrix1[][100], float matrix2[][100], int row1, int col1, int row2, int col2) {
    if(col1 != row2)
        return nullptr;
    else {
        float ** result;
        result = new float *[row1];

        for(int i = 0; i < row1; i++) {
            result[i] = new float[col2];
        }

        for(int i = 0; i < row1; i++) {
            for(int j = 0; j < col2; j++) {
                result[i][j] = matrix1[i][j] + matrix2[i][j];
            }
        }
        return result;
    }
}