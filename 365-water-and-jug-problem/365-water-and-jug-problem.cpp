class Solution {
public:
    bool canMeasureWater(int jug1Capacity, int jug2Capacity, int targetCapacity) {
        if(targetCapacity % gcd(jug1Capacity,jug2Capacity) || jug1Capacity + jug2Capacity < targetCapacity) return false;
        else return true;
    }
};