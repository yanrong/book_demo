#include <stdio.h>
main()
{
	float fahr, celsius;
	int lower,upper,step;
	lower=0;
	upper=300;
	step=25;
	
	celsius=lower;
	while(celsius<=upper)
	{
		fahr=(9.0/5.0)*celsius+32;//=(5.0/9.0)*(fahr-32);
		printf("%6.1f-->%3.2f\n",celsius,fahr);
		celsius+=step;
	}
}
