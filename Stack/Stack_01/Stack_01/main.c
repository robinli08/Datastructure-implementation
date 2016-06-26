//
//  main.c
//  Stack_01
//
//  Created by robin on 6/26/16.
//  Copyright © 2016 robin. All rights reserved.
//

#include <stdio.h>
#include <stdlib.h>

#define MaxSize 10
int stack[MaxSize];
int top = -1;

void push (int value) {
    
    int i;
    
    if (top >= MaxSize) {
        printf("\n The stack is full !!\n");
    } else {
        printf("\n The stack content before(top->bottom) : ");
        
        for (i = top; i > 0; i--) {
            printf("[%d]",stack[i]);
        }
        
        top++;
        stack[top] = value;
        
        printf("\nThe stack content after push(top->bottom) : ");
        
        for (i = top; i > 0; i--) {
            printf("[%d]",stack[i]);
        }
        printf("\n");
    }
}

int pop() {
    
    int temp;
    int i;
    
    if (top < 0) {
        printf("\n The stack is empty!!\n");
        return -1;
    }
    
    printf("\n The stack content before(top->bottom):");
    
    for (i = top; i >= 0; i--) {
        printf("[%d]",stack[i]);
    }
    
    temp = stack[top];
    top--;
    
    printf("\n The pop value is [%d]",temp);
    printf("\n The stack content after pop(top->bottom):");
    for (i = top; i >= 0; i--) {
        printf("[%d]",stack[i]);
    }
    
    printf("\n");
    return temp;
}

int main(int argc, const char * argv[]) {
    
    int select;
    int stack[5];
    int i,value;
    
    printf("\n(1) Input a stack data");
    printf("\n(2) Output a stack data");
    printf("\n(3) Exit");
    printf("\n Please select one=>");
    
    scanf("%d",&select);
    
    do {
        
        switch (select) {
            case 1:
                printf("\n Please input the data =>");
                scanf("%d",&value);
                push(value);
                break;
            case 2:
                value = pop();
                break;
            default:
                break;
        }
        printf("\n(1)Input a stack data");
        printf("\n(2)Output a stack data");
        printf("\n(3)Exit");
        printf("\n Please select one =>");
        scanf("%d",&select);
        printf("\n");
    } while (select != 3);
    
    
    return 0;
}
