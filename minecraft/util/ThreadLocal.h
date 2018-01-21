#pragma once

#include <functional>
#include <vector>
#include <mutex>
#include <pthread.h>

template <typename T>
class ThreadLocal {
public:
    std::function<std::unique_ptr<T> ()> func; // 10
    std::vector<std::unique_ptr<T>> vec; // 1C
    std::mutex mutex; // 20
    bool hasKey = false; // 24
    pthread_key_t key; // 28


    ThreadLocal(std::function<std::unique_ptr<T> ()> const& func) : func(func) {
        if (pthread_key_create(&key, [](void* p) { delete p; }) == 0)
            hasKey = true;
        if (!hasKey)
            throw std::runtime_error("Can't allocate a new Thread Local");
    }
    ~ThreadLocal() {
        if (hasKey)
            pthread_key_delete(key);
    }
    ThreadLocal& operator=(ThreadLocal&& loc) {
        std::unique_lock<std::mutex> lock (loc.mutex);
        func = std::move(loc.func);
        vec = std::move(loc.vec);
        key = std::move(loc.key);
        hasKey = loc.hasKey;
        loc.hasKey = false;
    }
};