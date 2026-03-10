#include <iostream>
using namespace std;

#ifndef card_h
#define card_h

class card{
   private: // suit and value
   string suit;
   string value;
    public:
    card(int suit_in, int value_in){ // constructor
        setSuit(suit_in);
        setValue(value_in);
    }
   card(const card& other){ //copy constructor
      suit = other.suit;
      value = other.value;
   }
   card& operator=(const card& other){ //overloaded assignment operator
      if (this != &other){
      suit = other.suit;
      value = other.value;
      }
      return *this;
   }
   void setSuit(int suit_in){
         const string suits[] = {"Club", "Diamond", "Heart", "Spade"}; // array of suits
         const string* ptr = suits; // pointer declaration
         suit = *(ptr + suit_in); // move pointer depending on what suit is selected

    }
   string getSuit() const{ // getter method
    return suit;
   }
void setValue(int value_in){
    const string values[] = {"Ace","2","3","4","5","6","7","8","9","10","Jack","Queen","King"};
    const string* ptr = values;
    value = *(ptr + (value_in - 1));  //offset by 1 since the deck doesn't have a value of 0
}

   string getValue() const{
    return value;
   }
   friend ostream& operator<<(ostream& os, card c) { // operator overload
        os << "Value: " << c.getValue(); // print value
        for (size_t i = (c.getValue()).length(); i < 7; i++) // adjust spaces for even formatting 
            os << ' ';
        os << " Suit: " << c.getSuit() << endl; // print suit
        return os;
   }
};

#endif






