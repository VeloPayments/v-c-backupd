/**
 * \file include/backupd/components.h
 *
 * \brief Components enumeration.
 *
 * \copyright 2020 Velo Payments.  See License.txt for license terms.
 */

#ifndef BACKUPD_COMPONENTS_HEADER_GUARD
#define BACKUPD_COMPONENTS_HEADER_GUARD

/* make this header C++ friendly. */
#ifdef __cplusplus
extern "C" {
#endif

/**
 * \brief backupd Components.
 */
enum backupd_components
{
    /**
     * \brief General Components.
     */
    BACKUPD_COMPONENT_GENERAL = 0x40U,

    /**
     * \brief commandline Component.
     */
    BACKUPD_COMPONENT_COMMANDLINE = 0x41U,
};

/* make this header C++ friendly. */
#ifdef __cplusplus
}
#endif  //__cplusplus

#endif /*BACKUPD_COMPONENTS_HEADER_GUARD*/
