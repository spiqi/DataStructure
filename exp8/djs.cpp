#pragma warning(disable:4996) 
#include<iostream>
const int MaxInt=32767;
const int MVNum = 100;
typedef char VerTexType;
typedef short ArcType;


typedef struct {
	//VerTexType vexs[MVNum];
	ArcType arcs[MVNum][MVNum];
	int vernum, arcnum;
}AMGraph;// 图的邻接矩阵

void ShortestPath_Floyd(AMGraph G) {
	const int a = G.arcnum;
	int D[MVNum][MVNum];
	int Path[MVNum][MVNum];
	for (int i = 0; i < G.vernum; ++i)
		for (int j = 0; j < G.vernum; ++j) {
			D[i][j] = G.arcs[i][j];
			if (D[i][j] < MaxInt && i != j)
				Path[i][j] = i;//如果i和j之间有弧,则将j的前驱置位i
			else Path[i][j] = -1;
		}
for (int k=0;k<G.vernum;++k)
	for(int i=0;i<G.vernum;++i)
		for(int j=0;j<G.vernum;++j)
			if (D[i][k] + D[k][j] < D[i][j]) {
				D[i][j] = D[i][k] + D[k][j];
				Path[i][j] = Path[k][j];
			}
}


int CreateUDN(AMGraph &G) {//生成无向图
	printf("Input verNum and ArcNum\n");
	std::cin >> G.vernum >> G.arcnum; //读入点和边的数目
	
	for (int i = 0; i < G.vernum; ++i)
		for (int j = 0; j < G.vernum; ++j)
			G.arcs[i][j] = MaxInt;//初始化所有边为最大
	for (int k = 0; k < G.arcnum; ++k) {
	
		int i, j,w;
		printf("Input the %d / %d ARC :v1 v2\n", k, G.arcnum);
		std::cin >> i >> j>>w;
		G.arcs[i][j] = w;
		G.arcs[j][i] = G.arcs[i][j]; //图的两侧定点互相连接,无向图,点对点

	}
	return 0;
}
int main1() {
	// to do define AMGraph
	int a;
	printf("choose: 1.Floyd");
	scanf("%d", &a);
	switch (a)
	{
	case 	1:ShortestPath_Floyd();
		break;
	default:
		break;
	}
}

int main() {
	//test();
	//scanf("%d");
	return 0;
}
