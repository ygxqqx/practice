int printf(const char*,...);
int add(int * restrict a,int  *restrict b)
{
	return (*a)+(*b);
}
main()
{
	for(int i=0;i<100;i++)
	{
		printf("%d\n",i);
	}
}
