/*
Flip card part b
EECE 2560
3/10/26
Group ID + #: ROBKLISYGRE 10
deck.h
This file declares the node structure and deck class used for the card deck
*/
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
    deck();                         // constructor
    ~deck();                        // destructor

    void shuffle();                 // shuffle deck
    void clear();                   // delete all nodes
    int size() const;               // count cards
    bool isEmpty() const;           // empty check
    void replace(node<card>* passedNode);

    node<card>* getFirst();         // return first card
    node<card>* deal();

    friend ostream& operator<<(ostream& ostr, const deck& d);

private:
    node<card>* firstCard;
};

#endif