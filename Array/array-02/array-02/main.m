//
//  main.m
//  array-02
//
//  Created by robin on 6/14/16.
//  Copyright © 2016 robin. All rights reserved.
//

#import <Foundation/Foundation.h>

int main(int argc, const char * argv[]) {
    @autoreleasepool {
        
        int Employee[10] = {27000, 32000, 32500, 27500, 28500, 29000,31000,32500,30000,26000};
        
        int index;
        int NewSalary;
        int Selection;
        
        while (1) {
            
            printf("==================================================\n");
            printf("=  simple Employee Salary Management System =\n");
            printf("= 1.Display employee salary                 =\n");
            printf("= 2.Modify employee salary                  =\n");
            printf("3.Quit                                      =\n");
            
            printf("==================================================\n");
            
            printf("Please input your choose:");
            scanf("%d",&Selection);
            
            
            if (Selection == 1 || Selection == 2) {
                
                printf("**  Please input the employee number:");
                scanf("%d",&index);
                
                if (index < 10) {
                    printf("** Employee Number is %d .", index);
                    printf("The Salary is %d\n", Employee[index]);
                } else {
                    printf("## The error employee number!!\n");
                    exit(1);
                }
            }
            
            switch (Selection) {
                case 1:
                    break;
                case 2:
                    printf("** Please input new salary:");
                    scanf("%d",&NewSalary);
                    Employee[index] = NewSalary;
                    break;
                case 3:
                    exit(1);
                    break;
                default:
                    break;
            }
            
            printf("\n");
        }
        
    }
    return 0;
}
