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
    0xf7, 0xdf, 0x7d, 0xb6, 0xcb, 0x4, 0x13, 0xdb, 0x0,

    /* U+0022 "\"" */
    0x72, 0xdc, 0xb7, 0x2d, 0xcb,

    /* U+0023 "#" */
    0x7, 0x4b, 0x1, 0xc3, 0x80, 0xb0, 0xe0, 0xff, 0xff, 0x2f, 0xbe, 0x43, 0x87,
    0x0, 0xd2, 0xc2, 0xff, 0xfd, 0xbe, 0xbe, 0xb, 0xe, 0x3, 0xc3, 0x40,

    /* U+0024 "$" */
    0x0, 0x0, 0x0, 0x30, 0x0, 0x7f, 0x80, 0xbf, 0xfc, 0x3d, 0xcf, 0x4f, 0x30,
    0x3, 0xfd, 0x0, 0x3f, 0xf4, 0x0, 0xff, 0x49, 0x32, 0xe7, 0xcc, 0xf8, 0xff,
    0xfc, 0xb, 0xf8, 0x0, 0x30, 0x0, 0x0, 0x0,

    /* U+0025 "%" */
    0x3e, 0x1, 0xcb, 0x78, 0x30, 0xe3, 0x8e, 0xb, 0x39, 0xc0, 0x7f, 0x34, 0x0,
    0xa, 0x0, 0x1, 0xcf, 0xc0, 0x35, 0xdf, 0xa, 0x2c, 0xb0, 0xc1, 0xde, 0x34,
    0xb, 0xc0,

    /* U+0026 "&" */
    0x7, 0xe0, 0x0, 0xff, 0x80, 0x2d, 0x3c, 0x1, 0xd7, 0x80, 0xf, 0xf0, 0x0,
    0xfc, 0x10, 0x3f, 0xe3, 0x87, 0x8b, 0xf8, 0x7c, 0x3f, 0x3, 0xff, 0xf0, 0xb,
    0xe7, 0xc0,

    /* U+0027 "'" */
    0x71, 0xc7, 0x1c,

    /* U+0028 "(" */
    0xf, 0xb, 0x83, 0xc1, 0xf0, 0xb8, 0x2e, 0xb, 0x82, 0xe0, 0xb8, 0x1f, 0x3,
    0xc0, 0xb8, 0xf, 0x0, 0x0,

    /* U+0029 ")" */
    0x78, 0xf, 0x41, 0xe0, 0x3c, 0xf, 0x43, 0xd0, 0xf4, 0x3d, 0xf, 0x43, 0xc1,
    0xf0, 0xf4, 0x7c, 0x0, 0x0,

    /* U+002A "*" */
    0xa, 0xa, 0xa9, 0x7f, 0x87, 0xfd, 0x6a, 0x90, 0xa0,

    /* U+002B "+" */
    0x3, 0x80, 0x3, 0x80, 0x3, 0x80, 0xff, 0xfd, 0xbf, 0xfc, 0x3, 0x80, 0x3,
    0x80, 0x2, 0x40,

    /* U+002C "," */
    0x0, 0x2c, 0x2c, 0x38, 0x34,

    /* U+002E "." */
    0x14, 0x3c, 0x3c,

    /* U+002F "/" */
    0x1, 0x80, 0x3c, 0x3, 0xc0, 0x74, 0xb, 0x0, 0xf0, 0xe, 0x1, 0xd0, 0x2c, 0x3,
    0xc0, 0x38, 0x7, 0x40, 0xb0, 0x0,

    /* U+0030 "0" */
    0x7, 0xf8, 0x3, 0xff, 0xc3, 0xe0, 0xf4, 0xf0, 0x2e, 0x3c, 0x7, 0xdf, 0x1,
    0xf3, 0xc0, 0x7c, 0xf0, 0x2e, 0x3e, 0xf, 0x43, 0xff, 0xc0, 0x7f, 0x80,

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
    0x1f, 0xff, 0xb, 0xff, 0x82, 0xd0, 0x0, 0xb0, 0x0, 0x3e, 0xf8, 0xf, 0xef,
    0xc0, 0x0, 0xf0, 0x0, 0x3d, 0x3c, 0xf, 0xb, 0xff, 0x80, 0xbf, 0x80,

    /* U+0036 "6" */
    0x3, 0xf8, 0x3, 0xff, 0xc3, 0xe0, 0xf4, 0xf0, 0x0, 0x7d, 0xfc, 0x1f, 0xef,
    0xc7, 0xd0, 0xf4, 0xf0, 0x2e, 0x3d, 0xf, 0x47, 0xff, 0xc0, 0x7f, 0x80,

    /* U+0037 "7" */
    0x7f, 0xfe, 0x7f, 0xfe, 0x0, 0x3d, 0x0, 0x7c, 0x0, 0xf4, 0x0, 0xf0, 0x2,
    0xe0, 0x3, 0xc0, 0xb, 0x80, 0xf, 0x0, 0x2e, 0x0,

    /* U+0038 "8" */
    0x7, 0xf8, 0xb, 0xef, 0xc3, 0xd0, 0xf0, 0xf4, 0x3c, 0xf, 0xbd, 0x3, 0xff,
    0x43, 0xd1, 0xf1, 0xf0, 0x2e, 0x3c, 0xf, 0x4f, 0xef, 0xc0, 0xbf, 0x80,

    /* U+0039 "9" */
    0x7, 0xf4, 0xb, 0xff, 0x83, 0xc0, 0xf1, 0xf0, 0x3d, 0x3c, 0xf, 0x8f, 0xef,
    0xe0, 0xbd, 0xb8, 0x40, 0x3d, 0x3d, 0x1f, 0xb, 0xff, 0x40, 0x7f, 0x40,

    /* U+003A ":" */
    0x3c, 0x3c, 0x14, 0x0, 0x0, 0x14, 0x3c, 0x3c,

    /* U+003B ";" */
    0x2c, 0x3d, 0x4, 0x0, 0x0, 0x0, 0x2c, 0x2c, 0x38, 0x34, 0x0,

    /* U+003C "<" */
    0x0, 0x0, 0x0, 0x2d, 0x2, 0xfc, 0x2f, 0xe0, 0xfd, 0x0, 0xbf, 0x40, 0x1b,
    0xf8, 0x0, 0xbd, 0x0, 0x8,

    /* U+003E ">" */
    0x0, 0x0, 0xa4, 0x0, 0xbf, 0x40, 0x1b, 0xf4, 0x0, 0xbd, 0x2, 0xfc, 0x6f,
    0xd0, 0xfd, 0x0, 0x90, 0x0,

    /* U+003F "?" */
    0xf, 0xe0, 0x3f, 0xfc, 0x78, 0x3c, 0x0, 0x3c, 0x0, 0xf8, 0x3, 0xe0, 0x7,
    0xc0, 0x2, 0x40, 0x1, 0x0, 0x7, 0xc0, 0x7, 0x80,

    /* U+0040 "@" */
    0x0, 0x6f, 0xf4, 0x0, 0x3f, 0xeb, 0xf0, 0xf, 0x80, 0xb, 0xc1, 0xe1, 0xb6,
    0x6d, 0x3c, 0x7f, 0xf8, 0xe3, 0xcf, 0xb, 0x8f, 0x38, 0xe0, 0x38, 0xf3, 0x8e,
    0x3, 0x8f, 0x3c, 0xf0, 0x78, 0xe3, 0xcb, 0xef, 0xfd, 0x2e, 0x2f, 0xaf, 0x40,
    0xf8, 0x0, 0x0, 0x3, 0xfe, 0xb8, 0x0, 0x7, 0xff, 0x40,

    /* U+0041 "A" */
    0x1, 0xfc, 0x0, 0xb, 0xf0, 0x0, 0x3f, 0xd0, 0x1, 0xf7, 0x80, 0xb, 0x8f, 0x0,
    0x3d, 0x3d, 0x0, 0xf0, 0xb8, 0xb, 0xff, 0xf0, 0x3f, 0xab, 0xd0, 0xf0, 0xb,
    0x8b, 0xc0, 0x1f, 0x0,

    /* U+0042 "B" */
    0x3f, 0xf8, 0xf, 0xff, 0xc3, 0xc0, 0xf4, 0xf0, 0x3d, 0x3c, 0x1f, 0xf, 0xff,
    0x3, 0xea, 0xf0, 0xf0, 0x2e, 0x3c, 0xb, 0x8f, 0xff, 0xd3, 0xff, 0xd0,

    /* U+0043 "C" */
    0x2, 0xfe, 0x0, 0xff, 0xfc, 0x2f, 0x3, 0xe3, 0xd0, 0x1e, 0x3c, 0x0, 0x7,
    0xc0, 0x0, 0x3c, 0x0, 0x3, 0xd0, 0x1e, 0x2f, 0x3, 0xd0, 0xff, 0xfc, 0x2,
    0xfe, 0x0,

    /* U+0044 "D" */
    0x3f, 0xf8, 0x3, 0xff, 0xf0, 0x3c, 0xb, 0xc3, 0xc0, 0x3c, 0x3c, 0x2, 0xd3,
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
    0xc0, 0xaa, 0x3c, 0x1f, 0xf3, 0xd0, 0xf, 0x2f, 0x3, 0xe0, 0xff, 0xfc, 0x2,
    0xfe, 0x0,

    /* U+0048 "H" */
    0x3c, 0x2, 0xe3, 0xc0, 0x2e, 0x3c, 0x2, 0xe3, 0xc0, 0x2e, 0x3c, 0x2, 0xe3,
    0xff, 0xfe, 0x3f, 0xff, 0xe3, 0xc0, 0x2e, 0x3c, 0x2, 0xe3, 0xc0, 0x2e, 0x3c,
    0x2, 0xe0,

    /* U+0049 "I" */
    0x3c, 0x3c, 0x3c, 0x3c, 0x3c, 0x3c, 0x3c, 0x3c, 0x3c, 0x3c, 0x3c,

    /* U+004A "J" */
    0x0, 0x3c, 0x0, 0x3c, 0x0, 0x3c, 0x0, 0x3c, 0x0, 0x3c, 0x0, 0x3c, 0x0, 0x3c,
    0x0, 0x3c, 0xb8, 0x3c, 0x7f, 0xf8, 0x1f, 0xe0,

    /* U+004B "K" */
    0x3c, 0xb, 0xc3, 0xc1, 0xf4, 0x3c, 0x3e, 0x3, 0xcf, 0x80, 0x3e, 0xf0, 0x3,
    0xff, 0x0, 0x3f, 0xf8, 0x3, 0xd7, 0xd0, 0x3c, 0x2f, 0x3, 0xc0, 0xf8, 0x3c,
    0x7, 0xc0,

    /* U+004C "L" */
    0x3c, 0x0, 0x3c, 0x0, 0x3c, 0x0, 0x3c, 0x0, 0x3c, 0x0, 0x3c, 0x0, 0x3c, 0x0,
    0x3c, 0x0, 0x3c, 0x0, 0x3f, 0xfd, 0x3f, 0xfd,

    /* U+004D "M" */
    0x3e, 0x0, 0x3f, 0x3f, 0x0, 0x7f, 0x3f, 0x40, 0xbf, 0x3f, 0xc0, 0xff, 0x3e,
    0xd1, 0xef, 0x3d, 0xe3, 0xdf, 0x3c, 0xf3, 0xcf, 0x3c, 0xbf, 0x4f, 0x3c,
    0x3f, 0xf, 0x3c, 0x3e, 0xf, 0x3c, 0x1d, 0xf,

    /* U+004E "N" */
    0x3c, 0x2, 0xd3, 0xe0, 0x2d, 0x3f, 0x42, 0xd3, 0xfc, 0x2d, 0x3e, 0xe2, 0xd3,
    0xcf, 0x6d, 0x3c, 0x7f, 0xd3, 0xc2, 0xfd, 0x3c, 0xf, 0xd3, 0xc0, 0x7d, 0x3c,
    0x3, 0xd0,

    /* U+004F "O" */
    0x2, 0xfe, 0x0, 0x3f, 0xff, 0x2, 0xf0, 0x3e, 0xf, 0x40, 0x7c, 0x3c, 0x0,
    0xf1, 0xf0, 0x3, 0xc3, 0xc0, 0xf, 0xf, 0x40, 0x7c, 0x2f, 0x3, 0xe0, 0x3f,
    0xff, 0x0, 0x2f, 0xe0, 0x0,

    /* U+0050 "P" */
    0x3f, 0xf8, 0xf, 0xff, 0xc3, 0xc0, 0xf4, 0xf0, 0x2e, 0x3c, 0xf, 0x4f, 0x7,
    0xd3, 0xff, 0xe0, 0xff, 0x90, 0x3c, 0x0, 0xf, 0x0, 0x3, 0xc0, 0x0,

    /* U+0051 "Q" */
    0x2, 0xfe, 0x0, 0x3f, 0xff, 0x2, 0xf0, 0x3e, 0xf, 0x40, 0x7c, 0x3c, 0x0,
    0xf1, 0xf0, 0x3, 0xc3, 0xc0, 0xf, 0xf, 0x4e, 0x7c, 0x2f, 0x1f, 0xe0, 0x3f,
    0xff, 0x0, 0x2f, 0xfd, 0x0, 0x0, 0x14,

    /* U+0052 "R" */
    0x3f, 0xf8, 0xf, 0xff, 0xc3, 0xc0, 0xf4, 0xf0, 0x2e, 0x3c, 0xf, 0x4f, 0xff,
    0xc3, 0xff, 0xc0, 0xf0, 0xf0, 0x3c, 0x2e, 0xf, 0x3, 0xc3, 0xc0, 0xb8,

    /* U+0053 "S" */
    0x7, 0xf8, 0xb, 0xff, 0xc3, 0xd0, 0xf4, 0xf0, 0x0, 0x3f, 0x90, 0x3, 0xff,
    0x40, 0x6, 0xf4, 0x90, 0x2e, 0x7c, 0xf, 0x8f, 0xff, 0xc0, 0xbf, 0x80,

    /* U+0054 "T" */
    0xbf, 0xff, 0xdf, 0xff, 0xe0, 0x1e, 0x0, 0x7, 0x80, 0x1, 0xe0, 0x0, 0x78,
    0x0, 0x1e, 0x0, 0x7, 0x80, 0x1, 0xe0, 0x0, 0x78, 0x0, 0x1e, 0x0,

    /* U+0055 "U" */
    0x3c, 0x3, 0xd3, 0xc0, 0x3d, 0x3c, 0x3, 0xd3, 0xc0, 0x3d, 0x3c, 0x3, 0xd3,
    0xc0, 0x3d, 0x3c, 0x3, 0xd3, 0xc0, 0x3d, 0x3e, 0xb, 0xc1, 0xff, 0xf4, 0x6,
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
    0x3c, 0x3, 0xc2, 0xe0, 0xb8, 0xf, 0x5f, 0x0, 0xbf, 0xe0, 0x3, 0xfc, 0x0,
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
    0x6, 0x40, 0x3f, 0x1, 0xdd, 0xe, 0x3c, 0x70, 0x70,

    /* U+005F "_" */
    0x2a, 0xa9, 0x3f, 0xfe,

    /* U+0060 "`" */
    0x14, 0x1d, 0xf,

    /* U+0061 "a" */
    0xb, 0xf0, 0x3e, 0xbc, 0x14, 0x3d, 0xa, 0xfd, 0x3e, 0x7d, 0x78, 0x3d, 0x7e,
    0xfd, 0x2f, 0xad,

    /* U+0062 "b" */
    0x3c, 0x0, 0xf, 0x0, 0x3, 0xc0, 0x0, 0xf7, 0xe0, 0x3f, 0xfe, 0xf, 0x43,
    0xc3, 0xc0, 0xf4, 0xf0, 0x3d, 0x3d, 0xf, 0xf, 0xff, 0x83, 0xdf, 0x80,

    /* U+0063 "c" */
    0xb, 0xf4, 0x2f, 0xbd, 0x3c, 0x1e, 0x78, 0x0, 0x78, 0x0, 0x3c, 0x1e, 0x2f,
    0xfd, 0xb, 0xf4,

    /* U+0064 "d" */
    0x0, 0xf, 0x0, 0xf, 0x0, 0xf, 0xb, 0xdf, 0x3f, 0xff, 0x7c, 0x1f, 0x7c, 0xf,
    0x7c, 0xf, 0x7c, 0x1f, 0x3f, 0xff, 0xb, 0xdf,

    /* U+0065 "e" */
    0xb, 0xf4, 0x2f, 0xbc, 0x3c, 0x1e, 0x7f, 0xff, 0x79, 0x54, 0x3c, 0x9, 0x3f,
    0xbd, 0xb, 0xf4,

    /* U+0066 "f" */
    0x1, 0x40, 0xfc, 0x2e, 0x42, 0xd0, 0xff, 0xcb, 0xf8, 0x2d, 0x2, 0xd0, 0x2d,
    0x2, 0xd0, 0x2d, 0x2, 0xd0,

    /* U+0067 "g" */
    0xb, 0xdf, 0xf, 0xff, 0xc3, 0xc1, 0xf1, 0xf0, 0x3c, 0x7c, 0xf, 0x1f, 0x7,
    0xc3, 0xfb, 0xf0, 0x3f, 0x7c, 0x4, 0xf, 0xf, 0xaf, 0x80, 0xbf, 0x80,

    /* U+0068 "h" */
    0x3c, 0x0, 0x3c, 0x0, 0x3c, 0x0, 0x3d, 0xf8, 0x3f, 0xfe, 0x3d, 0x1f, 0x3c,
    0xf, 0x3c, 0xf, 0x3c, 0xf, 0x3c, 0xf, 0x3c, 0xf,

    /* U+0069 "i" */
    0x14, 0x3c, 0x24, 0x0, 0x3c, 0x3c, 0x3c, 0x3c, 0x3c, 0x3c, 0x3c, 0x3c,

    /* U+006A "j" */
    0x5, 0x3, 0xc0, 0x90, 0x0, 0xf, 0x3, 0xc0, 0xf0, 0x3c, 0xf, 0x3, 0xc0, 0xf0,
    0x3c, 0xf, 0x1f, 0xc7, 0xc0,

    /* U+006B "k" */
    0x3c, 0x0, 0xf, 0x0, 0x3, 0xc0, 0x0, 0xf0, 0xf8, 0x3c, 0xb8, 0xf, 0x7c, 0x3,
    0xfd, 0x0, 0xff, 0xc0, 0x3c, 0xf4, 0xf, 0x1f, 0x3, 0xc2, 0xf0,

    /* U+006C "l" */
    0x3c, 0xf3, 0xcf, 0x3c, 0xf3, 0xcf, 0x3c, 0xf3, 0xc0,

    /* U+006D "m" */
    0x3d, 0xf8, 0xfc, 0x3f, 0xff, 0xbe, 0x3c, 0x2e, 0x1f, 0x3c, 0x2d, 0xf, 0x3c,
    0x2d, 0xf, 0x3c, 0x2d, 0xf, 0x3c, 0x2d, 0xf, 0x3c, 0x2d, 0xf,

    /* U+006E "n" */
    0x3d, 0xf8, 0x3f, 0xfe, 0x3c, 0x1f, 0x3c, 0xf, 0x3c, 0xf, 0x3c, 0xf, 0x3c,
    0xf, 0x3c, 0xf,

    /* U+006F "o" */
    0xb, 0xf4, 0xb, 0xef, 0x43, 0xc1, 0xf1, 0xe0, 0x3c, 0x78, 0xf, 0xf, 0x7,
    0xc2, 0xfb, 0xd0, 0x2f, 0xd0,

    /* U+0070 "p" */
    0x3d, 0xf8, 0xf, 0xef, 0x83, 0xd0, 0xf0, 0xf0, 0x3d, 0x3c, 0xf, 0x4f, 0x47,
    0xc3, 0xff, 0xe0, 0xf7, 0xe0, 0x3c, 0x0, 0xf, 0x0, 0x3, 0xc0, 0x0,

    /* U+0071 "q" */
    0xb, 0xdf, 0x3f, 0xff, 0x7c, 0x1f, 0x7c, 0xf, 0x7c, 0xf, 0x7c, 0x1f, 0x3f,
    0xff, 0xb, 0xdf, 0x0, 0xf, 0x0, 0xf, 0x0, 0xf,

    /* U+0072 "r" */
    0x0, 0x3, 0xdd, 0x3f, 0xd3, 0xd0, 0x3c, 0x3, 0xc0, 0x3c, 0x3, 0xc0, 0x3c,
    0x0,

    /* U+0073 "s" */
    0x1f, 0xe0, 0x3e, 0xbc, 0x7c, 0x14, 0x3f, 0xe0, 0x6, 0xfc, 0x24, 0x3d, 0x3e,
    0xbc, 0x1f, 0xf0,

    /* U+0074 "t" */
    0x2d, 0x2, 0xd0, 0xbf, 0xc7, 0xf8, 0x2d, 0x2, 0xd0, 0x2d, 0x2, 0xd0, 0x2f,
    0x80, 0xbc,

    /* U+0075 "u" */
    0x3c, 0x1f, 0x3c, 0x1f, 0x3c, 0x1f, 0x3c, 0x1f, 0x3c, 0x1f, 0x3c, 0x2f,
    0x3f, 0xff, 0xf, 0xdf,

    /* U+0076 "v" */
    0xb8, 0x1f, 0x7c, 0x2d, 0x3c, 0x3c, 0x2d, 0x3c, 0x1e, 0xb4, 0xf, 0xf0, 0xb,
    0xf0, 0x7, 0xd0,

    /* U+0077 "w" */
    0xb8, 0x3c, 0x2d, 0x7c, 0x7d, 0x3c, 0x3c, 0xbe, 0x3c, 0x3c, 0xff, 0x78,
    0x2e, 0xeb, 0xb4, 0x1f, 0xc7, 0xf0, 0xf, 0xc3, 0xf0, 0xf, 0x83, 0xe0,

    /* U+0079 "y" */
    0xb8, 0x1f, 0x7c, 0x2d, 0x3c, 0x3c, 0x2d, 0x3c, 0x1e, 0x74, 0xf, 0xf0, 0xb,
    0xf0, 0x7, 0xd0, 0x3, 0xc0, 0x2f, 0x80, 0x3e, 0x0,

    /* U+007A "z" */
    0x3f, 0xfc, 0x3f, 0xfc, 0x0, 0xf4, 0x3, 0xe0, 0xb, 0xc0, 0x1f, 0x0, 0x3f,
    0xfc, 0x3f, 0xfc,

    /* U+007B "{" */
    0x2, 0xd0, 0xfd, 0xf, 0x0, 0xf0, 0xf, 0x1, 0xe0, 0xb8, 0xb, 0xe0, 0x1f, 0x0,
    0xf0, 0xf, 0x0, 0xfd, 0x3, 0xd0,

    /* U+007C "|" */
    0x11, 0xe7, 0x9e, 0x79, 0xe7, 0x9e, 0x79, 0xe7, 0x9e, 0x79, 0xe7, 0x9e,
    0x79, 0xe0,

    /* U+007D "}" */
    0xb8, 0x7, 0xd0, 0x1e, 0x1, 0xf0, 0x1f, 0x0, 0xf0, 0x3, 0xd0, 0xfd, 0x1f,
    0x1, 0xf0, 0x1f, 0x7, 0xe0, 0xb8, 0x0,

    /* U+007E "~" */
    0x3e, 0x1d, 0xbf, 0xfc, 0xf1, 0xf8};

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
     .box_h = 15,
     .ofs_x = 0,
     .ofs_y = -2},
    {.bitmap_index = 73,
     .adv_w = 192,
     .box_w = 10,
     .box_h = 11,
     .ofs_x = 1,
     .ofs_y = 0},
    {.bitmap_index = 101,
     .adv_w = 151,
     .box_w = 10,
     .box_h = 11,
     .ofs_x = 0,
     .ofs_y = 0},
    {.bitmap_index = 129,
     .adv_w = 47,
     .box_w = 3,
     .box_h = 4,
     .ofs_x = 0,
     .ofs_y = 7},
    {.bitmap_index = 132,
     .adv_w = 92,
     .box_w = 5,
     .box_h = 14,
     .ofs_x = 1,
     .ofs_y = -3},
    {.bitmap_index = 150,
     .adv_w = 92,
     .box_w = 5,
     .box_h = 14,
     .ofs_x = 0,
     .ofs_y = -3},
    {.bitmap_index = 168,
     .adv_w = 126,
     .box_w = 6,
     .box_h = 6,
     .ofs_x = 1,
     .ofs_y = 5},
    {.bitmap_index = 177,
     .adv_w = 152,
     .box_w = 8,
     .box_h = 8,
     .ofs_x = 1,
     .ofs_y = 0},
    {.bitmap_index = 193,
     .adv_w = 68,
     .box_w = 4,
     .box_h = 5,
     .ofs_x = 0,
     .ofs_y = -3},
    {.bitmap_index = 198,
     .adv_w = 67,
     .box_w = 4,
     .box_h = 3,
     .ofs_x = 0,
     .ofs_y = 0},
    {.bitmap_index = 201,
     .adv_w = 87,
     .box_w = 6,
     .box_h = 13,
     .ofs_x = 0,
     .ofs_y = -2},
    {.bitmap_index = 221,
     .adv_w = 154,
     .box_w = 9,
     .box_h = 11,
     .ofs_x = 0,
     .ofs_y = 0},
    {.bitmap_index = 246,
     .adv_w = 110,
     .box_w = 6,
     .box_h = 11,
     .ofs_x = 0,
     .ofs_y = 0},
    {.bitmap_index = 263,
     .adv_w = 141,
     .box_w = 9,
     .box_h = 11,
     .ofs_x = 0,
     .ofs_y = 0},
    {.bitmap_index = 288,
     .adv_w = 148,
     .box_w = 9,
     .box_h = 11,
     .ofs_x = 0,
     .ofs_y = 0},
    {.bitmap_index = 313,
     .adv_w = 152,
     .box_w = 9,
     .box_h = 11,
     .ofs_x = 0,
     .ofs_y = 0},
    {.bitmap_index = 338,
     .adv_w = 144,
     .box_w = 9,
     .box_h = 11,
     .ofs_x = 0,
     .ofs_y = 0},
    {.bitmap_index = 363,
     .adv_w = 148,
     .box_w = 9,
     .box_h = 11,
     .ofs_x = 0,
     .ofs_y = 0},
    {.bitmap_index = 388,
     .adv_w = 133,
     .box_w = 8,
     .box_h = 11,
     .ofs_x = 0,
     .ofs_y = 0},
    {.bitmap_index = 410,
     .adv_w = 148,
     .box_w = 9,
     .box_h = 11,
     .ofs_x = 0,
     .ofs_y = 0},
    {.bitmap_index = 435,
     .adv_w = 148,
     .box_w = 9,
     .box_h = 11,
     .ofs_x = 0,
     .ofs_y = 0},
    {.bitmap_index = 460,
     .adv_w = 67,
     .box_w = 4,
     .box_h = 8,
     .ofs_x = 0,
     .ofs_y = 0},
    {.bitmap_index = 468,
     .adv_w = 68,
     .box_w = 4,
     .box_h = 11,
     .ofs_x = 0,
     .ofs_y = -3},
    {.bitmap_index = 479,
     .adv_w = 152,
     .box_w = 8,
     .box_h = 9,
     .ofs_x = 1,
     .ofs_y = 0},
    {.bitmap_index = 497,
     .adv_w = 152,
     .box_w = 8,
     .box_h = 9,
     .ofs_x = 1,
     .ofs_y = 0},
    {.bitmap_index = 515,
     .adv_w = 126,
     .box_w = 8,
     .box_h = 11,
     .ofs_x = 0,
     .ofs_y = 0},
    {.bitmap_index = 537,
     .adv_w = 231,
     .box_w = 14,
     .box_h = 14,
     .ofs_x = 0,
     .ofs_y = -3},
    {.bitmap_index = 586,
     .adv_w = 168,
     .box_w = 11,
     .box_h = 11,
     .ofs_x = 0,
     .ofs_y = 0},
    {.bitmap_index = 617,
     .adv_w = 148,
     .box_w = 9,
     .box_h = 11,
     .ofs_x = 0,
     .ofs_y = 0},
    {.bitmap_index = 642,
     .adv_w = 168,
     .box_w = 10,
     .box_h = 11,
     .ofs_x = 0,
     .ofs_y = 0},
    {.bitmap_index = 670,
     .adv_w = 163,
     .box_w = 10,
     .box_h = 11,
     .ofs_x = 0,
     .ofs_y = 0},
    {.bitmap_index = 698,
     .adv_w = 137,
     .box_w = 8,
     .box_h = 11,
     .ofs_x = 0,
     .ofs_y = 0},
    {.bitmap_index = 720,
     .adv_w = 131,
     .box_w = 8,
     .box_h = 11,
     .ofs_x = 0,
     .ofs_y = 0},
    {.bitmap_index = 742,
     .adv_w = 170,
     .box_w = 10,
     .box_h = 11,
     .ofs_x = 0,
     .ofs_y = 0},
    {.bitmap_index = 770,
     .adv_w = 167,
     .box_w = 10,
     .box_h = 11,
     .ofs_x = 0,
     .ofs_y = 0},
    {.bitmap_index = 798,
     .adv_w = 63,
     .box_w = 4,
     .box_h = 11,
     .ofs_x = 0,
     .ofs_y = 0},
    {.bitmap_index = 809,
     .adv_w = 128,
     .box_w = 8,
     .box_h = 11,
     .ofs_x = 0,
     .ofs_y = 0},
    {.bitmap_index = 831,
     .adv_w = 154,
     .box_w = 10,
     .box_h = 11,
     .ofs_x = 0,
     .ofs_y = 0},
    {.bitmap_index = 859,
     .adv_w = 127,
     .box_w = 8,
     .box_h = 11,
     .ofs_x = 0,
     .ofs_y = 0},
    {.bitmap_index = 881,
     .adv_w = 205,
     .box_w = 12,
     .box_h = 11,
     .ofs_x = 0,
     .ofs_y = 0},
    {.bitmap_index = 914,
     .adv_w = 165,
     .box_w = 10,
     .box_h = 11,
     .ofs_x = 0,
     .ofs_y = 0},
    {.bitmap_index = 942,
     .adv_w = 175,
     .box_w = 11,
     .box_h = 11,
     .ofs_x = 0,
     .ofs_y = 0},
    {.bitmap_index = 973,
     .adv_w = 145,
     .box_w = 9,
     .box_h = 11,
     .ofs_x = 0,
     .ofs_y = 0},
    {.bitmap_index = 998,
     .adv_w = 175,
     .box_w = 11,
     .box_h = 12,
     .ofs_x = 0,
     .ofs_y = -1},
    {.bitmap_index = 1031,
     .adv_w = 147,
     .box_w = 9,
     .box_h = 11,
     .ofs_x = 0,
     .ofs_y = 0},
    {.bitmap_index = 1056,
     .adv_w = 147,
     .box_w = 9,
     .box_h = 11,
     .ofs_x = 0,
     .ofs_y = 0},
    {.bitmap_index = 1081,
     .adv_w = 150,
     .box_w = 9,
     .box_h = 11,
     .ofs_x = 0,
     .ofs_y = 0},
    {.bitmap_index = 1106,
     .adv_w = 163,
     .box_w = 10,
     .box_h = 11,
     .ofs_x = 0,
     .ofs_y = 0},
    {.bitmap_index = 1134,
     .adv_w = 168,
     .box_w = 11,
     .box_h = 11,
     .ofs_x = 0,
     .ofs_y = 0},
    {.bitmap_index = 1165,
     .adv_w = 232,
     .box_w = 15,
     .box_h = 11,
     .ofs_x = 0,
     .ofs_y = 0},
    {.bitmap_index = 1207,
     .adv_w = 160,
     .box_w = 10,
     .box_h = 11,
     .ofs_x = 0,
     .ofs_y = 0},
    {.bitmap_index = 1235,
     .adv_w = 162,
     .box_w = 10,
     .box_h = 11,
     .ofs_x = 0,
     .ofs_y = 0},
    {.bitmap_index = 1263,
     .adv_w = 149,
     .box_w = 9,
     .box_h = 11,
     .ofs_x = 0,
     .ofs_y = 0},
    {.bitmap_index = 1288,
     .adv_w = 92,
     .box_w = 5,
     .box_h = 13,
     .ofs_x = 1,
     .ofs_y = -2},
    {.bitmap_index = 1305,
     .adv_w = 87,
     .box_w = 6,
     .box_h = 13,
     .ofs_x = 0,
     .ofs_y = -2},
    {.bitmap_index = 1325,
     .adv_w = 92,
     .box_w = 5,
     .box_h = 13,
     .ofs_x = 0,
     .ofs_y = -2},
    {.bitmap_index = 1342,
     .adv_w = 109,
     .box_w = 7,
     .box_h = 5,
     .ofs_x = 0,
     .ofs_y = 6},
    {.bitmap_index = 1351,
     .adv_w = 107,
     .box_w = 8,
     .box_h = 2,
     .ofs_x = -1,
     .ofs_y = -2},
    {.bitmap_index = 1355,
     .adv_w = 111,
     .box_w = 4,
     .box_h = 3,
     .ofs_x = 1,
     .ofs_y = 9},
    {.bitmap_index = 1358,
     .adv_w = 130,
     .box_w = 8,
     .box_h = 8,
     .ofs_x = 0,
     .ofs_y = 0},
    {.bitmap_index = 1374,
     .adv_w = 142,
     .box_w = 9,
     .box_h = 11,
     .ofs_x = 0,
     .ofs_y = 0},
    {.bitmap_index = 1399,
     .adv_w = 132,
     .box_w = 8,
     .box_h = 8,
     .ofs_x = 0,
     .ofs_y = 0},
    {.bitmap_index = 1415,
     .adv_w = 142,
     .box_w = 8,
     .box_h = 11,
     .ofs_x = 0,
     .ofs_y = 0},
    {.bitmap_index = 1437,
     .adv_w = 134,
     .box_w = 8,
     .box_h = 8,
     .ofs_x = 0,
     .ofs_y = 0},
    {.bitmap_index = 1453,
     .adv_w = 86,
     .box_w = 6,
     .box_h = 12,
     .ofs_x = 0,
     .ofs_y = 0},
    {.bitmap_index = 1471,
     .adv_w = 142,
     .box_w = 9,
     .box_h = 11,
     .ofs_x = 0,
     .ofs_y = -3},
    {.bitmap_index = 1496,
     .adv_w = 140,
     .box_w = 8,
     .box_h = 11,
     .ofs_x = 0,
     .ofs_y = 0},
    {.bitmap_index = 1518,
     .adv_w = 61,
     .box_w = 4,
     .box_h = 12,
     .ofs_x = 0,
     .ofs_y = 0},
    {.bitmap_index = 1530,
     .adv_w = 61,
     .box_w = 5,
     .box_h = 15,
     .ofs_x = -1,
     .ofs_y = -3},
    {.bitmap_index = 1549,
     .adv_w = 130,
     .box_w = 9,
     .box_h = 11,
     .ofs_x = 0,
     .ofs_y = 0},
    {.bitmap_index = 1574,
     .adv_w = 61,
     .box_w = 3,
     .box_h = 11,
     .ofs_x = 0,
     .ofs_y = 0},
    {.bitmap_index = 1583,
     .adv_w = 204,
     .box_w = 12,
     .box_h = 8,
     .ofs_x = 0,
     .ofs_y = 0},
    {.bitmap_index = 1607,
     .adv_w = 139,
     .box_w = 8,
     .box_h = 8,
     .ofs_x = 0,
     .ofs_y = 0},
    {.bitmap_index = 1623,
     .adv_w = 137,
     .box_w = 9,
     .box_h = 8,
     .ofs_x = 0,
     .ofs_y = 0},
    {.bitmap_index = 1641,
     .adv_w = 142,
     .box_w = 9,
     .box_h = 11,
     .ofs_x = 0,
     .ofs_y = -3},
    {.bitmap_index = 1666,
     .adv_w = 142,
     .box_w = 8,
     .box_h = 11,
     .ofs_x = 0,
     .ofs_y = -3},
    {.bitmap_index = 1688,
     .adv_w = 92,
     .box_w = 6,
     .box_h = 9,
     .ofs_x = 0,
     .ofs_y = 0},
    {.bitmap_index = 1702,
     .adv_w = 126,
     .box_w = 8,
     .box_h = 8,
     .ofs_x = 0,
     .ofs_y = 0},
    {.bitmap_index = 1718,
     .adv_w = 87,
     .box_w = 6,
     .box_h = 10,
     .ofs_x = 0,
     .ofs_y = 0},
    {.bitmap_index = 1733,
     .adv_w = 139,
     .box_w = 8,
     .box_h = 8,
     .ofs_x = 0,
     .ofs_y = 0},
    {.bitmap_index = 1749,
     .adv_w = 131,
     .box_w = 8,
     .box_h = 8,
     .ofs_x = 0,
     .ofs_y = 0},
    {.bitmap_index = 1765,
     .adv_w = 190,
     .box_w = 12,
     .box_h = 8,
     .ofs_x = 0,
     .ofs_y = 0},
    {.bitmap_index = 1789,
     .adv_w = 131,
     .box_w = 8,
     .box_h = 11,
     .ofs_x = 0,
     .ofs_y = -3},
    {.bitmap_index = 1811,
     .adv_w = 128,
     .box_w = 8,
     .box_h = 8,
     .ofs_x = 0,
     .ofs_y = 0},
    {.bitmap_index = 1827,
     .adv_w = 92,
     .box_w = 6,
     .box_h = 13,
     .ofs_x = 0,
     .ofs_y = -2},
    {.bitmap_index = 1847,
     .adv_w = 84,
     .box_w = 3,
     .box_h = 18,
     .ofs_x = 1,
     .ofs_y = -3},
    {.bitmap_index = 1861,
     .adv_w = 92,
     .box_w = 6,
     .box_h = 13,
     .ofs_x = 0,
     .ofs_y = -2},
    {.bitmap_index = 1881,
     .adv_w = 152,
     .box_w = 8,
     .box_h = 3,
     .ofs_x = 1,
     .ofs_y = 3}};

