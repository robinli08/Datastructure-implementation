//
//  main.c
//  Stack_05
//
//  Created by robin on 7/17/16.
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

Link operand=NULL;

Link push(Link stack,int value){
    
    Link newnode;
    newnode=(Link)malloc(sizeof(s_list));
    if (!newnode) {
        printf("\nMemory allocation failure!!!");
        return NULL;
    }
    
    newnode->data = value;
    newnode->next = stack;
    stack = newnode;
    return stack;
    
}

Link pop(Link stack, int *value) {
    Link top;
    
    if (stack!=NULL) {
        top = stack;
        stack=stack->next;
        *value = top->data;
        free(top);
        return stack;
    } else {
        *value = -1;
    }
    return 0;
}

int empty(Link stack) {
    
    if (stack == NULL) {
        return 1;
    } else {
        return 0;
    }
}

int is_operator (char operator) {
    switch (operator) {
        case '+':
            return 1;
            break;
        case '-':
            return 1;
            break;
        case '*':
            return 1;
            break;
        case '/':
            return 1;
            break;
        default:
            return 0;
            break;
    }
}

int two_result(int operator, int operand1, int operand2)
{
    
    switch (operator) {
        case '+':
            return (operand2 + operand1);
            break;
        case '-':
            return (operand2 - operand1);
            break;
        case '*':
            return (operand2 * operand1);
            break;
        case '/':
            return (operand2 / operand1);
            break;
        default:
            return 0;
            break;
    }
}

int main(int argc, const char * argv[]) {
    
    char expression[50];
    int position = 0;
    int operand1 = 0;
    int operand2 = 0;
    int evaluate;
    
    printf("\n Please input the posterorder expression :");
    gets(expression);
    
    while (expression[position]!='\0' && expression[position]!='\n') {
        if (is_operator(expression[position])) {
            operand = pop(operand, &operand1);
            operand = pop(operand, &operand2);
            operand = push(operand, two_result(expression[position],operand1,operand2));
        } else {
            operand = push(operand, expression[position] - 48);
        }
        position ++;
        
    }
    operand = pop(operand, &evaluate);
    printf("The expression [ %s] result is '%d'", expression, evaluate);
    
    return 0;
}
