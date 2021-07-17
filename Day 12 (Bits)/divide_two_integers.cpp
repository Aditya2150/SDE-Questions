// Given two integers dividend and divisor, divide two integers without using multiplication, division, and mod operator.
// Return the quotient after dividing dividend by divisor.
// The integer division should truncate toward zero, which means losing its fractional part.
// For example, truncate(8.345) = 8 and truncate(-2.7335) = -2.
// Note: Assume we are dealing with an environment that could only store integers within the 32-bit signed integer range:
//  [−231, 231 − 1]. For this problem, assume that your function returns 231 − 1 when the division result overflows.


class Solution {
public:
    int divide(int dividend, int divisor) {
        if(dividend==INT_MIN && divisor==-1)
            return INT_MAX;
        int sign=((dividend<0)^(divisor<0)?-1:1);
        long long divisors=abs(divisor);
        long long dividends=abs(dividend);
        long long quotient=0;
        for(int i=31;i>=0;--i)
        {
            if((divisors<<i)<=dividends)
            {
                dividends-=divisors<<i;
                quotient|=1LL<<i;
            }
        }
        return sign*quotient;
    }
};
