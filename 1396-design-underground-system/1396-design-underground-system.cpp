map<int,pair<string,int>> cust;
map<pair<string,string>,pair<int,int>> avg_time;
class UndergroundSystem {
public:
    UndergroundSystem() {
        
    }
    
    void checkIn(int id, string stationName, int t) {
        cust[id] = {stationName,t};
    }
    
    void checkOut(int id, string stationName, int t) {
        int tm = t - cust[id].second;
        avg_time[{cust[id].first,stationName}].first+=tm;
        avg_time[{cust[id].first,stationName}].second+=1;
    }
    
    double getAverageTime(string startStation, string endStation) {
     
        return (double)avg_time[{startStation,endStation}].first/avg_time[{startStation,endStation}].second;

    }
};

/**
 * Your UndergroundSystem object will be instantiated and called as such:
 * UndergroundSystem* obj = new UndergroundSystem();
 * obj->checkIn(id,stationName,t);
 * obj->checkOut(id,stationName,t);
 * double param_3 = obj->getAverageTime(startStation,endStation);
 */