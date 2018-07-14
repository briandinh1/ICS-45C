//// =========================================================
//// Brian Dinh
//// dinhb1@uci.edu
//// # 34546266
//// =========================================================
//
//#include <iostream>
//#include <fstream>
//#include "Coins.h"
//
//using namespace std;
//
//const int CENTS_PER_QUARTER = 25, CENTS_PER_DIME = 10, CENTS_PER_NICKEL = 5;
//
//Coins::Coins() : quarters(0), dimes(0), nickels(0), pennies(0), totalAmount(0){}
//
//Coins::Coins(int q, int d, int n, int p) :
//quarters(q), dimes(d), nickels(n), pennies(p),
//totalAmount(getTotalAmount()) {}
//
//void Coins::depositChange(Coins c)
//{
//	quarters += c.quarters;
//	dimes += c.dimes;
//	nickels += c.nickels;
//	pennies += c.pennies;
//	totalAmount += c.totalAmount;
//}
//
//bool Coins::hasSufficientAmount(int amount)
//{
//	return totalAmount >= amount;
//}
//
//Coins Coins::extractChange(int amount)
//{
//	if (hasSufficientAmount(amount))
//	{
//		// if exact amount is extracted 
//		if (totalAmount == amount)
//		{
//			Coins extractAll = *this;
//			*this = Coins();
//			return extractAll;
//		}
//
//		int q, d, n, p;
//		calculateChange(q, d, n, p, amount);
//
//		// if not enough specific coins to provide change
//		if (pennies < 0)
//		{
//			cout << "Not enough coins. Cannot provide change" << endl;
//			quarters += q;
//			dimes += d;
//			nickels += n;
//			pennies += p;
//
//			return Coins();
//		}
//
//		totalAmount -= amount;
//
//		return Coins(q, d, n, p);
//	}
//
//	// if insufficent amount 
//	cout << "Insufficient amount. Cannot extract change" << endl;
//	return Coins();
//}
//
//void Coins::calculateChange(int & q, int & d, int & n, int & p, int amount)
//{
//	q = amount / CENTS_PER_QUARTER;
//	if (q > quarters)
//	{
//		q = quarters;
//		amount -= q*CENTS_PER_QUARTER;
//	}
//	else amount %= CENTS_PER_QUARTER;
//
//	d = amount / CENTS_PER_DIME;
//	if (d > dimes)
//	{
//		d = dimes;
//		amount -= d*CENTS_PER_DIME;
//	}
//	else amount %= CENTS_PER_DIME;
//
//	n = amount / CENTS_PER_NICKEL;
//	if (n > nickels)
//	{
//		n = nickels;
//		p = amount - n*CENTS_PER_NICKEL;
//	}
//	else p = amount % CENTS_PER_NICKEL;
//
//	quarters -= q;
//	dimes -= d;
//	nickels -= n;
//	pennies -= p;
//}
//
//int Coins::getTotalAmount()
//{
//	return quarters * CENTS_PER_QUARTER
//		+ dimes * CENTS_PER_DIME
//		+ nickels * CENTS_PER_NICKEL
//		+ pennies;
//}
//
//void Coins::print(ostream & out)
//{
//	out << totalAmount << " cents, composed of: " << endl
//		<< quarters << " quarters, " << dimes << " dimes, "
//		<< nickels << " nickels, and " << pennies << " pennies" << endl;
//}
//
//ostream & operator << (ostream & out, Coins & c)
//{
//	c.print(out);
//	return out;
//}