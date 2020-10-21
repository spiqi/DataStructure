#include<iostream>
typedef struct BitNode {
	int data;
	struct BitNode *lchild, *rchild;
}BitNode, *tree;
void CreateBiTree(tree &T) {
	char ch;
	std::cin >> ch;
	if (ch == '#') T = NULL;
	else {
		T = new BitNode;
		T->data = ch;
		CreateBiTree(T->lchild);
		CreateBiTree(T->rchild);//先序遍历 genzuoy

	}
}
