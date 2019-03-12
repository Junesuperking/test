#include <iostream>
#include <time.h>
#include <stdlib.h>

using namespace std;

#define N 30

void init_arr(int *arr, int len)
{
	int i = 0;
	srand(time(NULL));
	for(i = 0; i <= len - 1; i ++)
	{
		arr[i] = rand()%100 + 1;
	}
	return;
}

void print_arr(int *arr, int len)
{
	for(int i = 0; i <= len - 1; i ++)
	{
		cout << arr[i] << ' ';
	}
	cout << endl;
	return ;
}

int partition(int *arr, int l, int r)
{
	int tmp = arr[l];
	int i = l;
	while(l < r)
	{
		while(l < r && arr[r] > tmp)
		{
			r --;
		}
		if (l < r)
		{
			arr[l++] = arr[r];
		}
		while(l < r && arr[l] <= tmp)
		{
			l ++;
		}
		if (l < r)
		{
			arr[r--] = arr[l];
		}
	}
	arr[l] = tmp;
	return l;

}

void quick_sort(int *arr,int l, int r)
{
	int tmp = 0;
	if(l < r)	
	{
		tmp = partition(arr, l, r); 	
		quick_sort(arr,l, tmp-1);
		quick_sort(arr, tmp+1, r);
	}

	return;
}

void bubble_sort(int *arr,int l, int r)
{
	int i,j=0;
	int tmp = 0;
	for (i = l;i <= r; i++)
	{
		for(j = r; j>=i+1; j--)
		{
			if(arr[j] < arr[j-1])
			{
				tmp = arr[j - 1];
				arr[j - 1] = arr[j];
				arr[j] = tmp;
			}
		}
	}
}

void merge(int *arr, int l, int r, int mid,int *tmp)
{
	int i = l;
	int k = 0;
	int t = 0;
	int j = mid + 1;
	while(i <= mid &&j <= r)
	{
		if(arr[i] <= arr[j])
		{
			tmp[k++] = arr[i++];
		}
		else
		{
			tmp[k++] = arr[j++];
		}

	}
	while(i <= mid)
	{
		tmp[k++] = arr[i++];
	}
	while(j <= r)
	{
		tmp[k++] = arr[j++];
	}
	for (t = 0; t<k; t++)
	{
		arr[l+t] = tmp[t];
	}
}

void merge_sort(int *arr, int l, int r,int *tmp)
{
	if(l < r)
	{
		int mid = (l + r)/2;
		merge_sort(arr,l,mid,tmp);
		merge_sort(arr,mid + 1, r, tmp);
		merge(arr,l,r,mid,tmp);
	}
}


int main(void)
{
	int arr[N];
	int tmp[N];
	init_arr(arr,N);
	print_arr(arr,N);

	quick_sort(arr, 0, N-1);
	//bubble_sort(arr, 0, N-1);
//	merge_sort(arr,0,N-1,tmp);
	print_arr(arr,N);

	return 0;
}
