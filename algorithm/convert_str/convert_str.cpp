#include <stdio.h>
#include <string.h>
#include <stdlib.h>

char *convert(char *src)
{
	char c;
	int i = 0;
	int j = strlen(src) - 1;

	for(; i < j; i++, j--)
	{
		c = src[i];
		src[i] = src[j];
		src[j] = c;
	}
	return src;

}

void convert_str(const char *src, char *dst)
{
	char *tmp = (char *)malloc(strlen(src) + 1);
	strcpy(tmp, src);
	char *q = tmp;
	
	while(*tmp)
	{
		if(*tmp == ' ')
		{
			*tmp = 0;
			tmp ++;
			strcat(dst,convert(q));
			strcat(dst," ");
			q = tmp;
		}
		tmp ++;
	}
	strcat(dst, convert(q));

	return ;
}

int main(void)
{
	char str[] = "hello world welcome!";
	//char *str_ret = (char *)malloc(strlen(str) + 1);
	char *str_ret = (char *)malloc(1);
	*str_ret = 0;

	convert_str(str,str_ret);
	printf("%s\n",str_ret);

	return 0;
}
