#include <iostream>

using namespace std;


tree_node* sum(tree_node *root, int sum)
{
	int a;
	if (!root)
	{
		return NULL;
	}
	a = root->para + sum;
	cout << root->para << endl;
	if (!root->left)
		sum(root->leftk, a);
	if (!root->right)
		sum(root->right, a);
	else
		put(a);
}

int main(void)
{
	sum(root, 0);
	return 0;
}
