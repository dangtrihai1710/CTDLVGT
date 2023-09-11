#include <iostream>
#include <cstring>
#define MAXQUEUE 100
using namespace std;

typedef struct queue{
    int front, rear;
    int node[MAXQUEUE];
}Queue;

void Init(Queue &q) {
    q.front = q.rear = -1;
}

int IsEmpty(Queue &q) {
    return (q.front == -1);
}

int IsFull(Queue &q) {
    return ((q.rear - q.front+1) % MAXQUEUE == 0);
}

int enQueue(Queue &q, int x) {
    if(IsFull(q)) return 0; // Full Queue
    else {
        if(IsEmpty(q)) q.front = 0;
        q.rear = (q.rear + 1) % MAXQUEUE; 
        q.node[q.rear] = x;
        return 1;
    }
} 

int deQueue(Queue &q, int &x) {
    if(IsEmpty(q)) return 0; //Empty Queue
    else {
        x = q.node[q.front];
        if(q.front == q.rear) Init(q);
        else    q.front = (q.front+1) % MAXQUEUE;
        return 1;
    }
}
