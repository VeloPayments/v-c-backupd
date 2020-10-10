/**
 * \file command/start/process_start_command.c
 *
 * \brief Process command-line options to build a start command.
 *
 * \copyright 2020 Velo Payments.  See License.txt for license terms.
 */

#include <backupd/command/start.h>
#include <backupd/command/root.h>
#include <backupd/commandline.h>
#include <backupd/status_codes.h>
#include <cbmc/model_assert.h>
#include <string.h>
#include <unistd.h>
#include <vpr/parameters.h>

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
int process_start_command(
    commandline_opts* opts, int UNUSED(argc), char* UNUSED(argv[]))
{
    int retval;

    /* parameter sanity checks. */
    MODEL_ASSERT(PROP_VALID_COMMANDLINE_OPTS(opts));

    /* allocate memory for a start_command structure. */
    start_command* start = (start_command*)malloc(sizeof(start_command));
    if (NULL == start)
    {
        retval = BACKUPD_ERROR_GENERAL_OUT_OF_MEMORY;
        goto done;
    }

    /* initialize the structure. */
    retval = start_command_init(start);
    if (BACKUPD_STATUS_SUCCESS != retval)
    {
        goto free_start;
    }

    /* set start command as the head of opts command. */
    start->hdr.next = opts->cmd;
    opts->cmd = &start->hdr;

    /* success. */
    retval = BACKUPD_STATUS_SUCCESS;
    goto done;

free_start:
    free(start);

done:
    return retval;
}
