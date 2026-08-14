class Solution {
public:
    vector<int> majorityElement(vector<int>& nums)
    {
        int n = nums.size();
        int el1 = INT_MIN;
        int el2 = INT_MIN;
        float cnt1 = 0.0;
        float cnt2 = 0.0;
        for(int i=0;i<n;i++)
        {
            if(cnt1==0.0 && nums[i]!=el2)
            {
                el1 = nums[i];
                cnt1=1.0;
            }
            else if(cnt2==0.0 && nums[i]!=el1)
            {
                el2 = nums[i];
                cnt2=1.0;
            }
            else if(el1==nums[i])
            {
                cnt1+=1.0;
            }
            else if(el2==nums[i])
            {
                cnt2+=1.0;
            }
            else
            {
                cnt1-=1.0;
                cnt2-=1.0;
            }
        }   
        // manual check
        int freq1=0;
        int freq2=0;
        for(int i=0;i<n;i++)
        {
            if(nums[i]==el1) freq1++;
            if(nums[i]==el2) freq2++;
        }
        vector<int>ls;
        int mini = (int)n/3 + 1;
        if(freq1>=mini) ls.push_back(el1);
        if(freq2>=mini) ls.push_back(el2);
        return ls;
    }
};