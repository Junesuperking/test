#include <iostream>
#include <stdio.h>
#include <time.h>
#include <stdlib.h>

int arr_search(int *arr, int l, int r, int num)
{
	while (l <= r)
	{
		int mid = (l + r) / 2;
		if (arr[mid] >= arr[l])
		{
			if (arr[mid] == num)
			{
				return mid;
			}
			else if (arr[mid] > num && num >= arr[l])
			{
				r = mid - 1;
			}
			else
			{
				l = mid + 1;
			}
		}
		else
		{
			if (arr[mid] == num)
			{
				return mid;
			}
			else if (arr[mid] < num && num <= arr[r])
			{
				l = mid + 1;	
			}
			else
			{
				r = mid - 1;
			}
		}

	}
}


int main(void)
{
	srand(time(NULL));
	int arr[] = {5,6,7,8,9,1,2,3,4};
	int num = rand()%9 + 1;
	printf("%d\n",num);
	int index = 0;
	index = arr_search(arr,0,8,num);
	printf("%d\n",index);

	return 0;
}
