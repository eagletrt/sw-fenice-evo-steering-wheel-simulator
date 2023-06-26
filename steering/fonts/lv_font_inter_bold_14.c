/*******************************************************************************
 * Size: 14 px
 * Bpp: 2
 * Opts:
 ******************************************************************************/

#ifdef LV_LVGL_H_INCLUDE_SIMPLE
#include "lvgl.h"
#else
#include "lvgl/lvgl.h"
#endif

#ifndef LV_FONT_INTER_BOLD_14
#define LV_FONT_INTER_BOLD_14 1
#endif

#if LV_FONT_INTER_BOLD_14

/*-----------------
 *    BITMAPS
 *----------------*/

/*Store the image of the glyphs*/
static LV_ATTRIBUTE_LARGE_CONST const uint8_t glyph_bitmap[] = {
    /* U+0020 " " */

    /* U+0021 "!" */
    0xf7, 0xdf, 0x6d, 0xb6, 0xcb, 0x4, 0x13, 0xdb, 0x0,

    /* U+0022 "\"" */
    0x72, 0xdc, 0xb7, 0x2d, 0xcb,

    /* U+0023 "#" */
    0x7, 0x4b, 0x1, 0xc3, 0xc0, 0xb0, 0xe0, 0xff, 0xff, 0x2f, 0xbe, 0x43, 0x87,
    0x0, 0xd2, 0xc2, 0xff, 0xfd, 0xbe, 0xbe, 0xb, 0xe, 0x3, 0xc3, 0x40,

    /* U+0024 "$" */
    0x0, 0xc0, 0x2, 0xfe, 0x2, 0xff, 0xf0, 0xf7, 0x3d, 0x3c, 0xc1, 0xf, 0xf4,
    0x0, 0xff, 0xd0, 0x3, 0xfd, 0x14, 0xcb, 0x9f, 0x33, 0xd3, 0xff, 0xf0, 0x2f,
    0xe0, 0x0, 0xc0, 0x0, 0x0, 0x0,

    /* U+0025 "%" */
    0x3e, 0x1, 0xcb, 0x74, 0x30, 0xe3, 0x8e, 0xb, 0x39, 0xc0, 0x3f, 0x34, 0x0,
    0xa, 0x0, 0x1, 0xcb, 0xc0, 0x35, 0xde, 0xa, 0x2c, 0xb0, 0xc1, 0xde, 0x34,
    0xb, 0xc0,

    /* U+0026 "&" */
    0x7, 0xe0, 0x0, 0xff, 0x80, 0x2d, 0x3c, 0x1, 0xe7, 0x80, 0xf, 0xf0, 0x0,
    0xfc, 0x10, 0x3f, 0xe3, 0x87, 0xcb, 0xf8, 0x7c, 0x3f, 0x3, 0xff, 0xf0, 0xb,
    0xe7, 0xc0,

    /* U+0027 "'" */
    0x71, 0xc7, 0x1c,

    /* U+0028 "(" */
    0xf, 0xb, 0x83, 0xc1, 0xf0, 0xb8, 0x2e, 0xb, 0x82, 0xe0, 0xb8, 0x1f, 0x3,
    0xc0, 0xb8, 0xf, 0x0, 0x0,

    /* U+0029 ")" */
    0x78, 0xf, 0x41, 0xe0, 0x3c, 0xf, 0x3, 0xd0, 0xf4, 0x3d, 0xf, 0x3, 0xc1,
    0xe0, 0xf4, 0x78, 0x0, 0x0,

    /* U+002A "*" */
    0xa, 0xa, 0xa9, 0x7f, 0x87, 0xfd, 0x6a, 0x90, 0xa0,

    /* U+002B "+" */
    0x3, 0x80, 0x3, 0x80, 0x3, 0x80, 0xff, 0xfd, 0xbf, 0xfc, 0x3, 0x80, 0x3,
    0x80, 0x1, 0x0,

    /* U+002C "," */
    0x0, 0x2c, 0x2c, 0x38, 0x34,

    /* U+002D "-" */
    0x2a, 0x93, 0xfe,

    /* U+002E "." */
    0x14, 0x3c, 0x3c,

    /* U+002F "/" */
    0x1, 0x80, 0x3c, 0x3, 0xc0, 0x74, 0xb, 0x0, 0xf0, 0xe, 0x1, 0xd0, 0x2c, 0x3,
    0xc0, 0x38, 0x7, 0x40, 0xb0, 0x0,

    /* U+0030 "0" */
    0x3, 0xf8, 0x3, 0xff, 0xc3, 0xe0, 0xf4, 0xf0, 0x2e, 0x3c, 0x7, 0xdf, 0x1,
    0xf3, 0xc0, 0x7c, 0xf0, 0x2e, 0x3e, 0xf, 0x43, 0xff, 0xc0, 0x3f, 0x80,

    /* U+0031 "1" */
    0xb, 0xd3, 0xfd, 0x7b, 0xd1, 0x3d, 0x3, 0xd0, 0x3d, 0x3, 0xd0, 0x3d, 0x3,
    0xd0, 0x3d, 0x3, 0xd0,

    /* U+0032 "2" */
    0xb, 0xf4, 0xb, 0xff, 0x43, 0xc1, 0xf0, 0x50, 0x3c, 0x0, 0x2e, 0x0, 0x1f,
    0x0, 0x1f, 0x40, 0x1f, 0x40, 0x1f, 0x40, 0xf, 0xff, 0xc3, 0xff, 0xf0,

    /* U+0033 "3" */
    0x7, 0xf8, 0xb, 0xff, 0x83, 0xc0, 0xf0, 0x0, 0x3c, 0x1, 0xbd, 0x0, 0xbf,
    0x40, 0x1, 0xf0, 0x40, 0x3d, 0x3c, 0xf, 0x4b, 0xff, 0xc0, 0xbf, 0x80,

    /* U+0034 "4" */
    0x0, 0x7e, 0x0, 0x3f, 0x80, 0x2f, 0xe0, 0xf, 0x78, 0xb, 0x5e, 0x7, 0xc7,
    0x83, 0xc1, 0xe1, 0xff, 0xfe, 0x7f, 0xff, 0xc0, 0x7, 0x80, 0x1, 0xe0,

    /* U+0035 "5" */
    0x1f, 0xff, 0xb, 0xff, 0x82, 0xd0, 0x0, 0xb0, 0x0, 0x3d, 0xf8, 0xf, 0xef,
    0xc0, 0x0, 0xf0, 0x0, 0x3d, 0x3c, 0xf, 0xb, 0xff, 0x80, 0x7f, 0x80,

    /* U+0036 "6" */
    0x2, 0xf8, 0x3, 0xff, 0x82, 0xe0, 0xf4, 0xf0, 0x0, 0x3d, 0xfc, 0x1f, 0xef,
    0xc7, 0xd0, 0xf4, 0xf0, 0x2e, 0x3d, 0xf, 0x47, 0xff, 0xc0, 0x7f, 0x80,

    /* U+0037 "7" */
    0x7f, 0xfe, 0x7f, 0xfe, 0x0, 0x3d, 0x0, 0x7c, 0x0, 0xf4, 0x0, 0xf0, 0x2,
    0xe0, 0x3, 0xc0, 0xb, 0x80, 0xf, 0x0, 0x2e, 0x0,

    /* U+0038 "8" */
    0x7, 0xf8, 0xb, 0xef, 0xc3, 0xd0, 0xf0, 0xf4, 0x3c, 0xf, 0xbd, 0x3, 0xff,
    0x43, 0xd1, 0xf1, 0xf0, 0x2e, 0x3c, 0xf, 0x4f, 0xef, 0xc0, 0xbf, 0x80,

    /* U+0039 "9" */
    0x7, 0xf4, 0xb, 0xff, 0x83, 0xc0, 0xf1, 0xf0, 0x3d, 0x3c, 0xf, 0x8f, 0xef,
    0xe0, 0xbd, 0xb4, 0x40, 0x3d, 0x3d, 0x1f, 0xb, 0xff, 0x40, 0x7f, 0x40,

    /* U+003A ":" */
    0x3c, 0x3c, 0x14, 0x0, 0x0, 0x14, 0x3c, 0x3c,

    /* U+003B ";" */
    0x2c, 0x3d, 0x4, 0x0, 0x0, 0x0, 0x2c, 0x2c, 0x38, 0x34, 0x0,

    /* U+003C "<" */
    0x0, 0x0, 0x0, 0x2d, 0x2, 0xfc, 0x2f, 0xe0, 0xfd, 0x0, 0xbf, 0x40, 0x1b,
    0xf8, 0x0, 0xbd, 0x0, 0x8,

    /* U+003D "=" */
    0xbf, 0xfc, 0xbf, 0xfc, 0x0, 0x0, 0xbf, 0xfc, 0xbf, 0xfc,

    /* U+003E ">" */
    0x0, 0x0, 0xa4, 0x0, 0xbf, 0x40, 0x1b, 0xf4, 0x0, 0xbd, 0x2, 0xfc, 0x6f,
    0xd0, 0xfd, 0x0, 0x90, 0x0,

    /* U+003F "?" */
    0xf, 0xe0, 0x3f, 0xfc, 0x78, 0x3c, 0x0, 0x3c, 0x0, 0xf8, 0x3, 0xe0, 0x7,
    0xc0, 0x2, 0x40, 0x1, 0x0, 0x7, 0xc0, 0x7, 0x80,

    /* U+0040 "@" */
    0x0, 0x6f, 0xe4, 0x0, 0x2f, 0xef, 0xe0, 0xb, 0x80, 0xb, 0x81, 0xe1, 0xa6,
    0x6d, 0x2c, 0x7f, 0xf8, 0xe3, 0xcf, 0xb, 0x8f, 0x38, 0xe0, 0x38, 0xf3, 0x8e,
    0x3, 0x8f, 0x3c, 0xf0, 0x78, 0xe3, 0xcb, 0xef, 0xfd, 0x1e, 0x2f, 0x9f, 0x40,
    0xf8, 0x0, 0x0, 0x3, 0xfe, 0xf8, 0x0, 0x7, 0xff, 0x40,

    /* U+0041 "A" */
    0x1, 0xfc, 0x0, 0xb, 0xf0, 0x0, 0x3f, 0xd0, 0x1, 0xf7, 0x80, 0xb, 0x8f, 0x0,
    0x3d, 0x3d, 0x0, 0xf0, 0xb8, 0xb, 0xff, 0xf0, 0x3f, 0xab, 0xd0, 0xf0, 0xb,
    0x8b, 0xc0, 0x1f, 0x0,

    /* U+0042 "B" */
    0x3f, 0xf8, 0xf, 0xff, 0xc3, 0xc0, 0xf4, 0xf0, 0x3d, 0x3c, 0x1f, 0xf, 0xff,
    0x3, 0xea, 0xf0, 0xf0, 0x2e, 0x3c, 0xb, 0x8f, 0xff, 0xd3, 0xff, 0xd0,

    /* U+0043 "C" */
    0x2, 0xfe, 0x0, 0xff, 0xfc, 0x2f, 0x3, 0xd3, 0xd0, 0x1e, 0x3c, 0x0, 0x7,
    0xc0, 0x0, 0x3c, 0x0, 0x3, 0xd0, 0x1e, 0x2f, 0x3, 0xd0, 0xff, 0xfc, 0x2,
    0xfe, 0x0,

    /* U+0044 "D" */
    0x3f, 0xf8, 0x3, 0xff, 0xf0, 0x3c, 0xb, 0xc3, 0xc0, 0x3c, 0x3c, 0x3, 0xd3,
    0xc0, 0x2d, 0x3c, 0x3, 0xd3, 0xc0, 0x3c, 0x3c, 0xb, 0xc3, 0xff, 0xf0, 0x3f,
    0xf8, 0x0,

    /* U+0045 "E" */
    0x3f, 0xff, 0x3f, 0xfe, 0x3c, 0x0, 0x3c, 0x0, 0x3c, 0x0, 0x3f, 0xfd, 0x3f,
    0xfd, 0x3c, 0x0, 0x3c, 0x0, 0x3f, 0xfe, 0x3f, 0xff,

    /* U+0046 "F" */
    0x3f, 0xfe, 0x3f, 0xfe, 0x3c, 0x0, 0x3c, 0x0, 0x3c, 0x0, 0x3f, 0xfc, 0x3f,
    0xfc, 0x3c, 0x0, 0x3c, 0x0, 0x3c, 0x0, 0x3c, 0x0,

    /* U+0047 "G" */
    0x2, 0xfe, 0x0, 0xff, 0xfc, 0x2f, 0x3, 0xd3, 0xd0, 0x1a, 0x3c, 0x0, 0x7,
    0xc0, 0xaa, 0x3c, 0x1f, 0xf3, 0xd0, 0x1f, 0x2f, 0x3, 0xe0, 0xff, 0xfc, 0x2,
    0xfe, 0x0,

    /* U+0048 "H" */
    0x3c, 0x2, 0xe3, 0xc0, 0x2e, 0x3c, 0x2, 0xe3, 0xc0, 0x2e, 0x3c, 0x2, 0xe3,
    0xff, 0xfe, 0x3f, 0xff, 0xe3, 0xc0, 0x2e, 0x3c, 0x2, 0xe3, 0xc0, 0x2e, 0x3c,
    0x2, 0xe0,

    /* U+0049 "I" */
    0x3c, 0x3c, 0x3c, 0x3c, 0x3c, 0x3c, 0x3c, 0x3c, 0x3c, 0x3c, 0x3c,

    /* U+004A "J" */
    0x0, 0x3c, 0x0, 0x3c, 0x0, 0x3c, 0x0, 0x3c, 0x0, 0x3c, 0x0, 0x3c, 0x0, 0x3c,
    0x0, 0x3c, 0xb8, 0x3c, 0x7f, 0xf8, 0x1f, 0xd0,

    /* U+004B "K" */
    0x3c, 0xb, 0xc3, 0xc1, 0xf4, 0x3c, 0x3d, 0x3, 0xcf, 0x80, 0x3e, 0xf0, 0x3,
    0xff, 0x0, 0x3f, 0xf8, 0x3, 0xd7, 0xd0, 0x3c, 0x2f, 0x3, 0xc0, 0xf8, 0x3c,
    0x7, 0xc0,

    /* U+004C "L" */
    0x3c, 0x0, 0x3c, 0x0, 0x3c, 0x0, 0x3c, 0x0, 0x3c, 0x0, 0x3c, 0x0, 0x3c, 0x0,
    0x3c, 0x0, 0x3c, 0x0, 0x3f, 0xfd, 0x3f, 0xfd,

    /* U+004D "M" */
    0x3e, 0x0, 0x3f, 0x3f, 0x0, 0x7f, 0x3f, 0x40, 0xbf, 0x3f, 0xc0, 0xff, 0x3e,
    0xc1, 0xef, 0x3d, 0xe3, 0xdf, 0x3c, 0xf3, 0xcf, 0x3c, 0xbf, 0x4f, 0x3c,
    0x3f, 0xf, 0x3c, 0x3e, 0xf, 0x3c, 0x1d, 0xf,

    /* U+004E "N" */
    0x3c, 0x2, 0xd3, 0xe0, 0x2d, 0x3f, 0x42, 0xd3, 0xfc, 0x2d, 0x3e, 0xe2, 0xd3,
    0xcf, 0x6d, 0x3c, 0x7f, 0xd3, 0xc2, 0xfd, 0x3c, 0xf, 0xd3, 0xc0, 0x7d, 0x3c,
    0x3, 0xd0,

    /* U+004F "O" */
    0x2, 0xfe, 0x0, 0x3f, 0xff, 0x2, 0xf0, 0x7e, 0xf, 0x40, 0x7c, 0x3c, 0x0,
    0xf1, 0xf0, 0x3, 0xc3, 0xc0, 0xf, 0xf, 0x40, 0x7c, 0x2f, 0x7, 0xe0, 0x3f,
    0xff, 0x0, 0x2f, 0xe0, 0x0,

    /* U+0050 "P" */
    0x3f, 0xf8, 0xf, 0xff, 0xc3, 0xc0, 0xf4, 0xf0, 0x2e, 0x3c, 0xf, 0x4f, 0x7,
    0xd3, 0xff, 0xe0, 0xff, 0x90, 0x3c, 0x0, 0xf, 0x0, 0x3, 0xc0, 0x0,

    /* U+0051 "Q" */
    0x2, 0xfe, 0x0, 0x3f, 0xff, 0x2, 0xf0, 0x7e, 0xf, 0x40, 0x7c, 0x3c, 0x0,
    0xf1, 0xf0, 0x3, 0xc3, 0xc0, 0xf, 0xf, 0x4e, 0x7c, 0x2f, 0x1f, 0xe0, 0x3f,
    0xff, 0x0, 0x2f, 0xfc, 0x0, 0x0, 0x14,

    /* U+0052 "R" */
    0x3f, 0xf8, 0xf, 0xff, 0xc3, 0xc0, 0xf4, 0xf0, 0x2e, 0x3c, 0xf, 0x4f, 0xff,
    0xc3, 0xff, 0xc0, 0xf0, 0xf0, 0x3c, 0x2e, 0xf, 0x3, 0xc3, 0xc0, 0xb8,

    /* U+0053 "S" */
    0x7, 0xf8, 0xb, 0xff, 0xc3, 0xd0, 0xf4, 0xf0, 0x0, 0x3f, 0x90, 0x2, 0xff,
    0x40, 0x6, 0xf4, 0x90, 0x2e, 0x7c, 0xf, 0x8f, 0xff, 0xc0, 0xbf, 0x80,

    /* U+0054 "T" */
    0xbf, 0xff, 0xdf, 0xff, 0xe0, 0x1e, 0x0, 0x7, 0x80, 0x1, 0xe0, 0x0, 0x78,
    0x0, 0x1e, 0x0, 0x7, 0x80, 0x1, 0xe0, 0x0, 0x78, 0x0, 0x1e, 0x0,

    /* U+0055 "U" */
    0x3c, 0x3, 0xd3, 0xc0, 0x3d, 0x3c, 0x3, 0xd3, 0xc0, 0x3d, 0x3c, 0x3, 0xd3,
    0xc0, 0x3d, 0x3c, 0x3, 0xd3, 0xc0, 0x3d, 0x3e, 0xb, 0xc1, 0xff, 0xf4, 0x2,
    0xfd, 0x0,

    /* U+0056 "V" */
    0xbc, 0x1, 0xf0, 0xf0, 0xb, 0x83, 0xd0, 0x3d, 0xb, 0xc1, 0xf0, 0xf, 0xb,
    0x80, 0x3d, 0x3d, 0x0, 0xb8, 0xf0, 0x1, 0xf7, 0x80, 0x3, 0xfd, 0x0, 0xb,
    0xf0, 0x0, 0x1f, 0xc0, 0x0,

    /* U+0057 "W" */
    0xb8, 0xf, 0x40, 0xf1, 0xf0, 0x3e, 0x7, 0xc3, 0xc1, 0xfc, 0x2e, 0xf, 0x4b,
    0xf0, 0xf4, 0x2e, 0x3e, 0xd3, 0xc0, 0x7c, 0xf7, 0x9f, 0x0, 0xf7, 0x4f, 0xb8,
    0x3, 0xfc, 0x2f, 0xd0, 0x7, 0xf0, 0x7f, 0x0, 0xf, 0x80, 0xf8, 0x0, 0x3d,
    0x3, 0xd0, 0x0,

    /* U+0058 "X" */
    0x7c, 0x3, 0xd2, 0xe0, 0xb8, 0xf, 0x5f, 0x0, 0xbf, 0xe0, 0x3, 0xfc, 0x0,
    0x2f, 0x80, 0x3, 0xfc, 0x0, 0xbf, 0xe0, 0xf, 0x5f, 0x2, 0xe0, 0xb8, 0x7c,
    0x3, 0xd0,

    /* U+0059 "Y" */
    0x7c, 0x3, 0xe3, 0xd0, 0x7c, 0x1f, 0xf, 0x80, 0xf5, 0xf0, 0x7, 0xfe, 0x0,
    0x3f, 0xc0, 0x1, 0xf4, 0x0, 0xf, 0x0, 0x0, 0xf0, 0x0, 0xf, 0x0, 0x0, 0xf0,
    0x0,

    /* U+005A "Z" */
    0x3f, 0xff, 0x8f, 0xff, 0xd0, 0x2, 0xf0, 0x0, 0xf0, 0x0, 0xf4, 0x0, 0xbc,
    0x0, 0x3c, 0x0, 0x3e, 0x0, 0x1f, 0x0, 0xf, 0xff, 0xd3, 0xff, 0xf8,

    /* U+005B "[" */
    0xbf, 0x6f, 0x9b, 0x82, 0xe0, 0xb8, 0x2e, 0xb, 0x82, 0xe0, 0xb8, 0x2e, 0xb,
    0x82, 0xf9, 0xbf, 0x40,

    /* U+005C "\\" */
    0x60, 0xb, 0x40, 0x78, 0x3, 0xc0, 0x3c, 0x2, 0xd0, 0x1e, 0x0, 0xf0, 0xb,
    0x0, 0x74, 0x3, 0x80, 0x3c, 0x2, 0xc0,

    /* U+005D "]" */
    0xbf, 0x5b, 0xd0, 0xf4, 0x3d, 0xf, 0x43, 0xd0, 0xf4, 0x3d, 0xf, 0x43, 0xd0,
    0xf5, 0xbd, 0xbf, 0x40,

    /* U+005E "^" */
    0x6, 0x0, 0x3e, 0x1, 0xdc, 0xe, 0x38, 0x74, 0x70,

    /* U+005F "_" */
    0x2a, 0xa9, 0x3f, 0xfe,

    /* U+0061 "a" */
    0xb, 0xf0, 0x3f, 0xbc, 0x14, 0x3d, 0x6, 0xfd, 0x3e, 0x7d, 0x78, 0x3d, 0x7e,
    0xfd, 0x2f, 0xad,

    /* U+0062 "b" */
    0x3c, 0x0, 0xf, 0x0, 0x3, 0xc0, 0x0, 0xf3, 0xe0, 0x3f, 0xfe, 0xf, 0x43,
    0xc3, 0xc0, 0xf4, 0xf0, 0x3d, 0x3d, 0xf, 0xf, 0xff, 0x83, 0xdf, 0x80,

    /* U+0063 "c" */
    0xb, 0xf4, 0x2f, 0xfc, 0x3c, 0x1e, 0x78, 0x0, 0x78, 0x0, 0x3c, 0x1e, 0x2f,
    0xfc, 0xb, 0xf4,

    /* U+0064 "d" */
    0x0, 0xf, 0x0, 0xf, 0x0, 0xf, 0xb, 0xdf, 0x3f, 0xff, 0x3c, 0x1f, 0x7c, 0xf,
    0x7c, 0xf, 0x3c, 0x1f, 0x3f, 0xff, 0xb, 0xdf,

    /* U+0065 "e" */
    0xb, 0xf4, 0x2f, 0xbc, 0x3c, 0x1e, 0x7f, 0xff, 0x7d, 0x54, 0x3c, 0x9, 0x2f,
    0xbd, 0xb, 0xf4,

    /* U+0066 "f" */
    0x1, 0x40, 0xfc, 0x2e, 0x42, 0xd0, 0xff, 0xcb, 0xf8, 0x2d, 0x2, 0xd0, 0x2d,
    0x2, 0xd0, 0x2d, 0x2, 0xd0,

    /* U+0067 "g" */
    0xb, 0xdf, 0xf, 0xff, 0xc3, 0xc1, 0xf1, 0xf0, 0x3c, 0x7c, 0xf, 0x1f, 0x7,
    0xc3, 0xfb, 0xf0, 0x2f, 0x7c, 0x4, 0xf, 0xf, 0xaf, 0x80, 0xbf, 0x40,

    /* U+0068 "h" */
    0x3c, 0x0, 0x3c, 0x0, 0x3c, 0x0, 0x3d, 0xf8, 0x3f, 0xfe, 0x3d, 0x1f, 0x3c,
    0xf, 0x3c, 0xf, 0x3c, 0xf, 0x3c, 0xf, 0x3c, 0xf,

    /* U+0069 "i" */
    0x14, 0x3c, 0x24, 0x0, 0x3c, 0x3c, 0x3c, 0x3c, 0x3c, 0x3c, 0x3c, 0x3c,

    /* U+006A "j" */
    0x5, 0x3, 0xc0, 0x90, 0x0, 0xf, 0x3, 0xc0, 0xf0, 0x3c, 0xf, 0x3, 0xc0, 0xf0,
    0x3c, 0xf, 0x1f, 0x87, 0x80,

    /* U+006B "k" */
    0x3c, 0x0, 0xf, 0x0, 0x3, 0xc0, 0x0, 0xf0, 0xf8, 0x3c, 0xb8, 0xf, 0x7c, 0x3,
    0xfd, 0x0, 0xff, 0xc0, 0x3c, 0xf4, 0xf, 0x1f, 0x3, 0xc2, 0xf0,

    /* U+006C "l" */
    0x3c, 0xf3, 0xcf, 0x3c, 0xf3, 0xcf, 0x3c, 0xf3, 0xc0,

    /* U+006D "m" */
    0x3d, 0xf4, 0xfc, 0x3f, 0xff, 0xfe, 0x3c, 0x3e, 0x1f, 0x3c, 0x2d, 0xf, 0x3c,
    0x2d, 0xf, 0x3c, 0x2d, 0xf, 0x3c, 0x2d, 0xf, 0x3c, 0x2d, 0xf,

    /* U+006E "n" */
    0x3d, 0xf8, 0x3f, 0xfe, 0x3c, 0x1f, 0x3c, 0xf, 0x3c, 0xf, 0x3c, 0xf, 0x3c,
    0xf, 0x3c, 0xf,

    /* U+006F "o" */
    0xb, 0xf4, 0xb, 0xef, 0x43, 0xc1, 0xf1, 0xe0, 0x3c, 0x78, 0xf, 0xf, 0x7,
    0xc2, 0xff, 0xd0, 0x2f, 0xd0,

    /* U+0070 "p" */
    0x3d, 0xf8, 0xf, 0xef, 0x83, 0xd0, 0xf0, 0xf0, 0x3d, 0x3c, 0xf, 0x4f, 0x47,
    0xc3, 0xff, 0xe0, 0xf7, 0xe0, 0x3c, 0x0, 0xf, 0x0, 0x3, 0xc0, 0x0,

    /* U+0071 "q" */
    0xb, 0xdf, 0x3f, 0xff, 0x3c, 0x1f, 0x7c, 0xf, 0x7c, 0xf, 0x3c, 0x1f, 0x3f,
    0xff, 0xb, 0xdf, 0x0, 0xf, 0x0, 0xf, 0x0, 0xf,

    /* U+0072 "r" */
    0x0, 0x3, 0xdd, 0x3f, 0xd3, 0xd0, 0x3c, 0x3, 0xc0, 0x3c, 0x3, 0xc0, 0x3c,
    0x0,

    /* U+0073 "s" */
    0xf, 0xe0, 0x3e, 0xbc, 0x3c, 0x14, 0x3f, 0xe0, 0x6, 0xfc, 0x24, 0x3d, 0x3e,
    0xbc, 0xf, 0xe0,

    /* U+0074 "t" */
    0x2d, 0x2, 0xd0, 0xbf, 0xc7, 0xf8, 0x2d, 0x2, 0xd0, 0x2d, 0x2, 0xd0, 0x1f,
    0x80, 0xbc,

    /* U+0075 "u" */
    0x3c, 0x1f, 0x3c, 0x1f, 0x3c, 0x1f, 0x3c, 0x1f, 0x3c, 0x1f, 0x3c, 0x2f,
    0x3f, 0xff, 0xf, 0xdf,

    /* U+0076 "v" */
    0xb8, 0x1f, 0x7c, 0x2d, 0x3c, 0x3c, 0x2d, 0x3c, 0x1e, 0xb4, 0xf, 0xf0, 0xb,
    0xf0, 0x7, 0xd0,

    /* U+0077 "w" */
    0xb8, 0x3c, 0x2d, 0x78, 0x7d, 0x3c, 0x3c, 0xbe, 0x3c, 0x3c, 0xff, 0x78,
    0x2e, 0xeb, 0xb4, 0x1f, 0xc7, 0xf0, 0xf, 0xc3, 0xf0, 0xf, 0x83, 0xe0,

    /* U+0078 "x" */
    0x7c, 0x3d, 0x3d, 0x7c, 0xf, 0xf0, 0xb, 0xe0, 0xb, 0xe0, 0xf, 0xf4, 0x3d,
    0x7c, 0x7c, 0x3d,

    /* U+0079 "y" */
    0xb8, 0x1f, 0x7c, 0x2d, 0x3c, 0x3c, 0x2d, 0x3c, 0x1e, 0xb4, 0xf, 0xf0, 0xb,
    0xf0, 0x7, 0xd0, 0x3, 0xc0, 0x2f, 0x80, 0x3e, 0x0,

    /* U+007A "z" */
    0x3f, 0xfc, 0x3f, 0xfc, 0x0, 0xf4, 0x2, 0xe0, 0xb, 0xc0, 0x1f, 0x0, 0x3f,
    0xfc, 0x3f, 0xfc,

    /* U+007B "{" */
    0x2, 0xd0, 0xfd, 0xf, 0x0, 0xf0, 0xf, 0x1, 0xf0, 0xbc, 0xb, 0xd0, 0x1f, 0x0,
    0xf0, 0xf, 0x0, 0xfd, 0x3, 0xd0,

    /* U+007C "|" */
    0x11, 0xe7, 0x9e, 0x79, 0xe7, 0x9e, 0x79, 0xe7, 0x9e, 0x79, 0xe7, 0x9e,
    0x79, 0xe0,

    /* U+007D "}" */
    0xb8, 0x7, 0xd0, 0x1e, 0x1, 0xf0, 0x1f, 0x0, 0xf0, 0x7, 0xd0, 0xbd, 0xf,
    0x1, 0xf0, 0x1e, 0x7, 0xe0, 0xb8, 0x0,

    /* U+00A3 "£" */
    0x2, 0xfc, 0x2, 0xff, 0xc0, 0xf4, 0xf4, 0x3c, 0x0, 0xf, 0x0, 0xf, 0xfd, 0x3,
    0xff, 0x40, 0x3d, 0x0, 0xf, 0x0, 0xf, 0xff, 0xd3, 0xff, 0xf4,

    /* U+00B0 "°" */
    0x0, 0x1, 0xf8, 0x39, 0xd3, 0xe, 0x39, 0xd1, 0xfc, 0x1, 0x0,

    /* U+00E0 "à" */
    0x5, 0x0, 0xb, 0x0, 0x3, 0x80, 0x0, 0x0, 0xb, 0xf0, 0x3f, 0xbc, 0x14, 0x3d,
    0x6, 0xfd, 0x3e, 0x7d, 0x78, 0x3d, 0x7e, 0xfd, 0x2f, 0xad,

    /* U+00E8 "è" */
    0x5, 0x0, 0xb, 0x40, 0x3, 0x80, 0x0, 0x0, 0xb, 0xf4, 0x2f, 0xbc, 0x3c, 0x1e,
    0x7f, 0xff, 0x7d, 0x54, 0x3c, 0x9, 0x2f, 0xbd, 0xb, 0xf4,

    /* U+00E9 "é" */
    0x0, 0x10, 0x0, 0xf0, 0x1, 0xd0, 0x0, 0x0, 0xb, 0xf4, 0x2f, 0xbc, 0x3c,
    0x1e, 0x7f, 0xff, 0x7d, 0x54, 0x3c, 0x9, 0x2f, 0xbd, 0xb, 0xf4,

    /* U+00EC "ì" */
    0x10, 0x3c, 0xd, 0x0, 0xf, 0xf, 0xf, 0xf, 0xf, 0xf, 0xf, 0xf,

    /* U+00F2 "ò" */
    0x5, 0x0, 0x1, 0xd0, 0x0, 0x3c, 0x0, 0x0, 0x0, 0xb, 0xf4, 0xb, 0xef, 0x43,
    0xc1, 0xf1, 0xe0, 0x3c, 0x78, 0xf, 0xf, 0x7, 0xc2, 0xff, 0xd0, 0x2f, 0xd0,

    /* U+00F9 "ù" */
    0x5, 0x0, 0x7, 0x40, 0x2, 0xc0, 0x0, 0x0, 0x3c, 0x1f, 0x3c, 0x1f, 0x3c,
    0x1f, 0x3c, 0x1f, 0x3c, 0x1f, 0x3c, 0x2f, 0x3f, 0xff, 0xf, 0xdf};

