#include <stdio.h> 
#include <stdlib.h>

typedef int element;

typedef struct ListNode { // 노드 타입
    element data;
    struct ListNode *link; 
} ListNode;

ListNode* insert_last(ListNode* head, element data) {
    ListNode *node = (ListNode *)malloc(sizeof(ListNode));
    node->data = data;
    
    if (head == NULL) {
        head = node; 
        node->link = head;
    }
    else {
        node->link = head->link; 
        head->link = node;
        head = node;
    }

    return head;
}

ListNode* kill_next(ListNode* cur, int K){
    ListNode *p = cur, *temp;
    int i;

    if(p->link == cur){
        printf("%d", cur->data);
        cur = NULL;
        free(p);
        return cur;
    }

    for(i = 1; i < K; i++) p = p->link;

    temp = p->link;
    printf("%d, ", temp->data);
    
    p->link = temp->link;
    free(temp);

    return p;
}

int main(void) {
    ListNode *cur = NULL;
    int i, N, K;

    scanf("%d %d", &N, &K);

    for(i = 1; i <= N; i++) cur = insert_last(cur, i);

    printf("<");
    while(cur) cur = kill_next(cur, K);
    printf(">");

    return 0;
}