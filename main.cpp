/*
Flip card part b
EECE 2560
3/10/26
Group ID + #: ROBKLISYGRE 10
main.cpp
This is the main file for the game it
connects the deck and card classes
and controls the overall program
*/
#include "deck.h"
#include "card.h"
#include <iostream>
using namespace std;

void playFlip()
{
  //(1) initialize a deck with 52 cards in order
  deck d;
  deck hand;

  //(2) shuffle the deck and print all cards after shuffle
  d.shuffle();
  cout << "Deck after shuffle:" << endl;
  cout << d << endl;

  //(3) draw and remove the top 24 cards from the deck and insert into the back of the current hand deck
  for (int i = 0; i < 24; i++)
  {
    node<card>* drawn = d.deal();
    hand.replace(drawn);
  }

  //(4) print all cards in the current hand deck and all remaining cards in the deck
  cout << "Current hand deck:" << endl;
  cout << hand << endl;

  cout << "Remaining deck:" << endl;
  cout << d << endl;

  //(5) start the game and print the results
  cout << "Flip game started..." << endl;

  int score = 0;
  int flipNumber = 1;

  while (!hand.isEmpty())
  {
    node<card>* flipped = hand.deal();
    cout << "Flip " << flipNumber << ": " << flipped->nodeValue << endl;
    int value = flipped->nodeValue.getValue();

    
      
  }
      
  
}

int main()
{
  deck d;
  cout << "Before Shuffle:" << endl;
  cout << d << endl;

  d.shuffle();

  cout << "After Shuffle:" << endl;
  cout << d << endl;
  
  return 0;
}
