//
//  main.c
//  array-10
//
//  Created by robin on 6/25/16.
//  Copyright © 2016 robin. All rights reserved.
//

#include <stdio.h>

// 对于下三角中的元素aij，其特点是：i≥j且1≤i≤n，存储到SA中后，根据存储原则，它前面有i-1行，共有1+2+…+i-1=i*(i-1)/2个元素，而aij又是它所在的行中的第j个，所以在上面的排列顺序中，aij是第i*(i-1)/2+j个元素，因此它在SA中的下标k与i、j的关系为： k=i*(i-1)/2+j-1 (0≤k<n*(n+1)/2 )若i<j，则aij是上三角中的元素，因为aij=aji ，这样，访问上三角中的元素aij时则去访问和它对应的下三角中的aji即可，因此将上式中的行列下标交换就是上三角中的元素在SA中的对应关系：k=j*(j-1)/2+i-1 (0≤k<n*(n+1)/2 )综上所述，对于对称矩阵中的任意元素aij，若令I=max(i,j)，J=min(i,j)，则将上面两个式子综合起来得到：　k=I*(I-1)/2+J-1。称SA[n(n+1)/2]为n阶对称矩阵A的压缩存储


int main(int argc, const char * argv[]) {
    
    int Lower[5][5] = {3,0,0,0,0,
                    7,5,0,0,0,
                    6,4,5,0,0,
                    8,3,2,1,0,
                    9,1,6,4,9};
    
    int RowMajor[15];
    int Index;
    int i ,j;
    
    printf("Two dimensional Lower triangelar array: \n");
    
    for (i = 0; i < 5 ; i ++) {
        for (j = 0;  j < 5; j ++) {
            printf("%3d",Lower[i][j]);
        }
        
        printf("\n");
    }
    
    for (i = 0; i < 5; i ++) {
        for (j = 0; j < 5; j ++) {
            if (i >=j) {
                Index = i * (i + 1) / 2 + j;
                RowMajor[Index] = Lower[i][j];
            }
        }
    }
    
    printf("\n");
    
    printf("Row Major one dimensional array : \n");
    
    for (i = 0; i < 15; i ++) {
        printf("%3d", RowMajor[i]);
    }
    
    printf("\n");
    return 0;
}
