#include <iostream>
using namespace std;

class Card{
   private:
   string suit;
   string value;
    public:
    Card(int suit_in, int value_in){
        setSuit(suit_in);
        setValue(value_in);
    }
   void setSuit(int suit_in){
         const string suits[] = {"Club", "Diamond", "Heart", "Spade"};
         const string* ptr = suits;
         suit = *(ptr + suit_in);

    }
   string getSuit(){
    return suit;
   }
   void setValue( int value_in){
    const string values[] = {"2","3","4","5","6","7","8","9","10","Jack","Queen","King","Ace"};
    const string* ptr = values;
    value = *(ptr + (value_in - 2));
   }

   string getValue(){
    return value;
   }
   friend ostream& operator<<(ostream& os, const Card& c) {
        os << "Value: " << c.value << " Suit: " << c.suit << endl;
        return os;
   }
};