//
//  main.c
//  array-06
//
//  Created by robin on 6/23/16.
//  Copyright © 2016 robin. All rights reserved.
//

#include <stdio.h>

int main(int argc, const char * argv[]) {
    
    
    int Data[5][4] = {9,7,6,6,
                    3,5,3,3,
                    6,6,4,7,
                    7,5,1,4,
                    1,2,8,0};
    
    int RowData[20];
    int ColData[20];
    int i,j;
    
    printf("The data of two dimensional array:\n");
    
    for (i = 0; i < 5; i ++) {
        for (j = 0; j < 4; j ++) {
            printf("%4d",Data[i][j]);
        }
        printf("\n");
    }
    
    for (i = 0; i < 5; i ++) {
        for (j = 0; j < 4; j ++) {
            RowData[i*4 + j] = Data[i][j];
        }
        
    }
    printf("\nThe Row Major Matrix:\n");
    
    for (i = 0; i < 20; i ++ ) {
        printf("%3d",RowData[i]);
    }
    printf("\n");
    
    for (i = 0; i < 5; i ++) {
        for (j = 0; j < 4 ; j ++) {
            ColData[j * 5 + i] = Data[i][j];
        }
    }
    
    printf("\nThe Column Major Matrix:\n");
    
    for (i = 0; i < 20; i ++) {
        printf("%3d",ColData[i]);
    }
    
    printf("\n");
    
    
    return 0;
}
