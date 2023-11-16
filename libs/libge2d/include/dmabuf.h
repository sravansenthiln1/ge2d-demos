/*
 * Copyright (c) 2014 Amlogic, Inc. All rights reserved.
 *
 * This source code is subject to the terms and conditions defined in the
 * file 'LICENSE' which is part of this source code package.
 *
 * Description:
 */

#ifndef DMABUF_H
#define DMABUF_H
#if defined (__cplusplus)
extern "C" {
#endif

/**
 * @brief DMA buffer type, Operation Input/Output
 */
enum {
    GE2D_BUF_INPUT1,  /**< Input buffer 1. */
    GE2D_BUF_INPUT2,  /**< Input buffer 2. */
    GE2D_BUF_OUTPUT   /**< Output buffer. */
};

/**
 * @brief Allocates a DMA buffer of specified length for GE2D processing.
 * @param ge2d_fd File descriptor for GE2D.
 * @param type Type of DMA buffer (Input 1, Input 2, or Output).
 * @param len Length of the DMA buffer to allocate.
 * @return fd of the DMA buffer
 */
int dmabuf_alloc(int ge2d_fd, int type, unsigned int len);

/**
 * @brief Synchronizes a DMA buffer with the device.
 * @param ge2d_fd File descriptor for GE2D.
 * @param dma_fd File descriptor for the DMA buffer.
 * @return 0 on success (ge2d_success), -1 on failure (ge2d_fail).
 */
int dmabuf_sync_for_device(int ge2d_fd, int dma_fd);

/**
 * @brief Synchronizes a DMA buffer with the CPU.
 * @param ge2d_fd File descriptor for GE2D.
 * @param dma_fd File descriptor for the DMA buffer.
 * @return 0 on success (ge2d_success), -1 on failure (ge2d_fail).
 */
int dmabuf_sync_for_cpu(int ge2d_fd, int dma_fd);

#if defined (__cplusplus)
}
#endif

#endif

