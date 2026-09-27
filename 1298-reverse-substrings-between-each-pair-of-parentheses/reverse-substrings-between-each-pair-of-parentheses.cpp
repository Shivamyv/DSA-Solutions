class Solution {
public:
    string reverseParentheses(string s) {
        int n=s.size();
        stack<int>st;
        string curr="";
        for(char ch:s){
            if(ch=='('){
            st.push(curr.size());
            }
            else if(ch==')'){
                int start=st.top();
                st.pop();
                reverse(curr.begin()+start,curr.end());

            }
            else{
                curr+=ch;
            }
        }
        return curr;
    }
};