class Solution {
public:
    void sortColors(vector<int>& nums)
    {
        int n = nums.size();
        int i=0;
        int l=0,r=n-1;
        while(i<=r)
        {
            if(nums[i]==0)
            {
                swap(nums[i],nums[l]);
                l++;
            }
            else if(nums[i]==2)
            {
                swap(nums[i],nums[r]);
                r--;
                i--; // essentially done so that i wont get incremented when we are in this case (bcoz i-1+1=i)
            }
            i++;
        }
    }
};