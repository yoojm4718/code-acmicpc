#include<stdio.h>
#include<stdlib.h>

typedef char element; 
typedef struct DListNode {
    element data;
    struct DListNode *llink; 
    struct DListNode *rlink;
} DListNode;

DListNode* dinsert(DListNode *cursor, element data) {
    DListNode *newnode = (DListNode *)malloc(sizeof(DListNode)); 

    newnode->data = data;
    newnode->llink = cursor;
    newnode->rlink = cursor->rlink;
    cursor->rlink->llink = newnode; 
    cursor->rlink = newnode;

    return newnode;
}

DListNode* ddelete(DListNode* head, DListNode* cursor) {
    DListNode* removed = cursor;

    if (cursor == head) return cursor; 

    cursor = cursor->llink;
    removed->llink->rlink = removed->rlink; 
    removed->rlink->llink = removed->llink; 
    free(removed);

    return cursor;
}

void init(DListNode* phead) {
    phead->llink = phead; 
    phead->rlink = phead;
}

void print_dlist(DListNode* phead) {
    DListNode* p;

    for (p = phead->rlink; p != phead; p = p->rlink) {
        printf("%c", p->data);
    }
    printf("\n");

}

DListNode* cursor_left(DListNode* head, DListNode* cursor){
    if(head == cursor) return cursor;

    return cursor->llink;
}

DListNode* cursor_right(DListNode* head, DListNode* cursor){
    if(head->llink == cursor) return cursor;

    return cursor->rlink;
}

int main(void) {
    DListNode *head = (DListNode *)malloc(sizeof(DListNode)), *cursor;
    int i = 0, num;
    char item, data, initial[100001];

    init(head);
    cursor = head;

    scanf("%s", initial);

    while (*(initial + i) != '\0')
        cursor = dinsert(cursor, *(initial + i++));

    scanf("%d", &num);

    for(i = 0; i < num; i++){
        getchar();
        scanf("%c", &item);

        switch (item) {
        case 'P':
            scanf(" %c", &data);
            cursor = dinsert(cursor, data);
            break;
        case 'L':
            cursor = cursor_left(head, cursor);
            break;
        case 'D':
            cursor = cursor_right(head, cursor);
            break;
        case 'B':
            cursor = ddelete(head, cursor);
            break;
        
        default:
            break;
        }
    }

    print_dlist(head);

    free(head); 
    
    return 0;
}