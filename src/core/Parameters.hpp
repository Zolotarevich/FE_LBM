#pragma once
#include <vector>
#include <string>

struct Component {
    std::string name;

    double Tc;     
    double Pc;     
    double omega;  
    double mu;
    double kappa;
};

struct Mixture {
    std::vector<Component> components;
    std::vector<double> moleFractions;
    std::vector<double> moleFractionsInLiquidPhase;
    std::vector<double> moleFractionsInGasPhase;
    std::vector<double> massFractions;
    std::vector<double> massFractionsInLiquidPhase;
    std::vector<double> massFractionsInGasPhase;
    std::vector<double> viscosities;
    double Sv;
    double rhoLiquid;
    double rhoGas;
    double allMoleLiquid;
    double allMoleGas;
};

struct DimensionlessCriticalParams {
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

};

struct LBMParams {
    double dt = 1.0;
    double dx = 1.0;

    double deltaX;

    double teta = 1.0 / 3.0 * dx * dx / dt / dt;
    double tau = 1.0;

    double D = 2.;
    double W = 8.;
    double g = 0; // gravitational acceleration
};

struct FreeEnergyParams {
    double kappa;     // gradient energy coefficient
};

struct ThermoParams {
    double temperature;
};

struct Parameters {
    LBMParams lbm;
    FreeEnergyParams fe;
    ThermoParams thermo;
    Mixture mixture;
};