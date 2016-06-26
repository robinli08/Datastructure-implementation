//
//  main.c
//  ListInvert
//
//  Created by robin on 6/26/16.
//  Copyright © 2016 robin. All rights reserved.
//

#include <stdio.h>
#include <stdlib.h>

#define Max 10

struct List {
    int Number;
    int Total;
    struct List *Next;
};

typedef struct List Node;
typedef Node *Link;

int Data[2][Max] = {1,3,5,7,2,4,6,8,0,
    15,35,10,67,25,65,38,70,30,20};


Link Invert_List(Link Head){
    
    Link Pointer;
    Link Back;
    Link Next;
    
    Back = Head;
    Pointer = Back->Next;
    Back->Next = NULL;
    
    while (Pointer->Next != NULL) {
        Next = Pointer->Next;
        Pointer->Next = Back;
        Back = Pointer;
        Pointer = Next;
    }
    
    Pointer->Next = Back;
    Head = Pointer;
    return Head;
}

void Print_List(Link Head) {
    
    Link Pointer;
    Pointer = Head;
    
    while (Pointer != NULL) {
        printf("[%d, %d]",Pointer->Number,Pointer->Total);
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

Link Create_List (Link Head) {
    
    Link New;
    Link Pointer;
    int i;
    
    Head = (Link) malloc(sizeof(Node));
    
    if (Head == NULL) {
        printf("Memory allocate Failure!!\n");
    } else {
        Head->Number = Data[0][0];
        Head->Total = Data[1][0];
        Head->Next = NULL;
        
        Pointer = Head;
        
        for (i = 1; i < Max; i ++) {
            New = (Link) malloc(sizeof(Node));
            
            New->Number = Data[0][i];
            New->Total = Data[1][i];
            New->Next = NULL;
            
            Pointer->Next = New;
            Pointer = New;
        }
    }
    
    return Head;
}


int main(int argc, const char * argv[]) {
    
    Link Head;
    Head = Create_List(Head);
    
    if (Head != NULL) {
        printf("Input Data : \n");
        Print_List(Head);
        Head = Invert_List(Head);
        printf("After Invert : \n");
        Print_List(Head);
        Free_List(Head);
    }
    
    return 0;
}
