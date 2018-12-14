/* -*- mode: C; c-basic-offset: 4 -*- */
/* ex: set shiftwidth=4 tabstop=4 expandtab: */
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
#ifndef AA_MATH_H
#define AA_MATH_H

/// maximum of a and b
#define AA_MAX(a,b) \
    ({ const typeof(a) aa_$_max_a = (a); \
       const typeof(b) aa_$_max_b = (b); \
       (aa_$_max_a > aa_$_max_b) ? aa_$_max_a : aa_$_max_b; })

/// Fortran modulo, Ada mod
#define AA_MODULO(a,b) (((a) % (b)) + (b)) % (b);

/// Fortran modulo, Ada mod
static inline int aa_imodulo( int a, int b ) {
    //return ((a % b) + b) % b;
    return AA_MODULO(a,b);
}

/// Fortran modulo, Ada mod
static inline long aa_lmodulo( long a, long b ) {
    return AA_MODULO(a,b);
}

/// Fortran modulo, Ada mod
static inline int64_t aa_imodulo64( int64_t a, int64_t b ) {
    return AA_MODULO(a,b);
}

/** Elementwise addition.
 * \f[ r_i \leftarrow x_i + y_i \f]
 */
AA_API void aa_la_vadd( size_t n, const double *x, const double *y, double *r );

/** Set diagonal of A to x. */
static inline void
aa_la_diag( size_t n, double *A, double x ) {
    for( size_t i = 0; i < n; i ++ )
        A[i*n+i] = x;
}

/** Set A to the identity matrix */
static inline void
aa_la_ident( size_t n, double *A ) {
    aa_fset(A, 0, n*n);
    aa_la_diag(n,A,1.0);
}
/** Inverse of A.
 *
 * \f[ A \leftarrow A^{-1} \f]
 *
 * \param A \f$A \in \Re^n \times \Re^n\f$, column major
 * \param n rows and columns
 */
AA_API int aa_la_inv( size_t n, double *A );

int aa_la_inv_( int *n, double *A );
#endif //AA_MATH_H
