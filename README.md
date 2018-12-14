# 45-amino-lean
A lean version of Neil Dantam's amino library. This one only contains functions that are used by the code base on Krang

Amino is package of basic utilities for robotics software.  It
includes mathematical and linear algebra routines, memory management,
and time-handling.  Design goals are easy integration, efficiency, and
simplicity.

## Dependencies

- blas / lapack
- gfortran

On Debian/Ubuntu:

    sudo apt install libblas-dev liblapack-dev

For libgfortran, install the latest lib and lib-dev packages. For Ubuntu 18.04, I have `libgfortran5` and `libgfortran-8-dev` packages. Do an apt search

    sudo apt search libgfortran
    
and scroll through the list to see which ones are the latest for your distro and install them.

## Installation

    git clone https://github.gatech.edu/WholeBodyControlAttempt1/45-amino-lean
    cd 45-amino-lean
    mkdir build
    cd build
    cmake ..
    make
    sudo make install
