//
// Created by 萧琛 on 2023/9/18.
//

#ifndef MY_PROJECT_NAME_LRUCACHE_H
#define MY_PROJECT_NAME_LRUCACHE_H
#include <list>
#include <unordered_map>
template<typename KeyType, typename ValueType>
class LRUCache {
  private:
    int cap_;
    std::list<std::pair<KeyType, ValueType>> cache_;
    std::unordered_map<KeyType, decltype(cache_.begin())> dict_;
  public:
    LRUCache(int capacity):cap_{capacity} {
    }
    ValueType get(KeyType key) {
        if (!dict_.count(key)) {
            return {};
        }
        cache_.splice(cache_.begin(), cache_, dict_[key]);
        return dict_[key]->second;
    }
    void put(KeyType key, ValueType value) {
        if (!dict_.count(key)) {
            if (cache_.size() == cap_) {
                dict_.erase(cache_.back().first);
                cache_.pop_back();
            }
            dict_[key] = cache_.emplace(cache_.begin(), key, value);
        } else {
            dict_[key]->second = value;
            cache_.splice(cache_.begin(), cache_, dict_[key]);
        }
    }
};
#endif // MY_PROJECT_NAME_LRUCACHE_H
