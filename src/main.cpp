#include "EuclideanGenerator.h" 
#include "WeeklyData.h"

#include <cstdlib>
#include <fstream>
#include <iostream>

#include <boost/program_options.hpp>

using namespace std;

boost::program_options::variables_map parseCommandline(int argc, char **argv) {
   namespace po = boost::program_options;
   po::options_description desc("Accepted generator options");
   desc.add_options()
      ("help,h", "shows this text")

      ("seed,s", po::value<int>()->default_value(1), "seed for the PRNG")

      ("config,c", po::value<string>(), "defines the configuration file to import the parameters for instance generation")

      ("days,d", po::value<int>()->default_value(-1), "overrides the planning horizon")
   ;

   po::variables_map vm;
   po::store(po::parse_command_line(argc, argv, desc), vm);
   po::notify(vm);

   if (vm.count("help") || !vm.count("config")) {
      cout << desc << "\n";
      exit(EXIT_FAILURE);
   }

   return vm;
}

int main(int argc, char* argv[]) {
   cout << "---------------------------------\n";
   cout << "Instance generator for the HHCRSP\n";
   cout << "---------------------------------\n";

   auto args = parseCommandline(argc, argv);
   const auto seed = args["seed"].as<int>();
   const auto configFile = args["config"].as<string>();
   const auto overrideDays = args["days"].as<int>();

   cout << "PRNG seed: " << seed << "\n";
   cout << "Configuration file: " << configFile << "\n";
   cout << "Override of number of days: ";
   if (overrideDays != -1) {
      cout << overrideDays << " day(s)\n";
   } else {
      cout << "override disabled\n";
   }

   mt19937 rng(seed);
   auto locGen = EuclideanGenerator(rng, 100, 100);

   auto params = GeneratorParameters(rng, locGen);
   auto instGen = WeeklyData(params);

   instGen.generateData();
   instGen.writeDailyData(0);
   
   return EXIT_SUCCESS;
}

