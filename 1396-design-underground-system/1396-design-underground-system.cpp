map<int,pair<string,int>> cust;
map<pair<string,string>,vector<int>> avg_time;
class UndergroundSystem {
public:
    UndergroundSystem() {
        
    }
    
    void checkIn(int id, string stationName, int t) {
        cust[id] = {stationName,t};
    }
    
    void checkOut(int id, string stationName, int t) {
        int tm = t - cust[id].second;
        avg_time[{cust[id].first,stationName}].push_back(tm); 
    }
    
    double getAverageTime(string startStation, string endStation) {
        double sm = 0.0;
        for(auto &el  : avg_time[{startStation,endStation}])
        {
              sm+=el;
        }
        sm/=(double)avg_time[{startStation,endStation}].size();
        return sm;
    }
};

/**
 * Your UndergroundSystem object will be instantiated and called as such:
 * UndergroundSystem* obj = new UndergroundSystem();
 * obj->checkIn(id,stationName,t);
 * obj->checkOut(id,stationName,t);
 * double param_3 = obj->getAverageTime(startStation,endStation);
 */