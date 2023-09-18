//
// Created by 萧琛 on 2023/9/18.
//
#include <string>
#include <iostream>
#include "LRUCache.h"

int main() {
    LRUCache<int, std::string> lru(2);
    lru.put(1, "One");
    lru.put(2, "Two");
    std::cout << lru.get(1) << std::endl; // 输出 "One"
    lru.put(3, "Three");
    std::cout << lru.get(2) << std::endl; // 输出空字符串
    lru.put(4, "Four");
    std::cout << lru.get(1) << std::endl; // 输出空字符串
    std::cout << lru.get(3) << std::endl; // 输出 "Three"
    std::cout << lru.get(4) << std::endl; // 输出 "Four"
    std::cout << lru.get(7) << std::endl; // 输出 ""

    return 0;
}


