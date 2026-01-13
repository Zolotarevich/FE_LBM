#ifndef LBMSOLVER_HPP
#define LBMSOLVER_HPP

#include <iostream>
#include <vector>

class LBMSolver
{
public:
	LBMSolver();
	~LBMSolver();

	void CalculateMassFraction();
	void FieldsInitialization();


private:
	/*int numberOfCompmonents;

	std::vector<double> rho;
	std::vector<double> molarFraction;
	std::vector<double> massFraction;

	std::vector<double> ux;
	std::vector<double> uy;
	std::vector<double> uz;

	std::vector<double> pressure;
	std::vector<double> fugacity;
	std::vector<double> chemicalPotential;

	std::vector<double> gradientFugacityX;
	std::vector<double> gradientFugacityY;
	std::vector<double> gradientFugacityZ;
	std::vector<double> gradientChemicalPotentialX;
	std::vector<double> gradientChemicalPotentialY;
	std::vector<double> gradientChemicalPotentialZ;
	std::vector<double> gradientRhoX;
	std::vector<double> gradientRhoY;
	std::vector<double> gradientRhoZ;
	std::vector<double> laplasRhoX;
	std::vector<double> laplasRhoY;
	std::vector<double> laplasRhoZ;
	std::vector<double> gradientLaplasRhoX;
	std::vector<double> gradientLaplasRhoY;
	std::vector<double> gradientLaplasRhoZ;


	std::vector<double> forceX;
	std::vector<double> forceY;
	std::vector<double> forceZ;

	std::vector<double> f;*/
};

#endif 
