#ifndef RTC_POINT
#define RTC_POINT

#include "tuple.hpp"

namespace rtc {
    template <typename T>
    class point : public tuple<T> {
        public:
            point(T x, T y, T z, T w) = delete;
            point(T x, T y, T z) : tuple<T>(x, y, z, static_cast<T>(1)) {}

            T& w() = delete;
    };

    template <typename T>
    bool operator==(const point<T> &p1, const point<T> &p2) {
        return p1.x() == p2.x()
            && p1.y() == p2.y()
            && p1.z() == p2.z();
    }
};

#endif
