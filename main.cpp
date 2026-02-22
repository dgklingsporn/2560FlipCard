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
