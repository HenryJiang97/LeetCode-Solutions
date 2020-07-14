class Solution {
public:
    double angleClock(double hour, double minutes) {
        if (hour == 12.0)    hour = 0.0;
        double angleHour = hour * 30 + minutes / 2;
        double angleMinute = minutes * 6;
        return min(abs(angleHour - angleMinute), 360 - abs(angleHour - angleMinute));
    }
};