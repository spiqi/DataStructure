#include<iostream>
#define ERROR 114514
#define MAX 19892019
const int bignum= 1145;
typedef struct BitNode {
	char data;
	struct BitNode *lchild, *rchild;
}BitNode ; //用BitNode* 代替BiTree
typedef struct StackNode
{
	BitNode * data[bignum];
	int top;
	
}StackNode;
int InitStack(StackNode  &S) {
	S.top = 0;
	return 0;
}
int Push(StackNode S, BitNode * e) {
	StackNode *p = new StackNode;
	S.data[++(S.top)]=e;

	return 0;
}
int Pop(StackNode S, BitNode * &e) {
	e = S.data[(S.top)--];
	return 0;
}
bool StackEmpty(StackNode S) {
	if (S.top==0) return true;
	return false;
}

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

void InOrderTraver2(BitNode *T) {
	//中序遍历二叉树的Fei递归算法
	StackNode  St;
	InitStack(St);
	BitNode *p = T;
	BitNode * q = new BitNode;
	while (p || !StackEmpty(St)) {
		if (p) {
			Push(St, p);
			p = p->lchild;
		}
		else {
			Pop(St, q);
			std::cout << q->data;
			p = q->rchild;

		}
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
	if (T) {
		std::cout << T->data;
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

	int main() {while(1){		BitNode * tree;
		CreateBiTree(tree);
		std::cout << std::endl << std::endl << "PreOrder Is:" << std::endl;
		PreOrderTraverse(tree);
		std::cout << std::endl << std::endl << "InOrder Is :" << std::endl;
		InOrderTraverse(tree);
		std::cout << std::endl << "PostOrder Is:" << std::endl;
		PostOrderTraverse(tree);
		std::cout << std::endl << std::endl << "Depth Is:" << Depth(tree) << std::endl << std::endl;
		std::cout << std::endl << std::endl << "test for the InOrderTraverse";
		InOrderTraver2(tree);
		std::cout << std::endl << std::endl;
}

		return 0;

	} 
