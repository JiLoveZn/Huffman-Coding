#include<stdio.h>
#include<stdlib.h>
#include<string.h>
typedef struct 
{
	unsigned int weight;
	unsigned int parent,lchild,rchild;
	char date;
}HTNode,*HuffmanTree;
typedef char **HuffmanCode;
void select(HTNode hc[],int k,int *s1,int *s2)
{
	int i ;
	for(i=1;i<=k && hc[i].parent!=0;i++)
	{
	;
	;	
	}
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
void HuffmanCodeing (HuffmanTree &HT,HuffmanCode &HC,int n)
{
	int i,m,s1,s2,start,f,c;
	char *cd;
	if(n<=1)
	{
		return;
	}
	else
	m=2*n-1;
	HT=(HuffmanTree)malloc((m+1)*sizeof(HTNode));
	printf("��������Ҫ������ַ���\n");
	getchar();
	for(i=1;i<=n;++i)
	{
		scanf("%c",&(HT->date));	
	}
	printf("������ÿ���ַ���Ȩ�أ�\n");
	for(i=1;i<=n;++i)
	{
		scanf("%d",&(HT[i].weight));
		HT[i].parent=0;
		HT[i].lchild=0;
		HT[i].rchild=0;
	}
	for(;i<=m;++i)
	{
		HT[i].weight=0;
		HT[i].parent=0;
		HT[i].lchild=0;
		HT[i].rchild=0;
	}
	for(i=n+1;i<=m;++i)
	{
		select(HT,i-1,&s1,&s2);
		HT[s1].parent=i;
		HT[s2].parent=i;
		HT[i].lchild=s1;
		HT[i].rchild=s2;
		HT[i].weight=HT[s1].weight + HT[s2].weight;	
	}
	HC=(HuffmanCode)malloc((n+1)*sizeof(char *));
	cd=(char *)malloc(n*sizeof(char));
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
		HC[i]=(char*)malloc((n-start)*sizeof(char));
		strcpy(HC[i],&cd[start]);
	}
	free(cd);
}
main()
{
	int a,b=1;
	for(a=1;a<=b;a++)
	{ 
		int i,n,t;
		HuffmanTree HT;
		HuffmanCode HC;
		printf("������������ַ��ĸ��� n=");
		scanf("%d",&n); 
		HuffmanCodeing(HT,HC,n);
		printf("�շ�������Ϊ��\n");
		for(i=1;i<=n;i++)
		{
			printf("(%s)\n",HC[i]); 
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
