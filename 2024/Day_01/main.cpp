// meu_programa.cpp
#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <cmath>

using namespace std;

int main()
{
	vector<int> list1;
	vector<int> list2;
	int num1, num2;
	int sum = 0;
	int cont = 0;

	while (cin >> num1 >> num2)
	{
		list1.push_back(num1);
		list2.push_back(num2);
	}

	sort(list1.begin(), list1.end());
	sort(list2.begin(), list2.end());

	for (int i = 0; i < list1.size(); i++)
	{
		cont = count(list2.begin(), list2.end(), list1[i]);
		sum += abs(list1[i] - list2[i]);
#ifdef DEBUG
		cout << abs(list1[i] - list2[i]) << " ";
#endif
	}

	cout << "\n--- Resultado Final ---\n";

	cout << sum << endl;

#ifdef DEBUG
	cout << "Lista 1 (" << list1.size() << " elementos): ";
	for (int elemento : list1)
	{
		cout << elemento << " ";
	}
	cout << endl;

	cout << "Lista 2 (" << list2.size() << " elementos): ";
	for (int elemento : list2)
	{
		cout << elemento << " ";
	}
	cout << endl;
#endif

	return 0;
}