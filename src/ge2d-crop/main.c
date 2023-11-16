#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdint.h>
#include <fcntl.h>
#include <sys/time.h>

#include "../../libs/libge2d/include/ge2d_port.h"
#include "../../libs/libge2d/include/aml_ge2d.h"
#include "../../libs/libge2d/include/ge2d_com.h"

#include "../../libs/bmp/include/bmp.h"

int64_t get_cur_us() {
    struct timeval tv;
    gettimeofday(&tv,NULL);
    return tv.tv_sec * 1000000 + tv.tv_usec;
}

int64_t get_cur_ms() {
    struct timeval tv;
    gettimeofday(&tv,NULL);
    return tv.tv_sec * 1000 + tv.tv_usec / 1000;
}

int main(void) {
        int ret = 0;
        int64_t start, end;

        int src_width = 1920;
        int src_height = 1080;
        int src_format = PIXEL_FORMAT_RGBA_8888;

        int dst_width = 480;
        int dst_height = 270;
        int dst_format = PIXEL_FORMAT_RGBA_8888;

        int op = AML_GE2D_BLIT;

        aml_ge2d_t amlge2d;

    /* Prepare the struct for GE2D operation info*/
        memset(&amlge2d,0x0,sizeof(aml_ge2d_t));
        memset(&(amlge2d.ge2dinfo.src_info[0]), 0, sizeof(buffer_info_t));
        memset(&(amlge2d.ge2dinfo.src_info[1]), 0, sizeof(buffer_info_t));
        memset(&(amlge2d.ge2dinfo.dst_info), 0, sizeof(buffer_info_t));

    /* Initialize GE2D */
        amlge2d.ge2dinfo.src_info[0].memtype = GE2D_CANVAS_ALLOC;
        amlge2d.ge2dinfo.src_info[0].canvas_w = src_width;
        amlge2d.ge2dinfo.src_info[0].canvas_h = src_height;
        amlge2d.ge2dinfo.src_info[0].format = src_format;
        amlge2d.ge2dinfo.src_info[0].plane_number = 4;

        amlge2d.ge2dinfo.dst_info.memtype = GE2D_CANVAS_ALLOC;
        amlge2d.ge2dinfo.dst_info.canvas_w = dst_width;
        amlge2d.ge2dinfo.dst_info.canvas_h = dst_height;
        amlge2d.ge2dinfo.dst_info.format = dst_format;
        amlge2d.ge2dinfo.dst_info.plane_number = 4;

        amlge2d.ge2dinfo.offset = 0;
        amlge2d.ge2dinfo.ge2d_op = op;
        amlge2d.ge2dinfo.blend_mode = BLEND_MODE_PREMULTIPLIED;

        printf("Init aml ge2d\n");

        ret = aml_ge2d_init(&amlge2d);
        if (ret < 0)
            return ge2d_fail;

        ret = aml_ge2d_mem_alloc(&amlge2d);
        if (ret < 0)
            goto exit;

        if (amlge2d.src_size[0] == 0)
            return 0;

        bmp_read(amlge2d.ge2dinfo.src_info[0].vaddr[0], "./input_rgba.bmp");

    /* Configure for the crop operation */
        amlge2d.ge2dinfo.src_info[0].rect.x = 0;
        amlge2d.ge2dinfo.src_info[0].rect.y = 0;
        amlge2d.ge2dinfo.src_info[0].rect.w = src_width;
        amlge2d.ge2dinfo.src_info[0].rect.h = src_height;

        amlge2d.ge2dinfo.dst_info.rect.x = 0;
        amlge2d.ge2dinfo.dst_info.rect.y = 0;
        amlge2d.ge2dinfo.dst_info.rect.w = dst_width;
        amlge2d.ge2dinfo.dst_info.rect.h = dst_height;

        amlge2d.ge2dinfo.src_info[0].layer_mode = LAYER_MODE_PREMULTIPLIED;
        amlge2d.ge2dinfo.src_info[0].plane_alpha = 0xff;

        start = get_cur_us();
        ret = aml_ge2d_process(&amlge2d.ge2dinfo);
        end = get_cur_us();

        if (ret < 0) {
            printf("resize err\n");
        }
        else {
            printf("resize success\n");
            printf("exec time: %ld us\n", end - start);
        }

        bmp_write(amlge2d.ge2dinfo.dst_info.vaddr[0], "./output.bmp", 480, 270);

    exit:
        if (amlge2d.src_data[0]) {
            free(amlge2d.src_data[0]);
            amlge2d.src_data[0] = NULL;
        }
        if (amlge2d.dst_data[0]) {
            free(amlge2d.dst_data[0]);
            amlge2d.dst_data[0] = NULL;
        }
        
        aml_ge2d_mem_free(&amlge2d);
        aml_ge2d_exit(&amlge2d);

        return(0);
}
