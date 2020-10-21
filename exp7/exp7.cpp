#include<iostream>
typedef struct BitNode {
	char data;
	struct BitNode *lchild, *rchild;
}BitNode; //用BitNode* 代替BiTree
void CreateBiTree(BitNode* &T) {
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
void InOrderTraverse(BitNode* T) { //中序遍历的递归算法
	if (T) {
		InOrderTraverse(T->lchild);
		std::cout << T->data;
		InOrderTraverse(T->rchild);
	}
}
void PreOrderTraverse(BitNode* T) { //xian序遍历的递归算法
	if (T) {std::cout << T->data;
		PreOrderTraverse(T->lchild);
		
		PreOrderTraverse(T->rchild);
	}
}
void PostOrderTraverse(BitNode* T) { //xian序遍历的递归算法
	if (T) {
		
		PostOrderTraverse(T->lchild);
		PostOrderTraverse(T->rchild);
		std::cout << T->data;
	}
}
int Depth(BitNode * T) {
	if (T == NULL) return 0; //空树深度归零
	else {
		int m = Depth(T->lchild);
		int n = Depth(T->rchild);
		if (m > n) return m + 1;
		else return n + 1;
	}
}
int main() {
	BitNode * tree;
	CreateBiTree(tree);
	std::cout << std::endl << std::endl << "PreOrder Is:" << std::endl;
	PreOrderTraverse(tree);
	std::cout << std::endl <<std::endl<< "InOrder Is :" << std::endl;
	InOrderTraverse(tree);
	std::cout << std::endl << "PostOrder Is:" << std::endl ;
	PostOrderTraverse(tree);
	std::cout << std::endl << std::endl << "Depth Is:" << std::endl << std::endl;
	return 0;

}