/*---------------------
 *  GLYPH DESCRIPTION
 *--------------------*/

static const lv_font_fmt_txt_glyph_dsc_t glyph_dsc[] = {
    {.bitmap_index = 0,
     .adv_w = 0,
     .box_w = 0,
     .box_h = 0,
     .ofs_x = 0,
     .ofs_y = 0} /* id = 0 reserved */,
    {.bitmap_index = 0,
     .adv_w = 52,
     .box_w = 0,
     .box_h = 0,
     .ofs_x = 0,
     .ofs_y = 0},
    {.bitmap_index = 0,
     .adv_w = 73,
     .box_w = 3,
     .box_h = 11,
     .ofs_x = 1,
     .ofs_y = 0},
    {.bitmap_index = 9,
     .adv_w = 88,
     .box_w = 5,
     .box_h = 4,
     .ofs_x = 0,
     .ofs_y = 7},
    {.bitmap_index = 14,
     .adv_w = 145,
     .box_w = 9,
     .box_h = 11,
     .ofs_x = 0,
     .ofs_y = 0},
    {.bitmap_index = 39,
     .adv_w = 147,
     .box_w = 9,
     .box_h = 14,
     .ofs_x = 0,
     .ofs_y = -2},
    {.bitmap_index = 71,
     .adv_w = 192,
     .box_w = 10,
     .box_h = 11,
     .ofs_x = 1,
     .ofs_y = 0},
    {.bitmap_index = 99,
     .adv_w = 151,
     .box_w = 10,
     .box_h = 11,
     .ofs_x = 0,
     .ofs_y = 0},
    {.bitmap_index = 127,
     .adv_w = 47,
     .box_w = 3,
     .box_h = 4,
     .ofs_x = 0,
     .ofs_y = 7},
    {.bitmap_index = 130,
     .adv_w = 92,
     .box_w = 5,
     .box_h = 14,
     .ofs_x = 1,
     .ofs_y = -3},
    {.bitmap_index = 148,
     .adv_w = 92,
     .box_w = 5,
     .box_h = 14,
     .ofs_x = 0,
     .ofs_y = -3},
    {.bitmap_index = 166,
     .adv_w = 126,
     .box_w = 6,
     .box_h = 6,
     .ofs_x = 1,
     .ofs_y = 5},
    {.bitmap_index = 175,
     .adv_w = 152,
     .box_w = 8,
     .box_h = 8,
     .ofs_x = 1,
     .ofs_y = 0},
    {.bitmap_index = 191,
     .adv_w = 68,
     .box_w = 4,
     .box_h = 5,
     .ofs_x = 0,
     .ofs_y = -3},
    {.bitmap_index = 196,
     .adv_w = 105,
     .box_w = 6,
     .box_h = 2,
     .ofs_x = 0,
     .ofs_y = 3},
    {.bitmap_index = 199,
     .adv_w = 67,
     .box_w = 4,
     .box_h = 3,
     .ofs_x = 0,
     .ofs_y = 0},
    {.bitmap_index = 202,
     .adv_w = 87,
     .box_w = 6,
     .box_h = 13,
     .ofs_x = 0,
     .ofs_y = -2},
    {.bitmap_index = 222,
     .adv_w = 154,
     .box_w = 9,
     .box_h = 11,
     .ofs_x = 0,
     .ofs_y = 0},
    {.bitmap_index = 247,
     .adv_w = 110,
     .box_w = 6,
     .box_h = 11,
     .ofs_x = 0,
     .ofs_y = 0},
    {.bitmap_index = 264,
     .adv_w = 141,
     .box_w = 9,
     .box_h = 11,
     .ofs_x = 0,
     .ofs_y = 0},
    {.bitmap_index = 289,
     .adv_w = 148,
     .box_w = 9,
     .box_h = 11,
     .ofs_x = 0,
     .ofs_y = 0},
    {.bitmap_index = 314,
     .adv_w = 152,
     .box_w = 9,
     .box_h = 11,
     .ofs_x = 0,
     .ofs_y = 0},
    {.bitmap_index = 339,
     .adv_w = 144,
     .box_w = 9,
     .box_h = 11,
     .ofs_x = 0,
     .ofs_y = 0},
    {.bitmap_index = 364,
     .adv_w = 148,
     .box_w = 9,
     .box_h = 11,
     .ofs_x = 0,
     .ofs_y = 0},
    {.bitmap_index = 389,
     .adv_w = 133,
     .box_w = 8,
     .box_h = 11,
     .ofs_x = 0,
     .ofs_y = 0},
    {.bitmap_index = 411,
     .adv_w = 148,
     .box_w = 9,
     .box_h = 11,
     .ofs_x = 0,
     .ofs_y = 0},
    {.bitmap_index = 436,
     .adv_w = 148,
     .box_w = 9,
     .box_h = 11,
     .ofs_x = 0,
     .ofs_y = 0},
    {.bitmap_index = 461,
     .adv_w = 67,
     .box_w = 4,
     .box_h = 8,
     .ofs_x = 0,
     .ofs_y = 0},
    {.bitmap_index = 469,
     .adv_w = 68,
     .box_w = 4,
     .box_h = 11,
     .ofs_x = 0,
     .ofs_y = -3},
    {.bitmap_index = 480,
     .adv_w = 152,
     .box_w = 8,
     .box_h = 9,
     .ofs_x = 1,
     .ofs_y = 0},
    {.bitmap_index = 498,
     .adv_w = 152,
     .box_w = 8,
     .box_h = 5,
     .ofs_x = 1,
     .ofs_y = 2},
    {.bitmap_index = 508,
     .adv_w = 152,
     .box_w = 8,
     .box_h = 9,
     .ofs_x = 1,
     .ofs_y = 0},
    {.bitmap_index = 526,
     .adv_w = 126,
     .box_w = 8,
     .box_h = 11,
     .ofs_x = 0,
     .ofs_y = 0},
    {.bitmap_index = 548,
     .adv_w = 231,
     .box_w = 14,
     .box_h = 14,
     .ofs_x = 0,
     .ofs_y = -3},
    {.bitmap_index = 597,
     .adv_w = 168,
     .box_w = 11,
     .box_h = 11,
     .ofs_x = 0,
     .ofs_y = 0},
    {.bitmap_index = 628,
     .adv_w = 148,
     .box_w = 9,
     .box_h = 11,
     .ofs_x = 0,
     .ofs_y = 0},
    {.bitmap_index = 653,
     .adv_w = 168,
     .box_w = 10,
     .box_h = 11,
     .ofs_x = 0,
     .ofs_y = 0},
    {.bitmap_index = 681,
     .adv_w = 163,
     .box_w = 10,
     .box_h = 11,
     .ofs_x = 0,
     .ofs_y = 0},
    {.bitmap_index = 709,
     .adv_w = 137,
     .box_w = 8,
     .box_h = 11,
     .ofs_x = 0,
     .ofs_y = 0},
    {.bitmap_index = 731,
     .adv_w = 131,
     .box_w = 8,
     .box_h = 11,
     .ofs_x = 0,
     .ofs_y = 0},
    {.bitmap_index = 753,
     .adv_w = 170,
     .box_w = 10,
     .box_h = 11,
     .ofs_x = 0,
     .ofs_y = 0},
    {.bitmap_index = 781,
     .adv_w = 167,
     .box_w = 10,
     .box_h = 11,
     .ofs_x = 0,
     .ofs_y = 0},
    {.bitmap_index = 809,
     .adv_w = 63,
     .box_w = 4,
     .box_h = 11,
     .ofs_x = 0,
     .ofs_y = 0},
    {.bitmap_index = 820,
     .adv_w = 128,
     .box_w = 8,
     .box_h = 11,
     .ofs_x = 0,
     .ofs_y = 0},
    {.bitmap_index = 842,
     .adv_w = 154,
     .box_w = 10,
     .box_h = 11,
     .ofs_x = 0,
     .ofs_y = 0},
    {.bitmap_index = 870,
     .adv_w = 127,
     .box_w = 8,
     .box_h = 11,
     .ofs_x = 0,
     .ofs_y = 0},
    {.bitmap_index = 892,
     .adv_w = 205,
     .box_w = 12,
     .box_h = 11,
     .ofs_x = 0,
     .ofs_y = 0},
    {.bitmap_index = 925,
     .adv_w = 165,
     .box_w = 10,
     .box_h = 11,
     .ofs_x = 0,
     .ofs_y = 0},
    {.bitmap_index = 953,
     .adv_w = 175,
     .box_w = 11,
     .box_h = 11,
     .ofs_x = 0,
     .ofs_y = 0},
    {.bitmap_index = 984,
     .adv_w = 145,
     .box_w = 9,
     .box_h = 11,
     .ofs_x = 0,
     .ofs_y = 0},
    {.bitmap_index = 1009,
     .adv_w = 175,
     .box_w = 11,
     .box_h = 12,
     .ofs_x = 0,
     .ofs_y = -1},
    {.bitmap_index = 1042,
     .adv_w = 147,
     .box_w = 9,
     .box_h = 11,
     .ofs_x = 0,
     .ofs_y = 0},
    {.bitmap_index = 1067,
     .adv_w = 147,
     .box_w = 9,
     .box_h = 11,
     .ofs_x = 0,
     .ofs_y = 0},
    {.bitmap_index = 1092,
     .adv_w = 150,
     .box_w = 9,
     .box_h = 11,
     .ofs_x = 0,
     .ofs_y = 0},
    {.bitmap_index = 1117,
     .adv_w = 163,
     .box_w = 10,
     .box_h = 11,
     .ofs_x = 0,
     .ofs_y = 0},
    {.bitmap_index = 1145,
     .adv_w = 168,
     .box_w = 11,
     .box_h = 11,
     .ofs_x = 0,
     .ofs_y = 0},
    {.bitmap_index = 1176,
     .adv_w = 232,
     .box_w = 15,
     .box_h = 11,
     .ofs_x = 0,
     .ofs_y = 0},
    {.bitmap_index = 1218,
     .adv_w = 160,
     .box_w = 10,
     .box_h = 11,
     .ofs_x = 0,
     .ofs_y = 0},
    {.bitmap_index = 1246,
     .adv_w = 162,
     .box_w = 10,
     .box_h = 11,
     .ofs_x = 0,
     .ofs_y = 0},
    {.bitmap_index = 1274,
     .adv_w = 149,
     .box_w = 9,
     .box_h = 11,
     .ofs_x = 0,
     .ofs_y = 0},
    {.bitmap_index = 1299,
     .adv_w = 92,
     .box_w = 5,
     .box_h = 13,
     .ofs_x = 1,
     .ofs_y = -2},
    {.bitmap_index = 1316,
     .adv_w = 87,
     .box_w = 6,
     .box_h = 13,
     .ofs_x = 0,
     .ofs_y = -2},
    {.bitmap_index = 1336,
     .adv_w = 92,
     .box_w = 5,
     .box_h = 13,
     .ofs_x = 0,
     .ofs_y = -2},
    {.bitmap_index = 1353,
     .adv_w = 109,
     .box_w = 7,
     .box_h = 5,
     .ofs_x = 0,
     .ofs_y = 6},
    {.bitmap_index = 1362,
     .adv_w = 107,
     .box_w = 8,
     .box_h = 2,
     .ofs_x = -1,
     .ofs_y = -2},
    {.bitmap_index = 1366,
     .adv_w = 130,
     .box_w = 8,
     .box_h = 8,
     .ofs_x = 0,
     .ofs_y = 0},
    {.bitmap_index = 1382,
     .adv_w = 142,
     .box_w = 9,
     .box_h = 11,
     .ofs_x = 0,
     .ofs_y = 0},
    {.bitmap_index = 1407,
     .adv_w = 132,
     .box_w = 8,
     .box_h = 8,
     .ofs_x = 0,
     .ofs_y = 0},
    {.bitmap_index = 1423,
     .adv_w = 142,
     .box_w = 8,
     .box_h = 11,
     .ofs_x = 0,
     .ofs_y = 0},
    {.bitmap_index = 1445,
     .adv_w = 134,
     .box_w = 8,
     .box_h = 8,
     .ofs_x = 0,
     .ofs_y = 0},
    {.bitmap_index = 1461,
     .adv_w = 86,
     .box_w = 6,
     .box_h = 12,
     .ofs_x = 0,
     .ofs_y = 0},
    {.bitmap_index = 1479,
     .adv_w = 142,
     .box_w = 9,
     .box_h = 11,
     .ofs_x = 0,
     .ofs_y = -3},
    {.bitmap_index = 1504,
     .adv_w = 140,
     .box_w = 8,
     .box_h = 11,
     .ofs_x = 0,
     .ofs_y = 0},
    {.bitmap_index = 1526,
     .adv_w = 61,
     .box_w = 4,
     .box_h = 12,
     .ofs_x = 0,
     .ofs_y = 0},
    {.bitmap_index = 1538,
     .adv_w = 61,
     .box_w = 5,
     .box_h = 15,
     .ofs_x = -1,
     .ofs_y = -3},
    {.bitmap_index = 1557,
     .adv_w = 130,
     .box_w = 9,
     .box_h = 11,
     .ofs_x = 0,
     .ofs_y = 0},
    {.bitmap_index = 1582,
     .adv_w = 61,
     .box_w = 3,
     .box_h = 11,
     .ofs_x = 0,
     .ofs_y = 0},
    {.bitmap_index = 1591,
     .adv_w = 204,
     .box_w = 12,
     .box_h = 8,
     .ofs_x = 0,
     .ofs_y = 0},
    {.bitmap_index = 1615,
     .adv_w = 139,
     .box_w = 8,
     .box_h = 8,
     .ofs_x = 0,
     .ofs_y = 0},
    {.bitmap_index = 1631,
     .adv_w = 137,
     .box_w = 9,
     .box_h = 8,
     .ofs_x = 0,
     .ofs_y = 0},
    {.bitmap_index = 1649,
     .adv_w = 142,
     .box_w = 9,
     .box_h = 11,
     .ofs_x = 0,
     .ofs_y = -3},
    {.bitmap_index = 1674,
     .adv_w = 142,
     .box_w = 8,
     .box_h = 11,
     .ofs_x = 0,
     .ofs_y = -3},
    {.bitmap_index = 1696,
     .adv_w = 92,
     .box_w = 6,
     .box_h = 9,
     .ofs_x = 0,
     .ofs_y = 0},
    {.bitmap_index = 1710,
     .adv_w = 126,
     .box_w = 8,
     .box_h = 8,
     .ofs_x = 0,
     .ofs_y = 0},
    {.bitmap_index = 1726,
     .adv_w = 87,
     .box_w = 6,
     .box_h = 10,
     .ofs_x = 0,
     .ofs_y = 0},
    {.bitmap_index = 1741,
     .adv_w = 139,
     .box_w = 8,
     .box_h = 8,
     .ofs_x = 0,
     .ofs_y = 0},
    {.bitmap_index = 1757,
     .adv_w = 131,
     .box_w = 8,
     .box_h = 8,
     .ofs_x = 0,
     .ofs_y = 0},
    {.bitmap_index = 1773,
     .adv_w = 190,
     .box_w = 12,
     .box_h = 8,
     .ofs_x = 0,
     .ofs_y = 0},
    {.bitmap_index = 1797,
     .adv_w = 129,
     .box_w = 8,
     .box_h = 8,
     .ofs_x = 0,
     .ofs_y = 0},
    {.bitmap_index = 1813,
     .adv_w = 131,
     .box_w = 8,
     .box_h = 11,
     .ofs_x = 0,
     .ofs_y = -3},
    {.bitmap_index = 1835,
     .adv_w = 128,
     .box_w = 8,
     .box_h = 8,
     .ofs_x = 0,
     .ofs_y = 0},
    {.bitmap_index = 1851,
     .adv_w = 92,
     .box_w = 6,
     .box_h = 13,
     .ofs_x = 0,
     .ofs_y = -2},
    {.bitmap_index = 1871,
     .adv_w = 84,
     .box_w = 3,
     .box_h = 18,
     .ofs_x = 1,
     .ofs_y = -3},
    {.bitmap_index = 1885,
     .adv_w = 92,
     .box_w = 6,
     .box_h = 13,
     .ofs_x = 0,
     .ofs_y = -2},
    {.bitmap_index = 1905,
     .adv_w = 150,
     .box_w = 9,
     .box_h = 11,
     .ofs_x = 0,
     .ofs_y = 0},
    {.bitmap_index = 1930,
     .adv_w = 103,
     .box_w = 6,
     .box_h = 7,
     .ofs_x = 0,
     .ofs_y = 5},
    {.bitmap_index = 1941,
     .adv_w = 130,
     .box_w = 8,
     .box_h = 12,
     .ofs_x = 0,
     .ofs_y = 0},
    {.bitmap_index = 1965,
     .adv_w = 134,
     .box_w = 8,
     .box_h = 12,
     .ofs_x = 0,
     .ofs_y = 0},
    {.bitmap_index = 1989,
     .adv_w = 134,
     .box_w = 8,
     .box_h = 12,
     .ofs_x = 0,
     .ofs_y = 0},
    {.bitmap_index = 2013,
     .adv_w = 61,
     .box_w = 4,
     .box_h = 12,
     .ofs_x = -1,
     .ofs_y = 0},
    {.bitmap_index = 2025,
     .adv_w = 137,
     .box_w = 9,
     .box_h = 12,
     .ofs_x = 0,
     .ofs_y = 0},
    {.bitmap_index = 2052,
     .adv_w = 139,
     .box_w = 8,
     .box_h = 12,
     .ofs_x = 0,
     .ofs_y = 0}};

