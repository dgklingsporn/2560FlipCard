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

  int score = 0; //keeping player's score
  int flipNumber = 1;
  bool playerWantsToPlay = true;

  while (playerWantsToPlay && !hand.isEmpty()) //player wants to play and deck is not empty
  {
    node<card>* flipped = hand.deal();
    cout << "Flip " << flipNumber << ": " << flipped->nodeValue << endl; //flips card
    int value = flipped->nodeValue.getValue(); //value
    int suit = flipped->nodeValue.getSuit(); //suit

    if(suit == "Heart") //extra point for heart
    {
      score += 1;
    }

    //points for each card value
    if (value == "Ace")
    {
      score += 10;
    }
    else if (value == "King" || value == "Queen" || value == "Jack")
    {
      score += 5;
    }
    else if (value == "8" || value == "9" || value == "10")
    {
      score += 0; //receives 0 points
    }
    else if (value == "7")
    {
      score /= 2;
    }
    else if (value == "2" || value == "3" || value == "4" || value == "5" || value == "6")
    {
      score = 0;
    }

    delete flipped; //finish flip turn
    flipNumber++; 

    float playerChoice; //ask player if they want to continue to play
    cout << "Would you like to flip another card? (y/n): ";
    cin >> playerChoice;

    if (playerChoice == 'y' || playerChoice == 'yes' || playerChoice == 'Y' || playerChoice == 'Yes')
    {
      playerWantsToPlay = true;
    }
    else
    {
      playerWantsToPlay = false; //doesn't want to continue to play
    }
  }
  //game has finished
  cout << "Game Over" << endl;
  cout << "Final Score: " << endl;
}

int main()
{
  playFlip(); //play global func
  
  return 0;
}
