#include <iostream>
#define MAX 100 // 队列可能达到的最大容量
typedef struct {
	int * base;
	int front;
	int rear; //尾指针
}SqQueue;
int Init(SqQueue & Q) {
	Q.base = new int[MAX];
	if (!Q.base) exit(OVERFLOW); //溢出
	return 0;
}
int QueueLength(SqQueue Q) {
	return Q.rear - Q.front + MAX
		% MAX;
}
int EnQueue(SqQueue & Q, int e)
{
	if ((Q.rear + 1) % MAX == Q.front)
		return 1;//队满溢出
	Q.base[Q.rear] = e;
	Q.rear = (Q.rear + 1) % MAX;
	return 0;
}  //入队
int DeQueue(SqQueue & Q) {  //循环队列的出队
	
	if (Q.front == Q.rear) return 1;//队空
	int e = Q.base[Q.front];
	Q.front = (Q.front + 1) % MAX;
	return e;
}
int GetHead(SqQueue Q) {
	if (Q.front != Q.rear) return Q.base[Q.front];
}

int main() {
	SqQueue  sq1,sq2 ;
	Init(sq1);
	Init(sq2);
	std::cout << "Please input the number of males and females\n";
	int a, b;
	std::cin >> a >> b;
	for (int i = 0;i < a;i++) EnQueue(sq1, i);
	for (int i = 0;i < b;i++) EnQueue(sq2, i);//读入女队
	std::cout << "Please input the number of the music";
	std::cin >> a;
	for (int i = 0;i < a;i++) {}
}
