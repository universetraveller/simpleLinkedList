#include "LinkedList.h"
#include "LinkedList.cpp"
int main() {
	LinkedList<int> a(0);
	LinkedList<int> b;
	a.push_back(1);
	a.push_back(2);
	a.push_back(3);
	a.push_back(4);
	b.push_back(5);
	a.merge(b);
	a.Print_cout();
	b.Print_cout();
	return 0;
}