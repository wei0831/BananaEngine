/******************************************************************************/
/*!
\file   Vec2.h
\author Jack Chang
\date   10/09/2014
\par    All content 2014 DigiPen (USA) Corporation, all rights reserved.
\brief

*/
/******************************************************************************/
#pragma once 

#include "MathIncludes.h"
#include <cereal/archives/json.hpp>

struct Vec2
{
  Vec2() {}
  Vec2(float x_, float y_) : x(x_), y(y_) {}
  
  void SetZero() { x = 0.0f; y = 0.0f; }

  void Set(float x_, float y_) { x = x_; y = y_; }

  Vec2 operator- () { Vec2 v; v.Set(-x, -y); return v; }
  Vec2 operator- () const { Vec2 v; v.Set(-x, -y); return v; }
  void operator+= (const Vec2& v) { x += v.x; y += v.y; }
  void operator-= (const Vec2& v) { x -= v.x; y -= v.y; }
  void operator*= (float a) { x *= a; y *= a; }

  float Length() const { return sqrtf(x*x + y*y); }
  float LengthSquared() const { return x* x + y*y; }
  float Normalize()
  {
    float length = this->Length();
    if (length < EPSILON) return 0.0f;

    float invLength = 1.0f / length;
    x *= invLength;
    y *= invLength;

    return length;
  }

  float DotProduct(const Vec2& v) const { return x * v.x + y * v.y; }
  float Cross(const Vec2& v) const { return x * v.y - y * v.x; }
  void FromAngleDeg(float angle)
  {
    x = cosf(angle * PI / 180.0f);
    y = sinf(angle * PI / 180.0f);
  }
  void FromAngleRad(float angle)
  {
    x = cosf(angle);
    y = sinf(angle);
  }

  float Distance(const Vec2& v) const
  {
    return sqrtf(SquareDistance(v));
  }

  float SquareDistance(const Vec2& v) const
  {
    return (v.x - x)*(v.x - x) + (v.y - y)*(v.y - y);
  }

  float x;
  float y;

  template <class Archive>
  void serialize(Archive & ar)
  {
    ar(CEREAL_NVP(x), CEREAL_NVP(y));
  }
};


inline float Vec2DDot(const Vec2& a, const Vec2& b)
{
  return a.x * b.x + a.y * b.y;
}

inline float Vec2DCross(const Vec2& a, const Vec2& b)
{
  return a.x * b.y - a.y * b.x;
}

inline std::ostream& operator<<(std::ostream& os, const Vec2& v)
{
  return os << "Vec2: (" << v.x << ", " << v.y << ")" << std::endl;
}

inline Vec2 operator + (const Vec2& a, const Vec2& b)
{
  return Vec2(a.x + b.x, b.x + b.y);
}

inline Vec2 operator - (const Vec2& a, const Vec2& b)
{
  return Vec2(a.x - b.x, b.x - b.y);
}

inline Vec2 operator* (float s, const Vec2& a)
{
  return Vec2(s * a.x, s * a.y);
}

inline bool operator== (const Vec2& a, const Vec2& b)
{
  return a.x == b.x && a.y == b.y;
}

inline float Vec2DDistance(const Vec2& a, const Vec2& b)
{
  Vec2 c = a - b;
  return c.Length();
}

inline float Vec2DDistanceSquared(const Vec2& a, const Vec2& b)
{
  Vec2 c = a - b;
  return Vec2DDot(c, c);
}

inline Vec2 Vec2DNormalVector(const Vec2& a, const Vec2& b)
{
  float dx = b.x - a.x;
  float dy = b.y - a.y;
  Vec2 result = Vec2(-dy, dx);
  result.Normalize();
  return result;
}
