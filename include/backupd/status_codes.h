/**
 * \file include/backupd/status_codes.h
 *
 * \brief Status code definitions for backupd.
 *
 * \copyright 2020 Velo Payments.  See License.txt for license terms.
 */

#ifndef BACKUPD_STATUS_CODES_HEADER_GUARD
#define BACKUPD_STATUS_CODES_HEADER_GUARD

#include <backupd/components.h>
#include <backupd/status_codes/commandline.h>
#include <backupd/status_codes/general.h>
#include <vctool/status_codes.h>

/* make this header C++ friendly. */
#ifdef __cplusplus
extern "C" {
#endif

/**
 * \brief Success status code.
 */
#define BACKUPD_STATUS_SUCCESS 0x00000000

/**
 * \brief Error code macro.
 */
#define BACKUPD_STATUS_ERROR_MACRO(component, reason) \
    ((int32_t)(0x8000000 | ((component & 0xFF) << 16) | (reason & 0xFFFF)))

/* make this header C++ friendly. */
#ifdef __cplusplus
}
#endif

#endif /*BACKUPD_STATUS_CODES_HEADER_GUARD*/
