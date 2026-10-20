#include <iostream>
#include <vector>
#include <cassert>

using namespace std;

int fold(int(*f)(int, int), vector<int> v, int i = 0)
{
	if(i<v.size()-1)return f(v[i],fold(f,v,i+1));return v[i];
}

int add(int x, int y)
{
	return x + y;
}

int mult(int x, int y)
{
	return x * y;
}

int main()
{
	vector<int> v = { 1, 2, 3, 4, 5 };
	assert(fold(add, v) == 15);
	assert(fold(mult, v) == 120);
	v.push_back(17);
	assert(fold(add, v) == 32);
	assert(fold(mult, v) == 2040);
	cout << "woahooohah it all work";
}