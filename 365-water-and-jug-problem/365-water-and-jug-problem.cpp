class Solution {
public:
    int gcd1(int a,int b)
    {
        if(a == 0) return b;
        return gcd1(b%a,a);
    }
    bool canMeasureWater(int jug1Capacity, int jug2Capacity, int targetCapacity) {
        if(targetCapacity % gcd1(jug1Capacity,jug2Capacity) || jug1Capacity + jug2Capacity < targetCapacity) return false;
        else return true;
    }
};