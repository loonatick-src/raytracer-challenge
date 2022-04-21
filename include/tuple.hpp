#ifndef RTC_TUPLE
#define RTC_TUPLE

namespace rtc {
    template <typename T>
    class tuple {
    public:
        tuple(T x, T y, T z, T w) : buf {x, y, z, w} {};
        tuple() : buf {{0}} {};

        // TODO: force inline?
        T& x() { return buf[0]; }
        T& y() { return buf[1]; }
        T& z() { return buf[2]; }
        T& w() { return buf[3]; }
        const T& x() const { return buf[0]; }
        const T& y() const { return buf[1]; }
        const T& z() const { return buf[2]; }
        const T& w() const { return buf[3]; }


    private:
        T buf[4];
    };

    template <typename T>
    bool operator==(const tuple<T> &t1, const tuple<T> &t2) {
        return t1.x() == t2.x()
            && t1.y() == t2.y()
            && t1.z() == t2.z()
            && t1.w() == t2.w();
    }
};
#endif
