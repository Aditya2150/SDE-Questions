#include<bits/stdc++.h>
using namespace std;


class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        for(int i=0;i<nums.size();i++)
        {
            if(nums[abs(nums[i])]>=0)
                nums[abs(nums[i])]=-nums[abs(nums[i])];
            else
                return abs(nums[i]);
        } 
        return 0;
    }

// Floyd's Tortoise and Hare (Cycle Detection)
    int findDuplicate(vector<int>& nums) {
            int slow=nums[0];
            int fast=nums[0];
            do{
                slow=nums[slow];
                fast=nums[nums[fast]];
            }while(slow!=fast);
            fast=nums[0];
            while(fast!=slow)
                fast=nums[fast],slow=nums[slow];
            return slow;
        }

};

int main()
{
    return 0;
}