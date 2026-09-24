class Solution(object):
    def smallestIndex(self, nums):
        """
        :type nums: List[int]
        :rtype: int
        """
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

        