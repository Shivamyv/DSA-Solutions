class Solution {
public:
    int maxNumberOfBalloons(string text) {
        unordered_map<char,int>hashlen;
        for(char ch:text) hashlen[ch]++;
        return min({
            hashlen['b'],
            hashlen['a'],
            hashlen['l']/2,
            hashlen['o']/2,
            hashlen['n']
        });

    }
};