//
// Created by Steph on 11/3/2025.
//

#ifndef MAP_H
#define MAP_H
#include <string>

template<typename TK, typename TV>
class KeyValuePair {
private:
    TK key;
    TV value;

public:
    KeyValuePair() : key(), value() {}
    KeyValuePair(TK key, TV value) : key(key), value(value) {}

    void setKey(TK key) { this->key = key; }
    TK getKey() { return key; }

    void setValue(TV value) { this->value = value; }
    TV getValue() { return value; }

    bool operator>(const KeyValuePair<TK, TV>& other) const {
        return key > other.key;
    }

    bool operator<(const KeyValuePair<TK, TV>& other) const {
        return key < other.key;
    }

    bool operator>=(const KeyValuePair<TK, TV>& other) const {
        return key >= other.key;
    }

    bool operator<=(const KeyValuePair<TK, TV>& other) const {
        return key <= other.key;
    }

    bool operator==(const KeyValuePair<TK, TV>& other) const {
        return key == other.key;
    }

    bool operator!=(const KeyValuePair<TK, TV>& other) const {
        return key != other.key;
    }

};
#endif //MAP_H
