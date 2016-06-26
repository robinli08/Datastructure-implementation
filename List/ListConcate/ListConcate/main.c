//
//  main.c
//  ListConcate
//
//  Created by robin on 6/26/16.
//  Copyright © 2016 robin. All rights reserved.
//

#include <stdio.h>
#include <stdlib.h>
#define Max1 10
#define Max2 6

struct List {
    int Number;
    int Total;
    struct List *Next;
};

typedef struct List Node;
typedef Node *Link;

int Data1[Max1] = {1,2,3,4,5,6,7,8,9,10};

int Data2[Max2] = {11,12,13,14,15,16};

Link Concatenate_List (Link Head1,Link Head2) {
    
    Link Pointer;
    Link Back;
    Link Next;
    
    Pointer = Head1;
    
    while (Pointer->Next != NULL) {
        Pointer = Pointer->Next;
    }
    Pointer->Next = Head2;
    return Head1;
}

void Print_List(Link Head) {
    
    Link Pointer;
    Pointer = Head;
    
    while (Pointer != NULL) {
        printf("[%d]",Pointer->Number);
        Pointer = Pointer->Next;
    }
    
    printf("\n");
}

void Free_List(Link Head) {
    
    Link Pointer;
    
    while (Head != NULL) {
        Pointer = Head;
        Head = Head->Next;
        free(Pointer);
    }
}

Link Create_List (Link Head,int *Data,int Max) {
    
    Link New;
    Link Pointer;
    int i;
    
    Head = (Link) malloc(sizeof(Node));
    
    if (Head == NULL) {
        printf("Memory allocate Failure!!\n");
    } else {
        Head->Number = Data[0];
        Head->Next = NULL;
        
        Pointer = Head;
        
        for (i = 1; i < Max; i ++) {
            New = (Link) malloc(sizeof(Node));
            
            New->Number = Data[i];
            New->Next = NULL;
            
            Pointer->Next = New;
            Pointer = New;
        }
    }
    
    return Head;
}


int main(int argc, const char * argv[]) {
    
    Link Head;
    Link Head1;
    Link Head2;
    
    Head1 = Create_List(Head1,Data1,Max1);
    
    Head2 = Create_List(Head2, Data2, Max2);
    
    if (Head1 != NULL && Head2 != NULL) {
        printf("Input Data: \n");
        Print_List(Head1);
        Print_List(Head2);
        
        Head = Concatenate_List(Head1, Head2);
        
        printf("After Concatenate : \n");
        Print_List(Head);
        Free_List(Head);
    }
    
    return 0;
}
