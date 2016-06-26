//
//  main.c
//  ListCompare
//
//  Created by robin on 6/26/16.
//  Copyright © 2016 robin. All rights reserved.
//

#include <stdio.h>
#include <stdlib.h>

#define Max1 10
#define Max2 10
#define Max3 6

struct List {
    
    int Number;
    struct List *Next;
};

typedef struct List Node;
typedef Node *Link;

int Data1[Max1] = {1,2,3,4,5,6,7,8,9,10};
int Data2[Max2] = {1,2,5,4,3,7,6,10,9,8};
int Data3[Max3] = {1,2,3,4,5,6};

void Compare_List(Link Head1, Link Head2) {
    
    Link Pointer1;
    Link Pointer2;
    
    Pointer1 = Head1;
    Pointer2 = Head2;
    
    while (1) {
        if ((Pointer1->Next == NULL) && (Pointer2->Next == NULL)) {
            printf("\n##EQUAL!!##\n");
            break;
        }
        
        if (Pointer1->Number != Pointer2->Number) {
            printf("\n[%d]<>[%d]\n",Pointer1->Number,Pointer2->Number);
            printf("##NOT EQUAL !! ##\n");
            break;
        } else {
            printf("[%d]",Pointer1->Number);
            Pointer1 = Pointer1->Next;
            Pointer2 = Pointer2->Next;
        }
    }
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
    
    Link Head1;
    Link Head2;
    Link Head3;
    int Flag;
    
    Head1 = Create_List(Head1, Data1, Max1);
    
    Head2 = Create_List(Head2, Data2, Max2);
    
    Head3 = Create_List(Head3, Data3, Max3);
    
    if (Head1 != NULL && Head2 != NULL && Head3 != NULL) {
        printf("Linke List 1 :");
        Print_List(Head1);
        
        printf("Linked List 2 : ");
        
        Print_List(Head2);
        
        printf("Linked List 3 : ");
        
        Print_List(Head3);
        
        printf("Linked List 1 compare with Linked List1 \n");
        Compare_List(Head1, Head1);
        
        printf("Linked List 1 compare with Linked List 2 \n");
        Compare_List(Head1, Head2);
        
        printf("Linked List 1 compare with Linked List 3 \n");
        Compare_List(Head1, Head3);
        
        Free_List(Head1);
        Free_List(Head2);
        Free_List(Head3);
    }
    
    return 0;
}
