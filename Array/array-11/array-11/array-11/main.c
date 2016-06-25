//
//  main.c
//  array-11
//
//  Created by robin on 6/26/16.
//  Copyright © 2016 robin. All rights reserved.
//

#include <stdio.h>

int main(int argc, const char * argv[]) {
    
    
    int Lower[5][5] = {3,0,0,0,0,
                7,5,0,0,0,
                6,4,5,0,0,
                8,3,2,1,0,
                9,1,6,4,9};
    
    int colMajor[15];
    int Index;
    int i ,j;
    
    printf("Two dimensional Lower triangular array:\n");
    
    for (i = 0; i < 5; i ++) {
        for (j = 0 ; j < 5; j ++) {
            printf("%3d",Lower[i][j]);
        }
        
        printf("\n");
    }
    
    for (i = 0; i < 5; i ++) {
        for (j = 0; j < 5; j ++) {
            if (i >=j ) {
                Index = (11-j) * j / 2 + (i - j);
                colMajor[Index] = Lower[i][j];
            }
        }
    }
    
    printf("\n");
    
    printf("Column Major one dinmensional array :\n");
    
    for (i = 0; i < 15; i ++) {
        printf("%3d",colMajor[i]);
    }
    
    printf("\n");
    
    return 0;
}
