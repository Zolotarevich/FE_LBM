lbm-wb-fe/
│
├── CMakeLists.txt
├── README.md
├── LICENSE
│
├── config/
│   ├── simulation.yaml
│   ├── eos_pr.yaml
│   └── bc.yaml
│
├── src/
│   │
│   ├── core/
│   │   ├── Lattice.hpp
│   │   ├── Lattice.cpp
│   │   │
│   │   ├── Grid.hpp
│   │   ├── Grid.cpp
│   │   │
│   │   ├── Distribution.hpp
│   │   ├── Distribution.cpp
│   │   │
│   │   ├── Fields.hpp
│   │   ├── Fields.cpp
│   │   │
│   │   ├── TimeIntegrator.hpp
│   │   └── TimeIntegrator.cpp
│   │
│   ├── lbm/
│   │   ├── Equilibrium.hpp
│   │   ├── Equilibrium.cpp
│   │   │
│   │   ├── Streaming.hpp
│   │   ├── Streaming.cpp
│   │   │
│   │   ├── ForcingScheme.hpp
│   │   ├── ForcingScheme.cpp
│   │   │
│   │   ├── Collision/
│   │   │   ├── CollisionModel.hpp
│   │   │   ├── CollisionModel.cpp
│   │   │   │
│   │   │   ├── BGK.hpp
│   │   │   ├── BGK.cpp
│   │   │   │
│   │   │   ├── MRT.hpp
│   │   │   ├── MRT.cpp
│   │   │   │
│   │   │   ├── MRTMatrix.hpp
│   │   │   └── MRTMatrix.cpp
│   │
│   ├── physics/
│   │   ├── EOS/
│   │   │   ├── EquationOfState.hpp
│   │   │   ├── EquationOfState.cpp
│   │   │   │
│   │   │   ├── PengRobinsonEOS.hpp
│   │   │   └── PengRobinsonEOS.cpp
│   │   │
│   │   ├── FreeEnergy/
│   │   │   ├── FreeEnergyModel.hpp
│   │   │   ├── FreeEnergyModel.cpp
│   │   │   │
│   │   │   ├── EOSBasedFreeEnergy.hpp
│   │   │   └── EOSBasedFreeEnergy.cpp
│   │   │
│   │   ├── Force/
│   │   │   ├── ForceModel.hpp
│   │   │   ├── ForceModel.cpp
│   │   │   │
│   │   │   ├── CapillaryForce.hpp
│   │   │   ├── CapillaryForce.cpp
│   │   │   │
│   │   │   ├── WellBalancedForce.hpp
│   │   │   └── WellBalancedForce.cpp
│   │
│   ├── boundary/
│   │   ├── BoundaryCondition.hpp
│   │   ├── BoundaryCondition.cpp
│   │   │
│   │   ├── BounceBack.hpp
│   │   ├── BounceBack.cpp
│   │   │
│   │   ├── InletOutlet.hpp
│   │   └── InletOutlet.cpp
│   │
│   ├── solver/
│   │   ├── LBMSolver.hpp
│   │   └── LBMSolver.cpp
│   │
│   ├── io/
│   │   ├── VTKWriter.hpp
│   │   ├── VTKWriter.cpp
│   │   │
│   │   ├── ConfigReader.hpp
│   │   ├── ConfigReader.cpp
│   │   │
│   │   ├── Logger.hpp
│   │   └── Logger.cpp
│   │
│   ├── parallel/
│   │   ├── OpenMP.hpp
│   │   ├── OpenMP.cpp
│   │   │
│   │   ├── MPI.hpp
│   │   └── MPI.cpp
│   │
│   ├── utils/
│   │   ├── Constants.hpp
│   │   ├── Constants.cpp
│   │   │
│   │   ├── Math.hpp
│   │   ├── Math.cpp
│   │   │
│   │   ├── Timer.hpp
│   │   └── Timer.cpp
│   │
│   └── main.cpp
│
├── tests/
│   ├── test_eos_pr.cpp
│   ├── test_free_energy.cpp
│   ├── test_well_balanced.cpp
│   ├── test_laplace_law.cpp
│   └── test_mrt_stability.cpp
│
├── examples/
│   ├── droplet_equilibrium/
│   │   ├── config.yaml
│   │   └── run.sh
│   │
│   ├── capillary_wave/
│   │   ├── config.yaml
│   │   └── run.sh
│   │
│   └── displacement_oil_gas/
│       ├── config.yaml
│       └── run.sh
│
└── docs/
    ├── architecture.puml
    ├── theory.md
    └── validation.md