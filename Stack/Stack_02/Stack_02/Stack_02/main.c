//
//  main.c
//  Stack_02
//
//  Created by robin on 6/29/16.
//  Copyright © 2016 robin. All rights reserved.
//

#include <stdio.h>
#include <stdlib.h>

struct s_node {
    
    int data;
    struct s_node *next;
};

typedef struct s_node s_list;
typedef s_list *Link;

Link stack = NULL;

void print_stack() {
    
    Link temp = NULL;
    temp = stack;
    
    if (temp == NULL) {
        
        printf("The stack is empty!!\n");
        
    } else {
        while (temp != NULL) {
            temp = temp -> next;
        }
        printf("\n");
    }
}

void push (int value) {
    
    Link newNode;
    
    printf("\n The stack content before(top->bottom): ");
    
    print_stack();
    
    newNode = (Link)malloc(sizeof(s_list));
    newNode->data = value;
    newNode->next = stack;
    stack = newNode;
}

int pop () {
    
    Link top;
    int temp;
    
    printf("\nThe stack content before(top->bottom) : ");
    print_stack();
    
    if (stack != NULL) {
        top = stack;
        stack = stack->next;
        temp = top->data;
        free(top);
        return temp;
    } else {
        return -1;
    }
}

int main(int argc, const char * argv[]) {
    
    Link point;
    int select;
    int i,value;
    
    printf("\n(1) Input a stack data");
    printf("\n(2) Output a stack data");
    printf("\(3) Exit");
    printf("\n Please select one function=>");
    scanf("%d",&select);
    
    do {
        
        switch (select) {
            case 1:
                printf("\n Please input the data =>");
                scanf("%d",&value);
                push(value);
                printf("The stack content current(top->bottom) : ");
                print_stack();
                break;
            case 2:
                value = pop();
                printf("The output value is [%d]",value);
                printf("\n");
                printf("The stack content current(top->bottom) : ");
                print_stack();
            default:
                break;
        }
        
        printf("\n (1) Input a stack data");
        printf("\n (2) Output a stack data");
        printf("\n (3) Exit");
        printf("\n Please select one =>");
        scanf("%d",&select);
        
    } while (select != 3);
    
    return 0;
}
