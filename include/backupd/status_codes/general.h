/**
 * \file include/backupd/status_codes/general.h
 *
 * \brief General status codes for backupd.
 *
 * \copyright 2020 Velo Payments.  See License.txt for license terms.
 */

#ifndef BACKUPD_STATUS_CODES_GENERAL_HEADER_GUARD
#define BACKUPD_STATUS_CODES_GENERAL_HEADER_GUARD

#include <backupd/status_codes.h>

/* make this header C++ friendly. */
#ifdef __cplusplus
extern "C" {
#endif

/**
 * \brief Out of memory error.
 */
#define BACKUPD_ERROR_GENERAL_OUT_OF_MEMORY \
    BACKUPD_STATUS_ERROR_MACRO(BACKUPD_COMPONENT_GENERAL, 0x0001U)

/* make this header C++ friendly. */
#ifdef __cplusplus
}
#endif

#endif /*BACKUPD_STATUS_CODES_GENERAL_HEADER_GUARD*/
