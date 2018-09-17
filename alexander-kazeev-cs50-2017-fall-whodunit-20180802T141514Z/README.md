# Questions

## What's `stdint.h`?

Standard C library with needed data types

## What's the point of using `uint8_t`, `uint32_t`, `int32_t`, and `uint16_t` in a program?

Standards format and size for input's data

## How many bytes is a `BYTE`, a `DWORD`, a `LONG`, and a `WORD`, respectively?

BYTE = 1, DWORD = 4, LONG = 4, WORD = 2

## What (in ASCII, decimal, or hexadecimal) must the first two bytes of any BMP file be? Leading bytes used to identify file formats (with high probability) are generally called "magic numbers."

ASCII = B M, decimal = 66 77, hexadecimal = 0x424d or 0x4d42

## What's the difference between `bfSize` and `biSize`?

bfSize - size of this file *.bmp, biSize - size of BITMAPINFOHEADER

## What does it mean if `biHeight` is negative?

Order of RGBTRIPLE's is like on the screen, not reversed (as usual)

## What field in `BITMAPINFOHEADER` specifies the BMP's color depth (i.e., bits per pixel)?

biBitCount

## Why might `fopen` return `NULL` in lines 24 and 32 of `copy.c`?

File wasn't opend (not exists, open error's etc.)

## Why is the third argument to `fread` always `1` in our code?

Need to read one structure at a moment (1 BITMAPFILEHEADER, 1 BITMAPINFOHEADER or 1 RGBTRIPLE)

## What value does line 63 of `copy.c` assign to `padding` if `bi.biWidth` is `3`?

Number of bytes for scanline to make it multiple of 4

## What does `fseek` do?

Shifts position in stream (from begin, from current position, from end) by number of positions

## What is `SEEK_CUR`?

Current Position in stream

## Whodunit?

It was Professor Plum with the candlestick in the library.
