#include<iostream>
#include<string>
#include<ctime>
#include <cstdlib>
using namespace std;
class PlayingCard
{
   private:
      int numValue;
	  string stringValue;
	  int numSuit;
	  string stringSuit;
   public:
	   PlayingCard(int, int);
       PlayingCard();
	   void display();
	   int getVal();
	   int getSuit();
};
PlayingCard::PlayingCard(int val, int suit)
{
	string valArray[] = {"", "Ace", "2", "3", "4", "5", "6", "7", "8",
	   "9", "10", "Jack", "Queen", "King"};
	string suitArray[] = {"", "spades", "hearts", "diamonds", "clubs"};
	numValue = val;
	numSuit = suit;
    stringValue = valArray[val];
	stringSuit = suitArray[suit];
}
PlayingCard::PlayingCard()
{
}
void PlayingCard::display()
{
	cout << "Card is " << stringValue << " of " << stringSuit << endl;
}
int PlayingCard::getVal()
{
	 return numValue;
}
int PlayingCard::getSuit()
{
	return numSuit;
}
class Hand
{
   private:
      PlayingCard card[5];
   public:
      Hand();
	  void display();
};
Hand::Hand()
{
   srand((unsigned)time(NULL));
   for(int x = 0; x < 5; ++x)
   {
	   int ranVal = rand() % 13 + 1;
       int ranSuit = rand() % 4 + 1;
	   card[x] = PlayingCard(ranVal, ranSuit);
	   for(int y = 0; y < x; ++y)
		   if(card[y].getVal() == ranVal && card[y].getSuit() == ranSuit)
			   --x;			   
   }
}
void Hand::display()
{
	for(int x = 0; x < 5; ++x)
		card[x].display();
}
int main()
{
   
   Hand hand;
   hand.display();
   return 0;
}
