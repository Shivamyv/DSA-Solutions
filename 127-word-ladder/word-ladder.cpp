class Solution {
public:
int bfs(string beginWord, string endWord, vector<string>& wordList){
     queue<pair<string,int>>q;
      q.push({beginWord,1});
      unordered_set<string>st(wordList.begin(),wordList.end());
      if(st.find(endWord)==st.end()) return 0;
      while(!q.empty()){
        auto it=q.front();
        q.pop();
        string word=it.first;
        int distance=it.second;
        if(word==endWord) return distance;
         for(int i=0;i<word.size();i++){
             char original=word[i];
             for(char ch='a';ch<='z';ch++){
                word[i]=ch;
             if(st.find(word)!=st.end()){
                st.erase(word);
                q.push({word,distance+1});
             }
         }
         word[i]=original;
         }
      }
         return 0;

      }


    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        return bfs(beginWord,endWord,wordList);
    }
};