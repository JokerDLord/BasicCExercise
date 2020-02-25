//#include <iostream>
#include <stdio.h>
#include <math.h>
#include <stdbool.h>//bool类型引用库
#include <stdlib.h>
#include <time.h>
#include <string.h>//字符串操作库

//指针应用场景1 交换变量
void swap(int *pa, int *pb)
{
	int t = *pa;
	*pa = *pb;
	*pb = t;
}

//场景2 多返回值



//利用malloc申请空间进行数组逆序输出
int mallocuse()
{
	int* p;
	int num;
	scanf("%d", &num);
	p = (int*)malloc(num*sizeof(int));
	for (int i = 0; i < num; i++)
	{
		scanf("%d", &p[i]);
	}
	for (int i = num - 1; i >= 0; i--)
	{
		printf("%d ", p[i]);
	}

	free(p);
	return 0;
}


//可分配内存大小查看
int memorysize()
{
	void* p;
	int cnt = 0;
	while ((p = malloc(100*1024 * 1024)))
	{
		cnt++;
	}
	printf("分配了共%d00MB的内存空间", cnt);
	
	return 0;
}

int memorysize2(void)
{
	void *p = 0;
	int cnt = 0;
	//p = malloc(1000 * 1024 * 1024);
	free(p);
	return 0;
}

//不包含结尾的0
int mystrlen(const char* s)
{
	int count = 0;
	while (s[count] != '\0')
	{
		count++;
	}
	return count;
}

int mystrcmp(const char* s1, const char* s2)
{
	while (*s1 == *s2 && *s1 != '\0')
	{
		s1++;
		s2++;
	}
	return *s1 - *s2;
}

char* mystrcopy(char* dst, const char* src)
{
	int index = 0;
	while (src[index]) //!= '\0'
	{
		dst[index] = src[index];
		index++;
	}
	dst[index] = '\0';
	return dst;
}

char* mystrcopy1(char* dst, const char* src)//简单版本/指针写法
{
	char* ret = dst;
	while (*dst++ == *src++);
	*dst = '\0';
	return ret;
}

//字符串中找字符
//
//题目说起来很简单，你会读到两个字符串，每个字符串占据一行，每个字符串的长度均小于10000字符，
//而且第一个字符串的长度小于第二个字符串的。
//你的程序要找出第一个字符串在第二个字符串中出现的位置，输出这些位置，如果找不到，则输出 - 1。
int strfind()
{
	char s1[10001] = { '\0' };//小字符
	char s2[10001] = { '\0' };//大字符
	/*char *s1 = (char*)malloc(10001 * sizeof(char));
	char *s2 = (char*)malloc(10001 * sizeof(char));*/
	int count = 0;
	int flg = 0;//未找到sub
	char* stemp = s2;
	char temp;
	char c;
	while ((c = getchar())!='\n')
	{
		s1[count++] = c;
	}
	count = 0;
	while ((c = getchar()) != '\n')
	{
		s2[count++] = c;
	}

	char* p = strstr(stemp, s1);
	while (p != NULL)
	{
		temp = *p;
		*p = '\0';
		printf("%d ", strlen(stemp));
		*p = temp;
		p = strstr(p + 1, s1);//指针右移一位
		flg = 1;
	}
	
	if (flg == 0)
	{
		printf("%d ", -1);
	}
	/*printf("%s\n", s1);*/

	return 0;


}

enum COLOR { red, yellow, green, NumCOLORS };

void f(enum color c)
{
	printf("%d\n", c);
}

//套路 自动计数的枚举,便于建立一个用枚举量做下标的数组
int enumidx()
{
	int color = -1;
	char *ColorNames[NumCOLORS] = { "red","yellow","green" };
	char* colorname = NULL;

	printf("请输入你喜欢颜色的代码");
	scanf("%d", &color);
	if (color >= 0 && color < NumCOLORS)
	{
		colorname = ColorNames[color];
	}
	else
	{
		colorname = "unknown";
	}
	printf("你喜欢的颜色是%s\n", colorname);
	return 0;
}


//结构
struct date 
{
	int day;
	int month;
	int year;

};//结构后可以直接接上实例进行声明

struct time
{
	int hour;
	int minute;
	int second;
};

int structuse()
{
	//结构变量初始化
	struct date today = { 25, 2,2020 };
	struct date thismonth = { .month = 2,.year = 2020 };//=thismonth = (struct date) { 0, 2, 2020 };
	struct date nextday, tomorrow;
	nextday = (struct date) { 26, 2, 2020 };
	tomorrow = nextday;
	tomorrow.year = 2021;

	printf("this month is %i-%i-%i\n", thismonth.year, thismonth.month, thismonth.day);
	printf("the next day is %i-%i-%i\n", nextday.year, nextday.month, nextday.day);
	printf("the next day is %i-%i-%i\n", tomorrow.year, tomorrow.month, tomorrow.day);

	//结构变量地址要用&today取
}

int numberofdays(struct date d);//在函数内是新建一个结构变量的值 //可以返回一个结构
bool isLeap(struct date d);

//结构通常传指针入函数
int structpoint()
{
	struct date mydate;
	struct date* p = &mydate;
	(*p).month = 12;
	p->month = 12;//多用这种 arrow

	struct date dates[5] = { {1,1,1}, };//结构数组

	struct dateNtime {
		struct date date;
		struct time time;
	};//
}


//union联合类型 类似于结构  可用来得到整数内部的字节？
int unionuse() 
{

}



int main(int argc, char const *argv[])
{
	//int a = 5;
	//int b = 6;
	//swap(&a, &b);
	//printf("a=%d,b=%d\n", a, b);


	//注意 指针加减运算类似于数组元素索引的加减挪位
	//两个指针相减的结果
	//
	//*p++ 取出p所指位置的元素，并把p移动到下一个位置去

	//NULL表示0地址
	//不同类型指针不能直接赋值

	//void*表示不知类型指针 表示一个地址
	//指针类型转换:
	//int *p = &i; void *q = (void*)p

	//c99之前的动态内存分配方法：
	//int *a = (int*)malloc(n*sizeof(int));

	//mallocuse();

	//memorysize();

	//memorysize2();

	//字符串数组 char sarray[][10] = {"nima","nmsl","wam"}

	char s1[] = "abchello";
	char s2[] = "abChello";
	/*printf("%d\n", mystrlen(s1));
	printf("%d\n", mystrcmp(s1, s2));*/

	//char* dst = (char*)malloc(strlen(s1) + 1);

	//char* p = strchr(s1, 'l');
	//p = strchr(p + 1, 'l');//可以找第二个l
	//printf("%s\n", p);
	//// strstr在字符串中寻找字符串
	//char* p = strstr(s1, 'l');
	////p = strchr(p + 1, 'l');//可以找第二个l
	//printf("%s\n", p);

	//strfind();


	/*enum color t = red;
	scanf("%d", &t);
	f(t);*/
	//enumidx();


	//structuse();

	//typedef 自定数据类型 typedef 原类型 新名字



	return 0;
}