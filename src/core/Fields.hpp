#pragma once
#include <vector>
#include <cassert>

#include "Grid.hpp"

class ScalarField {
public:
    ScalarField() = default;
    ScalarField(const Grid& g)
        : grid(g), data(g.size(), 0.0) {
    }

    ScalarField& operator=(const ScalarField& other) {
        if (this != &other) {
			data = other.data;
        }
		return *this;
	}

    inline double& operator()(int i, int j, int k = 0) {
        return data[grid.index(i, j, k)];
    }

private:
    const Grid& grid;
    std::vector<double> data;
};

class MultiScalarField {
public:
    MultiScalarField() = default;
    MultiScalarField(int n, const Grid& g)
        : grid(g), numOfComp(n), data(n * g.size(), 0.0) {
    }

    MultiScalarField& operator=(const MultiScalarField& other) {
        if (this != &other) {
            data = other.data;
        }
        return *this;
    }

    inline double& operator()(int n, int i, int j, int k = 0) {
        return data[n * grid.size() + grid.index(i, j, k)];
    }

private:
    const Grid& grid;
    int numOfComp;
    std::vector<double> data;
};


class VectorField {
public:
    VectorField() = default;
    VectorField(const Grid& g)
        : x(g), y(g), z(g) {
    }

    ScalarField x, y, z;
};

class MultiVectorField {
public:
    MultiVectorField() = default;
    MultiVectorField(int nComp, const Grid& g)
        : grid(g), N(nComp),
        x(nComp, g), y(nComp, g), z(nComp, g) {
    }

    MultiVectorField& operator=(const MultiVectorField& other) {
        if (this != &other) {
            x = other.x;
            y = other.y;
            z = other.z;
        }
        return *this;
    }

    inline double& x_comp(int n, int i, int j, int k = 0) {
        return x(n, i, j, k);
    }

    inline double& y_comp(int n, int i, int j, int k = 0) {
        return y(n, i, j, k);
    }

    inline double& z_comp(int n, int i, int j, int k = 0) {
        return z(n, i, j, k);
    }

private:
    const Grid& grid;
    int N;

    MultiScalarField x, y, z;
};

class DistributionField {
public:
    DistributionField() = default;
    DistributionField(int q, int n, const Grid& g)
        : grid(g), numOfComp(n), Q(q), data(n * g.size() * q, 0.0) {
    }

    DistributionField& operator=(const DistributionField& other) {
        if (this != &other) {
            data = other.data;
        }
        return *this;
    }

    inline double& operator()(int n, int q, int i, int j, int k) {
        return data[n * grid.size() * Q + q + Q * grid.index(i, j, k)];
    }

private:
    const Grid& grid;
    int Q;
    int numOfComp;
    std::vector<double> data;
};


struct Fields {
    ScalarField pressure;

    MultiScalarField rho;
    MultiScalarField molarFraction;
    MultiScalarField massFraction;
    
    MultiScalarField chemicalPotential;
    MultiScalarField fugacity;
    MultiScalarField laplasRho;
    
    VectorField u;
    MultiVectorField force;
    MultiScalarField gradientFugacityX;
    MultiScalarField gradientFugacityY;
    MultiScalarField gradientFugacityZ;
    MultiScalarField gradientChemicalPotentialX;
    MultiScalarField gradientChemicalPotentialY;
    MultiScalarField gradientChemicalPotentialZ;
    MultiScalarField gradientRhoX;
    MultiScalarField gradientRhoY;
    MultiScalarField gradientRhoZ;
    MultiScalarField gradientLaplasRhoX;
    MultiScalarField gradientLaplasRhoY;
    MultiScalarField gradientLaplasRhoZ;

    DistributionField f;
    DistributionField feq;

    Fields() = default;

    Fields(int numOfComp, int q, Grid& g) : pressure(g),
        rho(numOfComp, g), molarFraction(numOfComp, g), massFraction(numOfComp, g),
		chemicalPotential(numOfComp, g), fugacity(numOfComp, g), laplasRho(numOfComp, g),
        u(g), force(numOfComp, g),
		gradientFugacityX(numOfComp, g), gradientFugacityY(numOfComp, g), gradientFugacityZ(numOfComp, g),
		gradientChemicalPotentialX(numOfComp, g), gradientChemicalPotentialY(numOfComp, g), gradientChemicalPotentialZ(numOfComp, g),
		gradientRhoX(numOfComp, g), gradientRhoY(numOfComp, g), gradientRhoZ(numOfComp, g),
		gradientLaplasRhoX(numOfComp, g), gradientLaplasRhoY(numOfComp, g), gradientLaplasRhoZ(numOfComp, g),
        f(numOfComp, q, g),
        feq(numOfComp, q, g) {
    }

    Fields& operator=(const Fields& other) {
        if (this != &other) {
            pressure = other.pressure;
            rho = other.rho;
            molarFraction = other.molarFraction;
            massFraction = other.massFraction;
            chemicalPotential = other.chemicalPotential;
            fugacity = other.fugacity;
            laplasRho = other.laplasRho;
            u = other.u;
            force = other.force;
            gradientFugacityX = other.gradientFugacityX;
            gradientFugacityY = other.gradientFugacityY;
            gradientFugacityZ = other.gradientFugacityZ;
            gradientChemicalPotentialX = other.gradientChemicalPotentialX;
            gradientChemicalPotentialY = other.gradientChemicalPotentialY;
            gradientChemicalPotentialZ = other.gradientChemicalPotentialZ;
            gradientRhoX = other.gradientRhoX;
            gradientRhoY = other.gradientRhoY;
            gradientRhoZ = other.gradientRhoZ;
            gradientLaplasRhoX = other.gradientLaplasRhoX;
			gradientLaplasRhoY = other.gradientLaplasRhoY;
			gradientLaplasRhoZ = other.gradientLaplasRhoZ;
			f = other.f;
			feq = other.feq;

        }

        return *this;
    }
};