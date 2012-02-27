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

#ifndef OSKAR_CUDA_DEVICE_INFO_SCAN_H_
#define OSKAR_CUDA_DEVICE_INFO_SCAN_H_

/**
 * @file oskar_cuda_device_info_scan.h
 */

#include "oskar_global.h"
#include "utility/oskar_CudaDeviceInfo.h"

#ifdef __cplusplus
extern "C" {
#endif

/**
 * @brief Scans the specified device for information.
 *
 * @details
 * This function scans the specified device to populate a structure
 * containing device information, such as device name, the compute
 * capability, whether the device supports double precision, and the
 * amount of global memory (among others).
 *
 * @param[out] device Pointer to CUDA device info structure to fill.
 * @param[in]  id     The CUDA device ID number.
 */
OSKAR_EXPORT
void oskar_cuda_device_info_scan(oskar_CudaDeviceInfo* device, int id);

#ifdef __cplusplus
}
#endif

#endif /* OSKAR_CUDA_DEVICE_INFO_SCAN_H_ */
