//
// Created by Steph on 11/3/2025.
//

#ifndef TREEMAP_H
#define TREEMAP_H
#include "BinarySearchTree.h"
#include "Map.h"

class TreeMap {
    SplayTree<KeyValuePair<std::string, std::string>> Tree;
public:
    TreeMap() : Tree() {}

    void insert(const std::string& key, const std::string& value);

    std::string get(const std::string& key);

    std::string deleteKey(const std::string& key);
};

#endif //TREEMAP_H
