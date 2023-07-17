#include<iostream>

int main()
{
	int n,m;
	int i,j;
	std::cout<<"Enter how many rows";
	std::cin>>n;
	std::cout<<"Enter how many columns";
	std::cin>>m;
	int arr[n][m];
	int left=0;
	int right=n-1;
	int top=0;
	int bottom=m-1;
	
	for(i=0;i<n;i++)
	{
		for(j=0;j<m;j++)
		{
			std::cin>>arr[i][j];
		}
	}
	
	while(top<=bottom && left<=right)
	{
		for(i=left;i<=right;i++)
		{
			std::cout<<arr[top][i]<<" ";
		}
		top++;
		for(j=top;j<=bottom;j++)
		{
			std::cout<<arr[i][right]<<" ";
		}
		right--;
		if(top<=bottom)
		{
			for(i=right;i>=left;i--)
			{
				std::cout<<arr[bottom][i]<<" ";
			}
			bottom--;
		}
		if(right>=left)
		{
			for(j=bottom;j>=top;j--)
			{
				std::cout<<arr[i][left]<<" ";
			}
			left++;
		}
		
	}
}
