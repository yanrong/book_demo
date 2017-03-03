#include<stdio.h>
#include<string.h>

int next[100];
void get_next(char s[],int next[])
{
	int i=1,j=0;
	next[1]=0;
	while(i<strlen(s))
		if(j==0||s[i]==s[j])
		{
			++i;++j;
			next[i]=j;
		}
		else j=next[j];
}

int index_KMP(char p[],char m[],int pos)
{
	int i=pos,j=1;
	while(i<=strlen(p) && j<=strlen(m)){
		if(j==0 || p[i-1]==m[j-1])
		{++i,++j;}
		else j=next[j];
	}
	if(j>strlen(m)) return i-strlen(m);
	else return -1;
}


int main()
{
    char p[100],m[100];
    printf("pattern string：\n");
    scanf("%s",p);
    printf("match string：\n");
    scanf("%s",m);
    get_next(m,next);
    printf("the next value is\n");
    for(int i=1;i<=strlen(m);i++)
    	printf("%d ",next[i]);
    printf("\n");
    printf("%d\n",index_KMP(p,m,1));
    return 0;
}
