class Solution {
public:
    int majorityElement(vector<int>& nums)
    {
        int n = nums.size();
        int el = nums[0];
        int count = 0;
        for(int i=0;i<n;i++)
        {
            if(count==0)
            {
                el = nums[i];
                count++;
            }
            if(nums[i]==el)
            {
                count++;
            }
            else
            {
                count--;
            }
        }
        /* Checking if the stored element
         is the majority element*/
        int cnt1 = 0;
        for (int i = 0; i < n; i++) {
            if (nums[i] == el) {
                cnt1++;
            }
        }
        
        //return element if it is a majority element
        if (cnt1 > (n / 2)) {
            return el;
        }
        
        //return -1 if no such element found
        return -1;
    }
};