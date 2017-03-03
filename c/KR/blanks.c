#include <stdio.h>
main()
{
	long nb=0;
	int c;
	while((c=getchar())!=EOF)
	{
		if(c==' ')
		{
			++nb;
			if(nb<=1){	
				putchar(c);
				continue;
			}
		}
		else
		{
			nb=0;
			putchar(c);
		}
	}
}
