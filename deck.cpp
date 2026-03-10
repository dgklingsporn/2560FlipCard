/*
Flip card part b
EECE 2560
3/10/26
Group ID + #: ROBKLISYGRE 10
deck.cpp
This file implements deck construction, deletion, shuffling, dealing, replacing, and printing.
*/

#include "deck.h"

// ----------------------------------------------
// This creates 52 cards in order: Ace-King, then Club-Diamond-Heart-Spade
deck::deck()
{
    firstCard = nullptr;
    node<card>* tail = nullptr;

    // Outer loop: Suits (0: Club, 1: Diamond, 2: Heart, 3: Spade)
    for (int s = 0; s <= 3; s++)
    {
        // Inner loop: Values (1: Ace ... 13: King)
        for (int v = 1; v <= 13; v++)
        {
            card newCard(s, v);
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

// --------------------------
// the destructor
deck::~deck()
{
    clear();
}

// --------------------------
// returns size of deck for confirming that we didnt losing anything
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

// --------------------------
// checks if empty
bool deck::isEmpty() const
{
    return firstCard == nullptr;
}

// --------------------------
// The big one (shuffle method)
void deck::shuffle()
{
    if (firstCard == nullptr || firstCard->next == nullptr)
        return;

    vector<card> temp;

    node<card>* curr = firstCard;
    while (curr != nullptr)
    {
        temp.push_back(curr->nodeValue);
        curr = curr->next;
    }

    random_device rd;
    mt19937 gen(rd());
    std::shuffle(temp.begin(), temp.end(), gen);

    clear();

    firstCard = new node<card>(temp[0], nullptr);
    node<card>* tail = firstCard;

    for (size_t i = 1; i < temp.size(); i++)
    {
        tail->next = new node<card>(temp[i], nullptr);
        tail = tail->next;
    }
}

// --------------------------
// get first card
node<card>* deck::getFirst()
{
    return firstCard;
}

// deal out the first card
node<card>* deck::deal()
{
    if (firstCard == nullptr)
        return nullptr;

    node<card>* dealtCard = firstCard;
    firstCard = firstCard->next;
    dealtCard->next = nullptr;

    return dealtCard;
}

// place a passed card node on the bottom of the deck
void deck::replace(node<card>* passedNode)
{
    if (passedNode == nullptr)
        return;

    passedNode->next = nullptr;

    if (firstCard == nullptr)
    {
        firstCard = passedNode;
        return;
    }

    node<card>* curr = firstCard;
    while (curr->next != nullptr)
    {
        curr = curr->next;
    }

    curr->next = passedNode;
}

// --------------------------
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
            ostr << " ";

        if (count % 13 == 0)
            ostr << "\n";

        curr = curr->next;
    }

    ostr << "\n";
    return ostr;
}