class ProductOfNumbers {
     vector<int> v;
public:
    ProductOfNumbers() {
        
    }
    
    void add(int num) {
         if(num) {if(v.size()) v.push_back(v.back()*num); else v.push_back(num);} 
        else v.clear();
    }
    
    int getProduct(int k) {
         int a = v.size()-k;
     if(a>=0)
     {
         if(a) return v.back()/v[a-1];
         else return v.back();
     }
        else return 0;
    }
};

/**
 * Your ProductOfNumbers object will be instantiated and called as such:
 * ProductOfNumbers* obj = new ProductOfNumbers();
 * obj->add(num);
 * int param_2 = obj->getProduct(k);
 */