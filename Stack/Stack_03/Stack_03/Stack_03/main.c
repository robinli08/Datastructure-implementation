//
//  main.c
//  Stack_03
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

Link operator = NULL;
Link operand = NULL;

Link push (Link stack, int value) {
    
    Link newNode;
    newNode = (Link) malloc (sizeof(s_list));
    
    if (!newNode) {
        printf("\n Memory allocation failure !!");
        return NULL;
    }
    
    newNode->data = value;
    newNode->next = stack;
    stack = newNode;
    return stack;
}

Link pop (Link stack, int *value) {
    
    Link top;
    
    if (stack != NULL) {
        top = stack;
        stack = stack->next;
        *value = top->data;
        free(top);
        return stack;
    } else {
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

int priority (char operator) {
    
    switch (operator) {
        case '+':
            return 1;
            break;
        case '-':
            return 1;
            break;
        case '*':
            return 2;
            break;
        case '/':
            return 2;
            break;
        default:
            return 0;
            break;
    }
}

int two_result (int operator, int operand1,int operand2) {
    
    switch (operator)
    {
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
            break;
    }
    return 0;
}

int main(int argc, const char * argv[]) {
    
    char expression[50];
    int position = 0;
    int op = 0;
    int operand1 = 0;
    int operand2 = 0;
    int evaluate = 0;
    
    printf("\n Please input the in order expression : ");
    
    gets(expression);
    
    while (expression[position] != '\0' && expression[position] != '\n') {
        if (is_operator(expression[position])) {
            
            if (!empty(operator)) {
                
                while (priority(expression[position]) <= priority(operator->data) && !empty(operator)) {
                    
                    operand = pop(operand, &operand1);
                    operand = pop(operand, &operand2);
                    operator = pop(operator, &op);
                    operand = push(operand, two_result(op, operand1, operand2));
                }
            }
            operator = push(operator, expression[position]);
        } else {
            operand = push(operator, expression[position] - 48);
        }
        position ++;
    }
    
    while (!empty(operator)) {
        operator = pop(operator, &op);
        operand = pop(operand, &operand1);
        operand = pop(operand, &operand2);
        operand = push(operand, two_result(op, operand1, operand2));
    }
    
    operand = pop(operand, &evaluate);
    printf("The expression [%s] result is '%d'",expression,evaluate);
    
    return 0;
}
