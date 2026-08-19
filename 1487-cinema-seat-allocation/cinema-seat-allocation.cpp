class Solution {
public:
    int maxNumberOfFamilies(int n, vector<vector<int>>& reservedSeats) {
       unordered_map<int,unordered_set<int>>mpp;
       for(auto & it:reservedSeats){
            int row=it[0];
            int seat=it[1];
            mpp[row].insert(seat);

       }
      int result=(n-mpp.size())*2;
      for(auto &[row,bookedseat]:mpp){
        auto isavailable=[&](int seat){
            return bookedseat.find(seat)==bookedseat.end();
        };
       bool groupA=isavailable(2)&& isavailable(3) && isavailable(4) &&isavailable(5);
       bool groupB=isavailable(4)&& isavailable(5) && isavailable(6) &&isavailable(7);
       bool groupC=isavailable(6)&& isavailable(7) && isavailable(8) &&isavailable(9);
      if(groupA && groupC) result+=2;
      else if(groupA || groupB || groupC) result+=1;
         
      }

     return result;

    }
};