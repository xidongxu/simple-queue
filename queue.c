#include "queue.h"
/* 这里要注意：include的路径中""与<>的区别 */
/*构造一个空队列*/  
queue_t queue_init(void) {  
	queue_t queue = (queue_t)malloc(sizeof(queue));  
	if(queue!=NULL){  
		queue->head = NULL;  
		queue->rear = NULL;  
		queue->size = 0;   
	}  
	return queue;  
}  

/*销毁一个队列*/  
void queue_destroy(queue_t queue) {  
	if(queue_is_empty(queue)!= true) {  
		queue_clear(queue);
	}
	free(queue);  
}  

bool queue_is_empty(queue_t queue) {
	if((queue->head == NULL) && (queue->rear == NULL) && (queue->size == 0)){
		return true;
	} else {    
        return false;
	}
}

void queue_clear(queue_t queue) {
	while(queue_is_empty(queue) != true) {  
        queue_out(queue,NULL);  
    }  
}

/*将新元素入队列*/  
node_t queue_in(queue_t queue,char *data) {  
  
    node_t node = (node_t)malloc(sizeof(node));  
  
    if(node != NULL) {  
		strncpy(node->data,data,strlen(data));
        node->next = NULL;  
		if(queue_is_empty(queue)) {  
			queue->head = node;  
		} else {  
			queue->rear->next = node;  
		}  
		queue->rear = node;  
		queue->size++;  
    }  
    return node;
} 

/*队头元素出队*/
node_t queue_out(queue_t queue, char *data) {
    node_t node = queue->head;  
    if(queue_is_empty(queue) != true && node!=NULL ) {  
        if(data != NULL) {
			strncpy(data,node->data,strlen(node->data));
		}
        queue->size--;  
        queue->head = node->next;  
        free(node);  
        if(queue->size ==0) {
            queue->rear =NULL;
		}
    }  
    return queue->head;   
}

/*遍历队列*/  
void queue_traverse(queue_t queue,void (*visit)(node_t)) {  
	int i = 0;
    node_t node = queue->head;  
    i = queue->size;  
    while(i--) {  
		visit(node);  
		node = node->next;  
    }  
}

