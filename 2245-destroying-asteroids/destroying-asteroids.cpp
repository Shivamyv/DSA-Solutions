class Solution {
public:
    bool asteroidsDestroyed(int mass, vector<int>& asteroids) {
      int n=asteroids.size();
      sort(asteroids.begin(),asteroids.end());
        long long sum=mass;
       
       

        for (int x : asteroids) {
            if (sum < x)
                return false;

            sum += x;
        }

        return true;


    }
};