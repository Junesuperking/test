#include <stdio.h>


int findlastequal(int *arr, int l, int r, int num)
{
	while(l <= r)
	{
		int mid = (l+r)/2;
		if (arr[mid] <= num)
		{
			l = mid + 1;
		}
		else
		{
			r = mid - 1;
		}
	}
	if (r >= 0 && arr[r] == num)
		return r;
	
	return -1;
}

int main(void)
{
	int arr[] = {1,2,3,4,5,6,6,6,7};
	int index = 0;
	int num = 6;
	index = findlastequal(arr,0,8,num);
	printf("%d\n",index);

	return 0;
}
