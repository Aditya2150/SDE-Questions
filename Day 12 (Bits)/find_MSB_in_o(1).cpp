#include<bits/stdc++.h>
int findMSB(int n){
	return (1<<(int)log2(n));
}

int main()
{
	int n;
	cin >> n;
	cout << findMSB(n) << endl;
	return 0;
}