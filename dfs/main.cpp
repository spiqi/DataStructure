#include<iostream>
//const int MaxInt 32767;
const int MVNum=100;
typedef char VerTexType;
typedef bool ArcType;
typedef int QElemType;//暂定队列元素类型
typedef struct{
QElemType *base;
	int front;
	int rear;

}SqQueue;

typedef struct {
	VerTexType vexs[MVNum];
	ArcType arcs[MVNum][MVNum];
	int vernum, arcnum;
}AMGraph;// 图的邻接矩阵


int InitQueue( & Q){  //队列初始化
	Q.base = new int [MVNum];
	if (!Q.base) exit (OVERFLOW);
	Q.front =Q.rear =0;
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

	printf("No Such Vertex:%c!\n",v);
	return -1;
}
int CreateUDN(AMGraph &G) {
	printf("Input verNum and ArcNum\n");
	std::cin >> G.vernum >> G.arcnum;
	for (int i = 0; i < G.vernum; ++i) //依次读入 点的信息
	{
		printf("Vertex %d/%d: \n",i,G.vernum);
		std::	cin >> G.vexs[i];}
	for (int i = 0; i < G.vernum; ++i)
		for (int j = 0; j < G.vernum; ++j)
			G.arcs[i][j] = false;
	for (int k = 0; k < G.arcnum; ++k) {
		VerTexType v1, v2;
		int i,j;
		printf ("Input the %d / %d ARC :v1 v2\n",k,G.arcnum);
		std::cin >> v1 >> v2 ;
		i = LocateVex(G, v1);
		j = LocateVex(G, v2);
		G.arcs[i][j] = true;
		G.arcs[j][i] = G.arcs[i][j]; //图的两侧定点互相连接

	}
	return 0;
}
bool visited[MVNum];
/*void DFS(AMGraph G,int v){
	cout << v;
	visited[v] = true;
	for (int w = FirstAdjVex(G, v); w >= 0; w = NextAdjVex(G, v, w))
		//依次检查v的所有邻接点w,FirstAdjVex(G,v)表示v的第一个邻接点
		//NextAdjVex 表示 v相对于w的下一个邻接点 w>=0标识存在临界点
		if (!visited[w]) DFS(G, w);
} */ 
void DFS_AM(AMGraph G, int v) {

	std::cout << G.vexs[v]<<" ";
	visited[v] = true;
	for (int w = 0; w < G.vernum; w++) 
		if ((G.arcs[v][w] != false) and (!visited[w])) DFS_AM(G, w);
		
	
}
void BFS(AMGraph G,int v){
	std::cout<< G.vexs[v];
	
}
void test(AMGraph graph){
		for (int i=0;i<graph.arcnum;i++){ //test begin
		for(int j=0;j<graph.arcnum;j++){  printf("%d ",graph.arcs[i][j]);
		}
		printf("\n");
	 }
	 printf("       test");  //test end
}

int main() {
	AMGraph graph;
	CreateUDN(graph);

	DFS_AM(graph,0);
	return 0;
}
