#include <stdlib.h>
#include <stdio.h>
#include <math.h>

void *mem;

int usedMemory = 0;
int actualMemory = 0;
struct Node{
	void *bytes;
	int size;
	struct Node *next;
};

typedef struct Node Node;
Node *head,*tail;
void* allocate(int requestedBytes){
	if(head == NULL){
		head = (Node *)malloc(sizeof(Node));
		head->bytes = (void *)malloc(sizeof(requestedBytes));
		head->size = requestedBytes;
		head->next = NULL;
		tail = head;
		usedMemory = sizeof(head) + sizeof(tail) + requestedBytes;
		actualMemory = requestedBytes;
	}else{
		tail->next = (Node *)malloc(sizeof(Node));
		usedMemory += requestedBytes + sizeof(int) + sizeof(tail->next);
		actualMemory += requestedBytes;
		tail->next->bytes = (void *)malloc(sizeof(requestedBytes));
		tail = tail->next;
		tail->size = requestedBytes;
		tail->next = NULL;

	}
	
	return tail->bytes;
}


void deallocate(void *ptr){
	if(head == NULL)
		return;//invalid input
	Node *temp = head;
	Node *prev = NULL;
	while(temp){
		if(temp->bytes == ptr){
			if(prev ){
				usedMemory -= temp->size;
				actualMemory -= temp->size;
				prev->next = temp->next;
				free(temp->bytes);
				free(temp);
			}else{
				int toFree = sizeof(head)+sizeof(tail);
				//deleting first node
				usedMemory -= temp->size ;
				actualMemory -= temp->size;
				Node *next = temp->next;
				free(head);
				head = next;
				if(!head){
					usedMemory -= toFree;
				}
			}
			return;
		}
		prev = temp;
		temp = temp->next;
	}	
}
void stats(void){
	
	printf("total_memory_allocated %d \n",usedMemory);
	printf("Unusable Memory MetaData %d \n",usedMemory-actualMemory);
	printf("actualMemory size %d \n",actualMemory);
	printf("\n");
}

int main(){
	//intitally we have two pointers to point to the memory blocls
	//usedMemory = sizeof()
	void *newp = allocate(4096);
	void *newp2 = allocate(8192);
	void *newp3 = allocate(2048);
	void *newp4 = allocate(16384);
	//void *newp = allocate(45);
	stats();

	printf("freeing a memory block of size 8192 bytes\n");
	deallocate(newp2);
	stats();
	printf("freeing a memory block of size 2048 bytes\n");
	deallocate(newp3);
	stats();
	return 0;
}