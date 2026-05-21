class Solution {
public:
    int longestCommonPrefix(vector<int>& arr1, vector<int>& arr2) {
        
        unordered_set<string> st;

        // Store all prefixes of arr1
        for(auto it : arr1){

            string s = to_string(it);
            string temp = "";

            for(char ch : s){
                temp += ch;
                st.insert(temp);
            }
        }

        int maxlen = 0;

        // Check prefixes from arr2
        for(auto it : arr2){

            string s = to_string(it);
            string temp = "";

            for(char ch : s){

                temp += ch;

                if(st.find(temp) != st.end()){
                    maxlen = max(maxlen, (int)temp.size());
                }
            }
        }

        return maxlen;
    }
};