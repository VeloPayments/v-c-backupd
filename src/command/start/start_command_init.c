/**
 * \file command/start/start_command_init.c
 *
 * \brief Initialize a start command structure.
 *
 * \copyright 2020 Velo Payments.  See License.txt for license terms.
 */

#include <backupd/command/start.h>
#include <backupd/command/root.h>
#include <backupd/status_codes.h>
#include <cbmc/model_assert.h>
#include <string.h>
#include <vpr/parameters.h>

/* forward decls. */
static void start_command_dispose(void* disp);

/**
 * \brief Initialize a start command structure.
 *
 * \param start         The start command structure to initialize.
 *
 * \returns a status code indicating success or failure.
 *      - BACKUPD_STATUS_SUCCESS on success.
 *      - a non-zero error code on failure.
 */
int start_command_init(start_command* start)
{
    /* parameter sanity checks. */
    MODEL_ASSERT(NULL != start);

    /* clear start command structure. */
    memset(start, 0, sizeof(start_command));

    /* set disposer, func, etc. */
    start->hdr.hdr.dispose = &start_command_dispose;
    start->hdr.func = &start_command_func;

    /* success. */
    return BACKUPD_STATUS_SUCCESS;
}

/**
 * \brief Dispose of a start_command structure.
 *
 * \param disp          The start_command structure to dispose.
 */
static void start_command_dispose(void* UNUSED(disp))
{
    /* do nothing. */
}
