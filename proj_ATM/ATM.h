#pragma once
#include <string>
using namespace std;
class ATM
{
private:
	string id;

	int arrSize;
	int* arrBanknotes;

	const int minWithdraw = 10;
	const int maxWithdraw = 1000;

public:
	ATM() = default;
	ATM(const char* u_id, int u_arrSize, int* u_banknotes);
	ATM(const ATM& point);
	~ATM();

	void AddSum();
	void WithdrawalSum();

	void Print();
	void SortArr();

	string ToString();
};