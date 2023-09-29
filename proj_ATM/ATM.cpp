#include "ATM.h"
#include <iostream>
#include <string>
using namespace std;

ATM::ATM(const char* u_id, int u_arrSize, int* u_banknotes)
{
	id = u_id;
	arrSize = u_arrSize;
	arrBanknotes = new int[arrSize];
	for (int i = 0; i < arrSize; i++)
	{
		arrBanknotes[i] = u_banknotes[i];
	}
}

ATM::ATM(const ATM& point)
{
	id = point.id;
	arrSize = point.arrSize;
	arrBanknotes = new int[arrSize];
	for (int i = 0; i < arrSize; i++)
	{
		arrBanknotes[i] = point.arrBanknotes[i];
	}
}
ATM::~ATM()
{
	delete[] arrBanknotes;
}
string ATM::ToString()
{
	int sum = 0;
	for (int i = 0; i < arrSize; i++)
	{
		sum += arrBanknotes[i];
	}
	return string(to_string(sum));
}
void ATM::AddSum()
{
	int u_Amount;

	while (true)
	{
		cout << "\nEnter amount of banknotes to add: ";
		cin >> u_Amount;
		if (u_Amount <= 0)
		{
			cout << "Invalid amount. Try again." << endl;
		}
		else
		{
			break;
		}
	}
	int* newArr = new int[arrSize + u_Amount];
	for (int i = 0; i < arrSize + u_Amount; i++)
	{
		if (i < arrSize)
		{
			newArr[i] = arrBanknotes[i];
		}
		else
		{
			while (true)
			{
				cout << "Enter value: ";
				cin >> newArr[i];

				if (newArr[i] %10!=0|| newArr[i] == 0)
				{
					cout << "Value should a round number. Try again." << endl;
				}
				else
				{
					break;
				}
			}
		}
	}

	arrSize += u_Amount;
	delete[] arrBanknotes;
	arrBanknotes = newArr;
}
void ATM::WithdrawalSum()
{
	int u_Withdr;
	while (true)
	{
		cout << "\nEnter sum to withdraw: ";
		cin >> u_Withdr;

		if (u_Withdr % 10 != 0)
		{
			cout << "Value should a round number. Try again." << endl;
		}
		else if(u_Withdr < minWithdraw || u_Withdr > maxWithdraw)
		{
			cout << "Invalid amount. Try again." << endl;
		}
		else
		{
			break;
		}
	}
	SortArr();

	int newSize = arrSize;

	for (int i = 0; i < arrSize; i++) 
	{
		if ((u_Withdr - arrBanknotes[i]) >= 0) 
		{
			u_Withdr -= arrBanknotes[i];
			arrBanknotes[i] = 0;
			newSize--;

			if (u_Withdr == 0) 
			{
				break;
			}
		}
	}
	int* tempArr = new int[newSize];

	int c = 0;
	for (int i = 0; i < arrSize; i++) 
	{
		if (arrBanknotes[i] != 0) 
		{
			tempArr[c++] = arrBanknotes[i];
		}
	}

	delete[] arrBanknotes;
	arrBanknotes = tempArr;
	arrSize = newSize;
}
void ATM::Print()
{
	cout << "\n\tATM info: " << endl;
	cout << "ID bankomat: " << id << endl;
	cout << "Total sum available: " << ToString() << endl;
	cout << "Minimal withdrawal sum: " << minWithdraw << endl;
	cout << "Maximal withdrawals sum: " << maxWithdraw << endl;

	cout << "\n\tAvailable banknotes:" << endl;
	SortArr();
	for (int i = 0; i < arrSize; i++)
	{
		if (i != 0 && i % 5 == 0)
		{
			cout << endl;
		}
		cout << arrBanknotes[i] << "\t";
	}
	cout << endl;
}
void ATM::SortArr()
{
	for (int i = 0; i < arrSize - 1; i++) 
	{
		for (int j = 0; j < arrSize - i - 1; j++) 
		{
			if (arrBanknotes[j] < arrBanknotes[j + 1]) 
			{
				int temp = arrBanknotes[j];
				arrBanknotes[j] = arrBanknotes[j + 1];
				arrBanknotes[j + 1] = temp;
			}
		}
	}
}