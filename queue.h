#ifndef __QUEUE_H_
#define __QUEUE_H_

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <malloc.h>

#define DATA_BUFFER_MAX	256

/* 队列中数据的数据结构 */
typedef struct node {  
    char data[DATA_BUFFER_MAX];  
    struct node* next;  
} *node_t;  

/* 队列 */
typedef struct queue {
    node_t head;
    node_t rear;
    int size;  
} *queue_t;

queue_t queue_init(void);
void queue_destroy(queue_t queue);
bool queue_is_empty(queue_t queue);
void queue_clear(queue_t queue);
node_t queue_in(queue_t queue,char *data);
node_t queue_out(queue_t queue, char *data);
void queue_traverse(queue_t queue,void (*visit)(node_t));

#endif