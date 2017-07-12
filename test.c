#include "queue.h"
/* 这里要注意：include的路径中""与<>的区别 */
static void visit(node_t note);

int main(void) {
	
	int i = 0;
	char temp[5] = {0};
	char read_data[10] = {0};
	
	printf("\n this is queue test !\n");
	
	queue_t queue = queue_init(); 
	for(i = 0; i < 10; i++) {
		sprintf(temp,"%d",i+10);
		queue_in(queue,temp);
	}
	queue_traverse(queue,&visit); 
	
	printf("\n queue out test 0 !\n");
	queue_out(queue,read_data);
	printf("read_data ---------------> %s \n",read_data);
	memset(read_data,0,sizeof(read_data));
	queue_traverse(queue,&visit);

	printf("\n queue out test 1 !\n");
	queue_out(queue,read_data);
	printf("read_data ---------------> %s \n",read_data);
	memset(read_data,0,sizeof(read_data));
	queue_traverse(queue,&visit); 	
	
	printf("\n this is queue test !\n");
	queue_in(queue,"hello");
	queue_traverse(queue,&visit); 
	
	return 0;
}
 
void visit(node_t note) { 
	printf("node->data = %s\n",note->data);
}



