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

#ifndef OSKAR_WINDOWS_H_
#define OSKAR_WINDOWS_H_

//
// Macro used for creating windows the library.
// Note: should only be needed in header files.
//
// The __declspec(dllexport) modifier enables the method to
// be exported by the DLL so that it can be used by other applications.
//
// Usage examples:
//  DllExport void foo();
//  static DllExport double add(double a, double b);
//
// For more information see:
// http://msdn.microsoft.com/en-us/library/a90k134d(v=VS.90).aspx
//
//
// FIXME: Change DllExport to OSKAR_EXPORT or OSKAR_EXTERN to be more generic?
// FIXME: Change oskar_windows.h to oskar_global.h?
// FIXME: Add oskar version info as in Qt, Qwt global headers?
//

#if (defined(_WIN32) || defined(__WIN32__))
    #ifdef oskar_EXPORTS
        #ifndef DllExport
            #define DllExport __declspec(dllexport)
        #endif
    #else
        #ifndef DllExport
            #define DllExport
        #endif
    #endif
#else
    #ifndef DllExport
        #define DllExport
    #endif
#endif

#endif // OSKAR_WINDOWS_H_
