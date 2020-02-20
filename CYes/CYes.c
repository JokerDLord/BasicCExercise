// CYes.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

//#include <iostream>
#include <stdio.h>
#include <math.h>
#include <stdbool.h>//bool类型引用库
#include <stdlib.h>
#include <time.h>
#include <string.h>//字符串操作库



//题目1
//1时间换算（5分）
//题目内容：
//UTC是世界协调时，BJT是北京时间，UTC时间相当于BJT减去8。现在，你的程序要读入一个整数，表示BJT的时和分。整数的个位和十位表示分，百位和千位表示小时。如果小时小于10，则没有千位部分；如果小时是0，则没有百位部分；如果小时不是0而分小于10分，需要保留十位上的0；如果小时是0而分小于10分的，则不需要保留十位上的0。如1124表示11点24分，而905表示9点5分，36表示0点36分，7表示0点7分。
//有效的输入范围是0到2359，即你的程序不可能从测试服务器读到0到2359以外的输入数据。
//你的程序要输出这个时间对应的UTC时间，输出的格式和输入的相同，即输出一个整数，表示UTC的时和分。整数的个位和十位表示分，百位和千位表示小时。如果小时小于10，则没有千位部分；如果小时是0，则没有百位部分；如果小时不是0而分小于10分，需要保留十位上的0；如果小时是0而分小于10分的，则不需要保留十位上的0。

//提醒：要小心跨日的换算。

//输入格式 :
//
//一个整数，表示BJT的时和分。整数的个位和十位表示分，百位和千位表示小时。如果小时小于10，则没有千位部分；如果小时是0，则没有百位部分；如果小时不是0而分小于10分，需要保留十位上的0；如果小时是0而分小于10分的，则不需要保留十位上的0。
//
//
//
//输出格式：
//
//一个整数，表示UTC的时和分。整数的个位和十位表示分，百位和千位表示小时。如果小时小于10，则没有千位部分；如果小时是0，则没有百位部分；如果小时不是0而分小于10分，需要保留十位上的0；如果小时是0而分小于10分的，则不需要保留十位上的0。

//输入样例：
//
//803

//输出样例：
//3
int question1()
{
	int BJT;
	int UTC;

	scanf("%d", &BJT);
	if (BJT > 2359 || BJT < 0) return 0;    //确保输入数据在允许范围内
	UTC = BJT - 800;
	if (UTC < 0)
	{
		UTC += 2400;
	}

	//int hour = UTC / 100;
	//int minute = UTC % 100;
	//if (hour != 0)
	//{
	//	printf("%d", hour);
	//}
	printf("%d", UTC);

	return UTC;
}

//题目2
//题目内容：
//
//班级第一次列队，通常老师会让同学按身高排成一列，然后1、2报数，喊到1的同学向前一 步，就这样，队伍就变成两列了。假设现在一个班级有n个同学，并且他们已经按身高排成 了一列，同学按身高从1到n编号，你能告诉我最后哪些编号的同学站在了第一列么 ?
//
//输入格式 :
//
//	输入一个正整数n，表示班级的人数。
//
//
//	输出格式：
//
//	按顺序输出所有在第一列的同学对应的编号，每两个编号之间用一个空格隔开，最后一个编号后面没有空格。
//
//
//
//	输入样例：
//
//	11
//
//	输出样例：
//
//	1 3 5 7 9 11
int question2()
{
	int n;
	scanf("%d", &n);
	for (int i = 1; i <= n; i += 2)
	{
		printf(" %d", i);
	}

	return 0;
}


//题目内容：
//
//我们认为2是第一个素数，3是第二个素数，5是第三个素数，依次类推。
//
//现在，给定两个整数n和m，0 < n <= m <= 200，你的程序要计算第n个素数到第m个素数之间所有的素数的和，包括第n个素数和第m个素数。
//
//	输入格式 :
//
//两个整数，第一个表示n，第二个表示m。
//
//输出格式：
//
//一个整数，表示第n个素数到第m个素数之间所有的素数的和，包括第n个素数和第m个素数。
//
//输入样例：
//
//2 4
//输出样例：
//
//15

