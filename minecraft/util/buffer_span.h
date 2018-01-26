#pragma once

#include <cstddef>

template <typename T>
struct buffer_span {
    T* ptr;
    size_t len;
};