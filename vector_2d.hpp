#ifndef _VECTOR2D_
#define _VECTOR2D_

#include <iostream>
#include <cmath>

class Vector2D {
  public:
    static constexpr double RAD2DEG = 180/M_PI;
    static constexpr double DEG2RAD = M_PI/180;
    double x;
    double y;

    //constructor
    Vector2D() : x(0.0), y(0.0) { }
    //constructor
    Vector2D(const double & xx, const double & yy) : x(xx), y(yy) { }
    //inline
    Vector2D & assign(const double & xx, const double & yy)
    {
      x = xx;
      y = yy;
      return *this;
    }

    double abs() const
    {
      return sqrt( r2() );
    }

    double r2() const
    {
      return (x*x) + (y*y);
    }

    double r() const
    {
      return sqrt( r2() );
    }

    double r3() const
    {
      return ( r() * r() * r() );
    }

    Vector2D & setPolar(const double radius, const double angle)
    {
      x = radius * std::cos(angle);
      y = radius * std::sin(angle);
      
      return *this;
    }

    void print()
    {
      std::cout << "(x, y) = " << x << ", " << y << std::endl;
    }

    void rotateVector(const double angle)
    {
      double xx = x * cos(angle) - y * sin(angle);
      double yy = x * sin(angle) + y * cos(angle);

      x = xx;
      y = yy;
    }

    Vector2D normalize() const
    {
      Vector2D vec;
      vec = *this;
      vec /= r();
      return vec;
    }

    double innerProduct(Vector2D v) const
    {
      return ( (x * v.x) + (y * v.y) );
    }

    double outerProduct(Vector2D v) const
    {
      return ( (x * v.y) - (y * v.x) );
    }

    double radians() const
    {
      return atan2(y, x);
    }

    double degrees() const
    {
      return ( atan2(y, x) * RAD2DEG );
    }

    Vector2D rel_pos(const Vector2D origin)
    {
      Vector2D rel;

      rel.x = x - origin.x;
      rel.y = y - origin.y;

      return rel;
    }

    Vector2D unitRelPos(const Vector2D origin)
    {
      Vector2D unit = rel_pos(origin);
      return unit / unit.r();
    }


    /*
       operator overload
    */

    Vector2D & operator += (const Vector2D & v)
    {
      x += v.x;
      y += v.y;
      return *this;
    }

    Vector2D & operator + (const Vector2D & v)
    {
      x += v.x;
      y += v.y;
      return *this;
    }

    Vector2D & operator -= (const Vector2D & v)
    {
      x -= v.x;
      y -= v.y;
      return *this;
    }

    Vector2D operator - (const Vector2D & v)
    {
      x = x - v.x;
      y = y - v.y;
      return *this;
    }

    Vector2D operator *= (const double & a)
    {
      x *= a;
      y *= a;
      return *this;
    }

    Vector2D operator * (const double a)
    {
      x *= a;
      y *= a;
      return *this;
    }

    Vector2D operator /= (const double & a)
    {
      x /= a;
      y /= a;
      return *this;
    }

    Vector2D operator / (const double & a)
    {
      x /= a;
      y /= a;
      return *this;
    }
    
    Vector2D operator = (const Vector2D & v)
    {
      x = v.x;
      y = v.y;
      return *this;
    }

};

#endif //_VECTOR2D_
