/**
 * \file command/root/root_command_init.c
 *
 * \brief Initialize the root command.
 *
 * \copyright 2020 Velo Payments.  See License.txt for license terms.
 */

#include <backupd/command/root.h>
#include <backupd/status_codes.h>
#include <cbmc/model_assert.h>
#include <string.h>

/* forward decls. */
static void dispose_root_command(void* disp);

/**
 * \brief Initialize a root command structure.
 *
 * \param root          The root command structure to initialize.
 *
 * \returns a status code indicating success or failure.
 *      - BACKUPD_STATUS_SUCCESS on success.
 *      - a non-zero error code on failure.
 */
int root_command_init(root_command* root)
{
    /* parameter sanity checks. */
    MODEL_ASSERT(NULL != root);

    /* clear the root structure. */
    memset(root, 0, sizeof(root_command));

    /* set root command values. */
    root->hdr.hdr.dispose = &dispose_root_command;
    root->key_derivation_rounds = ROOT_COMMAND_DEFAULT_KEY_DERIVATION_ROUNDS;

    /* success. */
    return BACKUPD_STATUS_SUCCESS;
}

/**
 * \brief Dispose the root command structure.
 *
 * \param disp          The root command structure to dispose.
 */
static void dispose_root_command(void* disp)
{
    root_command* root = (root_command*)disp;

    /* if the output filename is set, then free it. */
    if (NULL != root->output_filename)
    {
        free(root->output_filename);
    }

    /* if the key filename is set, then free it. */
    if (NULL != root->key_filename)
    {
        free(root->key_filename);
    }
}
