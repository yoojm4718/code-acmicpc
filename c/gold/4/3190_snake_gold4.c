#include<stdio.h>
#include<stdlib.h>

typedef struct{
    int x, y;
} element; 

typedef struct DListNode {
    element data;
    struct DListNode *llink; 
    struct DListNode *rlink;
} DListNode;

void dinsert(DListNode *before, int data[]) {
    DListNode *newnode = (DListNode *)malloc(sizeof(DListNode)); 
    newnode->data.x = data[0];
    newnode->data.y = data[1];
    newnode->llink = before;
    newnode->rlink = before->rlink;
    before->rlink->llink = newnode; 
    before->rlink = newnode;
}

void ddelete(DListNode* head, DListNode* removed) {
    if (removed == head) return; 
    removed->llink->rlink = removed->rlink; 
    removed->rlink->llink = removed->llink; 
    free(removed);
}

void init(DListNode* phead) {
    phead->llink = phead; 
    phead->rlink = phead;
}

void print_dlist(DListNode* phead) {
    DListNode* p;

    for (p = phead->rlink; p != phead; p = p->rlink) {
        printf("(%d, %d)- ", p->data.x, p->data.y);
    }
    printf("\n");

}

int check_wall(DListNode* head, int N){
    if(head->rlink->data.x > -1 && head->rlink->data.x < N && head->rlink->data.y > -1 && head->rlink->data.y < N)
        return 1;
    return 0;
}

int check_self(DListNode* phead, int pos[]){
    DListNode* p;

    for (p = phead->rlink->rlink; p != phead; p = p->rlink) {
        if(p->data.x == pos[0] && p->data.y == pos[1])
            return 0;
    }

    return 1;
}

int is_change(int change[][2], int check){
    int i;

    for(i = 0; change[i][0] > 0; i++)
        if(change[i][0] == check)
            return change[i][1];

    return 0;
}

int main(void) {
    DListNode* head = (DListNode *)malloc(sizeof(DListNode));
    int i, N, K, L, x, y, X, cnt = 0, check_change, d = 0;
    char C;
    int cur_pos[2] = { 0, 0 };
    int dx[4] = { 0, 1, 0, -1 }, dy[4] = { 1, 0, -1, 0 };
    int change[100][2] = { 0, };
    int board[100][100] = { 0, };
    init(head);

    scanf("%d", &N);
    scanf("%d", &K);
    
    for(i = 0; i < K; i++){
        scanf("%d %d", &x, &y);
        board[x - 1][y - 1] = 1;
    }
    
    scanf("%d", &L);

    for(i = 0; i < L; i++){
        scanf("%d %c", &X, &C);
        change[i][0] = X;
        switch (C)
        {
        case 'D':
            change[i][1] = 1;
            break;
        case 'L':
            change[i][1] = 2;
            break;
        }
    }

    dinsert(head, cur_pos);

    while(1){
        cnt++;

        cur_pos[0] += dx[d];
        cur_pos[1] += dy[d];

        dinsert(head, cur_pos);
        // printf("%d %d ", cnt, d);
        // print_dlist(head);

        if(!(check_wall(head, N) && check_self(head, cur_pos)))
            break;
        
        if(!board[cur_pos[0]][cur_pos[1]]){
            ddelete(head, head->llink);
        }
        else{
            board[cur_pos[0]][cur_pos[1]] = 0;
        }

        check_change = is_change(change, cnt);

        switch (check_change)
        {
        case 1:
            d = (d + 1) % 4;
            break;
        case 2:
            d = (d + 3) % 4;
            break;
        }
        
    }

    printf("%d", cnt);

    free(head); 
    
    return 0;
}