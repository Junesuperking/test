#include<iostream>
#include<stdio.h>

void maxchildarr(int *arr, int l, int r)
{
	int result_arr_begin_index = 0;
	int result_arr_end_index = 0;
	int temp_sum = 0;
	int result_arr_sum = 0;
	int new_begin_index = 0;
	int i = l;

	for(; i <= r; i ++)
	{
		temp_sum += arr[i];
		if (temp_sum < 0)
		{
			new_begin_index = i + 1;
			temp_sum = 0;
		}
		else if (temp_sum > result_arr_sum)
		{
			result_arr_sum = temp_sum;
			result_arr_begin_index = new_begin_index;
			result_arr_end_index = i;
		}
	}
	printf("%d,%d,%d\n",result_arr_sum,result_arr_begin_index,result_arr_end_index);
}


int main(void)
{
	//int testarr[] = {10,-1,2,-19,2,3,4,5,7,-9};
	int testarr[] = {0,0,0,0,-9};

	maxchildarr(testarr,0,4);

	return 0;
}
