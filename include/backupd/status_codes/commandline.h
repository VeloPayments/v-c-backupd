/**
 * \file include/backupd/status_codes/commandline.h
 *
 * \brief commandline component status codes.
 *
 * \copyright 2020 Velo Payments.  See License.txt for license terms.
 */

#ifndef BACKUPD_STATUS_CODES_COMMANDLINE_HEADER_GUARD
#define BACKUPD_STATUS_CODES_COMMANDLINE_HEADER_GUARD

#include <backupd/status_codes.h>

/* make this header C++ friendly. */
#ifdef __cplusplus
extern "C" {
#endif

/**
 * \brief Missing argument.
 */
#define BACKUPD_ERROR_COMMANDLINE_MISSING_ARGUMENT \
    BACKUPD_STATUS_ERROR_MACRO(BACKUPD_COMPONENT_COMMANDLINE, 0x0001U)

/**
 * \brief Unknown command.
 */
#define BACKUPD_ERROR_COMMANDLINE_UNKNOWN_COMMAND \
    BACKUPD_STATUS_ERROR_MACRO(BACKUPD_COMPONENT_COMMANDLINE, 0x0002U)

/**
 * \brief Missing command.
 */
#define BACKUPD_ERROR_COMMANDLINE_MISSING_COMMAND \
    BACKUPD_STATUS_ERROR_MACRO(BACKUPD_COMPONENT_COMMANDLINE, 0x0003U)

/**
 * \brief Duplicate option.
 */
#define BACKUPD_ERROR_COMMANDLINE_DUPLICATE_OPTION \
    BACKUPD_STATUS_ERROR_MACRO(BACKUPD_COMPONENT_COMMANDLINE, 0x0004U)

/**
 * \brief Invalid number of key rounds.
 */
#define BACKUPD_ERROR_COMMANDLINE_BAD_KEY_ROUNDS \
    BACKUPD_STATUS_ERROR_MACRO(BACKUPD_COMPONENT_COMMANDLINE, 0x0005U)

/* make this header C++ friendly. */
#ifdef __cplusplus
}
#endif

#endif /*BACKUPD_STATUS_CODES_COMMANDLINE_HEADER_GUARD*/
