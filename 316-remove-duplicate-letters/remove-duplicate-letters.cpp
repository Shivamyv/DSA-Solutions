class Solution {
public:
    string removeDuplicateLetters(string s) {
        int n=s.size();
        vector<int>visited(26,false);
        vector<int>lastindex(26);
        for(int i=0;i<n;i++){
            lastindex[s[i]-'a']=i;
        }
        string st="";
        for(int i=0;i<n;i++){
            char ch=s[i];
            if(visited[ch-'a']) continue;
            while(!st.empty() && st.back() > ch && lastindex[st.back()-'a']>i){
                visited[st.back()-'a']=false;
                st.pop_back();
            }
            st.push_back(ch);
            visited[ch-'a']=true;
        }
        return st;
    }
};