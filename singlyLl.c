#include <stdio.h>
#include <stdlib.h>

typedef struct NODE{
    int x;
    struct NODE *next;
} NODE;

NODE *start = NULL, *ptr, *temp;
int totalElements = 0;

void create(int x){
    ptr = (NODE*)malloc(sizeof(NODE));
    ptr->x = x;

    if(start == NULL){
        start = ptr;
        ptr->next = NULL;
    }

    else {
        for (temp = start; temp->next != NULL; temp = temp->next);

        temp->next = ptr;
        ptr->next = NULL;
    }

    totalElements++;
}

void insertionAfter(int index, int x){
    if(start == NULL){
        printf("No node found!");
    }
    
    else{
        temp = start;
        for (int i = 0; i < index; i++){
            temp = temp->next;
        }

        ptr = (NODE*)malloc(sizeof(NODE));
        ptr->x = x;
        ptr->next = temp->next;
        temp->next = ptr;

        totalElements++;
    }
}

void insertionBefore(int index, int x){
    if(start == NULL){
        printf("No node found!");
    }
    
    else{
        temp = start;

        if(index == 0){
            ptr = (NODE*)malloc(sizeof(NODE));
            ptr->x = x;
            ptr->next = temp;
            start = ptr;
        }
        
        else {
            index = index-1;
            for (int i = 0; i < index; i++) temp = temp->next;

            ptr = (NODE*)malloc(sizeof(NODE));
            ptr->x = x;
            ptr->next = temp->next;
            temp->next = ptr;
        }

        totalElements++;
    } 
}

void display(int begin, int end){
    if(start == NULL){
        printf("No node to display.");
    }

    if (begin == -1 && end == -1){
        for (temp = start; temp != NULL; temp = temp->next){
            printf("%d ", temp->x);
        }
    }

    else {
        temp = start;
        for(int i = begin; i <= end; i++){
            printf("%d ", temp->x);
            temp = temp->next;
            if(temp == NULL) break;
        }
    }
}

void delete(int index){
    if (start == NULL){
        printf("No node to delete.");
    }

    temp = start;

    if(index == 0){
        start = temp->next;
        printf("The deleted item is: \'%d\'", temp->x);
        free(temp);

        totalElements--;
    }
    
    else {
        for(int i = 0; i < index; i++) {
            ptr = temp;
            temp = temp->next;
        }
        ptr->next = temp->next;
        printf("The deleted item is: \'%d\'", temp->x);
        free(temp);

        totalElements--;
    }
}

int main(){
    int n, x, index, choice, b = -1, e = -1;
    
    while (1)
    {
        printf("\n***********************************\n");
        printf("1> For NODE CREATION\n");
        printf("2> For INSERTION AFTER.\n");
        printf("3> For INSERTION BEFORE.\n");
        printf("4> For DISPLAY WHOLE.\n");
        printf("5> For DISPLAY FROM UPTO.\n");
        printf("6> For DELETION ANY NODE. \n");
        printf("7> For EXIT.\n");
        printf("***********************************\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice)
        {
        case 1:
            printf("How many nodes you want to create? ");
            scanf("%d", &n);
            for(int i = 0; i < n; i++){
                printf("Enter the element %d: ", i+1);
                scanf("%d", &x);
                create(x);
            }
            break;

        case 2:
            printf("Enter the index after which you want to insert (Eg.: if after first element then 0): ");
            scanf("%d", &index);
            
            if(index >= 0 && index < totalElements) {
                printf("Enter the element: ");
                scanf("%d", &x);
                insertionAfter(index, x);
            }
            else printf("No such index exist.");
            break;

        case 3:
            printf("Enter the index before which you want to insert (Eg.: if before first element then 0): ");
            scanf("%d", &index);
            
            if(index >= 0 && index < totalElements) {
                printf("Enter the element: ");
                scanf("%d", &x);
                insertionBefore(index, x);
            }
            else printf("No such index exist.");
            break;

        case 4:
            display(b, e);
            break;
        
        case 5:
            printf("Enter the index range to display (Eg. if from 1st element to 3rd element then enter 0 2): ");
            scanf("%d %d", &b, &e);
            display(b, e);
            break;

        case 6:
            printf("Enter the index to delete: ");
            scanf("%d", &index);
            if (index >= 0 && index < totalElements) delete(index);
            else printf("No such index exist.");
            break;

        case 7:
            printf("\n\nGoodbye...\n");
            return 0;
        
        default:
            printf("\nInvalid choice!\n");
            break;
        }
    }
    
    return 0;
}