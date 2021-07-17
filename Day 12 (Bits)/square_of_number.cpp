#include<bits/stdc++.h>
using namespace std;

// METHOD-1
// The idea is based on the fact that the square root of any number n can be calculated
// by adding odd numbers exactly n times. The relation can be expressed as:
// 1^2 = 1
// 2^2 = (1 + 3) = 4 42= (1 + 3 + 5 + 7) = 16
// 3^2= (1 + 3 + 5 =9)


// METHOD-2: Repeatedly adding a given number to the result
// The idea is to repeatedly addsa given number n to the result n times. For example,
// For n = 5, 5^2 = (5 + 5 + 5 + 5 + 5) = 25


// METHOD-3: Using Divide and Conquer with bitwise operators If n is even,
// the square of n can be expressed as n² = ((n/2) x 2)² = (n/2)² x 4.
// If n is odd, the square of n can be expressed as n² = ((n-1) + 1)2 = (n − 1)² + 1 + 2 x (n-1) x
// 1 = ((n/2)² x 4) + 1 + (n/2) x 4.


// METHOD-4
// For a given number `num` we get square of it by multiplying number as `num * num`. 
// Now write one of `num` in square `num * num` in terms of power of `2`. Check below examples.
// Eg: num = 10, square(num) = 10 * 10 = 10 * (8 + 2) = (10 * 8) + (10 * 2)
//     num = 15, square(num) = 15 * 15 = 15 * (8 + 4 + 2 + 1) = (15 * 8) + (15 * 4) + (15 * 2) + (15 * 1)
// Multiplication with power of 2's can be done by left shift bitwise operator.

int findSquare(int n)
{
    int x=log2(n);
    int ans=0;
    while(x!=-1)
    {
        if((n>>x)&1)
        ans+=n<<x;
        x--;
    }
    return ans;
}

int main()
{
    int t;
    cin >> t;
    while(t--){
    int n;
    cin >> n;
    cout << findSquare(n) << endl;
    }
    return 0;
}