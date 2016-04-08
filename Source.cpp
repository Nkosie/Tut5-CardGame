#include <iostream>
#include <string>
#include <cstdlib>
#include <ctime>

using namespace std;

class Card
{
	int numbr;
	string colr;
public:
	Card()
	{
		numbr = 1;
		colr = "red";
	}
	~Card(){}
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
	int NoOfCards=20;
	Card crds[20];
public:

	DeckOfCards reset()
	{
		DeckOfCards deck;
		for (int i = 0; i <10; i++)
		{
			deck.crds[i] = Card(i + 1, "black");
			crds[i] = deck.crds[i];
			deck.crds[i + 10] = Card(i +1, "red");	
			crds[i+10] = deck.crds[i+10];
		}
		
		return deck;
	}
	void shuffle()
	{
		DeckOfCards temp;
		for (int i = 0; i < 50; i++)
		{
			int index1 = (rand() % NoOfCards);
			int index2 = (rand() % NoOfCards);
			temp.crds[1] = crds[index1];
			crds[index1] = crds[index2];
			crds[index2] = temp.crds[1];
		}		
	}
	Card draw()
	{
		--NoOfCards;
		Card temp;
		temp= crds[NoOfCards];
		cout << "Top Card To be removed" << endl;
		temp.print();
		return temp;
	}
	Card peek()
	{
		Card temp;
		temp = crds[NoOfCards];
		cout << "Top Card on the stack!" << endl;
		temp.print();
		return temp;
	}
	int numberOfCards()
	{
		return NoOfCards;
	}

};

int main()
{
	srand(static_cast<unsigned int>(time(0)));
	Card crd(5, "red");
	crd.print();
	DeckOfCards Dcards;
	Dcards.reset();
	Dcards.shuffle();
	for (int i = 0; i < 50; i++)
	{
		Dcards.draw();
		Dcards.peek();
		cout <<"No of cards left: "<< Dcards.numberOfCards() << endl << endl << endl;
		int terminator = Dcards.numberOfCards();
		if (terminator == 0)
		{
			cout << "NO CARD LEFT!!!" << endl << endl;
				break;
		}
	}
	return 0;
}