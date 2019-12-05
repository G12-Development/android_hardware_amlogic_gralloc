/*
 * Copyright (c) 2017 Amlogic, Inc. All rights reserved.
 *
 * This source code is subject to the terms and conditions defined in the
 * file 'LICENSE' which is part of this source code package.
 *
 * Description:
 */

#ifndef AM_GRALLOC_EXT_H
#define AM_GRALLOC_EXT_H

#include <utils/NativeHandle.h>


bool am_gralloc_is_valid_graphic_buffer(const native_handle_t * hnd);

/*
For modules to set special usage to window.
all producer usage is in android.hardware.graphics.common@1.0.BufferUsage.
*/
uint64_t am_gralloc_get_video_overlay_producer_usage();
uint64_t am_gralloc_get_omx_metadata_producer_usage();
uint64_t am_gralloc_get_omx_osd_producer_usage();

/*
For modules
The usage is in android.hardware.graphics.common@1.0.BufferUsage.
*/
bool am_gralloc_is_omx_metadata_producer(uint64_t usage);
bool am_gralloc_is_omx_osd_producer(uint64_t usage);

/*
For modules get buffer information.
*/
int am_gralloc_get_format(const native_handle_t * bufferhnd);
int am_gralloc_get_buffer_fd(const native_handle_t * hnd);
int am_gralloc_get_stride_in_byte(const native_handle_t * hnd);
int am_gralloc_get_stride_in_pixel(const native_handle_t * hnd);
int am_gralloc_get_width(const native_handle_t * hnd);
int am_gralloc_get_height(const native_handle_t * hnd);
int am_gralloc_get_size(const native_handle_t * hnd);
uint64_t am_gralloc_get_producer_usage(const native_handle_t * hnd);
uint64_t am_gralloc_get_consumer_usage(const native_handle_t * hnd);
uint64_t am_gralloc_get_usage(const native_handle_t * hnd);

/*
For modules to check special buffer.
*/
bool am_gralloc_is_secure_buffer(const native_handle_t *hnd);
bool am_gralloc_is_coherent_buffer(const native_handle_t * hnd);
bool am_gralloc_is_overlay_buffer(const native_handle_t * hnd);
bool am_gralloc_is_omx_metadata_buffer(const native_handle_t * hnd);
bool am_gralloc_is_omx_v4l_buffer(const native_handle_t * hnd);
bool am_gralloc_is_video_dma_buffer(const native_handle_t *hnd);

/*
For modules to get/set omx video pipeline.
*/
int am_gralloc_get_omx_metadata_tunnel(const native_handle_t * hnd, int * tunnel);
int am_gralloc_set_omx_metadata_tunnel(const native_handle_t * hnd, int tunnel);

/*
For modules to get/set omx video type.
*/
int am_gralloc_get_omx_video_type(const native_handle_t * hnd, int * video_type);
int am_gralloc_set_omx_video_type(const native_handle_t * hnd, int video_type);

/*
For modules create sideband handle.
*/
typedef enum {
    AM_TV_SIDEBAND = 1,
    AM_OMX_SIDEBAND = 2,
    AM_AMCODEX_SIDEBAND = 3
} AM_SIDEBAND_TYPE;

typedef enum {
    AM_VIDEO_DEFAULT = 1,
    AM_VIDEO_EXTERNAL = 2
} AM_VIDEO_CHANNEL;

typedef enum {
    AM_VIDEO_DV          = 0x1,
    AM_VIDEO_HDR         = 0x2,
    AM_VIDEO_HDR10_PLUS  = 0x4,
    AM_VIDEO_HLG         = 0x8,
    AM_VIDEO_SECURE      = 0x10,
    AM_VIDEO_AFBC        = 0x20,
    AM_VIDEO_DI_POST     = 0x40,
    AM_VIDEO_4K          = 0x80,
} AM_VIDEO_TYPE;

native_handle_t * am_gralloc_create_sideband_handle(int type, int channel);
int am_gralloc_destroy_sideband_handle(native_handle_t * hnd);
int am_gralloc_get_sideband_channel(const native_handle_t * hnd, int * channel);


/*
Used by hwc to get afbc information.
*/
typedef enum {
    VPU_AFBC_EN                                 = (1 << 31),
    VPU_AFBC_TILED_HEADER_EN    = (1 << 18),
    VPU_AFBC_SUPER_BLOCK_ASPECT = (1 << 16),
    VPU_AFBC_BLOCK_SPLIT                = (1 << 9),
    VPU_AFBC_YUV_TRANSFORM              = (1 << 8),
} AM_VPU_AFBC_MASK;

int am_gralloc_get_vpu_afbc_mask(const native_handle_t * hnd);

/*
Get/Set amlogic extend info.
*/
typedef enum {
    AM_PRIV_ATTR_OMX_PTS_PRODUCER = (1 << 0),
    AM_PRIV_ATTR_OMX_V4L_PRODUCER = (1 << 1),
} AM_PRIV_ATTR_MASK;

int am_gralloc_get_omx_v4l_file(const native_handle_t * hnd);
int am_gralloc_get_video_dma_buf_fd(const native_handle_t * hnd);
int am_gralloc_attr_set_omx_v4l_producer_flag(native_handle_t * hnd);
int am_gralloc_attr_set_omx_pts_producer_flag(native_handle_t * hnd);

#endif/*AM_GRALLOC_EXT_H*/
