/*
 * Copyright (c) 2010-2011, Georgia Tech Research Corporation
 * All rights reserved.
 *
 * Author(s): Neil T. Dantam <ntd@gatech.edu>
 * Georgia Tech Humanoid Robotics Lab
 * Under Direction of Prof. Mike Stilman <mstilman@cc.gatech.edu>
 *
 *
 * This file is provided under the following "BSD-style" License:
 *
 *
 *   Redistribution and use in source and binary forms, with or
 *   without modification, are permitted provided that the following
 *   conditions are met:
 *
 *   * Redistributions of source code must retain the above copyright
 *     notice, this list of conditions and the following disclaimer.
 *
 *   * Redistributions in binary form must reproduce the above
 *     copyright notice, this list of conditions and the following
 *     disclaimer in the documentation and/or other materials provided
 *     with the distribution.
 *
 *   THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND
 *   CONTRIBUTORS "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES,
 *   INCLUDING, BUT NOT LIMITED TO, THE IMPLIED WARRANTIES OF
 *   MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE
 *   DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT HOLDER OR
 *   CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL,
 *   SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT
 *   LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF
 *   USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED
 *   AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT
 *   LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN
 *   ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE
 *   POSSIBILITY OF SUCH DAMAGE.
 *
 */

// uncomment to check that local allocs actually get freed
// #define AA_ALLOC_STACK_MAX 0

#include "amino.h"


void aa_la_vadd( size_t n, const double *x, const double *y, double *r ) {
    for( size_t i = 0; i < n; i ++ ) {
        r[i] = x[i] + y[i];
    }
}

int aa_la_inv( size_t n, double *A ) {
    const int mi = (int) n;
    const int ni = (int) n;
    int info;

    int *ipiv = (int*)
        aa_mem_region_local_alloc(sizeof(int)*n);

    // LU-factor
    info = aa_cla_dgetrf( mi, ni, A, mi, ipiv );

    int lwork = -1;
    while(1) {
        double *work = (double*)
            aa_mem_region_local_tmpalloc( sizeof(double)*
                                      (size_t)(lwork < 0 ? 1 : lwork) );
        aa_cla_dgetri( ni, A, mi, ipiv, work, lwork );
        if( lwork > 0 ) break;
        assert( -1 == lwork );
        lwork = (int)work[0];
    }

    aa_mem_region_local_pop(ipiv);

    return info;
}

int aa_la_inv_( int *n, double *A ) {
    size_t ns = (size_t)*n;
    return aa_la_inv(ns,A);
}
