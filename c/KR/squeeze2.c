#include <stdio.h>

void squeeze(char* ori,char* sub)
{
	int i,j,l;
	int instr;
	for(i=j=0;ori[i]!='\0';i++)
	{
		instr=0;
		for(l=0;sub[l]!='\0' && !instr;l++)
			if(ori[i]==sub[l])
				instr=1;
		if(!instr)
			ori[j++]=ori[i];
	}
	ori[j]='\0';
}

main()
{
	char s[]="asbsssdnnbssdsds";
	char t[]="sb";
	printf("%s-----%s",s,t);

	squeeze(s,t);
	printf("------>%s\n",s);
}
