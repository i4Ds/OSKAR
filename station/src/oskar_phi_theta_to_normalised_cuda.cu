/*
 * Copyright (c) 2011, The University of Oxford
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

#include "station/oskar_phi_theta_to_normalised_cuda.h"
#include "station/cudak/oskar_cudak_phi_theta_to_normalised.h"

#ifdef __cplusplus
extern "C" {
#endif

// Single precision.
int oskar_phi_theta_to_normalised_cuda_f(int n, const float* d_phi,
        const float* d_theta, float min_phi, float min_theta, float range_phi,
        float range_theta, float* d_norm_phi, float* d_norm_theta)
{
    // Set up block sizes.
    int num_threads = 256;
    int num_blocks = (n + num_threads - 1) / num_threads;

    // Call the kernel.
    oskar_cudak_phi_theta_to_normalised_f
            OSKAR_CUDAK_CONF(num_blocks, num_threads)
            (n, d_phi, d_theta, min_phi, min_theta, range_phi, range_theta,
                    d_norm_phi, d_norm_theta);

    // Return error code.
    cudaDeviceSynchronize();
    return cudaPeekAtLastError();
}

// Double precision.
int oskar_phi_theta_to_normalised_cuda_d(int n, const double* d_phi,
        const double* d_theta, double min_phi, double min_theta,
        double range_phi, double range_theta, double* d_norm_phi,
        double* d_norm_theta)
{
    // Set up block sizes.
    int num_threads = 256;
    int num_blocks = (n + num_threads - 1) / num_threads;

    // Call the kernel.
    oskar_cudak_phi_theta_to_normalised_d
            OSKAR_CUDAK_CONF(num_blocks, num_threads)
            (n, d_phi, d_theta, min_phi, min_theta, range_phi, range_theta,
                    d_norm_phi, d_norm_theta);

    // Return error code.
    cudaDeviceSynchronize();
    return cudaPeekAtLastError();
}

#ifdef __cplusplus
}
#endif
