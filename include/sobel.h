// Name: Kevin Kim
// USC ID: 6656-3408-40
// USC Email: kkim8899@usc.edu
// Submission Date: February 22, 2026
// Description: this file contains declarations for sobel edge detection functions.
#pragma once

#include "image_io.h"

// this struct will hold all Sobel outputs for HW2 Problem 1(a).
struct SobelResult
{
    RawImage gx_norm;     // normalized to [0,255], 1 channel
    RawImage gy_norm;     // normalized to [0,255], 1 channel
    RawImage mag_norm;    // normalized to [0,255], 1 channel
    RawImage edge_binary; // 0=edge, 255=background, 1 channel

    // chosen threshold on raw magnitude (before normalization).
    float mag_threshold = 0.0f;
};

// Sobel edge detector on a GRAYSCALE image (1 channel).
// edgePercent: percentage (0..100). Example: 10 => keep top 10% magnitudes as edges.
// this function will return SobelResult with normalized visualizations and binary edge map.
SobelResult SobelEdgeDetector(const RawImage &gray, float edgePercent);
