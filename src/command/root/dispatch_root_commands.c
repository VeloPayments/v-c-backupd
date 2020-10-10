/**
 * \file command/root/dispatch_root_commands.c
 *
 * \brief Dispatch root commands.
 *
 * \copyright 2020 Velo Payments.  See License.txt for license terms.
 */

#include <backupd/command/help.h>
#include <backupd/command/root.h>
#include <backupd/command/start.h>
#include <backupd/status_codes.h>
#include <cbmc/model_assert.h>
#include <stdio.h>
#include <string.h>

/**
 * \brief Dispatch root level commands.
 *
 * \param opts          The command-line option structure.
 * \param argc          The argument count.
 * \param argv          The argument vector.
 *
 * \returns a status code indicating success or failure.
 *      - BACKUPD_STATUS_SUCCESS on success.
 *      - a non-zero error code on failure.
 */
int dispatch_root_commands(commandline_opts* opts, int argc, char* argv[])
{
    /* parameter sanity checks. */
    MODEL_ASSERT(PROP_VALID_COMMANDLINE_OPTS(opts));

    /* we should have at least one argument. */
    if (argc < 1)
    {
        fprintf(stderr, "Expecting a command.\n");

        return BACKUPD_ERROR_COMMANDLINE_MISSING_ARGUMENT;
    }

    /* decode the command. */
    char* command = argv[0];
    --argc;
    ++argv;

    /* is this the help command? */
    if (!strcmp(command, "help"))
    {
        return process_help_command(opts, argc, argv);
    }
    /* is this the start command? */
    else if (!strcmp(command, "start"))
    {
        return process_start_command(opts, argc, argv);
    }
    /* handle unknown command. */
    else
    {
        fprintf(stderr, "Unknown command %s.\n", command);

        return BACKUPD_ERROR_COMMANDLINE_UNKNOWN_COMMAND;
    }
}
