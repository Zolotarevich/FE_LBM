#ifndef LATTICE_H
#define LATTICE_H

enum class LBMDescriptorType {
    D2Q9,
    D3Q19,
    D3Q27
};

void LatticeParameters(LBMDescriptorType type);

#endif 