/*---------------------
 *  CHARACTER MAPPING
 *--------------------*/

/*Collect the unicode lists and glyph_id offsets*/
static const lv_font_fmt_txt_cmap_t cmaps[] = {
    {.range_start = 32,
     .range_length = 13,
     .glyph_id_start = 1,
     .unicode_list = NULL,
     .glyph_id_ofs_list = NULL,
     .list_length = 0,
     .type = LV_FONT_FMT_TXT_CMAP_FORMAT0_TINY},
    {.range_start = 46,
     .range_length = 15,
     .glyph_id_start = 14,
     .unicode_list = NULL,
     .glyph_id_ofs_list = NULL,
     .list_length = 0,
     .type = LV_FONT_FMT_TXT_CMAP_FORMAT0_TINY},
    {.range_start = 62,
     .range_length = 58,
     .glyph_id_start = 29,
     .unicode_list = NULL,
     .glyph_id_ofs_list = NULL,
     .list_length = 0,
     .type = LV_FONT_FMT_TXT_CMAP_FORMAT0_TINY},
    {.range_start = 121,
     .range_length = 6,
     .glyph_id_start = 87,
     .unicode_list = NULL,
     .glyph_id_ofs_list = NULL,
     .list_length = 0,
     .type = LV_FONT_FMT_TXT_CMAP_FORMAT0_TINY}};

