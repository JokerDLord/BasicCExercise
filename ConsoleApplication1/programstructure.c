#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <math.h>
#include <stdbool.h>//bool类型引用库
#include <stdlib.h>
#include <time.h>
#include <string.h>//字符串操作库

#define PI 3.14159

//static静态本地变量实际是全局变量 但作用域是函数内部
//全局生存期 本地作用域
//返回本地变量的地址是危险的
//返回全局变量、静态本地变量的地址是安全的
//*使用全局变量和静态本地变量的函数的线程是不安全的

//extern int gall;

//#ifndef __LIST_HEAD__
//#define __LIST_HEAD__

//#endif


//位运算
int bituse()
{
	//按位与& 都为1才得1
	//按位或| 只要有1就得1
	//异或 相等为0 不相等为1

	int number;
	scanf("%d", &number);
	/*number = 123;*/
	unsigned mask = 1u << 31;
	for (; mask; mask >>= 1)
	{
		//如果这一位是1，则输出1，否则输出0
		printf("%d", number & mask ? 1 : 0);
	}
	printf("\n");
	return 0;
}






int main()
{
	//printf("%0+9d\n", 123);//右对齐有加号填充0
	//printf("%-9d\n", 123);//左对齐
	//printf("%9.2f\n", 123.001);//总共9位，小数点取前两位
	//printf("%d", 123);//左对齐

	//%n用于统计字符数量，放到一个地址&num里面

	//<文件作为输入 >文件作为输出

	/*FILE* fp = fopen("D:\\考研相关\\C练习\\基础练习题\\test1.txt", "r");
	if (fp)
	{
		char line[100];
		fscanf(fp,"%s", line);
		printf("%s\n", line);
		fclose(fp);
	}
	else
	{
		printf("无法打开文件\n");
	}*/


	bituse();
	return 0;
}
