class Solution(object):
    def reverseDegree(self, s):
        """
        :type s: str
        :rtype: int
        """
        n=len(s)
        sum=0
        for i in range(0,n):
            reverse=ord('z')-ord(s[i])+1
            sum+=(i+1)*reverse
            
        return sum
        