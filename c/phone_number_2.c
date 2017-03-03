#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int is_alph_num(int key)
{
	if( (key >= '0' && key <= '9') 
		||(key >= 'A' && key <= 'Y') )
		return 1;

	return 0;
}

char map_num(char i)
{
	char key ;
	switch (i)
	{
		case 'A': case 'B': case'C':key = '2';break;
		case 'D': case 'E': case'F':key = '3';break;
		case 'G': case 'H': case'I':key = '4';break;
		case 'J': case 'K': case'L':key = '5';break;
		case 'M': case 'N': case'O':key = '6';break;
		case 'P': case 'R': case'S':key = '7';break;
		case 'T': case 'U': case'V':key = '8';break;
		case 'W': case 'X': case'Y':key = '9';break;
		default: key = i;
	}
	return key;
}

void make_format(char *array,int length)
{
	int i,j = 0;;
	for(i = 0;i <= length; i++)
	{
		if(is_alph_num(array[i]))
		{
			array[j++] = map_num(array[i]);
		}
	}

	for(j = 7;j > 3; j--)
	{
		array[j] = array[j-1];
	}
	array[3] = '-';
}

void dprint(char(*p)[8] ,int i,int counts)
{
	int k;
	for(k = 0;k < 8; k++)
		printf("%c",p[i][k]);
	printf(" %d\n",counts);
}

int main(int argc,char *argv[])
{
	int num;
	int i,j,k;

	scanf("%d",&num);

	char temp[80] = {0};
	char sorted[100000][8]; 
 
	int counts = 1;

	for(j = 0;j < num;j++)
	{
		scanf("%s",temp);
		make_format(temp,15);
		strncpy(sorted[j],temp,8);
	}
	
	qsort(sorted, num, 8, strncmp);
	int tag =0;
	for(i = 0;i < num; i++)
	{
		
		if(!strncmp(sorted[i],sorted[i+1],8))
		{
			counts++; tag = 1;
		}else{
			if(counts > 1)
			{
				 dprint(sorted, i,counts);
			}
			counts = 1;
		}
	}
	if(!tag) 
        printf("No duplicates.\n");

	return 0;
}