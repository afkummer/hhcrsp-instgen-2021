#pragma once

#include "LocationGeneratorI.h"

#include <iosfwd>
#include <random>

class GeneratorParameters {
public:
   GeneratorParameters(std::mt19937 &rng, LocationGeneratorI &locGen);
   virtual ~GeneratorParameters();

   std::mt19937 &prng();
   LocationGeneratorI &locationGenerator();

   void importParams(std::istream &&fid);
   void exportParams(std::ostream &&out);

   int numDays() const;
   int numCaregivers() const;
   int numDailyPatients() const;
   int numSkills() const;

   double simultaneousDoubleServicesPerc() const;
   double precedenceDoubleServicesPerc() const;

   int maxSkillsPerCaregiver() const;

   int minPatientsPerSkillUnit() const;
   int maxPatientsPerSkillUnit() const;

   int dayStartingMinutes() const;
   int dayEndingMinutes() const;
   
   int twDurationMinutes() const;

   int minProcTime() const;
   int maxProcTime() const;

   int minSeparation() const;
   int maxSeparation() const;
   int minDynamicTwDurationMinutes() const;

  private:
   std::mt19937 &m_rng;
   LocationGeneratorI &m_locGen;

   int m_numDays;
   int m_numCaregivers;
   int m_numDailyPatients; 
   int m_numSkills;
};
