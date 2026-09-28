class Solution:
    def canTransform(self, source: list[int], target: list[int]) -> bool:
      n=len(source)
      sum1=0
      sum2=0
      for i in range(0,n):
        sum1+=source[i]
        sum2+=target[i]
      return sum1==sum2
