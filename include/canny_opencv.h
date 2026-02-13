// Name: Kevin Kim
// USC ID: 6656-3408-40
// USC Email: kkim8899@usc.edu
// Submission Date: February 22, 2026
// Description: this file contains declarations for Canny Edge Detector functions.
#pragma once

#include <string>

int RunCannyEdgeDetector(const std::string &inJpgPath,
                         const std::string &outPrefix,
                         int lowThresh,
                         int highThresh);
