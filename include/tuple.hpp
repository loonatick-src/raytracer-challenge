#ifndef RTC_TUPLE
#define RTC_TUPLE

namespace rtc {
    // classes
    template <typename T>
    class tuple {
    public:
        tuple(T x, T y, T z, T w) : buf {x, y, z, w} {};
        tuple(T t[4]) : buf { t[0], t[1], t[2], t[3] } {};
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

        tuple<T> operator-() const {
            return tuple<T>(-buf[0], -buf[1], -buf[2], -buf[3]);
        }

        tuple<T> operator*(const T a) const {
            return tuple<T>(a*buf[0], a*buf[1], a*buf[2], a*buf[3]);
        }

        tuple<T> operator/(const T a) const {
            return (*this) * (static_cast<T>(1)/a);
        }

        template <typename T1>
        friend tuple<T1> operator+(const tuple<T1>& t1, const tuple<T1> &t2);

        template <typename T1>
        friend tuple<T1> operator-(const tuple<T1>& t1, const tuple<T1> &t2);

        template <typename T1>
        friend T1 dot(const tuple<T1>& t1, const tuple<T1>& t2);
    private:
        // TODO: use std::array<T, 4> instead?
        T buf[4];
    };
    
    template <typename T>
    T dot(const tuple<T> &t1, const tuple<T> &t2) {
        T acc = static_cast<T>(0);
        for (int i = 0; i < 4; i++) {
            acc += t1.buf[i] * t2.buf[i];
        }
        return acc;
    }

    template <typename T>
    class vector : public tuple<T> {
    public:
        vector(T x, T y, T z, T w) = delete;
        vector(T x, T y, T z) : tuple<T>(x, y, z, static_cast<T>(0)) {};

        T& w() = delete;
    };

    template <typename T>
    class point : public tuple<T> {
        public:
            point(T x, T y, T z, T w) = delete;
            point(T x, T y, T z) : tuple<T>(x, y, z, static_cast<T>(1)) {}

            T& w() = delete;

            // cannot add two points
            point<T> operator+(const point<T> &p) = delete;
    };

    template <typename T>
    bool operator==(const point<T> &p1, const point<T> &p2) {
        return p1.x() == p2.x()
            && p1.y() == p2.y()
            && p1.z() == p2.z();
    }


    template <typename T>
    bool operator==(const vector<T> &v1, const vector<T> &v2) {
        return v1.x() == v2.x()
            && v1.y() == v2.y()
            && v1.z() == v2.z();
    }

    template <typename T>
    bool operator==(const tuple<T> &t1, const tuple<T> &t2) {
        return t1.x() == t2.x()
            && t1.y() == t2.y()
            && t1.z() == t2.z()
            && t1.w() == t2.w();
    }

    // do we really need this?
    template <typename T>
    tuple<T> operator+(const tuple<T> &t1, const tuple<T> &t2) {
        T buf[4];
        for (int i = 0; i < 4; i++) {
            buf[i] += t1.buf[i] + t2.buf[i];
        }
        return tuple<T>(buf);
    }

    template <typename T>
    tuple<T> operator-(const tuple<T> &t1, const tuple<T> &t2) {
        T buf[4];
        for (int i = 0; i < 4; i++) {
            buf[i] = t1.buf[i] - t2.buf[i];
        }
        return tuple<T>(buf);
    }
    
    // TODO: create vector and point constructors from tuple<T>
    template <typename T>
    vector<T> cross(const vector<T> &a, const vector<T> &b) {
        return vector<T>(a.y() * b.z() - a.z() * b.y(),
                         a.z() * b.x() - a.x() * b.z(),
                         a.x() * b.y() - a.y() * b.x());
    }
};
#endif
