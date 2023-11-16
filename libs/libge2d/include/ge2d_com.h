/*
 * Copyright (c) 2014 Amlogic, Inc. All rights reserved.
 *
 * This source code is subject to the terms and conditions defined in the
 * file 'LICENSE' which is part of this source code package.
 *
 * Description:
 */

#ifndef GE2D_COM_H_
#define GE2D_COM_H_

#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>
#include <string.h>
#include "ge2d_port.h"

/**
 * @struct ge2d_op_para_t
 * @brief Parameters for a GE2D operation.
 */
typedef struct {
    unsigned int color; /**< Color parameter for the operation. */
    rectangle_t src1_rect; /**< Source rectangle for the first input. */
    rectangle_t src2_rect; /**< Source rectangle for the second input. */
    rectangle_t dst_rect; /**< Destination rectangle for the output. */
    int op; /**< Operation code. */
} ge2d_op_para_t;

/**
 * @struct ge2d_blend_op
 * @brief Blending parameters for a GE2D operation.
 */
typedef struct {
    unsigned int color_blending_mode; /**< Color blending mode. */
    unsigned int color_blending_src_factor; /**< Factor for color blending on Source. */
    unsigned int color_blending_dst_factor; /**< Factor for color blending on Destination. */
    unsigned int alpha_blending_mode; /**< Select Alpha blending mode. */
    unsigned int alpha_blending_src_factor; /**< Factor for alpha blending on source. */
    unsigned int alpha_blending_dst_factor; /**< Factor for alpha blending on destination. */
} ge2d_blend_op;

#endif
