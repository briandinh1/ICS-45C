// =========================================================
// Brian Dinh
// dinhb1@uci.edu
// # 34546266
// ICS 45C HW_2
// =========================================================

#include <iostream>
#include <fstream>

using namespace std;

const int CENTS_PER_QUARTER = 25, CENTS_PER_DIME = 10, CENTS_PER_NICKEL = 5;

class Coins
{
public:
	Coins() : quarters(0), dimes(0), nickels(0), pennies(0), totalAmount(0){}

	Coins(int q, int d, int n, int p) :
		quarters(q), dimes(d), nickels(n), pennies(p),
		totalAmount(getTotalAmount()) {}

	void depositChange(Coins c)
	{
		quarters += c.quarters;
		dimes += c.dimes;
		nickels += c.nickels;
		pennies += c.pennies;
		totalAmount += c.totalAmount;
	}

	bool hasSufficientAmount(int amount)
	{
		return totalAmount >= amount;
	}

	Coins extractChange(int amount)
	{
		if (hasSufficientAmount(amount))
		{
			// if exact amount is extracted 
			if (totalAmount == amount)
			{
				Coins extractAll = *this;
				*this = Coins();
				return extractAll;
			}

			// otherwise calculate the coins needed for extraction
			return calculateChange(amount);
		}

		// if insufficent amount 
		cout << "Insufficient amount" << endl;
		return Coins();
	}


	void print(ostream & out)
	{
		out << totalAmount << " cents, composed of: " << endl
			<< quarters << " quarters, " << dimes << " dimes, "
			<< nickels << " nickels, and " << pennies << " pennies" << endl;
	}

	Coins calculateChange(int amount)
	{
		int q, d, n, p;

		q = amount / CENTS_PER_QUARTER;
		if (q > quarters)
		{
			q = quarters;
			amount -= q*CENTS_PER_QUARTER;
		}
		else amount %= CENTS_PER_QUARTER;

		d = amount / CENTS_PER_DIME;
		if (d > dimes)
		{
			d = dimes;
			amount -= d*CENTS_PER_DIME;
		}
		else amount %= CENTS_PER_DIME;

		n = amount / CENTS_PER_NICKEL;
		if (n > nickels)
		{
			n = nickels;
			p = amount - n*CENTS_PER_NICKEL;
		}
		else p = amount % CENTS_PER_NICKEL;

		// to catch any coin combination errors
		// ex: user has 1 quarter but wants to extract an amount < 25 cents
		if (pennies - p < 0)
		{
			cout << "Not enough coins. Cannot provide change" << endl;
			return Coins();
		}

		quarters -= q;
		dimes -= d;
		nickels -= n;
		pennies -= p;
		totalAmount = getTotalAmount();

		return Coins(q, d, n, p);
	}

	int getTotalAmount()
	{
		return quarters * CENTS_PER_QUARTER
			+ dimes * CENTS_PER_DIME
			+ nickels * CENTS_PER_NICKEL
			+ pennies;
	}

private:
	int quarters, dimes, nickels, pennies;
	int totalAmount;
};

ostream & operator << (ostream & out, Coins & c)
{
	c.print(out);
	return out;
}