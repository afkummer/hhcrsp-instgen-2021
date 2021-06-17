#pragma once

#include "LocationGeneratorI.h"

#include <random>

class EuclideanGenerator: public LocationGeneratorI {
public:
   EuclideanGenerator(std::mt19937 &rng, int xRegioLen, int yRegionLen);
   virtual ~EuclideanGenerator();

   virtual Point generatePoint() override;
   virtual double travelTimeMinutes(const Point &from, const Point &to) override;

  private:
   std::mt19937 &m_rng;
   const int m_xLen;
   const int m_yLen;

   std::uniform_int_distribution <int> m_xDist;
   std::uniform_int_distribution <int> m_yDist;
};