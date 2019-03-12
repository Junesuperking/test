#include <iostream>

using namespace std;

int search(int *arr, int l, int r, int num)
{
	int mid = 0;
	while(l <= r)
	{
		mid = (l + r)/2;

		if (arr[l] <= arr[mid])
		{
			if (num == arr[mid])
			{
				return mid;
			}
			if ( num < arr[mid] && num > arr[l])
			{
				l = mid + 1;
			}
			else
			{
				r =  mid - 1;
			}
		}
		else
		{
			if (num == arr[mid])
			{
				return mid;
			}
			if (arr[mid] < num && num < arr[r])
			{
				r = mid - 1;	
			}
			else
			{
				l = mid + 1;
			}
		}
	}
	return -1;
}

int main(void)
{
	int arr[]={5,6,7,8,9,1,2,3,4};
	int num = 9;	
	int idx = search(arr, 0, 8,num);
	cout << idx << ' ' << arr[idx] << endl;


	return 0;
}
