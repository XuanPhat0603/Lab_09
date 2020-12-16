#include "AVLTree.h"
#include <fstream>
#include <iomanip>
int main()
{
	int arr[1000] = { 0 };
	fstream in1, in2;
	int x;
	AVLTree a, b;
	in1.open("data_avl.bin", ios::in | ios::binary);
	in2.open("data_avl_search.bin", ios::in | ios::binary);
	while (!in1.eof())
	{
		in1.read((char*)&x, sizeof(x));
		a.addKey(x);
		b.addKey(x);
	}
	a.LNR();
	cout << "\n\n";
	a.removeEven();
	a.LNR();
	cout << "\n\n";
	b.printMinMax();
	cout << "\n\n";
	while (!in2.eof())
	{
		in2.read((char*)&x, sizeof(x));
		arr[x]++;
	}
	for (int i = 0; i < 1000; i++)
		if (arr[i] != 0)
			cout << "\nSearch cost : " << setw(3) << i << " => " << setw(3) << b.countFind(i) * arr[i];
	cout << "\n\n";
	return 0;
}