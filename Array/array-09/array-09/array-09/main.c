//
//  main.c
//  array-09
//
//  Created by robin on 6/25/16.
//  Copyright © 2016 robin. All rights reserved.
//

#include <stdio.h>

// i≥j且1≤i≤n，存储到SA中后，根据存储原则，它前面有i-1行，共有1+2+…+i-1=i*(i-1)/2个元素，而aij又是它所在的行中的第j个，所以在上面的排列顺序中，aij是第i*(i-1)/2+j个元素，因此它在SA中的下标k与i、j的关系为： k=i*(i-1)/2+j-1 (0≤k<n*(n+1)/2 )若i<j，则aij是上三角中的元素，因为aij=aji ，这样，访问上三角中的元素aij时则去访问和它对应的下三角中的aji即可，因此将上式中的行列下标交换就是上三角中的元素在SA中的对应关系：k=j*(j-1)/2+i-1 (0≤k<n*(n+1)/2 )

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
