/*
Flip card part b
EECE 2560
3/10/26
Group ID + #: ROBKLISYGRE 10
card.cpp
This file implements the card class methods
*/

#include "card.h"

// constructor
card::card(int suit_in, int value_in){
    setSuit(suit_in);
    setValue(value_in);
}

// copy constructor
card::card(const card& other){
    suit = other.suit;
    value = other.value;
}

// overloaded assignment operator
card& card::operator=(const card& other){
    if (this != &other){
        suit = other.suit;
        value = other.value;
    }
    return *this;
}

// setter for suit
void card::setSuit(int suit_in){
    const string suits[] = {"Club", "Diamond", "Heart", "Spade"}; // array of suits
    const string* ptr = suits; // pointer declaration
    suit = *(ptr + suit_in); // move pointer depending on what suit is selected
}

// getter for suit
string card::getSuit() const{
    return suit;
}

// setter for value
void card::setValue(int value_in){
    const string values[] = {"Ace","2","3","4","5","6","7","8","9","10","Jack","Queen","King"};
    const string* ptr = values;
    value = *(ptr + (value_in - 1));  // offset by 1 since the deck doesn't have a value of 0
}

// getter for value
string card::getValue() const{
    return value;
}

// operator overload for printing card
ostream& operator<<(ostream& os, card c){
    os << "Value: " << c.getValue(); // print value

    for (size_t i = (c.getValue()).length(); i < 7; i++) // adjust spaces for even formatting
        os << ' ';

    os << " Suit: " << c.getSuit() << endl; // print suit
    return os;
}