// a.
// 1.Iterative Approach-Time-Time=O(n),Space-O(1)

#include<bits/stdc++.h>
using namespace std;
int main()
{

	int n;
	cin >> n;
	int sum = 0;
	for (int i = 0; i <= n; i++)
	{
		sum = sum + i;
	}
	cout << sum;
}




