/**
 * \file commandline/command_execute.c
 *
 * \brief Execute a command from the options structure, if possible.
 *
 * \copyright 2020 Velo Payments.  See License.txt for license terms.
 */

#include <backupd/commandline.h>
#include <backupd/status_codes.h>
#include <cbmc/model_assert.h>
#include <stdio.h>

/**
 * \brief Execute a command.
 *
 * \param opts          The commandline options for this command.
 *
 * \returns a status code indicating success or failure.
 *      - BACKUPD_STATUS_SUCCESS on success.
 */
int command_execute(commandline_opts* opts)
{
    /* parameter sanity checks. */
    MODEL_ASSERT(PROP_VALID_COMMANDLINE_OPTS(opts));

    /* is there a command to execute? */
    if (NULL != opts->cmd->func)
    {
        return opts->cmd->func(opts);
    }
    else
    {
        fprintf(stderr, "Missing command.\n");

        return BACKUPD_ERROR_COMMANDLINE_MISSING_COMMAND;
    }
}
