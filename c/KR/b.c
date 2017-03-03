#include <stdio.h>
typedef enum boolean {false,true}Bool;
main()
{
	Bool isBlanks=false;
	int c;
	while((c=getchar())!=EOF)
	{
		if(c==' ')
		{
			if(!isBlanks){
				isBlanks=true;	
				putchar(c);
			}
		}
		else
		{
			isBlanks=false;
			putchar(c);
		}
	}
}
