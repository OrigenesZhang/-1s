#include <cmath>
#include <cstdlib>
struct Vector{
    int x, y, z;
    Vector operator + (const Vector& b) const{
        Vector c;
        c.x=x+b.x;
        c.y=y+b.y;
        c.z=z+b.z;
        return c;
    }
    Vector operator - (const Vector &b) const{
        Vector c;
        c.x=x-b.x;
        c.y=y-b.y;
        c.z=z-b.z;
        return c;
    }
    bool operator == (const Vector& b) const{
        return x==b.x&&y==b.y&&z==b.z;
    }
    inline Vector num_mult(int k){
        return {x*k, y*k, z*k};
    }
    inline double mod(){
        return sqrt(x*x+y*y+z*z);
    }
};
inline Vector cross_product(Vector v1, Vector v2){
    return {v1.x*v2.y-v2.x*v1.y, -v1.x*v2.z+v2.x*v1.z, v1.y*v2.z-v2.y*v1.z};
}
inline int dot_product(Vector v1, Vector v2){
    return v1.x*v2.x+v1.y*v2.y+v1.z*v2.z;
}