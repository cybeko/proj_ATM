#include "ATM.h"
#include <iostream>
#include <string>
using namespace std;

int main()
{
	const int arrSize = 10;
	int arr[arrSize] = { 500, 50, 10, 100, 10, 100, 50, 200, 1000, 200 };

	ATM obj1("5844989393", arrSize, arr);
	obj1.Print();

	obj1.AddSum();
	obj1.Print();
;
	obj1.WithdrawalSum();
	obj1.Print();
}