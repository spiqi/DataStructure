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
	for (int k = 0; k < G.arcnum; ++k) {
		int v1, v2, w,i,j;
		std::cin >> v1 >> v2 >> w;
		i = LocateVex(G, v1);
		j = LocateVex(G, v2);
		G.arcs[i][j] = w;
		G.arcs[j][i] = G.arcs[i][j];

	}
	return 0;
}
int LocateVex(AMGraph G, VerTexType v)//查找元素v在一维数组 Vertex[] 中的下标，并返回下标 
{
	int i;

	for (i = 0; i < G.vernum; i++)
	{
		if (v == G.vexs[i])
		{
			return i;
		}
	}

	printf("No Such Vertex!\n");
	return -1;
}
