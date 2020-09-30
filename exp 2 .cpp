#include <cstdio>
typedef struct LNode{
	int data;
	struct LNode  * next;

} LNode, * LinkList;

int InitList(LinkList &L) {
	L = new LNode;
	L->next = Null;
	return 0;

}

int ReadList(int n, LinkList &L) {
	LNode * p;
	p = L->next;

	for (int i = 1;i <= n;i++) {
		scanf("%d",p->data );
		p = p->next;
	}
	return 0;
}

int main() {
	LinkList List;
	InitList(List);
	int length;// the length of the list t o read;
	printf("Please input the length of the list");

	scanf("%d", &length);
	printf("input the content of the list");
	ReadList(length, List);

}
