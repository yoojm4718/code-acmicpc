#include<stdio.h>
#include<stdlib.h>
#define MAX_QUEUE_SIZE 2500

typedef struct {
    int x, y;
} element;

typedef struct {
	element queue[MAX_QUEUE_SIZE];
	int front, rear;
} QueueType;

void error(char *message)
{
	fprintf(stderr, "%s\n", message);
	exit(1);
}

void queue_init(QueueType *q)
{
	q->front = q->rear = 0;
}

int is_empty(QueueType *q)
{
	return (q->front == q->rear);
}

int is_full(QueueType *q)
{
	return ((q->rear + 1) % MAX_QUEUE_SIZE == q->front);
}

void enqueue(QueueType *q, int x, int y)
{
    element item;
    item.x = x;
    item.y = y;
	if (is_full(q))
		error("is full");
	q->rear = (q->rear + 1) % MAX_QUEUE_SIZE;
	q->queue[q->rear] = item;
}

element dequeue(QueueType *q)
{
	if (is_empty(q))
		error("is empty");
	q->front = (q->front + 1) % MAX_QUEUE_SIZE;
	return q->queue[q->front];
}

int board[50][50] = { 0, };
int dx[4] = { -1, 0, 1, 0 };
int dy[4] = { 0, 1, 0, -1 };

int bfs(int x, int y, int M, int N){
    int i, cx, cy, cdx, cdy;
    element cur;
    QueueType *q = (QueueType*)malloc(sizeof(QueueType));

    queue_init(q);

    enqueue(q, x, y);
    board[x][y] = 2;

    while (!is_empty(q)){
        cur = dequeue(q);
        cx = cur.x;
        cy = cur.y;

        for(i = 0; i < 4; i++){
            cdx = cx + dx[i];
            cdy = cy + dy[i];
            if(cdx >= 0 && cdx < M && cdy >= 0 && cdy < N && board[cdx][cdy] != 2 && board[cdx][cdy] == 1){
                enqueue(q, cdx, cdy);
                board[cdx][cdy] = 2;
            }
        }
    }

    free(q);

    return 1;
}

int main(){
    int T, M, N, K, X, Y, i, j, k, l, cnt;

    scanf("%d", &T);

    for(i = 0; i < T; i++){
        cnt = 0;

        scanf("%d %d %d", &M, &N, &K);

        for(j = 0; j < K; j++){
            scanf("%d %d", &X, &Y);
            board[X][Y] = 1;
        }

        for(j = 0; j < M; j++){
            for(k = 0; k < N; k++){
                if(board[j][k] == 1){
                    cnt += bfs(j, k, M, N);
                }
            }
        }
        printf("%d\n", cnt);

        // for(k = 0; k < M; k++){
        //     for(l = 0; l < N; l++){
        //         printf("%d ", board[k][l]);
        //     }
        //     printf("\n");
        // }

        for(j = 0; j < 50; j++){
            for(k = 0; k < 50; k++){
                board[j][k] = 0;
            }
        }

    }
}