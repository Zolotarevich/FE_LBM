cmake_minimum_required(VERSION 3.20)

project(FE_LBM LANGUAGES CXX)

# -------------------------------
# Общие настройки
# -------------------------------
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

# Для Visual Studio: папки targets
set_property(GLOBAL PROPERTY USE_FOLDERS ON)
set_property(GLOBAL PROPERTY PREDEFINED_TARGETS_FOLDER "CMakePredefinedTargets")

# -------------------------------
# Общие исходники
# -------------------------------
set(LBM_SRC_FILES

    # -------- Solver --------
    src/solver/LBMSolver.hpp
    src/solver/LBMSolver.cpp

    # -------- LBM --------
    src/lbm/Equilibrium.hpp
    src/lbm/Equilibrium.cpp

    src/lbm/BGK.hpp
    src/lbm/BGK.cpp

    src/lbm/MRT.hpp
    src/lbm/MRT.cpp

    src/lbm/Streaming.hpp
    src/lbm/Streaming.cpp

    src/lbm/Equilibrium.hpp
    src/lbm/Equilibrium.cpp

    src/lbm/ForcingScheme.hpp
    src/lbm/ForcingScheme.cpp

    # -------- EOS --------
    src/physics/EOS/PengRobinsonEOS.hpp
    src/physics/EOS/PengRobinsonEOS.cpp

    # -------- Boundary --------
    src/boundary/BoundaryConditions.hpp
    src/boundary/BoundaryConditions.cpp

    # -------- IO --------
    src/io/VTKWriter.hpp
    src/io/VTKWriter.cpp

    src/io/ConfigReader.hpp
    src/io/ConfigReader.cpp

    src/io/Logger.hpp
    src/io/Logger.cpp

    # -------- utils --------
    src/utils/Constants.hpp
    src/utils/Constants.cpp

    src/utils/Timer.hpp
    src/utils/Timer.cpp

    # -------- core --------
    src/core/Fields.hpp
    src/core/Fields.cpp

    src/core/Grid.hpp
    src/core/Grid.cpp

    src/core/Lattice.hpp
    src/core/Lattice.cpp

    src/core/TimeIntegrator.hpp
    src/core/TimeIntegrator.cpp

    src/core/Parameters.hpp
)

# -------------------------------
# Основной executable
# -------------------------------
add_executable(lbm_test
    ${LBM_SRC_FILES}
    Benchmarks/lbm_test.cpp
)

# Include directories — ПОСЛЕ add_executable
target_include_directories(lbm_test PRIVATE
    ${CMAKE_CURRENT_SOURCE_DIR}/src
)