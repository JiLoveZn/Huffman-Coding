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
	printf("请输入需编码字符的个数 n=");
	scanf("%d",&(*n));
	printf("请输入需要编码的字符：\n");
	getchar();
	for(i=1;i<=*n;i++)
	{
		scanf("%c,",&Z[i].date);
	}
	printf("请输入每个字符的权重：\n");
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
		printf("赫夫曼编码为：\n");
		for(i=1;i<=n;i++)
		{ 
			printf("%c(%s)\n",hc[i].date,hc[i].Code);  
		}
		printf("\n");
		printf("请选择是否继续运行该程序\n\n");
		printf("输入‘1’继续运行该程序，否则结束程序的运行\n\n");
		scanf("%d",&t);
		if(t==1)
		{
			b++;
			printf("按回车键确定继续运行该程序\n\n"); 
		}
		else
		printf("程序运行结束，双击回车键关闭该程序\n");
		system("pause\n");
	}	
}
