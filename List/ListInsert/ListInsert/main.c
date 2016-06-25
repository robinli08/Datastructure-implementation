//
//  main.c
//  ListInsert
//
//  Created by robin on 6/26/16.
//  Copyright © 2016 robin. All rights reserved.
//

#include <stdio.h>
#define Max 10

struct List {
    int Number;
    int Total;
    struct List *Next;
};

typedef struct List Node;
typedef Node *Link;


int Data[2][Max] = {1,3,5,7,2,4,6,8,9,0,
    15,35,10,67,25,65,38,70,30,20};

Link Insert_List(Link Head, Link New, int Key) {
    
    Link Pointer;
    
    Pointer = Head;
    
    while (1) {
        if (Pointer == NULL) {
            New->Next = Head;
            Head = New;
            break;
        }
        
        if (Pointer->Number == Key) {
            
            New->Next = Pointer->Next;
            Pointer->Next = New;
            break;
        }
        
        Pointer = Pointer->Next;
    }
    
    return Head;
}


void print_List(Link Head) {
    
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
        Free(Pointer);
    }
}

Link Create_List(Link Head) {
    
    Link New;
    Link Pointer;
    int i ;
    
    Head = (Link) malloc(sizeof(Node));
    
    if (Head == NULL) {
        printf("Memory allocate Failure!!\n");
    } else {
        Head->Number = Data[0][0];
        Head->Total = Data[1][0];
        Head->Next = NULL;
        
        Pointer = Head;
        
        for (i = 1; i <Max; i ++) {
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
    Link New;
    int Key;
    
    Head = Create_List(Head);
    
    if (Head != NULL) {
        print_List(Head);
        
        while (1) {
            printf("Input 0 to EXIT:\n");
            New = (Link) malloc(sizeof(Node));
            printf("Please input the data number: ");
            scanf("%d",&New->Number);
            
            if (New->Number == 0) {
                break;
            }
            
            printf("Please input the data total: ");
            scanf("%d",&New->Total);
            printf("Please input the data number for Insert : ");
            scanf("%d",&Key);
            
            Head = Insert_List(Head, New, Key);
            
            print_List(Head);
        }
        
        Free_List(Head);
    }
    
    return 0;
}
