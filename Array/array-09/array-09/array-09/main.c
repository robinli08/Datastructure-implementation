//
//  main.c
//  array-09
//
//  Created by robin on 6/25/16.
//  Copyright © 2016 robin. All rights reserved.
//

#include <stdio.h>

int main(int argc, const char * argv[]) {
    
    int Upper[5][5] = {3,9,1,4,7,
                    0,5,2,5,8,
                    0,0,5,2,4,
                    0,0,0,1,7,
                    0,0,0,0,9};
    
    int ColMajor[15];
    int Index;
    int i;
    int j;
    
    printf("Two dimensional upper triangel array:\n");
    
    for (i = 0; i < 5; i ++) {
        for (j = 0; j < 5; j ++) {
            printf("%3d",Upper[i][j]);
        }
        printf("\n");
    }
    
    for (i = 0; i < 5; i ++) {
        for (j = 0; j < 5; j ++) {
            if (i <= j) {
                Index = j * (j + 1) / 2 + i;
                ColMajor[Index] = Upper[i][j];
            }
        }
    }
    
    printf("\n");
    
    printf("Column Major one dimensional array: \n");
    for (i = 0; i < 15; i ++) {
        printf("%3d",ColMajor[i]);
    }
    printf("\n");
    
    return 0;
}
