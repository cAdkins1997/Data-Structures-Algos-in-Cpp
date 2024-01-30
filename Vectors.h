
#ifndef DATASTRUCTURESCPP_VECTORS_H
#define DATASTRUCTURESCPP_VECTORS_H

#include <concepts>

namespace wstd {

    template<typename T>
    requires std::is_arithmetic_v<T>
    struct Vec3 {
        T x, y, z;

        Vec3() = default;

        Vec3(T _x, T _y, T _z) : x(_x), y(_y), z(_z) {};
        explicit Vec3(T _x) : x(_x), y(_x), z(_x) {};

        T magnitude() {
            return x * x + y * y + z * z;
        }

        friend std::ostream& operator << (std::ostream& ostream, const Vec3<T>& vec) {
            ostream << vec.x << ' ' << vec.y << ' ' << vec.z;
            return ostream;
        }

    };
}

#endif //DATASTRUCTURESCPP_VECTORS_H
