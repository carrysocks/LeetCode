class RandomizedSet {
set<int> s;
public:
    RandomizedSet() {
    }
    
    bool insert(int val) {
        if(s.find(val) != s.end()) return false;
        s.insert(val);
        return true;
    }
    
    bool remove(int val) {
        if(s.find(val) == s.end()) return false;
        s.erase(val);
        return true;
    }
    
    int getRandom() {
        int idx = rand()%s.size();
        auto it = s.begin();
        advance(it, idx); 
        return *it; // 
    }
};

/**
 * Your RandomizedSet object will be instantiated and called as such:
 * RandomizedSet* obj = new RandomizedSet();
 * bool param_1 = obj->insert(val);
 * bool param_2 = obj->remove(val);
 * int param_3 = obj->getRandom();
 */