//
// Created by Steph on 11/3/2025.
//

#include "TreeMap.h"

void TreeMap::insert(const std::string& key, const std::string& value) {
    KeyValuePair<std::string, std::string> map(key, value);
    Tree.insert(map);
}

std::string TreeMap::get(const std::string& key) {
    KeyValuePair<std::string, std::string> map(key, "");
    Tree.search(map);

    auto root = Tree.getRoot();
    if (root == nullptr)
        return "Key not found";

    if (root->key.getKey() == key)
        return root->key.getValue();
    else
        return "Key not found";
}

std::string TreeMap::deleteKey(const std::string& key) {
    KeyValuePair<std::string, std::string> map(key, "");
    Tree.search(map);

    auto root = Tree.getRoot();
    if (root == nullptr || root->key.getKey() != key)
        return "Key not found";

    std::string value = root->key.getValue();
    Tree.remove(map);

    return value;
}