/*---------------------
 *  CHARACTER MAPPING
 *--------------------*/

static const uint16_t unicode_list_2[] = {0x0,  0xd,  0x3d, 0x45,
                                          0x46, 0x49, 0x4f, 0x56};

/*Collect the unicode lists and glyph_id offsets*/
static const lv_font_fmt_txt_cmap_t cmaps[] = {
    {.range_start = 32,
     .range_length = 64,
     .glyph_id_start = 1,
     .unicode_list = NULL,
     .glyph_id_ofs_list = NULL,
     .list_length = 0,
     .type = LV_FONT_FMT_TXT_CMAP_FORMAT0_TINY},
    {.range_start = 97,
     .range_length = 29,
     .glyph_id_start = 65,
     .unicode_list = NULL,
     .glyph_id_ofs_list = NULL,
     .list_length = 0,
     .type = LV_FONT_FMT_TXT_CMAP_FORMAT0_TINY},
    {.range_start = 163,
     .range_length = 87,
     .glyph_id_start = 94,
     .unicode_list = unicode_list_2,
     .glyph_id_ofs_list = NULL,
     .list_length = 8,
     .type = LV_FONT_FMT_TXT_CMAP_SPARSE_TINY}};

/*-----------------
 *    KERNING
 *----------------*/

/*Pair left and right glyphs for kerning*/
static const uint8_t kern_pair_glyph_ids[] = {
    3,   7,   3,   13,  3,   15,  3,   21,  3,   34,  3,   43,  5,   34,  7,
    3,   7,   8,   7,   53,  7,   55,  7,   56,  7,   58,  7,   61,  7,   86,
    7,   87,  7,   89,  8,   7,   8,   13,  8,   15,  8,   21,  8,   34,  8,
    43,  9,   67,  9,   68,  9,   69,  9,   71,  9,   74,  9,   79,  9,   81,
    9,   97,  9,   98,  9,   100, 11,  7,   11,  13,  11,  15,  11,  21,  11,
    34,  11,  43,  11,  64,  12,  19,  12,  20,  12,  24,  12,  53,  12,  55,
    12,  56,  12,  57,  12,  58,  12,  61,  12,  88,  13,  1,   13,  2,   13,
    3,   13,  8,   13,  17,  13,  18,  13,  20,  13,  22,  13,  23,  13,  24,
    13,  25,  13,  26,  13,  32,  13,  53,  13,  58,  14,  19,  14,  20,  14,
    24,  14,  53,  14,  55,  14,  56,  14,  57,  14,  58,  14,  61,  14,  88,
    15,  1,   15,  2,   15,  3,   15,  8,   15,  17,  15,  18,  15,  20,  15,
    22,  15,  23,  15,  24,  15,  25,  15,  26,  15,  32,  15,  53,  15,  58,
    16,  13,  16,  15,  16,  43,  16,  55,  16,  56,  16,  61,  17,  13,  17,
    15,  17,  24,  17,  58,  17,  64,  18,  13,  18,  15,  19,  21,  20,  13,
    20,  15,  21,  13,  21,  15,  21,  18,  22,  13,  22,  15,  23,  13,  23,
    15,  23,  64,  24,  4,   24,  7,   24,  13,  24,  15,  24,  17,  24,  20,
    24,  21,  24,  22,  24,  23,  24,  24,  24,  25,  24,  26,  24,  27,  24,
    28,  24,  29,  24,  34,  24,  43,  24,  64,  24,  65,  24,  67,  24,  68,
    24,  69,  24,  71,  24,  79,  24,  81,  24,  83,  24,  96,  24,  97,  24,
    98,  24,  100, 25,  13,  25,  15,  26,  13,  26,  15,  26,  24,  26,  58,
    26,  64,  27,  53,  27,  55,  27,  61,  28,  53,  28,  55,  28,  61,  30,
    34,  30,  55,  30,  56,  30,  57,  30,  58,  30,  61,  30,  86,  30,  88,
    30,  89,  31,  24,  31,  34,  31,  53,  31,  55,  31,  56,  31,  57,  31,
    58,  31,  59,  31,  61,  32,  34,  34,  3,   34,  5,   34,  8,   34,  11,
    34,  18,  34,  29,  34,  30,  34,  32,  34,  36,  34,  40,  34,  48,  34,
    50,  34,  52,  34,  53,  34,  55,  34,  56,  34,  58,  34,  61,  34,  63,
    34,  67,  34,  68,  34,  69,  34,  70,  34,  71,  34,  73,  34,  79,  34,
    81,  34,  83,  34,  84,  34,  86,  34,  87,  34,  89,  34,  95,  34,  97,
    34,  98,  34,  99,  34,  100, 36,  34,  36,  57,  36,  64,  36,  86,  36,
    89,  37,  13,  37,  15,  37,  16,  37,  34,  37,  53,  37,  55,  37,  56,
    37,  57,  37,  58,  37,  61,  37,  64,  39,  13,  39,  15,  39,  34,  39,
    43,  39,  64,  39,  65,  39,  67,  39,  68,  39,  69,  39,  71,  39,  77,
    39,  78,  39,  79,  39,  80,  39,  81,  39,  82,  39,  85,  39,  86,  39,
    89,  39,  90,  39,  96,  39,  97,  39,  98,  39,  100, 39,  101, 40,  34,
    40,  53,  40,  55,  40,  57,  40,  58,  40,  61,  40,  73,  40,  74,  40,
    99,  41,  64,  42,  64,  43,  13,  43,  15,  43,  16,  43,  64,  44,  5,
    44,  12,  44,  14,  44,  29,  44,  30,  44,  36,  44,  40,  44,  48,  44,
    50,  44,  52,  44,  67,  44,  68,  44,  69,  44,  71,  44,  73,  44,  79,
    44,  81,  44,  85,  44,  86,  44,  87,  44,  89,  44,  97,  44,  98,  44,
    99,  44,  100, 44,  101, 45,  3,   45,  8,   45,  11,  45,  12,  45,  14,
    45,  18,  45,  34,  45,  36,  45,  40,  45,  48,  45,  50,  45,  53,  45,
    55,  45,  56,  45,  58,  45,  61,  45,  63,  45,  84,  45,  86,  45,  89,
    45,  95,  46,  64,  47,  64,  48,  13,  48,  15,  48,  16,  48,  34,  48,
    53,  48,  55,  48,  56,  48,  57,  48,  58,  48,  61,  48,  64,  49,  7,
    49,  12,  49,  13,  49,  14,  49,  15,  49,  34,  49,  43,  49,  65,  49,
    67,  49,  68,  49,  69,  49,  71,  49,  79,  49,  81,  49,  96,  49,  97,
    49,  98,  49,  100, 50,  13,  50,  15,  50,  16,  50,  34,  50,  53,  50,
    55,  50,  56,  50,  57,  50,  58,  50,  61,  50,  64,  51,  55,  51,  58,
    51,  61,  51,  67,  51,  68,  51,  69,  51,  71,  51,  79,  51,  81,  51,
    97,  51,  98,  51,  100, 52,  34,  53,  7,   53,  12,  53,  13,  53,  14,
    53,  15,  53,  16,  53,  21,  53,  27,  53,  28,  53,  29,  53,  34,  53,
    36,  53,  40,  53,  43,  53,  48,  53,  50,  53,  64,  53,  65,  53,  67,
    53,  68,  53,  69,  53,  71,  53,  77,  53,  78,  53,  79,  53,  80,  53,
    81,  53,  82,  53,  83,  53,  85,  53,  86,  53,  87,  53,  88,  53,  89,
    53,  90,  53,  96,  53,  97,  53,  98,  53,  100, 53,  101, 54,  13,  54,
    15,  54,  16,  54,  64,  55,  7,   55,  12,  55,  13,  55,  14,  55,  15,
    55,  16,  55,  21,  55,  27,  55,  28,  55,  29,  55,  30,  55,  33,  55,
    34,  55,  36,  55,  40,  55,  43,  55,  48,  55,  50,  55,  61,  55,  64,
    55,  65,  55,  67,  55,  68,  55,  69,  55,  71,  55,  79,  55,  81,  55,
    83,  55,  96,  55,  97,  55,  98,  55,  100, 56,  5,   56,  7,   56,  12,
    56,  13,  56,  14,  56,  15,  56,  16,  56,  21,  56,  27,  56,  28,  56,
    29,  56,  30,  56,  34,  56,  36,  56,  40,  56,  43,  56,  48,  56,  50,
    56,  52,  56,  61,  56,  65,  56,  67,  56,  68,  56,  69,  56,  71,  56,
    77,  56,  78,  56,  79,  56,  80,  56,  81,  56,  82,  56,  83,  56,  96,
    56,  97,  56,  98,  56,  100, 57,  12,  57,  14,  57,  29,  57,  30,  57,
    36,  57,  40,  57,  48,  57,  50,  57,  67,  57,  68,  57,  69,  57,  71,
    57,  79,  57,  81,  57,  97,  57,  98,  57,  100, 58,  7,   58,  12,  58,
    13,  58,  14,  58,  15,  58,  21,  58,  27,  58,  28,  58,  29,  58,  30,
    58,  34,  58,  36,  58,  40,  58,  43,  58,  48,  58,  50,  58,  53,  58,
    65,  58,  67,  58,  68,  58,  69,  58,  71,  58,  73,  58,  77,  58,  78,
    58,  79,  58,  80,  58,  81,  58,  82,  58,  83,  58,  85,  58,  96,  58,
    97,  58,  98,  58,  99,  58,  100, 58,  101, 59,  12,  59,  14,  59,  29,
    59,  36,  59,  40,  59,  48,  59,  50,  60,  67,  60,  68,  60,  69,  60,
    71,  60,  74,  60,  79,  60,  81,  60,  97,  60,  98,  60,  100, 61,  3,
    61,  5,   61,  8,   61,  11,  61,  13,  61,  15,  61,  18,  61,  29,  61,
    30,  61,  32,  61,  36,  61,  40,  61,  48,  61,  50,  61,  52,  61,  53,
    61,  55,  61,  56,  61,  58,  61,  61,  61,  63,  61,  67,  61,  68,  61,
    69,  61,  70,  61,  71,  61,  73,  61,  79,  61,  81,  61,  83,  61,  84,
    61,  86,  61,  87,  61,  89,  61,  95,  61,  97,  61,  98,  61,  99,  61,
    100, 63,  7,   63,  13,  63,  15,  63,  21,  63,  34,  63,  43,  63,  64,
    64,  11,  64,  17,  64,  18,  64,  20,  64,  21,  64,  22,  64,  23,  64,
    25,  64,  26,  64,  36,  64,  40,  64,  48,  64,  50,  64,  53,  64,  54,
    64,  55,  64,  61,  64,  63,  64,  73,  64,  74,  64,  77,  64,  78,  64,
    80,  64,  82,  64,  86,  64,  89,  64,  95,  64,  99,  65,  18,  65,  53,
    65,  55,  65,  56,  65,  58,  65,  61,  65,  86,  65,  89,  66,  10,  66,
    34,  66,  53,  66,  55,  66,  56,  66,  57,  66,  58,  66,  61,  66,  62,
    66,  86,  66,  87,  66,  88,  66,  89,  66,  93,  67,  53,  67,  56,  67,
    58,  67,  88,  68,  64,  69,  53,  69,  55,  69,  56,  69,  58,  69,  61,
    69,  86,  69,  87,  69,  88,  69,  89,  70,  12,  70,  13,  70,  14,  70,
    15,  70,  16,  70,  21,  70,  34,  70,  43,  70,  58,  70,  64,  70,  65,
    70,  67,  70,  68,  70,  69,  70,  71,  70,  79,  70,  81,  70,  83,  70,
    96,  70,  97,  70,  98,  70,  100, 71,  53,  71,  64,  71,  74,  72,  18,
    72,  53,  72,  55,  72,  56,  72,  58,  72,  61,  72,  86,  72,  89,  73,
    10,  73,  55,  73,  56,  73,  61,  73,  62,  73,  64,  73,  93,  74,  10,
    74,  55,  74,  56,  74,  61,  74,  62,  74,  64,  74,  93,  75,  12,  75,
    14,  75,  21,  75,  29,  75,  53,  75,  67,  75,  68,  75,  69,  75,  71,
    75,  79,  75,  81,  75,  86,  75,  89,  75,  97,  75,  98,  75,  100, 76,
    64,  77,  18,  77,  53,  77,  55,  77,  56,  77,  58,  77,  61,  77,  86,
    77,  89,  78,  18,  78,  53,  78,  55,  78,  56,  78,  58,  78,  61,  78,
    86,  78,  89,  79,  10,  79,  34,  79,  53,  79,  55,  79,  56,  79,  57,
    79,  58,  79,  61,  79,  62,  79,  86,  79,  87,  79,  88,  79,  89,  79,
    93,  80,  10,  80,  34,  80,  53,  80,  55,  80,  56,  80,  57,  80,  58,
    80,  61,  80,  62,  80,  86,  80,  87,  80,  88,  80,  89,  80,  93,  81,
    53,  81,  64,  81,  74,  82,  12,  82,  13,  82,  14,  82,  15,  82,  16,
    82,  29,  82,  34,  82,  43,  82,  53,  82,  59,  82,  65,  82,  67,  82,
    68,  82,  69,  82,  70,  82,  71,  82,  79,  82,  81,  82,  84,  82,  86,
    82,  87,  82,  88,  82,  89,  82,  96,  82,  97,  82,  98,  82,  100, 83,
    53,  83,  55,  83,  56,  83,  58,  83,  61,  84,  12,  84,  14,  84,  21,
    84,  29,  84,  35,  84,  37,  84,  38,  84,  39,  84,  41,  84,  42,  84,
    44,  84,  45,  84,  46,  84,  47,  84,  49,  84,  51,  84,  53,  84,  55,
    84,  56,  84,  58,  84,  61,  84,  66,  84,  67,  84,  68,  84,  69,  84,
    71,  84,  72,  84,  75,  84,  76,  84,  79,  84,  81,  84,  83,  84,  92,
    84,  97,  84,  98,  84,  100, 85,  53,  85,  58,  86,  13,  86,  15,  86,
    16,  86,  29,  86,  30,  86,  34,  86,  43,  86,  53,  86,  58,  86,  64,
    86,  65,  86,  67,  86,  68,  86,  69,  86,  71,  86,  79,  86,  81,  86,
    96,  86,  97,  86,  98,  86,  100, 87,  7,   87,  13,  87,  15,  87,  34,
    87,  43,  87,  53,  87,  59,  87,  67,  87,  68,  87,  69,  87,  71,  87,
    79,  87,  81,  87,  97,  87,  98,  87,  100, 88,  12,  88,  14,  88,  30,
    88,  53,  88,  65,  88,  67,  88,  68,  88,  69,  88,  71,  88,  79,  88,
    81,  88,  96,  88,  97,  88,  98,  88,  100, 89,  13,  89,  15,  89,  16,
    89,  29,  89,  30,  89,  34,  89,  43,  89,  53,  89,  58,  89,  64,  89,
    65,  89,  67,  89,  68,  89,  69,  89,  71,  89,  79,  89,  81,  89,  96,
    89,  97,  89,  98,  89,  100, 90,  53,  90,  67,  90,  68,  90,  69,  90,
    71,  90,  79,  90,  81,  90,  97,  90,  98,  90,  100, 91,  67,  91,  68,
    91,  69,  91,  71,  91,  74,  91,  79,  91,  81,  91,  97,  91,  98,  91,
    100, 92,  64,  95,  7,   95,  13,  95,  15,  95,  21,  95,  34,  95,  36,
    95,  40,  95,  43,  95,  48,  95,  50,  95,  64,  96,  18,  96,  53,  96,
    55,  96,  56,  96,  58,  96,  61,  96,  86,  96,  89,  97,  53,  97,  55,
    97,  56,  97,  58,  97,  61,  97,  86,  97,  87,  97,  88,  97,  89,  98,
    53,  98,  55,  98,  56,  98,  58,  98,  61,  98,  86,  98,  87,  98,  88,
    98,  89,  99,  10,  99,  55,  99,  56,  99,  61,  99,  62,  99,  64,  99,
    93,  100, 10,  100, 34,  100, 53,  100, 55,  100, 56,  100, 57,  100, 58,
    100, 61,  100, 62,  100, 86,  100, 87,  100, 88,  100, 89,  100, 93,  101,
    53,  101, 58};

