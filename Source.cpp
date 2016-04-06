#include <iostream>
#include <string>
#include <cstdlib>

using namespace std;

class Card
{
	int numbr;
	string colr;
public:
	Card(int num, string col)
	{
		if (num >= 1 && num <= 10)
		{
			numbr = num;
		}
		else
			cout << "Number not Valid!" << endl;
		if (col == "red" || col == "black")
		{
			colr = col;
		}
		else
			cout << "Invalid Colour!" << endl;
	}

	string colour()
	{
		return colr;
	}

	int number()
	{
		return numbr;
	}
	void print()
	{
		if ((numbr >= 1 && numbr <= 10) && (colr == "red" || colr == "black"))
			cout << colr << " " << numbr << endl;
		else
			cout << "Validate your inputs!" << endl;
	}
};

class DeckOfCards
{


};

int main()
{
	Card crd(5, "Red");

	crd.print();
	return 0;
}