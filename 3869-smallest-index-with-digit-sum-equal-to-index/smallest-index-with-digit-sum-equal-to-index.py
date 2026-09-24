class Solution:
    def smallestIndex(self, nums: List[int]) -> int:
        n=len(nums)
        for i in range(0,n):
            sum=0
            x=nums[i]
            while x>0 :
             cnt=x%10
             sum+=cnt
             x//=10
            if(sum==i):
             return i
        return -1