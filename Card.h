#include <iostream>
using namespace std;

#ifndef card_h
#define card_h

class card{
   private:
   string suit;
   string value;
    public:
    card(int suit_in, int value_in){
        setSuit(suit_in);
        setValue(value_in);
    }
   void setSuit(int suit_in){
         const string suits[] = {"Club", "Diamond", "Heart", "Spade"};
         const string* ptr = suits;
         suit = *(ptr + suit_in);

    }
   string getSuit() const{
    return suit;
   }
   void setValue( int value_in){
    const string values[] = {"2","3","4","5","6","7","8","9","10","Jack","Queen","King","Ace"};
    const string* ptr = values;
    value = *(ptr + (value_in - 2));
   }

   string getValue() const{
    return value;
   }
   friend ostream& operator<<(ostream& os, card c) {
        os << "Value: " << c.getValue();
        for (size_t i = (c.getValue()).length(); i < 7; i++)
            os << ' ';
        os << " Suit: " << c.getSuit() << endl;
        return os;
   }
};

#endif




