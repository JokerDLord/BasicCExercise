//#include <iostream>
#include <stdio.h>
#include <math.h>
#include <stdbool.h>//bool�������ÿ�
#include <stdlib.h>
#include <time.h>
#include <string.h>//�ַ���������

//ָ��Ӧ�ó���1 ��������
void swap(int *pa, int *pb)
{
	int t = *pa;
	*pa = *pb;
	*pb = t;
}

//����2 �෵��ֵ



//����malloc����ռ���������������
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


//�ɷ����ڴ��С�鿴
int memorysize()
{
	void* p;
	int cnt = 0;
	while ((p = malloc(100*1024 * 1024)))
	{
		cnt++;
	}
	printf("�����˹�%d00MB���ڴ�ռ�", cnt);
	
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

//��������β��0
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

char* mystrcopy1(char* dst, const char* src)//�򵥰汾/ָ��д��
{
	char* ret = dst;
	while (*dst++ == *src++);
	*dst = '\0';
	return ret;
}

//�ַ��������ַ�
//
//��Ŀ˵�����ܼ򵥣������������ַ�����ÿ���ַ���ռ��һ�У�ÿ���ַ����ĳ��Ⱦ�С��10000�ַ���
//���ҵ�һ���ַ����ĳ���С�ڵڶ����ַ����ġ�
//��ĳ���Ҫ�ҳ���һ���ַ����ڵڶ����ַ����г��ֵ�λ�ã������Щλ�ã�����Ҳ���������� - 1��
int strfind()
{
	char s1[10001] = { '\0' };//С�ַ�
	char s2[10001] = { '\0' };//���ַ�
	/*char *s1 = (char*)malloc(10001 * sizeof(char));
	char *s2 = (char*)malloc(10001 * sizeof(char));*/
	int count = 0;
	int flg = 0;//δ�ҵ�sub
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
		p = strstr(p + 1, s1);//ָ������һλ
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

//��· �Զ�������ö��,���ڽ���һ����ö�������±������
int enumidx()
{
	int color = -1;
	char *ColorNames[NumCOLORS] = { "red","yellow","green" };
	char* colorname = NULL;

	printf("��������ϲ����ɫ�Ĵ���");
	scanf("%d", &color);
	if (color >= 0 && color < NumCOLORS)
	{
		colorname = ColorNames[color];
	}
	else
	{
		colorname = "unknown";
	}
	printf("��ϲ������ɫ��%s\n", colorname);
	return 0;
}


//�ṹ
struct date 
{
	int day;
	int month;
	int year;

};//�ṹ�����ֱ�ӽ���ʵ����������

struct time
{
	int hour;
	int minute;
	int second;
};

int structuse()
{
	//�ṹ������ʼ��
	struct date today = { 25, 2,2020 };
	struct date thismonth = { .month = 2,.year = 2020 };//=thismonth = (struct date) { 0, 2, 2020 };
	struct date nextday, tomorrow;
	nextday = (struct date) { 26, 2, 2020 };
	tomorrow = nextday;
	tomorrow.year = 2021;

	printf("this month is %i-%i-%i\n", thismonth.year, thismonth.month, thismonth.day);
	printf("the next day is %i-%i-%i\n", nextday.year, nextday.month, nextday.day);
	printf("the next day is %i-%i-%i\n", tomorrow.year, tomorrow.month, tomorrow.day);

	//�ṹ������ַҪ��&todayȡ
}

int numberofdays(struct date d);//�ں��������½�һ���ṹ������ֵ //���Է���һ���ṹ
bool isLeap(struct date d);

//�ṹͨ����ָ���뺯��
int structpoint()
{
	struct date mydate;
	struct date* p = &mydate;
	(*p).month = 12;
	p->month = 12;//�������� arrow

	struct date dates[5] = { {1,1,1}, };//�ṹ����

	struct dateNtime {
		struct date date;
		struct time time;
	};//
}


//union�������� �����ڽṹ  �������õ������ڲ����ֽڣ�
int unionuse() 
{

}



int main(int argc, char const *argv[])
{
	//int a = 5;
	//int b = 6;
	//swap(&a, &b);
	//printf("a=%d,b=%d\n", a, b);


	//ע�� ָ��Ӽ���������������Ԫ�������ļӼ�Ųλ
	//����ָ������Ľ��
	//
	//*p++ ȡ��p��ָλ�õ�Ԫ�أ�����p�ƶ�����һ��λ��ȥ

	//NULL��ʾ0��ַ
	//��ͬ����ָ�벻��ֱ�Ӹ�ֵ

	//void*��ʾ��֪����ָ�� ��ʾһ����ַ
	//ָ������ת��:
	//int *p = &i; void *q = (void*)p

	//c99֮ǰ�Ķ�̬�ڴ���䷽����
	//int *a = (int*)malloc(n*sizeof(int));

	//mallocuse();

	//memorysize();

	//memorysize2();

	//�ַ������� char sarray[][10] = {"nima","nmsl","wam"}

	char s1[] = "abchello";
	char s2[] = "abChello";
	/*printf("%d\n", mystrlen(s1));
	printf("%d\n", mystrcmp(s1, s2));*/

	//char* dst = (char*)malloc(strlen(s1) + 1);

	//char* p = strchr(s1, 'l');
	//p = strchr(p + 1, 'l');//�����ҵڶ���l
	//printf("%s\n", p);
	//// strstr���ַ�����Ѱ���ַ���
	//char* p = strstr(s1, 'l');
	////p = strchr(p + 1, 'l');//�����ҵڶ���l
	//printf("%s\n", p);

	//strfind();


	/*enum color t = red;
	scanf("%d", &t);
	f(t);*/
	//enumidx();


	//structuse();

	//typedef �Զ��������� typedef ԭ���� ������



	return 0;
}