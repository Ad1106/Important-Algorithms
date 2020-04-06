#include<stdio.h>
int main()
{
	int n,i,j,k,temp,count;
	printf("Enter the value of n");
	scanf("%d",&n);
	int arr[n];
	printf("Enter the binary code:");
	for(i=0;i<n;i++)
	scanf("%d",&arr[i]);
	for(i=0;i<n;i++)
	{
	    count=0;
		if(arr[i]==0)
		{
			for(j=i+1;j<i+6;j++)
			{
			    if(arr[j]==1)
				{
				    count++;
				}
				    if(count==5)
				    {
					   for(k=n;k>=i+7;k--)
					   {
						   arr[k]=arr[k-1];
					   }
					   arr[i+6]=0;
					   n++;
				    }	
				
			}
		}
	}
	printf("After Stuffing :\n");
	for(i=0;i<n;i++)
	printf("%d ",arr[i]);
	
	for(i=0;i<n;i++)
	{
	    count=0;
		if(arr[i]==0)
		{
			for(j=i+1;j<i+6;j++)
			{
			    if(arr[j]==1)
				{
				    count++;
				}
				    if(count==5)
				    {
					   for(k=n;k>=i+7;k--)
					   {
						   arr[k-1]=arr[k];
					   }
					   n--;
				    }	
				
			}
		}
	}
	printf("\nAfter de-tuffing :\n");
	for(i=0;i<n;i++)
	printf("%d ",arr[i]);
	return 0;
}
