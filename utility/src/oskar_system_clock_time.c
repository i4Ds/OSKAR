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

#include "utility/oskar_system_clock_time.h"
#include <stdlib.h>
#include <stdio.h>
#include <time.h>

#ifdef __cplusplus
extern "C" {
#endif

const char* oskar_system_clock_time(int utc, int* data)
{
    static char str[80];
    time_t unix_time;
    struct tm* timeinfo;

    /* Get raw system time. */
    unix_time = time(NULL);

    /* Convert to local time or UTC. */
    if (utc)
        timeinfo = gmtime(&unix_time);
    else
        timeinfo = localtime(&unix_time);

    /* Save data. */
    if (data)
    {
        data[0] = timeinfo->tm_year;
        data[1] = timeinfo->tm_mon;
        data[2] = timeinfo->tm_mday;
        data[3] = timeinfo->tm_hour;
        data[4] = timeinfo->tm_min;
        data[5] = timeinfo->tm_sec;
        data[6] = timeinfo->tm_isdst;
    }

    /* Convert to string. */
    strftime(str, sizeof(str), "%Y-%m-%d, %H:%M:%S (%Z)", timeinfo);
    return str;
}

#ifdef __cplusplus
}
#endif

