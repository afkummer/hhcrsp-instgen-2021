#include "EuclideanGenerator.h"

#include <cmath>

using namespace std;

EuclideanGenerator::EuclideanGenerator(std::mt19937 &rng, int xRegioLen, int yRegionLen):
   m_rng(rng), m_xLen(xRegioLen), m_yLen(yRegionLen), m_xDist(1, m_xLen), m_yDist(1, m_yLen) {
   
   // Empty.
}

EuclideanGenerator::~EuclideanGenerator() {
   // Empty
}

EuclideanGenerator::Point EuclideanGenerator::generatePoint() {
   return {m_xDist(m_rng), m_yDist(m_rng)};
}

double EuclideanGenerator::travelTimeMinutes(const Point &from, const Point &to) {
   auto dx = get<0>(from) - get<0>(to);
   auto dy = get<1>(from) - get<1>(to);
   return sqrt(pow(dx, 2) + pow(dy, 2));
}
