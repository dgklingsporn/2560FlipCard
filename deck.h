#ifndef deck_h
#define deck_h

#include <iostream>
#include <vector>
#include <algorithm>
#include <random>
#include "card.h" // we need the seperate card header file class

using namespace std;

template <typename T>
struct node {
    T nodeValue;
    node<T>* next;
    node(T val, node<T>* n = nullptr) : nodeValue(val), next(n) {}
};




class deck
{
public:
    deck();                         // constructor (someone else should have made?)
    ~deck();                        // destructor

    void shuffle();                 // shuffle deck
    void clear();                   // delete all nodes
    int size() const;               // count cards
    bool isEmpty() const;           // empty check

    node<card>* getFirst();         // return first card

    friend ostream& operator<<(ostream& ostr, const deck& d);

private:
    node<card>* firstCard = nullptr;
};
// ----------------------------------------------
// This creates 52 cards in order: Ace-King, then Club-Diamond-Heart-Spade
deck::deck()
{
    firstCard = nullptr;
    node<card>* tail = nullptr;

    // Outer loop: Suits (1: Club, 2: Diamond, 3: Heart, 4: Spade)
    for (int s = 0; s <= 3; s++)
    {
        // Inner loop: Values (1: Ace ... 13: King)
        for (int v = 2; v <= 14; v++)
        {
            card newCard(s, v); // Assumes Member 1's constructor is Card(value, suit)
            node<card>* newNode = new node<card>(newCard);

            if (firstCard == nullptr)
            {
                firstCard = newNode;
                tail = firstCard;
            }
            else
            {
                tail->next = newNode;
                tail = newNode;
            }
        }
    }
}

// ----------------------------------------------
// clear decks previous memory
void deck::clear()
{
    node<card>* curr = firstCard;

    while (curr != nullptr)
    {
        node<card>* nextNode = curr->next;
        delete curr;
        curr = nextNode;
    }

    firstCard = nullptr;
}


//--------------------------
// the destructor

deck::~deck()
{
    clear();
}


//--------------------------
// returns size of deck for confirming that we didnt kosing anything

int deck::size() const
{
    int count = 0;
    node<card>* curr = firstCard;

    while (curr != nullptr)
    {
        count++;
        curr = curr->next;
    }

    return count;
}


//--------------------------
// checks if empty

bool deck::isEmpty() const
{
    return firstCard == nullptr;
}


//--------------------------
// The big one (shuffle method)

void deck::shuffle()
{
    if (firstCard == nullptr || firstCard->next == nullptr)
        return;

    vector<card> temp;

    // copy linked list → vector
    node<card>* curr = firstCard;
    while (curr != nullptr)
    {
        temp.push_back(curr->nodeValue);
        curr = curr->next;
    }

    // random shuffle
    random_device rd;
    mt19937 gen(rd());
    std::shuffle(temp.begin(), temp.end(), gen);

    // delete old list
    clear();

    // rebuild list
    firstCard = new node<card>(temp[0], nullptr);
    node<card>* tail = firstCard;

    for (size_t i = 1; i < temp.size(); i++)
    {
        tail->next = new node<card>(temp[i], nullptr);
        tail = tail->next;
    }
}


//--------------------------
// get first card
node<card>* deck::getFirst()
{
    return firstCard;
}


//--------------------------
// print the deck
ostream& operator<<(ostream& ostr, const deck& d)
{
    node<card>* curr = d.firstCard;
    int count = 0;

    ostr << "\nDeck:\n";

    while (curr != nullptr)
    {
        count++;
        ostr << curr->nodeValue;

        if (curr->next != nullptr)
            ostr << "";

        if (count % 13 == 0)
            ostr << "\n";

        curr = curr->next;
    }

    ostr << "\n";
    return ostr;
}


#endif
