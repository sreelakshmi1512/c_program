#include<stdio.h>
int main()
{
	int n,original,sum=0,r;
	printf("Enter the number:");
	scanf("%d",&n);
	original=n;
	while(original!=0)
	{
		r=original%10;
		sum=sum+(r*r*r);
		original/=10;
	}
	if(sum==n)
		printf("%d Amstrong number",n);
	else
		printf("%d Not an amstrong number",n);
	return 0;
}

	
