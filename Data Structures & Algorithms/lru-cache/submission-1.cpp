class LRUCache {
private:
    vector<pair<int, int>> cache;
    int capacity;
public:
    LRUCache(int capacity) {
        this->capacity = capacity;
    }
    int get(int key) {
        cout << capacity << " " << cache.size() << " \n";
        for (int i = 0; i < cache.size(); i++) {
            if (cache[i].first == key) {
                int tempvalue = cache[i].second;
                cache.erase(cache.begin() + i);
                cache.push_back({key, tempvalue});
                return tempvalue;
            }
        }         
        return -1;
    }
    
    void put(int key, int value) {
        for (int i = 0; i < cache.size(); i++) {
            if (cache[i].first == key) {
                cache.erase(cache.begin() + i);
                cache.push_back({key, value});
                return;
            }
        }
        if (cache.size() == this->capacity) {
            cache.erase(cache.begin());
        }
        cache.push_back({key, value});
        return;
    }
};
