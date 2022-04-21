#ifndef RTC_VECTOR
#define RTC_VECTOR

#include "tuple.hpp"

namespace rtc {
    template <typename T>
    class vector : public tuple<T> {
    public:
        vector(T x, T y, T z, T w) = delete;
        vector(T x, T y, T z) : tuple<T>(x, y, z, static_cast<T>(0)) {};

        T& w() = delete;
    };

    template <typename T>
    bool operator==(const vector<T> &v1, const vector<T> &v2) {
        return v1.x() == v2.x()
            && v1.y() == v2.y()
            && v1.z() == v2.z();
    }
};
#endif
