class Solution:
    def smallestIndex(self, nums: List[int]) -> int:
        n=len(nums)
        for i in range(0,n):
            sum=0

            while nums[i]>0 :
             cnt=nums[i]%10
             sum+=cnt
             nums[i]//=10
            if(sum==i):
             return i
        return -1