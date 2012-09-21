#include <stdio.h>
#include <stdlib.h>
#include <math.h>

typedef struct BSTreeNode
{
	int m_nValue;
	struct BSTreeNode *m_pLeft;
	struct BSTreeNode *m_pRight;
}BSTreeNode;

BSTreeNode * Func(BSTreeNode *p)
{
	if(p==NULL)return NULL;
	p->m_pLeft=Func(p->m_pLeft->m_pRight);
//	printf("%d=", p->m_nValue);
	p->m_pRight=Func(p->m_pRight->m_pLeft);
	return p->m_nValue>p->m_pLeft->Value?p:p->m_pRight;
}

void print(BSTreeNode *p)
{
if(p==NULL)return;
print(p->m_pLeft);
printf("%d=", p->m_nValue);
print(p->m_pRight);
}

int main()
{
	BSTreeNode head, *pl, *pr;
	head.m_nValue=10;
	pl = (BSTreeNode *)malloc(sizeof(BSTreeNode));
	pr = (BSTreeNode *)malloc(sizeof(BSTreeNode));
	pl->m_nValue=6;pr->m_nValue=14;
	head.m_pLeft=pl, head.m_pRight=pr;
	pl = (BSTreeNode *)malloc(sizeof(BSTreeNode));
        pr = (BSTreeNode *)malloc(sizeof(BSTreeNode));
        pl->m_nValue=4;pr->m_nValue=8;
        head.m_pLeft->m_pLeft=pl, head.m_pLeft->m_pRight=pr;
	pl = (BSTreeNode *)malloc(sizeof(BSTreeNode));
        pr = (BSTreeNode *)malloc(sizeof(BSTreeNode));
        pl->m_nValue=12;pr->m_nValue=16;
        head.m_pRight->m_pLeft=pl, head.m_pRight->m_pRight=pr;
	pl->m_pLeft=NULL;pl->m_pRight=NULL;
	print(&head);
	head=*Func(&head);
	printf("\n%d, %d", head.m_nValue, head.m_pLeft->m_nValue);
	printf("\n");
	return 0;
}
