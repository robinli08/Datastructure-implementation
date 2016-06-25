//
//  main.m
//  createList
//
//  Created by robin on 6/15/16.
//  Copyright © 2016 robin. All rights reserved.
//

#import <Foundation/Foundation.h>

#define Max 10 
struct   List {
    int Number;
    char Name[Max];
    struct List *Next;
};


typedef struct List Node;
typedef Node *Link;


void Free_List (Link Head)
{
    Link Pointer;
    
    while (Head != NULL) {
        Pointer = Head;
        Head = Head->Next;
        free(Pointer);
    }
}

void Print_List(Link Head)
{
    Link Pointer;
    Pointer = Head;
    while (Pointer != NULL) {
        printf("## Input Data ##\n");
        printf("Data Number : %d\n",Pointer->Number);
        printf("Data Name : %s\n",Pointer->Name);
        Pointer = Pointer->Next;
    }
}

Link Create_List(Link Head) {
    int DataNum;
    char DataName[Max];
    Link New;
    Link Pointer;
    int i;
    
    Head = (Link) malloc(sizeof(Node));
    
    if (Head == NULL) {
        printf("Memory allocate Failuer!!\n");
    } else {
        
        DataNum = 1;
        printf("Please input the data name : ");
        scanf("%s", DataName);
        Head->Number = DataNum;
        
        for (i = 0; i <= Max; i ++) {
            Head->Name[i] = DataName[i];
        }
        
        Head->Next = NULL;
        Pointer = Head;
        
        while (1) {
            
            DataNum++;
            New = (Link)malloc(sizeof(Node));
            printf("Please input the data name : ");
            scanf("%s", DataName);
            
            if (DataName[0] == '0') {
                break;
            }
            New->Number = DataNum;
            
            for (i = 0; i <= Max; i++) {
                New->Name[i] = DataName[i];
            }
            
            New->Next = NULL;
            Pointer->Next = New;
            Pointer = New;
        }
    }
    return Head;
}

int main(int argc, const char * argv[]) {
    @autoreleasepool {
      
        Link Head;
        
        Head = Create_List(Head);
        
        if (Head != NULL) {
            Print_List(Head);
            Free_List(Head);
        }
        
        
    }
    return 0;
}
