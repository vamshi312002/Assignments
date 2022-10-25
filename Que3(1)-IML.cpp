//2. Recursive Approach-Time and Space =O(n)

#include<bits/stdc++.h>
using namespace std;
int rec(int n)
{
	if (n == 0)
		return 0;
	else
		return n + rec(n - 1);
}

int main()
{

	int n;
	cin >> n;
	int x = rec(n);
	cout << x;
}