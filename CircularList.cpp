//ѭ������
#include <stdio.h>
#include <malloc.h>
#include <stdlib.h>

#define TRUE 1
#define FALSE 0
#define OK 1
#define ERROR 0
#define INFEASTABLE -1
#define OVERFLOW -2

typedef struct LNODE{
	int data;
	struct LNODE*next;
}LNode,*Linklist;

void PrintCir(Linklist L){
	Linklist p;
	printf("������ѭ��������Ϊ��\n");
	p = L->next;
	while (p!=L){
		printf("%d ", p->data);
		p = p->next;
	}
	printf("\n");
}

void CreatCir(Linklist &L){
	Linklist p, nail;
	L = (LNode*)malloc(sizeof(LNode));
	L->next = L;
	nail = L;
	p = (LNode*)malloc(sizeof(LNode));
	printf("������ѭ������Ԫ��,��Ctrl+Z������\n");
	while ((scanf("%d", &(p->data))) != EOF){
		p->next = L;
		nail->next = p;
		nail = p;
		p = (LNode*)malloc(sizeof(LNode));
	}
}

void Mergelist(Linklist &L1, Linklist &L2){
	CreatCir(L2);
	Linklist pA,pB,rear;
	pA = L1->next;
	pB = L2->next;
	while (pA->next != L1)
		pA = pA->next;
	while (pB->next != L2)
		pB = pB->next;
	rear = pA->next;
	pA->next = pB->next->next;
	pB->next = rear;
	free(L2);
}

int main(){
	Linklist list,listSec;
	CreatCir(list);
	PrintCir(list);
	Mergelist(list, listSec);
	PrintCir(list);
	system("pause");
	return 0;
}