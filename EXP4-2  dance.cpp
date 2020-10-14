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
	Q.front = Q.rear = 0;
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
	SqQueue  sq1;
	Init(sq1); // 男队初始化
	SqQueue sq2;
	Init(sq2);  //女队
	std::cout << "Please input the number of males and females\n";
	int a, b;
	std::cin >> a >> b;// 读入男 女 
	for (int i = 1; i <=a; i++) EnQueue(sq1, i);

	for (int i = 1; i <=b; i++) EnQueue(sq2, i);//读入女队
	std::cout << "Please input the number of the music\n";//读入歌曲的数量
	std::cin >> a;
	std::cout << "Input each music will accept the number of dancers"<<std::endl;//输入每首音乐需要的舞伴数目
	std::cin >> b;//
	for (int i = 0; i < a; i++) {
		std::cout <<std::endl<< "Song:" << i << "\n";
		for (int j = 0; j < b; j++) {
			int s = DeQueue(sq1);
			std::cout << s; //nan出队
			EnQueue(sq1, s);
			s = DeQueue(sq2);
			std::cout << " " << s << std::endl; // nv 出队
			EnQueue(sq2, s);//女入队
		}
		
	}
std::cin >> a; //test for pause 
}
