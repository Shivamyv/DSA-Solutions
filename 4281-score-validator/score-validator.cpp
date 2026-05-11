class Solution {
public:
    vector<int> scoreValidator(vector<string>& events) {
        
        int n=events.size();
        int score=0,counter=0;
        for(string ch:events){
            if(counter==10) break;
            
            if(ch=="W"){
                counter++;
            }
            else if(ch=="WD"|| ch=="NB"){
                score++;
            }
            else{
                int eve=stoi(ch);
                score+=eve;
            }
        }
        
        
    return{score,counter};
        

    }
};