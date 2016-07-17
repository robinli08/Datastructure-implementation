//
//  main.c
//  stack_06
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

Link operator=NULL;

int empty(Link stack) {
    
    if (stack==NULL) {
        return 1;
    } else {
        return 0;
    }
}

int is_op (char op) {
    
    switch (op) {
        case '(':
            return 1;
            break;
        case ')':
            return 1;
            break;
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

int prority (char op) {
    
    switch (op) {
        case '(':
            return 1;
            break;
        case '+':
            return 2;
            break;
        case '-':
            return 2;
            break;
        case '*':
            return 3;
            break;
        case '/':
            return 3;
            break;
        default:
            return 0;
            break;
    }
}

Link push (Link stack, int value) {
    
    Link newnode;
    
    newnode = (Link)malloc(sizeof(s_list));
    newnode->data = value;
    newnode->next = stack;
    stack = newnode;
    return stack;
}

Link pop (Link stack, int *value) {
    
    Link top;
    
    if (stack != NULL) {
        top = stack;
        stack = stack -> next;
        *value = top->data;
        free(top);
        return stack;
    } else {
        
        *value = -1;
    }
    
    return 0;
}


int main(int argc, const char * argv[]) {
    
    char inorder[50];
    char postorder[50];
    int op = 0;
    int in_position;
    int po_position;
    int i;
    
    in_position = 0;
    po_position = 0;
    
    for (i=0; i <= 50; i ++) {
        postorder[i]=' ';
    }
    printf("Please input the inorder expression:");
    gets(inorder);
    
    while (inorder[in_position]!='\0' && inorder[in_position]!='\n') {
        if (is_op(inorder[in_position])) {
            if (empty(operator) || inorder[in_position]=='(') {
                operator = push(operator, inorder[in_position]);
            } else {
                if (inorder[in_position]==')') {
                    while (operator->data != '(') {
                        operator = pop(operator, &op);
                        postorder[po_position++] = op;
                    }
                } else {
                    while (prority(inorder[in_position]) <= prority(operator->data) && empty(operator)) {
                        operator=pop(operator,&op);
                        postorder[po_position ++] = op;
                    }
                    operator = push(operator, inorder[in_position]);
                }
            }
        } else {
            postorder[po_position++] = inorder[in_position];
        }
        in_position ++;
        
        
    }
    
    while (!empty(operator)) {
        operator=pop(operator,&op);
        postorder[po_position++] = op;
    }
    postorder[po_position - 1] = '\0';
    printf("The postorder expression is[");
    
    for (i = 0; i<= 50; i ++) {
        if (postorder[i] != '(' && postorder[i]!='\0') {
            printf("%c",postorder[i]);
        }
        printf(")\n");
    }
    
    return 0;
}