/*-----------------
 *    KERNING
 *----------------*/

/*Pair left and right glyphs for kerning*/
static const uint8_t kern_pair_glyph_ids[] = {
    3,  7,  3,  13, 3,  14, 3,  20, 3,  32, 3,  41, 5,  32, 7,  3,  7,  8,  7,
    51, 7,  53, 7,  54, 7,  56, 7,  59, 7,  85, 7,  86, 7,  87, 8,  7,  8,  13,
    8,  14, 8,  20, 8,  32, 8,  41, 9,  66, 9,  67, 9,  68, 9,  70, 9,  73, 9,
    78, 9,  80, 11, 7,  11, 13, 11, 14, 11, 20, 11, 32, 11, 41, 11, 62, 12, 18,
    12, 19, 12, 23, 12, 51, 12, 53, 12, 54, 12, 55, 12, 56, 12, 59, 13, 1,  13,
    2,  13, 3,  13, 8,  13, 16, 13, 17, 13, 19, 13, 21, 13, 22, 13, 23, 13, 24,
    13, 25, 13, 30, 13, 51, 13, 56, 13, 63, 14, 1,  14, 2,  14, 3,  14, 8,  14,
    16, 14, 17, 14, 19, 14, 21, 14, 22, 14, 23, 14, 24, 14, 25, 14, 30, 14, 51,
    14, 56, 14, 63, 15, 13, 15, 14, 15, 41, 15, 53, 15, 54, 15, 59, 16, 13, 16,
    14, 16, 23, 16, 56, 16, 62, 17, 13, 17, 14, 18, 20, 19, 13, 19, 14, 20, 13,
    20, 14, 20, 17, 21, 13, 21, 14, 22, 13, 22, 14, 22, 62, 23, 4,  23, 7,  23,
    13, 23, 14, 23, 16, 23, 19, 23, 20, 23, 21, 23, 22, 23, 23, 23, 24, 23, 25,
    23, 26, 23, 27, 23, 28, 23, 32, 23, 41, 23, 62, 23, 64, 23, 66, 23, 67, 23,
    68, 23, 70, 23, 78, 23, 80, 23, 82, 24, 13, 24, 14, 25, 13, 25, 14, 25, 23,
    25, 56, 25, 62, 26, 51, 26, 53, 26, 59, 27, 51, 27, 53, 27, 59, 29, 23, 29,
    32, 29, 51, 29, 53, 29, 54, 29, 55, 29, 56, 29, 57, 29, 59, 30, 32, 32, 3,
    32, 5,  32, 8,  32, 11, 32, 17, 32, 28, 32, 30, 32, 34, 32, 38, 32, 46, 32,
    48, 32, 50, 32, 51, 32, 53, 32, 54, 32, 56, 32, 59, 32, 61, 32, 66, 32, 67,
    32, 68, 32, 69, 32, 70, 32, 72, 32, 78, 32, 80, 32, 82, 32, 83, 32, 85, 32,
    86, 32, 87, 34, 32, 34, 55, 34, 62, 34, 85, 34, 87, 35, 13, 35, 14, 35, 15,
    35, 32, 35, 51, 35, 53, 35, 54, 35, 55, 35, 56, 35, 59, 35, 62, 37, 13, 37,
    14, 37, 32, 37, 41, 37, 62, 37, 64, 37, 66, 37, 67, 37, 68, 37, 70, 37, 76,
    37, 77, 37, 78, 37, 79, 37, 80, 37, 81, 37, 84, 37, 85, 37, 87, 37, 88, 38,
    32, 38, 51, 38, 53, 38, 55, 38, 56, 38, 59, 38, 72, 38, 73, 39, 62, 40, 62,
    41, 13, 41, 14, 41, 15, 41, 62, 42, 5,  42, 12, 42, 28, 42, 34, 42, 38, 42,
    46, 42, 48, 42, 50, 42, 66, 42, 67, 42, 68, 42, 70, 42, 72, 42, 78, 42, 80,
    42, 84, 42, 85, 42, 86, 42, 87, 42, 92, 43, 3,  43, 8,  43, 11, 43, 12, 43,
    17, 43, 32, 43, 34, 43, 38, 43, 46, 43, 48, 43, 51, 43, 53, 43, 54, 43, 56,
    43, 59, 43, 61, 43, 83, 43, 85, 43, 87, 43, 92, 44, 62, 45, 62, 46, 13, 46,
    14, 46, 15, 46, 32, 46, 51, 46, 53, 46, 54, 46, 55, 46, 56, 46, 59, 46, 62,
    47, 7,  47, 12, 47, 13, 47, 14, 47, 32, 47, 41, 47, 64, 47, 66, 47, 67, 47,
    68, 47, 70, 47, 78, 47, 80, 47, 92, 48, 13, 48, 14, 48, 15, 48, 32, 48, 51,
    48, 53, 48, 54, 48, 55, 48, 56, 48, 59, 48, 62, 49, 53, 49, 56, 49, 59, 49,
    66, 49, 67, 49, 68, 49, 70, 49, 78, 49, 80, 50, 32, 51, 7,  51, 12, 51, 13,
    51, 14, 51, 15, 51, 20, 51, 26, 51, 27, 51, 28, 51, 32, 51, 34, 51, 38, 51,
    41, 51, 46, 51, 48, 51, 62, 51, 64, 51, 66, 51, 67, 51, 68, 51, 70, 51, 76,
    51, 77, 51, 78, 51, 79, 51, 80, 51, 81, 51, 82, 51, 84, 51, 85, 51, 86, 51,
    87, 51, 88, 51, 92, 52, 13, 52, 14, 52, 15, 52, 62, 53, 7,  53, 12, 53, 13,
    53, 14, 53, 15, 53, 20, 53, 26, 53, 27, 53, 28, 53, 31, 53, 32, 53, 34, 53,
    38, 53, 41, 53, 46, 53, 48, 53, 59, 53, 62, 53, 64, 53, 66, 53, 67, 53, 68,
    53, 70, 53, 78, 53, 80, 53, 82, 53, 92, 54, 5,  54, 7,  54, 12, 54, 13, 54,
    14, 54, 15, 54, 20, 54, 26, 54, 27, 54, 28, 54, 32, 54, 34, 54, 38, 54, 41,
    54, 46, 54, 48, 54, 50, 54, 59, 54, 64, 54, 66, 54, 67, 54, 68, 54, 70, 54,
    76, 54, 77, 54, 78, 54, 79, 54, 80, 54, 81, 54, 82, 54, 92, 55, 12, 55, 28,
    55, 34, 55, 38, 55, 46, 55, 48, 55, 66, 55, 67, 55, 68, 55, 70, 55, 78, 55,
    80, 55, 92, 56, 7,  56, 12, 56, 13, 56, 14, 56, 20, 56, 26, 56, 27, 56, 28,
    56, 32, 56, 34, 56, 38, 56, 41, 56, 46, 56, 48, 56, 51, 56, 64, 56, 66, 56,
    67, 56, 68, 56, 70, 56, 72, 56, 76, 56, 77, 56, 78, 56, 79, 56, 80, 56, 81,
    56, 82, 56, 84, 56, 92, 57, 12, 57, 28, 57, 34, 57, 38, 57, 46, 57, 48, 57,
    92, 58, 66, 58, 67, 58, 68, 58, 70, 58, 73, 58, 78, 58, 80, 59, 3,  59, 5,
    59, 8,  59, 11, 59, 13, 59, 14, 59, 17, 59, 28, 59, 30, 59, 34, 59, 38, 59,
    46, 59, 48, 59, 50, 59, 51, 59, 53, 59, 54, 59, 56, 59, 59, 59, 61, 59, 66,
    59, 67, 59, 68, 59, 69, 59, 70, 59, 72, 59, 78, 59, 80, 59, 82, 59, 83, 59,
    85, 59, 86, 59, 87, 61, 7,  61, 13, 61, 14, 61, 20, 61, 32, 61, 41, 61, 62,
    62, 11, 62, 16, 62, 17, 62, 19, 62, 20, 62, 21, 62, 22, 62, 24, 62, 25, 62,
    34, 62, 38, 62, 46, 62, 48, 62, 51, 62, 52, 62, 53, 62, 59, 62, 61, 62, 72,
    62, 73, 62, 76, 62, 77, 62, 79, 62, 81, 62, 85, 62, 87, 64, 17, 64, 51, 64,
    53, 64, 54, 64, 56, 64, 59, 64, 85, 64, 87, 65, 10, 65, 32, 65, 51, 65, 53,
    65, 54, 65, 55, 65, 56, 65, 59, 65, 60, 65, 85, 65, 86, 65, 87, 65, 91, 66,
    51, 66, 54, 66, 56, 67, 62, 68, 51, 68, 53, 68, 54, 68, 56, 68, 59, 68, 85,
    68, 86, 68, 87, 69, 12, 69, 13, 69, 14, 69, 15, 69, 20, 69, 32, 69, 41, 69,
    56, 69, 62, 69, 64, 69, 66, 69, 67, 69, 68, 69, 70, 69, 78, 69, 80, 69, 82,
    69, 92, 70, 51, 70, 62, 70, 73, 71, 17, 71, 51, 71, 53, 71, 54, 71, 56, 71,
    59, 71, 85, 71, 87, 72, 10, 72, 53, 72, 54, 72, 59, 72, 60, 72, 62, 72, 91,
    73, 10, 73, 53, 73, 54, 73, 59, 73, 60, 73, 62, 73, 91, 74, 12, 74, 20, 74,
    28, 74, 51, 74, 66, 74, 67, 74, 68, 74, 70, 74, 78, 74, 80, 74, 85, 74, 87,
    74, 92, 75, 62, 76, 17, 76, 51, 76, 53, 76, 54, 76, 56, 76, 59, 76, 85, 76,
    87, 77, 17, 77, 51, 77, 53, 77, 54, 77, 56, 77, 59, 77, 85, 77, 87, 78, 10,
    78, 32, 78, 51, 78, 53, 78, 54, 78, 55, 78, 56, 78, 59, 78, 60, 78, 85, 78,
    86, 78, 87, 78, 91, 79, 10, 79, 32, 79, 51, 79, 53, 79, 54, 79, 55, 79, 56,
    79, 59, 79, 60, 79, 85, 79, 86, 79, 87, 79, 91, 80, 51, 80, 62, 80, 73, 81,
    12, 81, 13, 81, 14, 81, 15, 81, 28, 81, 32, 81, 41, 81, 51, 81, 57, 81, 64,
    81, 66, 81, 67, 81, 68, 81, 69, 81, 70, 81, 78, 81, 80, 81, 83, 81, 85, 81,
    86, 81, 87, 81, 92, 82, 51, 82, 53, 82, 54, 82, 56, 82, 59, 83, 12, 83, 20,
    83, 28, 83, 33, 83, 35, 83, 36, 83, 37, 83, 39, 83, 40, 83, 42, 83, 43, 83,
    44, 83, 45, 83, 47, 83, 49, 83, 51, 83, 53, 83, 54, 83, 56, 83, 59, 83, 65,
    83, 66, 83, 67, 83, 68, 83, 70, 83, 71, 83, 74, 83, 75, 83, 78, 83, 80, 83,
    82, 83, 90, 83, 92, 84, 51, 84, 56, 85, 13, 85, 14, 85, 15, 85, 28, 85, 32,
    85, 41, 85, 51, 85, 56, 85, 62, 85, 64, 85, 66, 85, 67, 85, 68, 85, 70, 85,
    78, 85, 80, 86, 7,  86, 13, 86, 14, 86, 32, 86, 41, 86, 51, 86, 57, 86, 66,
    86, 67, 86, 68, 86, 70, 86, 78, 86, 80, 87, 13, 87, 14, 87, 15, 87, 28, 87,
    32, 87, 41, 87, 51, 87, 56, 87, 62, 87, 64, 87, 66, 87, 67, 87, 68, 87, 70,
    87, 78, 87, 80, 88, 51, 88, 66, 88, 67, 88, 68, 88, 70, 88, 78, 88, 80, 89,
    66, 89, 67, 89, 68, 89, 70, 89, 73, 89, 78, 89, 80, 90, 62, 92, 18, 92, 19,
    92, 23, 92, 51, 92, 53, 92, 54, 92, 55, 92, 56, 92, 59};

