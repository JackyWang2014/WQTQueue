//
//  main.c
//  WQTQueue
//
//  Created by 王亓泰 on 16/4/14.
//  Copyright © 2016年 WangQitai. All rights reserved.
//

#include <stdio.h>
#include <stdlib.h>
typedef struct data {
    int data;       // 存储数据
    struct data * next; // 指向下一节点的指针
}data_t;
// 队列的头尾指针
typedef struct queue {
    data_t * front; // 头
    data_t * rear; // 尾
}queue_t;
// 将数据或者任务置入队列
void en_queue(queue_t * queue, int data);
// 从队列中取出数据
int de_queue(queue_t * queue, int * x);

int main(int argc, const char * argv[]) {
  
    queue_t queue = {};
    en_queue(&queue, 4);
    en_queue(&queue, 5);
    en_queue(&queue, 6);
    
    int data;
    while (de_queue(&queue, &data)) {
        printf("%d\n",data);
    }
    
    return 0;
}

// 将数据或者任务置入队列
void en_queue(queue_t * queue, int data)
{
    // 开辟空间, 存储数据
    data_t * p = (data_t *)malloc(sizeof(data_t));
    if (!p) {
        perror("malloc");
        exit(-1);
    }
    
    p->data = data;
    p->next = NULL;
    
    // 放入队列
    if (queue->front == NULL) {
        queue->front = queue->rear = p;
    } else {
        queue->rear->next = p;
        queue->rear = p;
    }
    
}
// 从队列中取出数据
int de_queue(queue_t * queue, int * x)
{
    if (queue->front == NULL) {
        return 0;
    }
    // 取出数据
    *x = queue->front->data;
    // 去掉源队列的顶端
    data_t * temp = queue->front->next;
    free(queue->front);
    queue->front = temp;
    return 1;
}



