//
//  main.m
//  ListSearch
//
//  Created by robin on 6/15/16.
//  Copyright © 2016 robin. All rights reserved.
//

#import <Foundation/Foundation.h>

#define Max 10

struct List {
    int Number;
    int Total;
    struct List *Next;
};

typedef struct List Node;
typedef Node *Link;


int Data[2][Max] = {3,9,25,5,7,26,65,80,2,6,1050,3850,1000,5670,2250,9650,
    2380,1700,3000,2000};

int SearchTime = 0;

int List_Search(int Key, Link Head) {
    Link Pointer;
    
    Pointer = Head;
    
    while (Pointer != NULL) {
        SearchTime ++;
        if (Pointer->Number == Key) {
            printf("Data Number : %d\n",Pointer->Number);
            printf("Data Total : %d\n", Pointer->Total);
            return 1;
        }
        Pointer = Pointer->Next;
    }
    return 0;
}

void Free_List(Link Head) {
    Link Pointer;
    
    while (Head != NULL) {
        Pointer = Head;
        Head = Head->Next;
        free(Pointer);
    }
}

Link Create_List(Link Head) {
    
    Link New;
    Link Pointer;
    int i;
    
    Head = (Link)malloc(sizeof(Node));
    
    if (Head == NULL) {
        printf("Memory allocate Failure!!\n");
    } else {
        Head->Number = Data[0][0];
        Head->Total = Data[1][0];
        Head->Next = NULL;
        
        Pointer = Head;
        
        for (i = 1;i < Max ; i ++) {
            New = (Link)malloc(sizeof(Node));
            
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
    @autoreleasepool {
        
        Link Head;
        int Num;
        
        Head = Create_List(Head);
        
        if (Head != NULL) {
            printf("Please input the data number : ");
            scanf("%d", &Num);
            
            if (List_Search(Num, Head)) {
                printf("Search Time = %d\n", SearchTime);
            } else {
                printf("Not Found !!\n");
            }
            
            Free_List(Head);
        }
        
    }
    return 0;
}