/* Kerning between the respective left and right glyphs
 * 4.4 format which needs to scaled with `kern_scale`*/
static const int8_t kern_pair_values[] = {
    -8,  -20, -20, -14, -18, -37, -4,  -8,  -8,  -13, -14, -9,  -17, -14, -8,
    -8,  -8,  -8,  -20, -20, -14, -18, -37, -1,  -1,  -1,  -1,  3,   -1,  -1,
    -1,  -1,  -1,  -8,  -31, -31, -10, -22, -22, -15, -5,  -1,  -7,  -7,  -5,
    -5,  -12, -7,  -5,  -5,  -8,  -3,  -23, -23, -7,  -20, -5,  -1,  -7,  -6,
    -7,  -3,  -23, -8,  -15, -5,  -1,  -7,  -7,  -5,  -5,  -12, -7,  -5,  -5,
    -8,  -3,  -23, -23, -7,  -20, -5,  -1,  -7,  -6,  -7,  -3,  -23, -8,  -15,
    -9,  -9,  -14, 2,   2,   2,   -7,  -7,  -4,  -8,  -10, -9,  -9,  -3,  -5,
    -5,  -3,  -3,  -2,  -5,  -5,  -7,  -7,  -10, -13, -10, -28, -28, -3,  -4,
    -13, -2,  -3,  4,   -3,  -2,  -8,  -8,  -20, -24, -22, -36, -10, -11, -11,
    -11, -11, -11, -11, -9,  -10, -11, -11, -11, -5,  -5,  -7,  -7,  -4,  -8,
    -10, -8,  -14, -14, -8,  -14, -14, -11, -15, -14, -11, -22, -15, -9,  -8,
    -9,  -17, -10, -18, -17, -17, -13, -20, -14, -17, -14, -18, -4,  -18, -22,
    -8,  -10, -11, -14, -8,  -8,  -8,  -8,  -4,  -20, -20, -17, -17, -20, -22,
    -6,  -6,  -6,  -2,  -6,  0,   -6,  -6,  -3,  -8,  -15, -15, -15, -22, -6,
    -6,  0,   -6,  -3,  -4,  -9,  2,   2,   -10, -10, -9,  -9,  -7,  -9,  -6,
    -7,  -10, -9,  -9,  -9,  -8,  -20, -15, -8,  -2,  -9,  -9,  -9,  -9,  -2,
    -2,  -9,  -2,  -9,  -2,  -8,  -8,  -8,  -8,  -2,  -9,  -9,  -9,  -8,  -5,
    -7,  -5,  -4,  -7,  -5,  8,   8,   8,   8,   8,   -8,  -8,  -13, -11, -1,
    -10, -10, -15, -8,  -9,  -9,  -9,  -9,  -1,  -9,  -9,  -9,  -9,  8,   -9,
    -9,  -8,  -9,  -14, -9,  -9,  -9,  8,   -9,  -8,  -20, -20, -9,  -8,  -11,
    -10, 4,   -6,  -6,  -6,  -6,  -20, -18, -9,  -21, -18, -29, -5,  -15, -15,
    -10, 8,   8,   -10, -10, -9,  -9,  -7,  -9,  -6,  -7,  -10, -9,  -9,  -8,
    -4,  -9,  -4,  -8,  -19, -22, -3,  -2,  -2,  -2,  -2,  -2,  -2,  -3,  -2,
    -2,  -2,  -10, -10, -9,  -9,  -7,  -9,  -6,  -7,  -10, -9,  -9,  -5,  -7,
    -5,  -2,  -2,  -2,  -2,  -2,  -2,  -2,  -2,  -2,  -4,  -8,  -7,  -8,  -11,
    -8,  -18, -15, -8,  -8,  -18, -20, -7,  -7,  -20, -7,  -7,  -13, -17, -18,
    -18, -18, -18, -13, -13, -18, -13, -18, -13, -17, -17, -14, -14, -6,  -14,
    -10, -17, -18, -18, -18, -17, -8,  -8,  -13, -11, -11, -5,  -22, -5,  -22,
    -14, -8,  -14, -14, -17, -14, -8,  -22, -9,  -9,  -22, -9,  -9,  2,   -18,
    -14, -14, -14, -14, -14, -14, -14, -10, -14, -14, -14, -14, -2,  -11, -5,
    -22, -5,  -22, -8,  -8,  -11, -11, -17, -14, -17, -9,  -9,  -14, -9,  -9,
    -2,  2,   -13, -13, -13, -13, -13, -8,  -8,  -13, -8,  -13, -8,  -8,  -13,
    -13, -13, -13, -12, -12, -13, -11, -7,  -7,  -7,  -7,  -6,  -6,  -6,  -6,
    -6,  -6,  -6,  -6,  -6,  -14, -7,  -15, -7,  -15, -15, -14, -14, -23, -22,
    -17, -10, -10, -8,  -10, -10, 10,  -24, -25, -25, -25, -25, -2,  -9,  -9,
    -25, -9,  -25, -9,  -15, -9,  -24, -25, -25, -2,  -25, -9,  -4,  -4,  -14,
    -8,  -8,  -8,  -8,  -1,  -1,  -1,  -1,  3,   -1,  -1,  -1,  -1,  -1,  -18,
    -4,  -18, -22, 9,   9,   -8,  -10, -11, -14, -8,  -8,  -8,  -8,  -4,  -9,
    -12, -13, -17, -12, -22, -6,  -6,  -6,  -2,  -6,  0,   -6,  -6,  -3,  -8,
    -11, -15, -11, -22, -6,  -6,  0,   -6,  -8,  -31, -31, -10, -22, -22, -15,
    -15, -10, -24, -10, -13, -10, -10, -10, -10, -9,  -9,  -9,  -9,  -13, -9,
    -18, -18, -15, 8,   22,  10,  10,  10,  10,  -18, -18, -15, 8,   -9,  -10,
    -11, -11, -22, -11, -4,  -4,  -3,  -8,  -9,  -14, -11, -6,  -26, -14, -3,
    -4,  -3,  -5,  -4,  -3,  -17, -7,  -14, 0,   8,   -11, -11, -11, -25, -11,
    -3,  -1,  -2,  -3,  -4,  -13, -4,  -13, -3,  -14, -8,  -14, 1,   -3,  -4,
    -4,  -4,  -4,  -4,  -4,  -4,  -4,  -4,  -4,  -4,  -4,  -11, 8,   2,   -9,
    -10, -11, -11, -22, -11, -4,  -4,  8,   8,   8,   8,   8,   9,   8,   8,
    8,   8,   8,   8,   9,   8,   -4,  -4,  -10, -19, -13, -5,  -5,  -5,  -5,
    -5,  -5,  2,   2,   -5,  -5,  -5,  8,   -9,  -10, -11, -11, -22, -11, -4,
    -4,  -9,  -10, -11, -11, -22, -11, -4,  -4,  -3,  -8,  -9,  -14, -11, -6,
    -26, -14, -3,  -4,  -3,  -5,  -4,  -3,  -3,  -8,  -9,  -14, -11, -6,  -26,
    -14, -3,  -4,  -3,  -5,  -4,  -3,  -11, 8,   2,   -4,  -14, -4,  -14, -7,
    -9,  -9,  -13, -13, -8,  -3,  -6,  -6,  -6,  6,   -6,  -6,  -6,  6,   4,
    2,   4,   4,   -3,  -6,  -6,  -6,  -17, -10, -8,  -17, -10, -4,  -4,  -1,
    -6,  3,   3,   3,   3,   3,   3,   3,   3,   3,   3,   3,   3,   -8,  -1,
    -1,  -1,  -1,  3,   -1,  -1,  -1,  -1,  3,   3,   3,   -1,  -1,  -2,  3,
    -1,  -1,  -1,  -11, -13, -8,  -8,  -13, -8,  -9,  -15, -14, -8,  -8,  -18,
    -3,  -4,  -4,  -4,  -4,  -4,  -4,  -3,  -4,  -4,  -4,  -8,  -17, -17, -15,
    -13, -11, -8,  -3,  -3,  -3,  -3,  -3,  -3,  -3,  -3,  -3,  -5,  -5,  -8,
    -6,  -1,  -5,  -5,  -5,  -5,  -5,  -5,  -1,  -5,  -5,  -5,  -8,  -8,  -13,
    -8,  -9,  -15, -14, -8,  -8,  -18, -3,  -4,  -4,  -4,  -4,  -4,  -4,  -3,
    -4,  -4,  -4,  -8,  -3,  -3,  -3,  -3,  -3,  -3,  -3,  -3,  -3,  -1,  -1,
    -1,  -1,  3,   -1,  -1,  -1,  -1,  -1,  8,   -8,  -31, -31, -10, -22, -4,
    -4,  -22, -4,  -4,  -15, -9,  -10, -11, -11, -22, -11, -4,  -4,  -11, -11,
    -11, -25, -11, -3,  -1,  -2,  -3,  -11, -11, -11, -25, -11, -3,  -1,  -2,
    -3,  8,   8,   8,   8,   8,   9,   8,   -3,  -8,  -9,  -14, -11, -6,  -26,
    -14, -3,  -4,  -3,  -5,  -4,  -3,  -11, -13};

