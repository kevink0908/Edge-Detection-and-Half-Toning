// Name: Kevin Kim
// USC ID: 6656-3408-40
// USC Email: kkim8899@usc.edu
// Submission Date: February 22, 2026
// Description: this file contains declarations for utility functions.
#pragma once
#include "image_io.h"
#include <cstdint>

int ClampInt(int v, int lo, int hi);

// Clamp float to [0,255] and return uint8_t
uint8_t ClampU8(float v);

// Convert RGB image to grayscale using luminance weights.
// Output is 1-channel image (same width/height).
RawImage RgbToGray(const RawImage &rgb);
