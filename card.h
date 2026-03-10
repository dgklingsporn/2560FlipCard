/*
Flip card part b
EECE 2560
3/10/26
Group ID + #: ROBKLISYGRE 10
card.h
This file declares the card class used to store one playing card
*/
#ifndef card_h
#define card_h

#include <iostream>
#include <string>
using namespace std;

class card{
   private: // suit and value
   string suit;
   string value;

public:
   card(int suit_in, int value_in); // constructor

   card(const card& other); // copy constructor

   card& operator=(const card& other); // overloaded assignment operator

   void setSuit(int suit_in); // setter for suit

   string getSuit() const; // getter method

   void setValue(int value_in); // setter for value

   string getValue() const; // getter method

   friend ostream& operator<<(ostream& os, card c); // operator overload
};

#endif


