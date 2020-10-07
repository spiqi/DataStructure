#include<iostream>
using namespace std;

typedef struct Stac
{
	char  data;
	struct Stac *next;
}Stack, *Linkstack;
Linkstack Init_stack(Linkstack &S)
{
	S = NULL;
	return S;
}
Linkstack Push(Linkstack &S, char e)
{
	Linkstack p = new Stack;
	if (!p) exit(0);
	p->data = e;
	p->next = S;
	S = p;
	return S;
}
bool Stack_empty(Linkstack &S)
{
	if (S == NULL) return true;
	else return false;
}
char Pop(Linkstack &S)
{
	Linkstack p = new Stac;
	if (Stack_empty(S)) { cout << "Stack is empty";return 0; }
	else
	{
		int x = S->data;
		p = S;
		S = S->next;
		delete p;
		return x;
	}
}
char get_top(Linkstack &S)
{
	if (!Stack_empty(S))
		return S->data;
}

bool isMatch(Linkstack &S) {
	char ch;
	char c[100];
	int i = 1;
	cout << "输入表达式：";
	
	ch = getchar();
	while (ch != '\n') {
		c[i++] = ch;
		ch = getchar();
	}
for (int q=1;q<i;q++)
	{
		switch (c[q])
		{
		case '[':Push(S, c[q]);break;


		case ']':if (!Stack_empty(S) && get_top(S) == '[')
			Pop(S);
				 else
				 {
					 cout << "匹配失败！" << endl;
					 return false;
				 }
				 break;

		}
	}

	if (Stack_empty(S))
		cout << "匹配成功" << endl;
	else cout << "匹配失败！" << endl;
}
int  main()
{
	
	while (true) {
		Linkstack S;
		Init_stack(S);
		isMatch(S);
	}
	return 0;
}
