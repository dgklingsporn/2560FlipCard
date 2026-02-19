# 2560FlipCard
Project Flip 
A C++ console-based card game played with a standard 52-card deck. Players draw cards to accumulate points while navigating risks that can halve or reset their score.

Game Rules
The Shuffle: The deck is shuffled three times at the start.
The Draw: The player draws 24 cards from the top, placed face down.
The Turn: On each turn, the player chooses to Flip a card or End the game.

Scoring:
Ace: +10 points
King, Queen, Jack: +5 points
8, 9, 10: 0 points
7: Lose half of current points
2, 3, 4, 5, 6: Lose ALL points
Heart (Any): +1 bonus point (added to the above)
Goal: Exit the game at the right time to finish with the highest possible score.

Technical Architecture
1. Card Class
Stores the identity of a single card.
Attributes: int value, string suit.
Methods: Getters/Setters for value and suit.
Overloads: << operator to print card details (e.g., "Ace of Hearts").

2. Deck Class
Manages the collection of cards using a Linked List.
Structure: A linked list of Node objects, each containing a Card.
Pointer: front points to the first card.
Functions:
shuffle(): Randomizes the linked list order.
operator<<: Prints the entire contents of the deck.


