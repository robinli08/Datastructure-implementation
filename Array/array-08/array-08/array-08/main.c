//
//  main.c
//  array-08
//
//  Created by robin on 6/25/16.
//  Copyright © 2016 robin. All rights reserved.
//

#include <stdio.h>

// Index (i-1)*(2n-i+2)/2+(j-i+1) 以行为主序顺序存储上三角部分，最后存储对角线下方的常量。对于第1行，存储n个元素，第2行存储n-1个元素，…，第p行存储(n-p+1)个元素，aij的前面有i-1行，共存储：n+(n-1) +…+(n-i+1)= =(i-1)*(2n-i+2)/2个元素，而aij 是它所在的行中要存储的第（j-i+1）个；所以，它是上三角存储顺序中的第 (i-1)*(2n-i+2)/2+(j-i+1)个，因此它在SA中的下标为：k=(i-1)*(2n-i+2)/2+j-i。

int main(int argc, const char * argv[]) {
    
    
    int Upper[5][5] = {3,9,1,4,7,
                    0,5,2,5,8,
                    0,0,5,2,4,
                    0,0,0,1,7,
                    0,0,0,0,9};
    
    int RowMajor[15];
    int Index;
    int i,j;
    
    printf("Two dimensional upper triangel array:\n");
    
    for (i = 0; i < 5; i++) {
        for (j = 0; j < 5; j ++) {
            printf("%3d",Upper[i][j]);
        }
        printf("\n");
    }
    
    for (i = 0; i < 5; i ++) {
        for (j = 0; j < 5; j ++) {
            if (i <= j) {
                Index = (11 - i) * i / 2 + (j - i);
                RowMajor[Index] = Upper[i][j];
            }
        }
    }
    
    printf("\n");
    
    printf("Row Major one dimensional array:\n");
    
    for (i = 0; i < 15; i++) {
        printf("%3d",RowMajor[i]);
    }
    
    printf("\n");
    
    return 0;
}
