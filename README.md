# 45-amino-lean
A lean version of Neil Dantam's amino library. This one only contains functions that are used by the code base on Krang

Amino is package of basic utilities for robotics software.  It
includes mathematical and linear algebra routines, memory management,
and time-handling.  Design goals are easy integration, efficiency, and
simplicity.

## Dependencies

- libblas-dev`, `liblapack-dev`,

    sudo apt install libblas-dev liblapack-dev

- `gfortran`

For libgfortran, install the latest lib and lib-dev packages. For Ubuntu 18.04, I have `libgfortran5` and `libgfortran-8-dev` packages.

    sudo apt install libgfortran5 libgfortran-8-dev

Do an apt search

    sudo apt search libgfortran

and scroll through the list to see which ones are the latest for your distro and install them.

## Installation

    git clone https://github.gatech.edu/WholeBodyControlAttempt1/45-amino-lean
    cd 45-amino-lean
    mkdir build
    cd build
    cmake ..
    sudo make install

## Uninstall
 To remove system files created by the installation of this repo.

    sudo make uninstall
