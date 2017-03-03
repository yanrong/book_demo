#include <stdio.h>
#include <stdlib.h>

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
	int i,j=0;
	for(i = 0;i <= length; )
	{
		if(j==3)
		{
			array[j++] = '-';
			continue;
		}
		if(is_alph_num(array[i]))
		{
			array[j++] = map_num(array[i]);
		}
		i++;
	}
}

int get_cp(char *dest,char *src,int length)
{
	int i;
	for(i = 0;i < length;i++)
		dest[i] = src[i];
}


int main(int argc,char *argv[])
{
	int num;
	int i,j,k;
	scanf("%d",&num);
	char temp[16] = {0};
	char aline[8] = {0};
	char sorted[num][8]; 

	int result[num]={0};
	int counts = 0;

	for(j = 0;j<num;j++)
	{
		gets(temp);
		make_format(temp,15);
		get_cp(aline,temp,8);
		/*
		for (k = 0; k < 8; ++k)
		{
			printf("%c",aline[k]);
		}
		printf("\n");
		//puts(aline);
		*/
		for(i = 0;i <= counts;i++)
		{

		}
	}
	return 0;
}