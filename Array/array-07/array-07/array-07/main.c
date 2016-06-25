//
//  main.c
//  array-07
//
//  Created by robin on 6/23/16.
//  Copyright © 2016 robin. All rights reserved.
//

#include <stdio.h>

int main(int argc, const char * argv[]) {
    
    
    int Data[9][7] = {0,0,0,0,0,0,0,
                    0,3,0,0,0,0,0,
                    0,0,0,0,0,0,0,
                    1,4,0,0,0,0,0,
                    0,0,7,0,0,0,0,
                    0,0,0,0,0,5,0,
                    0,0,0,0,0,0,0,
                    0,0,0,0,0,0,0,
                    0,0,0,0,0,0,0};
    
    int CompressData[10][3];
    int Index;
    int i,j;
    
    Index = 0;
    
    printf("Two dimensional sparse array:\n");
    
    for (i = 0; i < 9; i ++) {
        for (j  = 0; j < 7; j ++) {
            printf("%3d",Data[i][j]);
        }
        printf("\n");
    }
    
    for (i = 0; i < 9; i ++) {
        for (j = 0; j <7; j ++) {
            if (Data[i][j] != 0) {
                Index ++;
                CompressData[Index][0] = i;
                CompressData[Index][1] = j;
                CompressData[Index][2] = Data[i][j];
            }
        }
    }
    
    CompressData[0][0] = 9;
    CompressData[0][1] = 7;
    CompressData[0][2] = Index;
    
    printf("Two dimensional compress array: \n");
    
    for (i = 0; i < Index; i ++) {
        for (j = 0; j < 3; j ++) {
            printf("%3d",CompressData[i][j]);
        }
        
        printf("\n");
    }
    
    return 0;
}
