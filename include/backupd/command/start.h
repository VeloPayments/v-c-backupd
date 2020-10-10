/**
 * \file include/backupd/command/start.h
 *
 * \brief Start command structure.
 *
 * \copyright 2020 Velo Payments.  See License.txt for license terms.
 */

#ifndef  BACKUPD_COMMAND_START_HEADER_GUARD
# define BACKUPD_COMMAND_START_HEADER_GUARD

#include <backupd/commandline.h>
#include <stdbool.h>
#include <stdio.h>

/* make this header C++ friendly. */
#ifdef __cplusplus
extern "C" {
#endif

typedef struct start_command
{
    command hdr;
} start_command;

/**
 * \brief Initialize a start command structure.
 *
 * \param start         The start command structure to initialize.
 *
 * \returns a status code indicating success or failure.
 *      - BACKUPD_STATUS_SUCCESS on success.
 *      - a non-zero error code on failure.
 */
int start_command_init(start_command* start);

/**
 * \brief Process the start command.
 *
 * \param opts          The command-line option structure.
 * \param argc          The argument count.
 * \param argv          The argument vector.
 *
 * \returns a status code indicating success or failure.
 *      - BACKUPD_STATUS_SUCCESS on success.
 *      - a non-zero error code on failure.
 */
int process_start_command(commandline_opts* opts, int argc, char* argv[]);

/**
 * \brief Execute the start command.
 *
 * \param opts          The commandline opts for this operation.
 *
 * \returns a status code indicating success or failure.
 *      - BACKUPD_STATUS_SUCCESS on success.
 *      - a non-zero error code on failure.
 */
int start_command_func(commandline_opts* opts);

/* make this header C++ friendly. */
#ifdef __cplusplus
}
#endif

#endif /*BACKUPD_COMMAND_START_HEADER_GUARD*/
