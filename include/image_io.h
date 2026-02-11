// Name: Kevin Kim
// USC ID: 6656-3408-40
// USC Email: kkim8899@usc.edu
// Submission Date: February 22, 2026
// Description: this file contains declartions for RAW image I/O functions and utilities.
#pragma once

#include <cstdint>
#include <cstddef>
#include <string>
#include <vector>

void read_raw(const std::string &filename,
              std::vector<uint8_t> &buffer,
              int width, int height, int channels);

void write_raw(const std::string &filename,
               const std::vector<uint8_t> &buffer);

struct RawImage
{
    int width = 0;
    int height = 0;
    int channels = 0; // 1 = gray, 3 = RGB
    std::vector<uint8_t> data;

    bool Empty() const { return width <= 0 || height <= 0 || channels <= 0 || data.empty(); }
};

inline RawImage MakeImage(int width, int height, int channels, uint8_t fillValue = 0)
{
    RawImage img;
    img.width = width;
    img.height = height;
    img.channels = channels;

    if (width <= 0 || height <= 0 || channels <= 0)
        return img;

    const std::size_t total =
        static_cast<std::size_t>(width) * static_cast<std::size_t>(height) * static_cast<std::size_t>(channels);

    img.data.assign(total, fillValue);
    return img;
}

// Pixel access helpers (row-major, interleaved)
inline std::size_t Index(const RawImage &img, int x, int y, int c)
{
    return static_cast<std::size_t>((y * img.width + x) * img.channels + c);
}

inline uint8_t &At(RawImage &img, int x, int y, int c)
{
    return img.data[Index(img, x, y, c)];
}

inline const uint8_t &At(const RawImage &img, int x, int y, int c)
{
    return img.data[Index(img, x, y, c)];
}
