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
#include <iostream>
using namespace std;

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
