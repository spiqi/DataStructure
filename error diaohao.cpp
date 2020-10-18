#include <stdio.h>
#include <stdlib.h>
#define MAXSIZE 100
#define OVERFLOW 0
typedef  struct SqStack {
	int* base;  //栈底指针
	int* top;//栈顶指针
	int stacksize;
}SqStack;


char n[MAXSIZE];
char m[MAXSIZE];
SqStack S;
char k;



void InitStack() {
	//构造一个空栈
	S.base = new int[MAXSIZE];
	//if (!S.base) exit(OVERFLOW);
	S.top = S.base;
	S.stacksize = MAXSIZE;
}

//进栈
void Push( char a) {
	//插入元素为 a 为新的栈顶元素

	if (S.top - S.base == S.stacksize) { //栈满
		printf("ERROR1");
	}
	*S.top++ = a;

}

//出栈
void Pop( char& a) {
	//删除S的栈顶元素,用a返回其值
	if (S.top == S.base) {
		printf("ERROR2");
	}
	a = *--S.top;  //栈顶指针减一，将新栈顶元素赋值给a

}

// 取栈顶元素
void GetTop( char &b) {
	//返回栈顶元素，不修改栈顶指针
	if (S.top != S.base) {//栈非空

		b = *S.top;     //将栈顶元素赋值给b

	}
	else {
		b ='E';
	}

}
void Getchar() {
	int i = 0;
	char ch;
	ch = getchar();    //读取一个字符
	while (ch != '\n'){ 
		m[i++] = ch;
		ch = getchar();
	}
	for (int j = 0; j < i; j++) {
		if (m[j] == '(') {
			Push( m[j]);
		}
		else {
			
			GetTop( k);
			if (k != '(') {
				printf("匹配失败   1 Fail\n");
				return;
			}
			
			Pop( n[j]);
		}}
		GetTop( k);
		if (k == 'E') {
			printf("匹配成功 Succ\n");

		}
		else {
			printf("匹配失败  2 Fail\n");

		}




	}



int main() {
	InitStack();
	printf("请输入需要判断的括号表达式");
	Getchar();
	printf("\naaaaa");



	system("pause");
	return 0;
}
