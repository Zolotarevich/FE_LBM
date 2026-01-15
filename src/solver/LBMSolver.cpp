#include "LBMSolver.hpp"

LBMSolver::LBMSolver() {}

LBMSolver::~LBMSolver() {}

void LBMSolver::step() {}

void LBMSolver::run() {}

void LBMSolver::CalculateMassFraction() {
	std::vector<double> massOfComponentsInLiquidPhase(numComponents);
	std::vector<double> massOfComponentsInGasPhase(numComponents);
	double sumMassOfComponentsInLiquidPhase = 0;
	double sumMassOfComponentsInGasPhase = 0;

	for (int i = 0; i < numComponents; i++) {
		massOfComponentsInLiquidPhase[i] = parameters.mixture.allMoleLiquid * parameters.mixture.moleFractionsInLiquidPhase[i] / 100.;
		massOfComponentsInGasPhase[i] = parameters.mixture.allMoleGas * parameters.mixture.moleFractionsInGasPhase[i] / 100.;

	}

	for (int i = 0; i < numComponents; i++) {
		massOfComponentsInLiquidPhase[i] *= components[mix[i]].mu;
		sumMassOfComponentsInLiquidPhase += massOfComponentsInLiquidPhase[i];

		massOfComponentsInGasPhase[i] *= components[mix[i]].mu;
		sumMassOfComponentsInGasPhase += massOfComponentsInGasPhase[i];

	}

	for (int i = 0; i < numComponents; i++) {
		parameters.mixture.massFractionsInLiquidPhase[i] = massOfComponentsInLiquidPhase[i] / sumMassOfComponentsInLiquidPhase;
		parameters.mixture.massFractionsInGasPhase[i] = massOfComponentsInGasPhase[i] / sumMassOfComponentsInGasPhase;

		/*std::cout << "massFractionLiquid(" << mix[i] << ") = " << massFractionLiquid[i] << std::endl;
		std::cout << "massFractionGas(" << mix[i] << ") = " << massFractionGas[i] << std::endl;*/
	}
}

void LBMSolver::Initialization(const CaseConfig& cfg) {
	parameters.thermo.temperature = cfg.temperature;
	parameters.mixture = cfg.mixture;

	grid = Grid(cfg.nx, cfg.ny, cfg.nz);

	fields = Fields(parameters.mixture.numberOfComponents, 9, grid);
}
