//
//  main.c
//  Stack_04
//
//  Created by robin on 7/1/16.
//  Copyright © 2016 robin. All rights reserved.
//

#include <stdio.h>
#include <stdlib.h>

struct s_node{
    
    int data;
    struct s_node *next;
};

typedef struct s_node s_list;
typedef s_list *Link;

Link prefix=NULL;
Link operand=NULL;

Link push(Link stack, int value) {
    
    Link newNode;
    
    newNode = (Link)malloc(sizeof(s_list));
    
    if (!newNode) {
        printf("\n Memory allocation failure!!");
        return NULL;
    }
    
    newNode->data = value;
    newNode->next = stack;
    stack = newNode;
    return stack;
}

Link pop (Link stack,int *value) {
    
    Link top;
    
    if (stack != NULL) {
        top = stack;
        stack = stack->next;
        *value = top->data;
        free(top);
        return stack;
    } else {
        *value = -1;
        return NULL;
    }
}

int empty (Link stack) {
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

int two_result (int operator,int operand1,int operand2) {
    
    switch (operator) {
        case '+':
            return (operand1 + operand2);
            break;
        case '-':
            return (operand1 - operand2);
            break;
        case '*':
            return (operand1 * operand2);
            break;
        case '/':
            return (operand1 / operand2);
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
    int evaluate = 0;
    int token = 0;
    
    printf("\nPlease input the preorder expression : ");
    
    gets(expression);
    
    while (expression[position]!='\0' && expression[position] !='\n') {
        prefix = push(prefix, expression[position]);
        position ++;
    }
    
    while (!empty(prefix)) {
        prefix = pop(prefix, &token);
        
        if (is_operator(token)) {
            operand = pop(operand, &operand1);
            operand = pop(operand, &operand2);
            operand = push(operand, two_result(token, operand2, operand1));
        } else {
            operand = push(operand, token-48);
        }
    
    }
    
    operand = pop(operand, &evaluate);
    printf("The expression [%s] result is '%d'",expression,evaluate);
    return 0;
}
