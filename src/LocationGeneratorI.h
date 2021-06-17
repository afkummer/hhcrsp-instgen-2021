#pragma once

#include <tuple>

class LocationGeneratorI {
public:
   using Point = std::tuple <double, double>;

   virtual Point generatePoint() = 0;

   virtual double travelTimeMinutes(const Point &from, const Point &to) = 0;
};
