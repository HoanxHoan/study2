#include <stdio.h>

int isValid(int sudoku[9][9]) {
    int row[9][9] = {0};
    int col[9][9] = {0};
    int subgrid[3][3][9] = {0};

    for (int i = 0; i < 9; i++) {
        for (int j = 0; j < 9; j++) {
            int num = sudoku[i][j];
            if (num < 1 || num > 9 || row[i][num - 1] || col[j][num - 1] || subgrid[i/3][j/3][num - 1]) {
                return 0;
            }
            row[i][num - 1] = 1;
            col[j][num - 1] = 1;
            subgrid[i/3][j/3][num - 1] = 1;
        }
    }
    return 1;
}

int main() {
    int sudoku[9][9] ;
    for (int i = 0; i < 9; i++) {
        for (int j = 0; j < 9; j++) {
            scanf("%d",&sudoku[i][j]);
        }
    }
    int result = isValid(sudoku);
    if (result) {
        printf("1\n");
    } else {
        printf("0\n");
    }

    return 0;
}

