class Solution {
public:
    double angleClock(int hour, int minutes) {
        //Q =30h-5.5m;
        //min q=min(Q,360-Q);

        double Q= abs(30*(hour %12)-5.5*minutes);
        double minangle=min(Q,360-Q);

        return minangle;

    }
};