/*Collect the kern pair's data in one place*/
static const lv_font_fmt_txt_kern_pair_t kern_pairs = {
    .glyph_ids = kern_pair_glyph_ids,
    .values = kern_pair_values,
    .pair_cnt = 999,
    .glyph_ids_size = 0};

/*--------------------
 *  ALL CUSTOM DATA
 *--------------------*/

#if LV_VERSION_CHECK(8, 0, 0)
/*Store all the custom data of the font*/
static lv_font_fmt_txt_glyph_cache_t cache;
static const lv_font_fmt_txt_dsc_t font_dsc = {
#else
static lv_font_fmt_txt_dsc_t font_dsc = {
#endif
    .glyph_bitmap = glyph_bitmap,
    .glyph_dsc = glyph_dsc,
    .cmaps = cmaps,
    .kern_dsc = &kern_pairs,
    .kern_scale = 16,
    .cmap_num = 3,
    .bpp = 2,
    .kern_classes = 0,
    .bitmap_format = 0,
#if LV_VERSION_CHECK(8, 0, 0)
    .cache = &cache
#endif
};

/*-----------------
 *  PUBLIC FONT
 *----------------*/

/*Initialize a public general font descriptor*/
#if LV_VERSION_CHECK(8, 0, 0)
const lv_font_t lv_font_inter_bold_14 = {
#else
lv_font_t lv_font_inter_bold_14 = {
#endif
    .get_glyph_dsc =
        lv_font_get_glyph_dsc_fmt_txt, /*Function pointer to get glyph's data*/
    .get_glyph_bitmap =
        lv_font_get_bitmap_fmt_txt, /*Function pointer to get glyph's bitmap*/
    .line_height = 18, /*The maximum line height required by the font*/
    .base_line = 3,    /*Baseline measured from the bottom of the line*/
#if !(LVGL_VERSION_MAJOR == 6 && LVGL_VERSION_MINOR == 0)
    .subpx = LV_FONT_SUBPX_NONE,
#endif
#if LV_VERSION_CHECK(7, 4, 0) || LVGL_VERSION_MAJOR >= 8
    .underline_position = -2,
    .underline_thickness = 1,
#endif
    .dsc = &font_dsc /*The custom font data. Will be accessed by
                        `get_glyph_bitmap/dsc` */
};

#endif /*#if LV_FONT_INTER_BOLD_14*/
