#ifndef GRID_H
#define GRID_H

struct Grid {
    int nx, ny, nz;
    //bool is3D() const { return nz > 1; }

    int size() const { return nx * ny * nz; }

    inline int index(int i, int j, int k) const {
        return i + nx * (j + ny * k);
    }
};

#endif