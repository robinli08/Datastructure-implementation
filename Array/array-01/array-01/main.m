//
//  main.m
//  array-01
//
//  Created by robin on 6/14/16.
//  Copyright © 2016 robin. All rights reserved.
//

#import <Foundation/Foundation.h>

int main(int argc, const char * argv[]) {
    @autoreleasepool {
        
        
        int Max=0;
        int i;
        float Number[20];
        float Summary;
        float Average;
        
        Summary = 0;
        
        printf("Please input the number of data:");
        scanf("%d", &Max);
        
        if (Max <= 20) {
            for (i = 0; i < Max; i++) {
                printf("Please input a number:");
                scanf("%f", &Number[i]);
                Summary += Number[i];
            }
            
            Average = Summary / Max;
            printf("The average is %5.2f \n", Average);
            
        } else {
            printf("Please input a number less than 20.");
        }
    }
    return 0;
}
