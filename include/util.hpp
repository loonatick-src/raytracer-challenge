#ifndef RTC_UTIL
#define RTC_UTIL

#include "tuple.hpp"

using rtc::tuple;

namespace rtc {
    template <typename T>
    bool is_point(const tuple<T> &t) {
        return t.w() == static_cast<T>(1);
    }

    template <typename T>
    bool is_vector(const tuple<T> &t) {
        return t.w() == static_cast<T>(0);
    }
};

#endif
