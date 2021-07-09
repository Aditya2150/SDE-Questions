class Solution {
public:

    // DYNAMIC APPROACH (PREFIX AND SUFIX) Space- O(3N)
    int trap(vector<int>& height) {
        int n=height.size();
        if(n==0)
            return 0;
        int pre[n],suf[n];
        pre[0]=height[0],suf[n-1]=height[n-1];
        for(int i=1;i<n;i++)
            pre[i]=max(pre[i-1],height[i]);
        for(int i=n-2;i>=0;i--)
            suf[i]=max(suf[i+1],height[i]);
        int ans=0;
        for(int i=1;i<n-1;i++)
            ans+=min(pre[i],suf[i])-height[i];
        return ans;
    }

    // Stack Space-O(N)
    int trap(vector<int>& height) {
        int n=height.size();
        int current=0;
        int ans=0;
        stack<int>s;
        while(current<n)
        {
            while(!s.empty() && height[current]>height[s.top()])
            {
                int top=s.top();
                s.pop();
                if(s.empty())
                    break;
                int dist=current-s.top()-1;
                int bounded_height=min(height[s.top()],height[current])-height[top];
                ans+=dist*bounded_height;
            }
            s.push(current++);
        }
        return ans;
    }


    // 2 POINTER APPROACH Space-O(1)
    int trap(vector<int>& height) {    
        int left=0,right=n-1,ans=0;
        int left_max=0,right_max=0;
        while(left<right)
        {
            if(height[left]<height[right])
            {
                height[left]<left_max?ans+=left_max-height[left]:left_max=height[left];
                left++;
            }
            else
            {
                height[right]<right_max?ans+=right_max-height[right]:right_max=height[right];
                right--;
            }
        }
        return ans;
    }
};
