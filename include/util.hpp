#ifndef RTC_UTIL
#define RTC_UTIL

#include "tuple.hpp"

#include <cmath>

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

    // TODO: consider moving this to tuple.hpp
    // template <typename T>
    // T magnitude(const tuple<T> &t) {
    //     return sqrtf(t.x() * t.x() + t.y() * t.y() + t.z() * t.z() + t.w() * t.w());
    // }

    template <typename T>
    T magnitude(const vector<T> &t) {
        return sqrt(t.x() * t.x() + t.y() * t.y() + t.z() * t.z());
    }

    bool approx_eqf(const float t1, const float t2, const float eps) {
        return fabs(t1 - t2) < eps;
    }

    // template <typename T>
    // tuple<T> normalize(const tuple<T> &t) {
    //     const auto m = magnitude(t);
    //     return tuple<T>(t.x()/m, t.y()/m, t.z()/m, t.w()/m);
    // }
    
    template <typename T>
    vector<T> normalize(const vector<T> &t) {
        const auto m = magnitude(t);
        return vector<T>(t.x()/m, t.y()/m, t.z()/m);
    }

    template <typename T>
    void normalize_inplace(vector<T> &t) {
        const auto m = magnitude(t);
        t.x() /= m;
        t.y() /= m;
        t.z() /= m;
    }
} // namespace rtc
#endif
