#define ERROR 114514
#pragma warning(disable:4996) 
#include <cstdio>
typedef struct LNode {
	int data;
	struct LNode  * next;

} LNode, *LinkList;

int InitList(LinkList &L) {
	L = new LNode;
	L->next = NULL;
	return 0;

}

/*int ReadList(int n, LinkList &L) {
LNode * p;
p = L->next;

for (int i = 1;i <= n;i++) {
scanf("%d", p->data);
p = p->next;
}
return 0;
} */

int ListInsert(LinkList &L, int i, int e)  // 在带头结点的单链表L 中的 第 i个 位置插入 值为 e 的新节点
{
	LinkList p = L;
	int j = 0;
	while (p && (j < i - 1)) {
		p = p->next;
		++j;

	}
	if (!p || j > i - 1) return ERROR;
	LinkList s = new LNode;
	s->data = e;
	s->next = p->next;
	p->next = s;
	return 0;


}

int GetElem(LinkList L, int i) {
	LinkList p = L->next;
	int j = 1;
	while (p&& j < 1) {
		p = p->next;
		++j;
	}
	if (!p || j > i)return ERROR;
	return p->data;




}
int main() {
	LinkList List;
	InitList(List);
	int length;// the length of the list t o read;
	printf("Please input the length of the list\n");

	scanf("%d", &length);
	printf("input the content of the list\n");
	int temp;

	for (int i = 1;i <= length;i++) {
		scanf("%d", &temp);
		ListInsert(List, i, temp);

	}
	//ReadList(length, List);
	printf("input the position you wanna check\n");
	scanf("%d", &temp);// 读入temp 位置
	
	for (int i = 1;i <= length;i++) {
		printf("%d", GetElem(List, i));
	}
	scanf("%d");

}