/* Kerning between the respective left and right glyphs
 * 4.4 format which needs to scaled with `kern_scale`*/
static const int8_t kern_pair_values[] = {
    -8,  -20, -20, -14, -18, -37, -4,  -8,  -8,  -13, -14, -9,  -17, -14, -8,
    -8,  -8,  -8,  -20, -20, -14, -18, -37, -1,  -1,  -1,  -1,  3,   -1,  -1,
    -8,  -31, -31, -10, -22, -22, -15, -5,  -1,  -7,  -7,  -5,  -5,  -12, -7,
    -5,  -8,  -3,  -23, -23, -7,  -20, -5,  -1,  -7,  -6,  -7,  -3,  -23, -8,
    -15, -31, -8,  -3,  -23, -23, -7,  -20, -5,  -1,  -7,  -6,  -7,  -3,  -23,
    -8,  -15, -31, -9,  -9,  -14, 2,   2,   2,   -7,  -7,  -4,  -8,  -10, -9,
    -9,  -3,  -5,  -5,  -3,  -3,  -2,  -5,  -5,  -7,  -7,  -10, -13, -10, -28,
    -28, -3,  -4,  -13, -2,  -3,  4,   -3,  -2,  -8,  -8,  -20, -24, -22, -36,
    -10, -11, -11, -11, -11, -11, -11, -9,  -5,  -5,  -7,  -7,  -4,  -8,  -10,
    -8,  -14, -14, -8,  -14, -14, -17, -10, -18, -17, -17, -13, -20, -14, -17,
    -14, -18, -4,  -18, -22, -8,  -10, -14, -8,  -8,  -8,  -8,  -4,  -20, -20,
    -17, -17, -20, -22, -6,  -6,  -6,  -2,  -6,  0,   -6,  -6,  -3,  -8,  -15,
    -15, -15, -3,  -4,  -9,  2,   2,   -10, -10, -9,  -9,  -7,  -9,  -6,  -7,
    -10, -9,  -9,  -9,  -8,  -20, -15, -8,  -2,  -9,  -9,  -9,  -9,  -2,  -2,
    -9,  -2,  -9,  -2,  -8,  -8,  -8,  -8,  -5,  -7,  -5,  -4,  -7,  -5,  8,
    8,   8,   8,   -8,  -8,  -13, -11, -1,  -10, -15, -9,  -9,  -9,  -9,  -1,
    -9,  -9,  -9,  -9,  8,   -9,  -9,  -8,  -9,  -14, -9,  -10, -20, -20, -9,
    -8,  -10, 4,   -6,  -6,  -6,  -6,  -20, -18, -9,  -21, -18, -29, -5,  -15,
    -15, -9,  8,   8,   -10, -10, -9,  -9,  -7,  -9,  -6,  -7,  -10, -9,  -9,
    -8,  -4,  -9,  -8,  -19, -22, -3,  -2,  -2,  -2,  -2,  -2,  -2,  -4,  -10,
    -10, -9,  -9,  -7,  -9,  -6,  -7,  -10, -9,  -9,  -5,  -7,  -5,  -2,  -2,
    -2,  -2,  -2,  -2,  -4,  -8,  -7,  -8,  -8,  -18, -15, -8,  -8,  -18, -20,
    -7,  -7,  -20, -7,  -7,  -13, -17, -18, -18, -18, -18, -13, -13, -18, -13,
    -18, -13, -17, -17, -14, -14, -14, -10, -7,  -8,  -8,  -13, -11, -11, -5,
    -22, -22, -14, -8,  -14, -14, -17, -8,  -22, -9,  -9,  -22, -9,  -9,  2,
    -18, -14, -14, -14, -14, -14, -14, -14, -10, -5,  -2,  -11, -5,  -22, -22,
    -8,  -8,  -11, -11, -17, -17, -9,  -9,  -14, -9,  -9,  -2,  2,   -13, -13,
    -13, -13, -13, -8,  -8,  -13, -8,  -13, -8,  -8,  -5,  -12, -13, -7,  -7,
    -7,  -7,  -6,  -6,  -6,  -6,  -6,  -6,  -12, -14, -7,  -15, -15, -15, -14,
    -14, -23, -17, -10, -10, -8,  -10, -10, 10,  -24, -25, -25, -25, -25, -2,
    -9,  -9,  -25, -9,  -25, -9,  -15, -9,  -7,  -4,  -14, -8,  -8,  -8,  -8,
    -4,  -1,  -1,  -1,  -1,  3,   -1,  -1,  -18, -4,  -18, -22, 9,   9,   -8,
    -10, -14, -8,  -8,  -8,  -8,  -4,  -9,  -12, -13, -17, -12, -22, -6,  -6,
    -6,  -2,  -6,  0,   -6,  -6,  -3,  -8,  -11, -15, -11, -8,  -31, -31, -10,
    -22, -22, -15, -15, -10, -24, -10, -13, -10, -10, -10, -10, -9,  -9,  -9,
    -9,  -13, -9,  -18, -18, -15, 8,   22,  10,  10,  10,  10,  -18, -18, -9,
    -10, -11, -11, -22, -11, -4,  -4,  -3,  -8,  -9,  -14, -11, -6,  -26, -14,
    -3,  -4,  -3,  -4,  -3,  -17, -7,  -14, 8,   -11, -11, -11, -25, -11, -3,
    -1,  -3,  -4,  -13, -13, -3,  -14, -8,  -14, 1,   -3,  -4,  -4,  -4,  -4,
    -4,  -4,  -4,  -4,  -4,  -11, 8,   2,   -9,  -10, -11, -11, -22, -11, -4,
    -4,  8,   8,   8,   8,   8,   9,   8,   8,   8,   8,   8,   8,   9,   8,
    -4,  -10, -19, -13, -5,  -5,  -5,  -5,  -5,  -5,  2,   2,   -4,  8,   -9,
    -10, -11, -11, -22, -11, -4,  -4,  -9,  -10, -11, -11, -22, -11, -4,  -4,
    -3,  -8,  -9,  -14, -11, -6,  -26, -14, -3,  -4,  -3,  -4,  -3,  -3,  -8,
    -9,  -14, -11, -6,  -26, -14, -3,  -4,  -3,  -4,  -3,  -11, 8,   2,   -4,
    -14, -14, -7,  -9,  -9,  -13, -13, -8,  -3,  -6,  -6,  -6,  6,   -6,  -6,
    -6,  6,   4,   2,   4,   -4,  -17, -10, -8,  -17, -10, -4,  -1,  -6,  3,
    3,   3,   3,   3,   3,   3,   3,   3,   3,   3,   3,   -8,  -1,  -1,  -1,
    -1,  3,   -1,  -1,  -1,  -1,  3,   3,   3,   -1,  -1,  -2,  3,   -4,  -11,
    -13, -8,  -8,  -13, -8,  -15, -14, -8,  -8,  -18, -3,  -4,  -4,  -4,  -4,
    -4,  -4,  -8,  -17, -17, -15, -13, -11, -8,  -3,  -3,  -3,  -3,  -3,  -3,
    -8,  -8,  -13, -8,  -15, -14, -8,  -8,  -18, -3,  -4,  -4,  -4,  -4,  -4,
    -4,  -8,  -3,  -3,  -3,  -3,  -3,  -3,  -1,  -1,  -1,  -1,  3,   -1,  -1,
    8,   -5,  -1,  -7,  -7,  -5,  -5,  -12, -7,  -5};

/*Collect the kern pair's data in one place*/
static const lv_font_fmt_txt_kern_pair_t kern_pairs = {
    .glyph_ids = kern_pair_glyph_ids,
    .values = kern_pair_values,
    .pair_cnt = 805,
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
    .cmap_num = 4,
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
