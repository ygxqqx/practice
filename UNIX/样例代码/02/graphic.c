#include <stdio.h>
void diamond(int r)
{
	int x,y;
	for(y=0;y<=2*r;y++)
	{
		for(x=0;x<=2*r;x++)
		{
			if(y==x+r  || y==x-r 
			|| y==-x+r || y==-x+3*r)
			{
				printf("*");
			}
			else
			{
				printf(" ");
			}
		}
		printf("\n");
	}
}
