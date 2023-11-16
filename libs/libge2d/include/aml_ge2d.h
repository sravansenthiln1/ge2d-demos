/*
 * Copyright (c) 2014 Amlogic, Inc. All rights reserved.
 *
 * This source code is subject to the terms and conditions defined in the
 * file 'LICENSE' which is part of this source code package.
 *
 * Description:
 */

#ifndef AML_GE2D_H_
#define AML_GE2D_H_

#include "ge2d_port.h"

#if defined (__cplusplus)
extern "C" {
#endif

/**
 * @struct aml_ge2d_t
 * @brief Structure representing the state of the GE2D (Graphics Engine 2D).
 */
typedef struct aml_ge2d {
    aml_ge2d_info_t ge2dinfo; /**< GE2D information structure. */
    char *src_data[GE2D_MAX_PLANE]; /**< First Source data for GE2D operation. */
    char *src2_data[GE2D_MAX_PLANE]; /**< Second source data for GE2D operation. */
    char *dst_data[GE2D_MAX_PLANE]; /**< Destination data for GE2D operation. */
    unsigned int src_size[GE2D_MAX_PLANE]; /**< Size of the first source data. */
    unsigned int src2_size[GE2D_MAX_PLANE]; /**< Size of the second source data. */
    unsigned int dst_size[GE2D_MAX_PLANE]; /**< Size of the destination data. */
    void *cmemParm_src[GE2D_MAX_PLANE]; /**< Memory parameters for first source data. */
    void *cmemParm_src2[GE2D_MAX_PLANE]; /**< Memory parameters for second source data. */
    void *cmemParm_dst[GE2D_MAX_PLANE]; /**< Memory parameters for destination data. */
} aml_ge2d_t;

/**
 * @brief Initializes the GE2D library.
 * @param pge2d Pointer to the GE2D structure.
 * @return 0 on success (ge2d_success), -1 on failure (ge2d_fail).
 */
int aml_ge2d_init(aml_ge2d_t *pge2d);

/**
 * @brief Exits the GE2D library, releasing resources.
 * @param pge2d Pointer to the GE2D structure.
 */
void aml_ge2d_exit(aml_ge2d_t *pge2d);

/**
 * @brief Retrieves the capabilities of the GE2D hardware.
 * @param fd_ge2d File descriptor for GE2D.
 * @return Capabilities of the GE2D hardware.
 */
int aml_ge2d_get_cap(int fd_ge2d);

/**
 * @brief Allocates memory using ION (Input/Output Memory Management Unit) for GE2D data.
 * @param pge2d Pointer to the GE2D structure.
 * @return 0 on success (ge2d_success), -1 on failure (ge2d_fail).
 */
int aml_ge2d_mem_alloc_ion(aml_ge2d_t *pge2d);

/**
 * @brief Frees memory allocated using ION for GE2D data.
 * @param pge2d Pointer to the GE2D structure.
 */
void aml_ge2d_mem_free_ion(aml_ge2d_t *pge2d);

/**
 * @brief Allocates memory for GE2D data.
 * @param pge2d Pointer to the GE2D structure.
 * @return 0 on success (ge2d_success), -1 on failure (ge2d_fail).
 */
int aml_ge2d_mem_alloc(aml_ge2d_t *pge2d);

/**
 * @brief Frees memory allocated for GE2D data.
 * @param pge2d Pointer to the GE2D structure.
 */
void aml_ge2d_mem_free(aml_ge2d_t *pge2d);

/**
 * @brief Processes the GE2D operation based on the provided GE2D information.
 * @param pge2dinfo Pointer to the GE2D information structure.
 * @return 0 on success (ge2d_success), -1 on failure (ge2d_fail).
 */
int aml_ge2d_process(aml_ge2d_info_t *pge2dinfo);

/**
 * @brief Enqueues the GE2D operation for processing.
 * @param pge2dinfo Pointer to the GE2D information structure.
 * @return 0 on success (ge2d_success), -1 on failure (ge2d_fail).
 */
int aml_ge2d_process_enqueue(aml_ge2d_info_t *pge2dinfo);

/**
 * @brief Posts the queued GE2D operation for execution.
 * @param pge2dinfo Pointer to the GE2D information structure.
 * @return 0 on success (ge2d_success), -1 on failure (ge2d_fail).
 */
int aml_ge2d_post_queue(aml_ge2d_info_t *pge2dinfo);

/**
 * @brief Attaches a DMA (Direct Memory Access) file descriptor for GE2D data.
 * @param pge2dinfo Pointer to the GE2D information structure.
 * @param data_type Type of GE2D data.
 * @return 0 on success (ge2d_success), -1 on failure (ge2d_fail).
 */
int aml_ge2d_attach_dma_fd(aml_ge2d_info_t *pge2dinfo, enum ge2d_data_type_e data_type);

/**
 * @brief Configures the GE2D operation based on the provided GE2D information.
 * @param pge2dinfo Pointer to the GE2D information structure.
 * @return 0 on success (ge2d_success), -1 on failure (ge2d_fail).
 */
int aml_ge2d_config(aml_ge2d_info_t *pge2dinfo);

/**
 * @brief Executes the configured GE2D operation.
 * @param pge2dinfo Pointer to the GE2D information structure.
 * @return 0 on success (ge2d_success), -1 on failure (ge2d_fail).
 */
int aml_ge2d_execute(aml_ge2d_info_t *pge2dinfo);

/**
 * @brief Enqueues the configured GE2D operation for execution.
 * @param pge2dinfo Pointer to the GE2D information structure.
 * @return 0 on success (ge2d_success), -1 on failure (ge2d_fail).
 */
int aml_ge2d_execute_enqueue(aml_ge2d_info_t *pge2dinfo);

/**
 * @brief Detaches a DMA file descriptor for GE2D data.
 * @param pge2dinfo Pointer to the GE2D information structure.
 * @param data_type Type of GE2D data.
 */
void aml_ge2d_detach_dma_fd(aml_ge2d_info_t *pge2dinfo, enum ge2d_data_type_e data_type);

/**
 * @brief Processes the GE2D operation using ION.
 * @param pge2dinfo Pointer to the GE2D information structure.
 * @return 0 on success (ge2d_success), -1 on failure (ge2d_fail).
 */
int aml_ge2d_process_ion(aml_ge2d_info_t *pge2dinfo);

/**
 * @brief Synchronizes the cache for GE2D data.
 * @param pge2dinfo Pointer to the GE2D information structure.
 * @param src_id Source ID.
 * @return 0 on success (ge2d_success), -1 on failure (ge2d_fail).
 */
int aml_ge2d_sync_cache(aml_ge2d_info_t *pge2dinfo, int src_id);

/**
 * @brief Invalidates the cache for GE2D data.
 * @param pge2dinfo Pointer to the GE2D information structure.
 * @return 0 on success (ge2d_success), -1 on failure (ge2d_fail).
 */
int aml_ge2d_invalid_cache(aml_ge2d_info_t *pge2dinfo);

/**
 * @brief Synchronizes the data for GE2D with the device.
 * @param pge2dinfo Pointer to the GE2D information structure.
 * @param src_id Source ID.
 */
void aml_ge2d_sync_for_device(aml_ge2d_info_t *pge2dinfo, int src_id);

/**
 * @brief Synchronizes the data for GE2D with the CPU.
 * @param pge2dinfo Pointer to the GE2D information structure.
 */
void aml_ge2d_sync_for_cpu(aml_ge2d_info_t *pge2dinfo);

#if defined (__cplusplus)
}
#endif

#endif


