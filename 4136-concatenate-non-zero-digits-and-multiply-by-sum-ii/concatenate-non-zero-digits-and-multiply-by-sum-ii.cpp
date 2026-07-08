class Solution {
public:
 const int mod=1e9+7;

    vector<int> sumAndMultiply(string s, vector<vector<int>>& queries) {
        int n=s.size();
      

       vector<long long>prefixsum(n,0);
       prefixsum[0]=s[0]-'0';
       for(int i=1;i<n;i++){
        prefixsum[i]=prefixsum[i-1]+s[i]-'0';
       }
       vector<long long>pow(n+1,0);
       pow[0]=1;
       for(int i=1;i<=n;i++){
        pow[i]=(pow[i-1]*10)%mod;

       }
       vector<long long>nonzero(n,0);
       vector<long long>uptocount(n,0);
       nonzero[0]= (s[0] != '0') ? 1 : 0;
        uptocount[0] = s[0] - '0';
       for (int i = 1; i < n; i++) {
            int digit = s[i] - '0';
            nonzero[i] = nonzero[i - 1] + (digit != 0 ? 1 : 0);
        }
        for (int i = 1; i < n; i++) {
            int digit = s[i] - '0';
            if (digit != 0)
                uptocount[i] = ( uptocount[i - 1] * 10 + digit) % mod;
            else
                 uptocount[i] =  uptocount[i - 1];
        }
        int q=queries.size();
        vector<int>result(q);
        for(int i=0;i<q;i++){
            int l=queries[i][0];
            int r=queries[i][1];
              int startCount = (l == 0) ? 0 : nonzero[l - 1];
            long long numBefore   = (l == 0) ? 0 : uptocount[l - 1];
              int endCount = nonzero[r];
            int subStrLen = endCount - startCount;

            if (subStrLen == 0) {
                result[i] = 0;
                continue;
            }

            long long x   = (uptocount[r] - (numBefore * pow[subStrLen] % mod) + mod) % mod;
            long long sum = prefixsum[r] - ((l == 0) ? 0 :prefixsum[l - 1]);

            result[i] = (int)((x * sum) % mod);
        }


       return result;


    }
};