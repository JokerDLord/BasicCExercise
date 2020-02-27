#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <math.h>
#include <stdbool.h>//bool类型引用库
#include <stdlib.h>
#include <time.h>
#include <string.h>//字符串操作库

const int BLOCK_SIZE = 20;


typedef struct {
	int* array;
	int size;
} Array;

void array_inflate(Array* a, int more_size)
{
	int* p = (int*)malloc(sizeof(int) * (a->size + more_size));
	for (int i = 0; i < a->size; i++)
	{
		p[i] = a->array[i];
	}
	free(a->array);
	a->array = p;
	a->size += more_size;

}

Array array_create(int int_size)
{
	Array a;
	a.size = int_size;
	a.array = (int*)malloc(sizeof(int) * a.size);
	return a;
}

void array_free(Array* a)
{
	free(a->array);
	a->size = 0;
	a->array = NULL;
}

// 封装
int array_size(const Array* a)
{
	return a->size;
}

int* array_at(Array* a, int index)
{
	if (index >= a->size)
	{
		array_inflate(a, (index / BLOCK_SIZE + 1) * BLOCK_SIZE - a->size);
	}
	return &(a->array[index]);//返回的是一个指针
}

int array_get(Array* a, int index)
{
	return a->array[index];
}

void array_set(Array* a, int index, int value)
{
	a->array[index] = value;
}

//////////////链表定义

typedef struct _node {
	int value;
	struct _node* next;//这里不能直接用Node，因为还未出现
}Node;

typedef struct _list {
	Node* head;
	Node* tail;
}List;


//注意传进去的第一个参数所代表的是head的指针，
//或者用list结构的指针调用head
void add(List* plist, int number)
{
	//add to linked-list
	Node* p = (Node*)malloc(sizeof(Node));
	p->value = number;
	p->next = NULL;
	//find then last
	/////////
	Node* last = plist->head;
	if (last) {//确保last存在，不是第一个null
		while (last->next)//只要next存在
		{
			last = last->next;
		}
		// attach
		last->next = p;
	}
	else {
		plist->head = p;
	}
	/////////以上这一段可以换成用tail做

}


//遍历操作
void print(List* plist)
{
	Node* p;
	for (p = plist->head; p; p = p->next)
	{
		printf("%d\t", p->value);
	}
	printf("\n");
}


int main()
{
	/*Array a = array_create(100);
	printf("%d\n", array_size(&a));
	*array_at(&a, 0) = 10;
	printf("%d\n", array_get(&a, 0));
	int cnt = 0;
	int number = 0;
	while (number!=-1)
	{
		scanf_s("%d", &number);
		if (number != -1)
			* array_at(&a, cnt++) = number;
	}

	array_free(&a);*/

	//链表可更高效的实现可变数组
	//linked list 


	/*Node* head = NULL;*/
	List list;
	list.head = NULL;
	list.tail = NULL;
	int number;
	do {
		scanf("%d", &number);
		if (number != -1)
		{
			add(&list, number);
		}
	} while (number != -1);
	
	print(&list);

	scanf("%d", &number);
	Node* p;
	int isfound = 0;
	for (p = list.head; p; p = p->next)
	{
		if (p->value == number)
		{
			printf("找到了\n");
			isfound = 1;
			break;
		}
	}
	if (!isfound)
		printf("没找到\n");

	//删除操作
	Node* q;
	for (q=NULL,p = list.head; p; q=p,p = p->next)
	{
		if (p->value == number)
		{
			if (q) {
				q->next = p->next;
				free(p);
				break;
			}
			else {
				list.head = p->next;
			}
		}
	}

	//链表的清除干净
	for (p = list.head; p; p = q)
	{
		q = p->next;
		free(p);
	}


	


	return 0;
}
