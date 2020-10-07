#define ERROR 114514
#include <iostream>
#define MAX 100
typedef struct {
	int * base;
	int * top;
	int stacksize;
} SqStack;
int InitStack(SqStack &S) {
	S.base = new int[MAX];
	if (!S.base) exit(OVERFLOW);// 存储分配失败
		S.top = S.base;
		S.stacksize = MAX;
		return 0;
}
int Push(SqStack &S, int e) {
	if (S.top - S.base == S.stacksize) return ERROR;// stack if full
	*S.top++ = e;
	return 0;
	}
int Pop(SqStack & S, int & e) {

}
