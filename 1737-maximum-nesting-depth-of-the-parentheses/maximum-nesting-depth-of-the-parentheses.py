class Solution:
    def maxDepth(self, s: str) -> int:
     n=len(s)
     leftchar=0
     ans=0
     for i in range(0,n):
       if s[i]=='(':
         leftchar+=1
         ans=max(ans,leftchar)
       if s[i]==')':
         leftchar-=1

     return ans  



