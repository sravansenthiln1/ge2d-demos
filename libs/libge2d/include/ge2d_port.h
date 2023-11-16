/*
 * Copyright (c) 2014 Amlogic, Inc. All rights reserved.
 *
 * This source code is subject to the terms and conditions defined in the
 * file 'LICENSE' which is part of this source code package.
 *
 * Description:
 */

#ifndef GE2D_PORT_H_
#define GE2D_PORT_H_

#define ge2d_fail      -1
#define ge2d_success        0

#define OSD0        0
#define OSD1        1

#define SRC1_GB_ALPHA_ENABLE 0x80000000

#ifdef __DEBUG
#define D_GE2D(fmt, args...) printf(fmt, ## args)
#else
#define D_GE2D(fmt, args...)
#endif
#define E_GE2D(fmt, args...) printf(fmt, ## args)

#if defined (__cplusplus)
extern "C" {
#endif

int CANVAS_ALIGNED(int x);
int YV12_Y_ALIGNED(int x);

#define GE2D_MAX_PLANE  4

/**
 * @enum ge2d_data_type_e
 * @brief Different types of GE2D data.
 */
enum ge2d_data_type_e {
    AML_GE2D_SRC,          /**< Source data type. */
    AML_GE2D_SRC2,         /**< Second source data type. */
    AML_GE2D_DST,          /**< Destination data type. */
    AML_GE2D_TYPE_INVALID, /**< Invalid data type. */
};

/**
 * @typedef ge2d_canvas_t
 * @brief Different types of GE2D canvas.
 */
typedef enum {
    GE2D_CANVAS_OSD0 = 0,  /**< OSD0 canvas. */
    GE2D_CANVAS_OSD1,      /**< OSD1 canvas. */
    GE2D_CANVAS_ALLOC,     /**< Allocated canvas. */
    GE2D_CANVAS_TYPE_INVALID, /**< Invalid canvas type. */
} ge2d_canvas_t;

/**
 * @enum ge2d_memtype_s
 * @brief Different types of GE2D memory.
 */
enum ge2d_memtype_s {
    AML_GE2D_MEM_ION,      /**< ION (Input/Output Memory Management Unit) memory type. */
    AML_GE2D_MEM_DMABUF,   /**< DMABUF (DMA Buffer) memory type. */
    AML_GE2D_MEM_INVALID,  /**< Invalid memory type. */
};

/**
 * @typedef layer_mode_t
 * @brief Different layer modes in GE2D operations.
 */
typedef enum {
    LAYER_MODE_INVALID = 0,         /**< Invalid layer mode. */
    LAYER_MODE_NONE = 1,             /**< Non-layer mode. */
    LAYER_MODE_PREMULTIPLIED = 2,   /**< Premultiplied layer mode. */
    LAYER_MODE_COVERAGE = 3,        /**< Coverage layer mode. */
} layer_mode_t;

/**
 * @typedef blend_mode_t
 * @brief Different blending modes in GE2D operations.
 */
typedef enum {
    BLEND_MODE_INVALID = 0,          /**< Invalid blending mode. */

    /* colorOut = colorSrc */
    BLEND_MODE_NONE = 1,             /**< No blending mode. */

    /* colorOut = colorSrc + colorDst * (1 - alphaSrc) */
    BLEND_MODE_PREMULTIPLIED = 2,    /**< Premultiplied blending mode. */

    /* colorOut = colorSrc * alphaSrc + colorDst * (1 - alphaSrc) */
    BLEND_MODE_COVERAGE = 3,         /**< Coverage blending mode. */
} blend_mode_t;

/**
 * @enum pixel_format_t
 * @brief Different pixel formats in GE2D operations.
 */
typedef enum  {
    PIXEL_FORMAT_RGBA_8888          = 1,
    PIXEL_FORMAT_RGBX_8888          = 2,
    PIXEL_FORMAT_RGB_888            = 3,
    PIXEL_FORMAT_RGB_565            = 4,
    PIXEL_FORMAT_BGRA_8888          = 5,
    PIXEL_FORMAT_YV12               = 6,           // YCrCb 4:2:0 Planar  YYYY......  V......U......
    PIXEL_FORMAT_Y8                 = 7,           // YYYY
    PIXEL_FORMAT_YCbCr_422_SP       = 0x10,        // NV16   YYYY.....UVUV....
    PIXEL_FORMAT_YCrCb_420_SP       = 0x11,        // NV21   YCrCb YYYY.....VU....
    PIXEL_FORMAT_YCbCr_422_UYVY     = 0x14,        // UYVY   U0-Y0-V0-Y1 U2-Y2-V2-Y3 U4 ...
    PIXEL_FORMAT_BGR_888,
    PIXEL_FORMAT_YCbCr_420_SP_NV12,                // NV12 YCbCr YYYY.....UV....
    PIXEL_FORMAT_ARGB_8888,
    PIXEL_FORMAT_ABGR_8888,
    PIXEL_FORMAT_YU12,                             // YCbCr 4:2:0 Planar  YYYY......  U......V......
    PIXEL_FORMAT_ARGB_1555,
    PIXEL_FORMAT_ARGB_4444,
    PIXEL_FORMAT_RGBA_4444,
    PIXEL_FORMAT_CLUT8
} pixel_format_t;

#define PIXEL_FORMAT_LITTLE_ENDIAN 0
#define PIXEL_FORMAT_BIG_ENDIAN    1

/* if customized matrix is used, set this flag in format */
#define MATRIX_CUSTOM               (0x80000000)

/* if customized stride is used, set this flag in format */
#define STRIDE_CUSTOM               (0x40000000)

/* if full range is used, set this flag in format */
#define FORMAT_FULL_RANGE           (0x20000000)

#define EXT_FUN_MASK               ((1 << 25) | ( 1 << 26) | ( 1 << 27) | (1 << 28))
/* if dst x repeat is used, 2/4/8 times, set this flag in format */
#define DST_REPEAT_2                (1 << 28)
#define DST_REPEAT_4                (1 << 27)
#define DST_REPEAT_8                ((1 << 28) | (1 << 27))

/* if dst repeat is used, set this flag in format */
#define DST_SIGN_MDOE               (1 << 26)

/* capability flags */
#define DST_SIGN_MODE   (1 << 8)
#define DST_REPEAT      (1 << 7)
#define CANVAS_STATUS   ((1 << 5) | (1 << 6))
#define HAS_SELF_POWER  (1 << 4)
#define DEEP_COLOR      (1 << 3)
#define ADVANCED_MATRIX (1 << 2)
#define SRC2_REPEAT     (1 << 1)
#define SRC2_ALPHA      (1 << 0)

/**
 * @typedef GE2D_ROTATION
 * @brief Different rotation and mirroring modes in GE2D operations.
 */
typedef enum {
    GE2D_ROTATION_0,    /**< Rotation 0 degrees. */
    GE2D_ROTATION_90,   /**< Rotation 90 degrees. */
    GE2D_ROTATION_180,  /**< Rotation 180 degrees. */
    GE2D_ROTATION_270,  /**< Rotation 270 degrees. */
    GE2D_MIRROR_X,      /**< Mirror along the X-axis. */
    GE2D_MIRROR_Y,      /**< Mirror along the Y-axis. */
} GE2D_ROTATION;

/**
 * @typedef GE2DOP
 * @brief Different GE2D operations.
 */
typedef enum {
    AML_GE2D_FILLRECTANGLE,  /**< Fill rectangle operation. */
    AML_GE2D_BLEND,         /**< Blend operation. */
    AML_GE2D_STRETCHBLIT,   /**< Stretch blit operation. */
    AML_GE2D_BLIT,          /**< Blit operation. */
    AML_GE2D_NONE,          /**< No operation. */
} GE2DOP;

/**
 * @struct rectangle_t
 * @brief GE2D rectangle with its position (x, y) and dimensions (width, height).
 */
typedef struct {
    int x; /**< X-coordinate of the top-left corner. */
    int y; /**< Y-coordinate of the top-left corner. */
    int w; /**< Width of the rectangle. */
    int h; /**< Height of the rectangle. */
} rectangle_t;

/**
 * @struct buffer_info_t
 * @brief Information about a buffer used in GE2D operations.
 */
typedef struct buffer_info {
    unsigned int mem_alloc_type;  /**< Memory allocation type. */
    unsigned int memtype;         /**< Memory type. */
    char* vaddr[GE2D_MAX_PLANE];  /**< Virtual addresses of planes. */
    unsigned long offset[GE2D_MAX_PLANE]; /**< Offsets of planes. */
    unsigned int canvas_w;        /**< Canvas width. */
    unsigned int canvas_h;        /**< Canvas height. */
    rectangle_t rect;             /**< Rectangle information. */
    int format;                   /**< Pixel format. */
    unsigned int rotation;        /**< Rotation mode. */
    int shared_fd[GE2D_MAX_PLANE];/**< Shared file descriptors. */
    unsigned char plane_alpha;    /**< Plane alpha value. */
    unsigned char layer_mode;     /**< Layer mode. */
    unsigned char fill_color_en;  /**< Fill color enable flag. */
    unsigned int def_color;       /**< Default color. */
    int plane_number;             /**< Number of planes. */
    unsigned char endain;         /**< Endian type. */
} buffer_info_t;

/**
 * @struct ge2d_matrix_s
 * @brief Matrix for GE2D operations.
 */
struct ge2d_matrix_s {
	unsigned int pre_offset0;
	unsigned int pre_offset1;
	unsigned int pre_offset2;
	unsigned int coef0;
	unsigned int coef1;
	unsigned int coef2;
	unsigned int coef3;
	unsigned int coef4;
	unsigned int coef5;
	unsigned int coef6;
	unsigned int coef7;
	unsigned int coef8;
	unsigned int offset0;
	unsigned int offset1;
	unsigned int offset2;
	/* input y/cb/cr saturation enable */
	unsigned char sat_in_en;
};

/**
 * @struct ge2d_stride_s
 * @brief Strides for source and destination in GE2D operations.
 */
struct ge2d_stride_s {
	unsigned int src1_stride[GE2D_MAX_PLANE];
	unsigned int src2_stride[GE2D_MAX_PLANE];
	unsigned int dst_stride[GE2D_MAX_PLANE];
};

/**
 * @struct ge2d_clut8_t
 * @brief CLUT (Color Look-Up Table) for 8-bit color format.
 */
struct ge2d_clut8_t {
    unsigned int data[256];
    unsigned int count;
};

/**
 * @typedef aml_ge2d_info_t
 * @brief Information about a GE2D operation.
 */
typedef struct aml_ge2d_info {
    int ge2d_fd;               /**< GE2D file descriptor. */
    int ion_fd;                /**< ION file descriptor. */
    unsigned int offset;       /**< Offset value. */
    unsigned int blend_mode;   /**< Blend mode. */
    GE2DOP ge2d_op;            /**< GE2D operation type. */
    buffer_info_t src_info[2]; /**< Source buffer information. */
    buffer_info_t dst_info;    /**< Destination buffer information. */
    unsigned int color;        /**< Color value. */
    unsigned int gl_alpha;     /**< Global alpha value. */
    unsigned int const_color;  /**< Constant color value. */
    /* means do multi ge2d op */
    unsigned int dst_op_cnt;   /**< Destination operation count. */
    int cap_attr;              /**< Capability attribute. */
    int b_src_swap;            /**< Source swap flag. */
    struct ge2d_matrix_s matrix_custom; /**< Custom matrix for GE2D operation. */
    struct ge2d_stride_s stride_custom; /**< Custom strides for GE2D operation. */
    unsigned int reserved;     /**< Reserved field. */
} aml_ge2d_info_t;

/**
 * @brief Opens the GE2D device.
 * @param None.
 * @return Returns 0 on success (ge2d_success), -1 on failure (ge2d_fail).
 */
int ge2d_open(void);


/**
 * @brief Closes the GE2D device.
 * @param fd File descriptor for GE2D.
 * @return Returns 0 on success (ge2d_success), -1 on failure (ge2d_fail).
 */
int ge2d_close(int fd);

/**
 * @brief Retrieves the capabilities of the GE2D device.
 * @param fd File descriptor for GE2D.
 * @return Returns 0 on success (ge2d_success), -1 on failure (ge2d_fail).
 */
int ge2d_get_cap(int fd);

/**
 * @brief Processes the GE2D operation.
 * @param fd File descriptor for GE2D.
 * @param pge2dinfo Pointer to GE2D information structure.
 * @param enqueue Flag indicating whether to enqueue the operation.
 * @return Returns 0 on success (ge2d_success), -1 on failure (ge2d_fail).
 */
int ge2d_process(int fd, aml_ge2d_info_t *pge2dinfo, int enqueue);

/**
 * @brief Posts the GE2D operation to the queue.
 * @param fd File descriptor for GE2D.
 * @return 0 on success (ge2d_success), -1 on failure (ge2d_fail).
 */
int ge2d_post_queue(int fd);

/**
 * @brief Attaches the DMA file descriptor for GE2D data type.
 * @param fd File descriptor for GE2D.
 * @param pge2dinfo Pointer to GE2D information structure.
 * @param data_type GE2D data type.
 * @return Returns 0 on success (ge2d_success), -1 on failure (ge2d_fail).
 */
int ge2d_attach_dma_fd(int fd, aml_ge2d_info_t *pge2dinfo, enum 
                ge2d_data_type_e data_type);

/**
 * @brief Configures the GE2D operation.
 * @param fd File descriptor for GE2D.
 * @param pge2dinfo Pointer to GE2D information structure.
 * @return Returns 0 on success (ge2d_success), -1 on failure (ge2d_fail).
 */
int ge2d_config(int fd, aml_ge2d_info_t *pge2dinfo);

/**
 * @brief Executes the GE2D operation.
 * @param fd File descriptor for GE2D.
 * @param pge2dinfo Pointer to GE2D information structure.
 * @param enqueue Flag indicating whether to enqueue the operation.
 * @return Returns 0 on success (ge2d_success), -1 on failure (ge2d_fail).
 */
int ge2d_execute(int fd, aml_ge2d_info_t *pge2dinfo, int enqueue);

/**
 * @brief Detaches the DMA file descriptor for GE2D data type.
 * @param fd File descriptor for GE2D.
 * @param data_type GE2D data type.
 * @return None.
 */
void ge2d_detach_dma_fd(int fd, enum ge2d_data_type_e data_type);

/* for dst buffer */
/**
 * @brief Synchronizes the destination DMA buffer to the CPU.
 * @param pge2dinfo Pointer to GE2D information structure.
 * @return None.
 */
void sync_dst_dmabuf_to_cpu(aml_ge2d_info_t *pge2dinfo);

/* for src0 or src1, use src_id to config */
/**
 * @brief Synchronizes the source DMA buffer to the device for src0 or src1.
 * @param pge2dinfo Pointer to GE2D information structure.
 * @param src_id Source ID to configure.
 * @return None.
 */
void sync_src_dmabuf_to_device(aml_ge2d_info_t *pge2dinfo, int src_id);

/**
 * @brief Processes the GE2D operation with ION memory allocation.
 * @param fd File descriptor for GE2D.
 * @param pge2dinfo Pointer to GE2D information structure.
 * @return Returns 0 on success (ge2d_success), -1 on failure (ge2d_fail).
 */
int ge2d_process_ion(int fd, aml_ge2d_info_t *pge2dinfo);

/**
 * @brief Sets the CLUT8 table for GE2D operation.
 * @param fd File descriptor for GE2D.
 * @param clut8_table Pointer to the CLUT8 table structure.
 * @return Returns 0 on success (ge2d_success), -1 on failure (ge2d_fail).
 */
int ge2d_set_clut8_table(int fd, struct ge2d_clut8_t *clut8_table);

#if defined (__cplusplus)
}
#endif

#endif
