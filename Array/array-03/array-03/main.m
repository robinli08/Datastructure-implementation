//
//  main.m
//  array-03
//
//  Created by robin on 6/14/16.
//  Copyright © 2016 robin. All rights reserved.
//

#import <Foundation/Foundation.h>

int main(int argc, const char * argv[]) {
    @autoreleasepool {
        
        
        int Employee[10] = {27000,32000,32500,27500,28500,29000,31000,32500,30000,26000};
        int Salary;
        int Counter = 0;
        int i;
        
        printf("Please input the employee salary: ");
        scanf("%d", &Salary);
        
        for (i = 0; i < 10; i++) {
            if (Salary == Employee[i]) {
                printf("Number %d Employee`s salary is %d ! \n",i,Salary);
                Counter ++;
            }
            
        }
            if (Counter == 0) {
                printf("No employee`s salary is %d!!\n",Salary);
            } else {
                printf("Have %d employee salary is %d !!\n", Counter,Salary);
            }
        
    }
    return 0;
}
