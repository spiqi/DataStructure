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
void PostOrderTraverse(BitNode* T) { //后序遍历的递归算法
	if (T) {
		
		PostOrderTraverse(T->lchild);
		PostOrderTraverse(T->rchild);
		std::cout << T->data;
	}
}
int main() {
	BitNode * tree;
	CreateBiTree(tree);
	std::cout << std::endl << "PreOrder Is:" << std::endl<<std::endl;
	PreOrderTraverse(tree);
	std::cout <<std::endl<< "InOrder Is :" << std::endl << std::endl;
	InOrderTraverse(tree);
	std::cout << std::endl << "PostOrder Is:" << std::endl << std::endl;
	PostOrderTraverse(tree);
	return 0;

}
