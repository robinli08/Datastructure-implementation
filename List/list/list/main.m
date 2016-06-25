//
//  main.m
//  list
//
//  Created by robin on 6/15/16.
//  Copyright © 2016 robin. All rights reserved.
//

#import <Foundation/Foundation.h>

#define Max 10

struct List {
    int Number;
    char Name[Max];
    struct List *Next;
};

typedef struct List Node;
typedef Node *Link;

int main(int argc, const char * argv[]) {
    @autoreleasepool {
        
        Link New;
        int DataNum;
        char DataName[Max];
        int i;
        
        New = (Link)malloc(sizeof(Node));
        
        if (New == NULL) {
            printf("Memory allocate Failure!!\n");
        } else {
            printf("Please input the data number : ");
            scanf("%d", &DataNum);
            printf("Please input the data name : ");
            scanf("%s", DataName);
            
            New->Number = DataNum;
            for (i = 0; i < Max; i++) {
                New->Name[i] = DataName[i];
            }
            
            New->Next = NULL;
            
            printf("## Input Data## \n");
            printf("Data Number : %d\n",New->Number);
            printf("Data Name : %s\n",New->Name);
        }
        
        free(New);
        
    }
    return 0;
}
