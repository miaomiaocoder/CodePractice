/*
 * @lc app=leetcode.cn id=146 lang=cpp
 *
 * [146] LRU 缓存
 */

// @lc code=start
// 靠近尾部的键值对是最近使用的
class LRUCache {
    int capacity_;
    std::list<int> keyList_;
    std::unordered_map<int, std::pair<int, std::list<int>::iterator>> hashMap_;
    void insert(int key, int value) {
        keyList_.push_back(key);
        hashMap_[key] = make_pair(value, --keyList_.end());
    }

   public:
    LRUCache(int capacity) : capacity_(capacity) {}

    int get(int key) {
        auto it = hashMap_.find(key);
        if (it != hashMap_.end()) {
            keyList_.erase(it->second.second);
            keyList_.push_back(key);
            hashMap_[key].second = (--keyList_.end());
            return it->second.first;
        }
        return -1;
    }

    void put(int key, int value) {
        if (get(key) != -1) {
            hashMap_[key].first = value;
            return;
        }
        if (hashMap_.size() < capacity_) {
            insert(key, value);
        } else {
            int removeKey = keyList_.front();
            keyList_.pop_front();
            hashMap_.erase(removeKey);

            insert(key, value);
        }
    }
};

class LRUCache {
    int capacity_;
    std::list<int> keyList_;
    std::unordered_map<int, std::pair<int, std::list<int>::iterator>> hashMap_;
    void insert(int key, int value) {
        keyList_.emplace_back(key);
        hashMap_[key] = make_pair(value, --keyList_.end());
    }

   public:
    LRUCache(int capacity) : capacity_(capacity) {}

    int get(int key) {
        auto it = hashMap_.find(key);
        if (it != hashMap_.end()) {
            keyList_.erase(it->second.second);
            insert(key, it->second.first);
            return it->second.first;
        }
        return -1;
    }

    void put(int key, int value) {
        if (get(key) != -1) {
            hashMap_[key].first = value;
            return;
        }

        if (hashMap_.size() < capacity_) {
            insert(key, value);
        } else {
            int removeKey = keyList_.front();
            keyList_.pop_front();
            hashMap_.erase(removeKey);

            insert(key, value);
        }
    }
};
/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */
// @lc code=end
