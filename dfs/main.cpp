#include<iostream>
#define MaxInt 32767
#define MVNum 100
typedef char VerTexType;
typedef int ArcType;
typedef struct {
	VerTexType vexs[MVNum];
	ArcType arcs[MVNum][MVNum];
	int vernum, arcnum;
}AMGraph;// 图的邻接矩阵
int CreateUDN(AMGraph &G) {
	std::cin >> G.vernum >> G.arcnum;
	for (int i = 0; i < G.vernum; ++i) //依次读入 点的信息
	std::	cin >> G.vexs[i];
	for (int i = 0; i < G.vernum; ++i)
		for (int j = 0; j < G.vernum; ++j)
			G.arcs[i][j] = MaxInt;
}


int main() {
	int a;
	printf("e");
	}
}
