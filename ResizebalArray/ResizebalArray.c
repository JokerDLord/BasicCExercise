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



int main()
{
	Array a = array_create(100);
	printf("%d\n", array_size(&a));
	*array_at(&a, 0) = 10;
	printf("%d\n", array_get(&a, 0));
	/*int cnt = 0;
	int number = 0;
	while (number!=-1)
	{
		scanf("%d", &number);
		if (number != -1)
			* array_at(&a, cnt++) = number;
	}*/

	array_free(&a);

	return 0;
}
