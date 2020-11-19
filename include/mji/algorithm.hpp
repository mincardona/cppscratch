#ifndef MJI_ALGORITHM_HPP_INCLUDED_
#define MJI_ALGORITHM_HPP_INCLUDED_

#include <algorithm>
#include <map>
#include <optional>
#include <unordered_map>

namespace mji {

// variants of find which always return a pointer instead of an iterator

template<typename InputIt, typename T>
constexpr T* find_get(InputIt first, InputIt last, const T& value) {
    auto iter = std::find(first, last, value);
    if (iter != last) {
        return &*iter;
    } else {
        return nullptr;
    }
}

template<typename Container, typename T>
constexpr T* find_get(Container container, const T& value) {
    auto last = container.end();
    auto iter = std::find(container.begin(), last, value);
    if (iter != last) {
        return &*iter;
    } else {
        return nullptr;
    }
}

// ...etc, for find_if, find_if_not, and the execution policy variants

/// Like map.at(), but returns a pointer to the value
/// TODO: const/non-const
template<typename Key, typename T, typename Compare, typename Allocator>
T* map_maybe_at(std::map<Key, T, Compare, Allocator> m, const Key& key) {
    auto iter = m.find(key);
    if (iter == m.end()) {
        return nullptr;
    } else {
        return &iter->second;
    }
}

/// Like unordered_map.at(), but returns a pointer to the value
/// TODO: const/non-const
template<typename Key, typename T, typename Hash, typename KeyEqual, typename Allocator>
T* map_maybe_at(std::unordered_map<Key, T, Hash, KeyEqual, Allocator> m, const Key& key) {
    auto iter = m.find(key);
    if (iter == m.end()) {
        return nullptr;
    } else {
        return &iter->second;
    }
}

/// like lisp cond
template<typename OutType>
constexpr OutType select_value(std::initializer_list<std::pair<bool, OutType>> list) {
    /*
    // example:
    constexpr int result = select_value<int>({
        {cond0, 0}, {cond1, 1}, {cond2, 2}, {cond3, 3}, {true, 0}
    });
    */

    for (auto& p : list) {
        if (p.first) {
            return p.second;
        }
    }
    throw std::logic_error("select_value has no true cond!");
}

// std::clamp variants

template<class T>
constexpr const T& clamp_low(const T& v, const T& lo) {
    return clamp_low<T, std::less<T>>(v, lo, std::less<T>());
}

template<class T, class Compare>
constexpr const T& clamp_low(const T& v, const T& lo, Compare comp) {
    if (comp(v, lo)) {
        return lo;
    } else {
        return v;
    }
}

template<class T>
constexpr const T& clamp_high(const T& v, const T& hi) {
    return clamp_high<T, std::less<T>>(v, hi, std::less<T>());
}

template<class T, class Compare>
constexpr const T& clamp_high(const T& v, const T& hi, Compare comp) {
    if (comp(v, hi)) {
        return v;
    } else {
        return hi;
    }
}

}  // namespace mji

#endif  // MJI_ALGORITHM_HPP_INCLUDED_
