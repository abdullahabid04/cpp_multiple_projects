#include<iostream>
#include<iomanip>
#include<ctime>
#include<cstdlib>
using namespace std;

struct Card
{
	char *face;
	char *suit;
};

class Deckofcards
{
	public:
		Deckofcards()
		{
			static char *suit[4] = {"Hearts","Diamonds","Clubs","Spades"};
			static char *face[13] = {"Ace","Duece","Three","Four","Five","Six","Seven","Eight","Nine","Ten","Jack","Queen","King"};
			
			for(int i=0;i<52;i++)
			{
				deck[i].face = face[i%13];
				deck[i].suit = suit[i/13];
			}
			
			srand(time(0));
		}
		void shuffle()
		{
			for(int i=0;i<52;i++)
			{
				int j = rand()%52;
				Card temp = deck[i];
				deck[i] = deck[j];
				deck[j] = temp;
 			}	
		}
		void deal()
		{
			for(int i=0;i<52;i++)
			{
				cout<<right<<setw(5)<<deck[i].face<<" of "<<left<<setw(8)<<deck[i].suit<<((i+1)%2?'\t':'\n');
			}
		}
	private:
		Card deck[52];
};

int main()
{
	Deckofcards deckofcards;
	
	deckofcards.shuffle();
	deckofcards.deal();
	
	return 0;
}
