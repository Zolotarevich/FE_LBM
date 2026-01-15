#ifndef LBMSOLVER_HPP
#define LBMSOLVER_HPP

#include <iostream>
#include <vector>

#include "../src/core/Fields.hpp"
#include "../src/core/Parameters.hpp"
#include "../src/core/Grid.hpp"

class LBMSolver
{
public:
	LBMSolver();
	~LBMSolver();

	void step();
	void run();

private:
	int numComponents = 0;
	Grid grid;
	Parameters parameters;
	Mixture mixture;
	Fields fields;

	std::vector<double> rhoCritical;
	std::vector<double> rhoCriticalHat;
	std::vector<double> temperatureCritical;
	std::vector<double> temperatureCriticalHat;
	std::vector<double> pressureCritical;
	std::vector<double> pressureCriticalHat;
	std::vector<double> mu;
	std::vector<double> muHat;
	std::vector<double> omega;
	std::vector<double> kappaHat;

	void CalculateMassFraction();
	void Initialization(const CaseConfig& cfg);
	
};

#endif 
