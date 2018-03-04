#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define N 10
#define M (2*N-1) 
typedef struct 
{
	unsigned int weight;
	unsigned int parent,lchild,rchild;
}HTNode,*HuffmanTree;
typedef struct
{
	char date;
	int weight;
	char Code[N];
}Zifu;
void Chushihua(Zifu Z[],int *n)
{
	int i;
	printf("������������ַ��ĸ��� n=");
	scanf("%d",&(*n));
	printf("��������Ҫ������ַ���\n");
	getchar();
	for(i=1;i<=*n;i++)
	{
		scanf("%c,",&Z[i].date);
	}
	printf("������ÿ���ַ���Ȩ�أ�\n");
	for(i=1;i<=*n;i++)
	{
		scanf("%d",&Z[i].weight);
	}
	getchar();	
}
void select(HTNode hc[],int k,int *s1,int *s2)
{
	int i ;
	*s1=i;
	for(i=1; i<=k; ++i)
	{
		if(hc[i].parent==0 && hc[i].weight<hc[*s1].weight)
		{
			*s1 = i;	
		}
	}
	for(i=1; i<=k; ++i)
	{
		if(hc[i].parent==0 && i!=*s1)
		break;
	}
	*s2 = i;
	for(i=1; i<=k; ++i)
	{
		if(hc[i].parent==0 && i!=*s1 && hc[i].weight<hc[*s2].weight)
		{
			*s2 = i;
		}
	}
}
void HuffmanCodeing (HTNode HT[],Zifu HC[],int n)
{
	int i,m,s1,s2,start,f,c;
	char cd[N];
	if(n<=1)
	{
		return;
	}
	else
	m=2*n-1;
	for(i=1;i<=n;i++)
	{
		if(i<=n)
		{
			HT[i].weight = HC[i].weight;
			HT[i].parent = HT[i].lchild = HT[i].rchild = 0;
		}
		else
		{
			HT[i].parent = 0;
			HT[i].parent = HT[i].lchild = HT[i].rchild = 0;	
		}
	}	
	for(i=n+1;i<=m;i++)
	{
		select(HT,i-1,&s1,&s2);
		HT[s1].parent=i;
		HT[s2].parent=i;
		HT[i].lchild=s1;
		HT[i].rchild=s2;
		HT[i].weight=HT[s1].weight + HT[s2].weight;	
	}
	cd[n-1]='\0';
	for(i=1;i<=n;i++)
	{
		start=n-1;
		for(c=i,f=HT[i].parent;f!=0;c=f,f=HT[f].parent)
		{
			if(HT[f].lchild==c)
			{
				cd[--start]='0';	
			}
			else
			{
				cd[--start]='1';
			} 
		}
		strcpy(HC[i].Code,&cd[start]);
	}
}
main()
{
	int a,b=1;
	for(a=1;a<=b;a++)
	{
		int i,n,t;
		HTNode ht[M+1];
		Zifu hc[N+1];
		Chushihua(hc,&n);
		HuffmanCodeing(ht,hc,n);
		printf("�շ�������Ϊ��\n");
		for(i=1;i<=n;i++)
		{ 
			printf("%c(%s)\n",hc[i].date,hc[i].Code);  
		}
		printf("\n");
		printf("��ѡ���Ƿ�������иó���\n\n");
		printf("���롮1���������иó��򣬷���������������\n\n");
		scanf("%d",&t);
		if(t==1)
		{
			b++;
			printf("���س���ȷ���������иó���\n\n"); 
		}
		else
		printf("�������н�����˫���س����رոó���\n");
		system("pause\n");
	}	
}
