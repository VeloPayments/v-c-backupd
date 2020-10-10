/**
 * \file command/start/start_command_func.c
 *
 * \brief Entry point for the start command.
 *
 * \copyright 2020 Velo Payments.  See License.txt for license terms.
 */

#include <backupd/commandline.h>
#include <backupd/command/root.h>
#include <backupd/command/start.h>
#include <backupd/status_codes.h>
#include <cbmc/model_assert.h>
#include <fcntl.h>
#include <stdio.h>
#include <vccrypt/compare.h>
#include <vpr/parameters.h>

/**
 * \brief Execute the start command.
 *
 * \param opts          The commandline opts for this operation.
 *
 * \returns a status code indicating success or failure.
 *      - BACKUPD_STATUS_SUCCESS on success.
 *      - a non-zero error code on failure.
 */
int start_command_func(commandline_opts* UNUSED(opts))
{
    fprintf(stderr, "backupd start not yet implemented.\n");

    return BACKUPD_STATUS_SUCCESS;
}
