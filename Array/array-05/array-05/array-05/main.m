//
//  main.m
//  array-05
//
//  Created by robin on 6/15/16.
//  Copyright © 2016 robin. All rights reserved.
//

#import <Foundation/Foundation.h>

int main(int argc, const char * argv[]) {
    @autoreleasepool {
        
        
        int MatrixA[5][4] = {1,5,7,3,
                            3,6,3,9,
                            1,2,8,7,
                            0,3,1,9,
                            3,2,5,4};
        
        int MatrixB[4][6] = {3,9,1,4,1,4,
                            5,6,7,9,0,3,
                            3,2,7,2,5,6,
                            9,7,4,7,8,0};
        
        int MatrixC[5][6];
        int i,j,k;
        
        for (i = 0; i < 5; i++) {
            for (j = 0; j<6; j++) {
                MatrixC[i][j] = 0;
                
                for (k = 0; k < 4; k ++) {
                    MatrixC[i][j] += MatrixA[i][k] * MatrixB[k][j];
                }
            }
        }
        
        
        printf("The MatrixA : \n");
        
        for (i = 0; i < 5 ; i ++) {
            for (k = 0; k < 4; k ++) {
                printf("%5d", MatrixA[i][k]);
            }
            printf("\n");
        }
     
        
        printf("\nThe MatrixB : \n");
        
        for (k = 0; k < 4; k ++) {
            for (j = 0; j < 6; j++) {
                printf("%5d",MatrixB[k][j]);
            }
            printf("\n");
        }
        
        
        printf("\nThe MatrixC : \n");
        
        for (i = 0; i < 5; i ++) {
            
            for (j = 0; j < 6; j ++) {
                printf("%5d", MatrixC[i][j]);
            }
            printf("\n");
        }
    }
    return 0;
}
