#include<stdio.h>
int main()
{
	int n,arr[100],key,low,high,mid,i;
	printf("Enter the number of elements:");
	scanf("%d",&n);
	printf("Enter elements to array:");
	for(i=0;i<n;i++)
		scanf("%d",&arr[i]);
	printf("Enter the element to search:");
	scanf("%d",&key);
	low=0;
	high=n-1;
	mid=(low+high)/2;
	while(low<=high)
	{
		if(arr[mid] < key)
		low = mid + 1;
		else if (arr[mid] == key)
		{
			printf("%d found at location %d", key, mid+1);
			break;
		}
		else
		high = mid - 1;
		mid = (low + high)/2;
	}
	if(low > high)
	printf("Not found! %d isn't present in the list", key);
	return 0;
}
