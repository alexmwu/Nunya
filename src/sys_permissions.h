/*
Copyright (C) 2015 The University of Notre Dame
This software is distributed under the GNU General Public License.
See the file LICENSE for details.
*/

#ifndef SYS_PERMISSIONS_H
#define SYS_PERMISSIONS_H

#include "kerneltypes.h"

/**
 * @brief   Creates a new permissions template for a process to use.
 * @details Allocates an identifier for a process permissions template,
 *          to be adjusted as needed before passed as a parameter to the
 *          run() syscall. The identifier will need to be freed by the process
 *          when no longer needed so as to stop counting toward the process'
 *          memory allocation.
 *
 * @return  The identifier of the newly created process template.
 */
static inline int32_t permissions_template_create() {
    return syscall(SYSCALL_template_create, 0, 0, 0, 0, 0);
}

/**
 * @brief   Deletes the template indicated by the identifier
 * @details Checks whether the current process owns the template
 *          associated with the identifier, and if so, deletes it.
 *          This returns the memory associated with the template to
 *          the process' memory allowance.
 *
 * @param   identifier The identifier of the template to delete.
 */
static inline void permissions_template_delete(uint32_t identifier) {
    syscall(SYSCALL_template_delete, identifier, 0, 0, 0, 0);
}

// todo: how to share with the user what's inside the permissions struct without returning it?
// Or is it write-only?



#endif
