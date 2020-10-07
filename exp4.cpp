#include <iostream>
typedef struct Stack {
	char data;
	struct Stack * next;
}Stack;
Stack * S;

Stack * Init() {
	S = NULL;
	return S;

}
Stack * Push( char c) {
	Stack * p = new Stack;
	p->data = c; 
	p->next = S;
	return p;// New stack become the p and return it

}
bool Empty() {
	if (S == NULL) return true;
	else return false;
}
char Pop() {
	Stack * p = new Stack;
	if (Empty()) {
		std::cout << "Stack is empty";
		return 0;

	}
	else {
		char x = S->data;
		p = S;
		S = S->next;
		delete p; // 释放栈空间
		return x;
	}
}
char 