int question3()
{
	int n, m, count = 0, num = 2, sum = 0;
	scanf("%d %d", &n, &m);
	while (1)
	{
		int isprime = 1;
		for (int i = 2; i < num; i++)//判断一个数是否是素数
		{
			if (num % i == 0)
			{
				isprime = 0;
				break;
			}

		}
		if (isprime == 1)
		{
			count += 1;
			if (count >= n && count <= m)
			{
				sum += num;
			}
		}
		if (count == m)
			break;
		num += 1;
	}
	printf("%d", sum);
	return 0;
}

//题目内容：
//
//你的程序要读入一个整数，范围是[-100000, 100000]。然后，用汉语拼音将这个整数的每一位输出出来。
//
//如输入1234，则输出：
//
//yi er san si
//
//注意，每个字的拼音之间有一个空格，但是最后的字后面没有空格。当遇到负数时，在输出的开头加上“fu”，如 - 2341输出为：
//
//fu er san si yi
//
//输入格式 :
//
//一个整数，范围是[-100000, 100000]。
//
//
//
//输出格式：
//
//表示这个整数的每一位数字的汉语拼音，每一位数字的拼音之间以空格分隔，末尾没有空格。
//

//输入样例：
//
//- 30
//
//输出样例：
//
//fu san ling

int question4()
{
	int num, temp, count=0;
	scanf("%d", &num);
	temp = num;
	//确定输入数的位数
	while (temp!=0)
	{
		temp /= 10;
		count += 1;
	}

	if (num < 0)
	{
		num = -num;
		printf("fu");
	}
	// 整数为零需要特殊处理
	if (count == 0) printf("ling");

	for (int i = count-1; i >= 0; i--)
	{
		int sp = num / pow(10, i);
		switch (sp)
		{
		case 0:
			printf(" ling"); break;
		case 1:
			printf(" yi"); break;
		case 2:
			printf(" er"); break;
		case 3:
			printf(" san"); break;
		case 4:
			printf(" si"); break;
		case 5:
			printf(" wu"); break;
		case 6:
			printf(" liu"); break;
		case 7:
			printf(" qi"); break;
		case 8:
			printf(" ba"); break;
		case 9:
			printf(" jiu"); break;

		default:
			break;
		}
		num -= (sp * pow(10, i));
	}

	return 0;
}

//整数求逆序
int reverseorder()
{
	int x;
	scanf("%d", &x);
	
	int digit;//逆序时的每一位
	int ret = 0;//
	while (x>0)
	{
		digit = x % 10;
		printf("%d", digit);
		ret = ret * 10 + digit;
		//printf("%d", ret);
		x /= 10;
	}
	//printf("%d", ret);
	return 0;
}

//奇数偶数统计
int question5()
{
	int odd = 0, even = 0, x;
	
	while (scanf("%d", &x))
	{
		if (x == -1) break;
		else if (x % 2 == 0)
		{
			even++;
		}
		else if (x % 2 == 1)
		{
			odd++;
		}
	} 	
	printf("%d %d", odd, even);
	return 0;
}

int question6()
{
	int num, rem;
	int count = 0, binum = 0;
	scanf("%d", &num);
	while (num > 0)
	{
		count += 1;
		rem = num % 10;
		if (rem % 2 == count % 2)
		{
			binum += pow(2, count - 1);
		}
		num /= 10;
	}
	printf("%d", binum);
	return 0;
}

//统计0-9各个数字出现次数
void statnum()
{
	const int number = 10;
	int count[10];
	int x;

	for (int i = 0; i < number; i++)
	{
		count[i] = 0;
	}
	scanf("%d", &x);
	while (x != -1)
	{
		if (x >= 0 && x <= 9)
		{
			count[x]++;
		}
		scanf("%d", &x);
	}
	for (int j = 0; j < number; j++)
	{
		printf("%d ", count[j]);
	}
}

//请写一个程序，输入一个分数，计算出它的小数形式。无论是否可以除尽，输出最多小数点后200位。
//输入格式:
//
//形如
//
//a / b
//
//的两个数，其中10 <= a < b < 100。也就是说，这个小数一定是小于1的正数。
//	提示：输入是带着两个数中间的“ / ”的，所以scanf应采用“ % d / % d”这样的输入格式。
int Fraction2Decimal()
{
	int numerator, denominator, count = 0, rem;
	scanf("%d/%d", &numerator, &denominator);
	printf("0.");
	do
	{
		rem = numerator * 10 / denominator;
		printf("%d", rem);
		numerator = numerator * 10 % denominator;
		count++;
	} while (count <= 200 && (numerator != 0 || rem != 0));
	printf("\n");
	return 0;

}

