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
		sum += (cont*(list1[i]));
	}

	cout << endl;
	cout << "--- Resultado Final ---" << endl;
	cout << sum << endl;

	return 0;
}