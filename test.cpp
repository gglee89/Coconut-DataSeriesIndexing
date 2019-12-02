#include <iostream>

using namespace std;

int main() {
  cout << "================================" << endl;
  cout << "========= Search Query =========" << endl;
  cout << "================================" << endl;
  cout << "== Description: Sequence ending with a #(pound) symbol" << endl;
  cout << "== Example: 2 4 20 6 3 1 #" << endl;
  cout << "================================" << endl;
  cout << "Enter query:" << endl;

  string name;
  getline(cin, name, '#');

  cout << name << endl;
}