//判断素数函数
int isPrime(int x)
{
	int ret = 1;
	if (x == 1 || (x % 2 == 0 && x != 2)) ret = 0;
	for (int i = 3; i < sqrt(x); i+=2)
	{
		if (x % i == 0)
		{
			ret = 0;
			break;
		}
	}
	return ret;
}

//通过结构链接面值和面额
int coins()
{
	int amount[] = { 1,5,10,25,50 };
	char *name[] = { "penny", "nickel","dime","quarter","half_dollor" };

	struct
	{
		int amount;
		char *name;
	}coins[] = 
	{
		{1,"penny"},
		{5,"nickel"},
		{10,"dime"},
		{25,"quarter"},
		{50,"half_dollor"}
	};

	return 0;
}

int pointer()
{
	int a[10];

	printf("%p\n", &a);
	printf("%p\n", a);
	printf("%p\n", &a[0]);
	printf("%p\n", &a[1]);
	return 0;
}

//语句各单词字符长度统计
int wordlength()
{
	int i = 0;
	char a;
	while (1) {
		scanf("%c", &a);
		if (a == '.') {
			if (i != 0) {
				printf("%d", i);
			}
			printf("\n");
			break;
		}
		if (a == ' ') {
			if (i != 0) {
				printf("%d ", i);
				i = 0;
			}
		}
		else {
			i += 1;
		}
	}
	return 0;
}

//最简分式
//本质 辗转相除法求最大公约数
int simplest()
{
	int a, b, temp = 0;
	scanf("%d/%d", &a, &b);
	int max = (a > b) ? a : b;
	int min = a + b - max;
	temp = max % min;
	while (temp != 0)
	{
		max = min;
		min = temp;
		temp = max % min;
	}
	printf("%d/%d", a / min, b / min);


	return 0;
}



int main()
{
	/*printf("hello world!!\n");
	int a = 25;
	int b = 45;
	printf("a+b=%d\n", a + b);*/

	/*int a = 0;
	int b = 0;
	scanf("%d %d", &a, &b);
	printf("%d %d", a, b);
	return 0;*/

	/*int a;
	int b;
	printf("请输入两个整数:");
	scanf("%d %d", &a, &b);

	printf("%d + %d = %d", a, b, a + b);*/

	//printf("%f", 10.0 / 3 * 3);//C里面要注意不同数据类型相除得结果

	/*double foot;
	double inch;
	printf("输入身高的尺和寸：");
	scanf("%lf %lf", &foot, &inch);
	printf("身高是%f米。\n", (foot + inch / 12) * 0.3048);*/

	//int x = 1;
	//int n = 0;
	//while (x)
	//{
	//	n++;
	//	printf("%d ", n);
	//}

	//int UTC = question1();
	//question2();
	//question3();
	//question4();
	//reverseorder();
	//question5();
	//question6();

	//statnum();

	//Fraction2Decimal();

	//int a[10] = { 2,4,6,7,1,98,};
	//for (int i = 0; i < sizeof(a)/sizeof(a[0]); i++)
	//{
	//	printf("%d ", a[i]);
	//}
	////数组作为函数参数时，要传入数组大小，不能再参数内直接获取数组大小

	//pointer();

	//&i 取i的地址
	//*p 取p指针（地址）指向（存储）的元素  int* p = &i;
	//int* p,q; 同 int *p,q;
	//
	//函数参数表中的数组实际是指针
	//数组a = &a[0] 数组就是第一个变量的地址（指针）
	//[]可以对数组做 也可以对指针做 a[0]  p[0]
	//*可以对指针做，也可以对数组做 *a = 25
	//数组变量是const指针，所以不能被赋值

	// char *str = "hello";
	// char str[] = "hello";
	//*str字符串只能读不能写 str[]数组形式字符串存在本地变量，可以读写
	//str用指针的地方：1要求可读 2作为处理参数 3动态分配空间malloc

	// char string[8];//注意char string[8] = "";的写法完全错误
	//scanf("%7s",string); 安全的输入 只读7个

	//指针字符串记得初始化
	//wordlength();
	simplest();


	return 0;

}

