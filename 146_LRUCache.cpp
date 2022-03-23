class LRUCache {
public:
    LRUCache(int capacity) {
        capacity_ = capacity;

    }

    int get(int key) {
        auto it = map_.find(key);
        if (it == map_.end())
            return -1;
        cache_.splice(cache_.begin(), cache_, it->second);
        return it->second->second;
    }

    void put(int key, int value) {
        auto it = map_.find(key);
        if (it != map_.end()) {
            cache_.splice(cache_.begin(), cache_, it->second);
            it->second->second = value;
            return;
        }
        if (cache_.size() == capacity_) {
            map_.erase(cache_.back().first);
            cache_.pop_back();
        }
        cache_.emplace_front(key, value);
        map_[key] = cache_.begin();
    }

private:
    int capacity_;
    list<pair<int, int>> cache_;
    unordered_map<int, list<pair<int, int>>::iterator> map_;
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */