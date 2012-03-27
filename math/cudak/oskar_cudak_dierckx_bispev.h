/*
 * Copyright (c) 2012, The University of Oxford
 * All rights reserved.
 *
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions are met:
 * 1. Redistributions of source code must retain the above copyright notice,
 *    this list of conditions and the following disclaimer.
 * 2. Redistributions in binary form must reproduce the above copyright notice,
 *    this list of conditions and the following disclaimer in the documentation
 *    and/or other materials provided with the distribution.
 * 3. Neither the name of the University of Oxford nor the names of its
 *    contributors may be used to endorse or promote products derived from this
 *    software without specific prior written permission.
 *
 * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS"
 * AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE
 * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE
 * ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT HOLDER OR CONTRIBUTORS BE
 * LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR
 * CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF
 * SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS
 * INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN
 * CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE)
 * ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE
 * POSSIBILITY OF SUCH DAMAGE.
 */

#ifndef OSKAR_CUDAK_DIERCKX_BISPEV_H_
#define OSKAR_CUDAK_DIERCKX_BISPEV_H_

/**
 * @file oskar_cudak_dierckx_bispev.h
 */

#include "oskar_global.h"

/**
 * @brief
 * CUDA kernel to evaluate B-spline coefficients (single precision).
 *
 * @details
 * This CUDA kernel evaluates B-spline coefficients to determine values of
 * a fitted surface at the specified points.
 *
 * @param[in] tx     Array of knot positions in x.
 * @param[in] nx     Number of knot positions in x.
 * @param[in] ty     Array of knot positions in y.
 * @param[in] ny     Number of knot positions in y.
 * @param[in] c      Array of spline coefficients.
 * @param[in] kx     Order of spline in x (use 3 for bicubic).
 * @param[in] ky     Order of spline in y (use 3 for bicubic).
 * @param[in] n      Number of points to evaluate.
 * @param[in] x      Input x positions.
 * @param[in] y      Input y positions.
 * @param[in] stride Memory stride of output values (use 1 for contiguous).
 * @param[out] z     Output surface values.
 */
__global__
void oskar_cudak_dierckx_bispev_f(const float* tx, const int nx,
        const float* ty, const int ny, const float* c, const int kx,
        const int ky, const int n, const float* x, const float* y,
        const int stride, float* z);

/**
 * @brief
 * CUDA kernel to evaluate B-spline coefficients (double precision).
 *
 * @details
 * This CUDA kernel evaluates B-spline coefficients to determine values of
 * a fitted surface at the specified points.
 *
 * @param[in] tx     Array of knot positions in x.
 * @param[in] nx     Number of knot positions in x.
 * @param[in] ty     Array of knot positions in y.
 * @param[in] ny     Number of knot positions in y.
 * @param[in] c      Array of spline coefficients.
 * @param[in] kx     Order of spline in x (use 3 for bicubic).
 * @param[in] ky     Order of spline in y (use 3 for bicubic).
 * @param[in] n      Number of points to evaluate.
 * @param[in] x      Input x positions.
 * @param[in] y      Input y positions.
 * @param[in] stride Memory stride of output values (use 1 for contiguous).
 * @param[out] z     Output surface values.
 */
__global__
void oskar_cudak_dierckx_bispev_d(const double* tx, const int nx,
        const double* ty, const int ny, const double* c, const int kx,
        const int ky, const int n, const double* x, const double* y,
        const int stride, double* z);

#endif // OSKAR_CUDAK_DIERCKX_BISPEV_H_
