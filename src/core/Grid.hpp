#ifndef GRID_H
#define GRID_H

struct Grid {
    int nx, ny, nz;

    Grid() = default;
	Grid(int nx, int ny, int nz = 1) : nx(nx), ny(ny), nz(nz) {}

    int size() const { return nx * ny * nz; }

    inline int index(int i, int j, int k) const {
        return i + nx * (j + ny * k);
    }
};

#endif