EE 569 Digital Image Processing Homework #2
Name: Seung Kyu (Kevin) Kim
USC ID: 6656-3408-40
Email: kkim8899@usc.edu
Submission Date: February 22, 2026

==================================================
Environment
==================================================
Operating System:
macOS Sequoia 15.1.1

Compiler:
clang++ (Apple clang, C++17)

==================================================
Source File Descriptions
==================================================
<include src file description here>
==================================================
How to compile this program:
==================================================
make clean
make
// this will generate an executable called "hw2".
==================================================
How to run this program:
==================================================
Problem 1a: Sobel on RAW (Bird.raw, Deer.raw)
Input RAW is RGB, output RAW is 8-bit gray or binary depending on mode.

1) X gradient normalized:
  bin/hw2 sobel_raw data/p1_edge/Bird.raw out/p1_edge/sobel/bird_gx.raw 481 321

2) Y gradient normalized:
  bin/hw2 sobel_raw data/p1_edge/Bird.raw out/p1_edge/sobel/bird_gy.raw 481 321

3) Gradient magnitude normalized:
  bin/hw2 sobel_raw data/p1_edge/Bird.raw out/p1_edge/sobel/bird_gm.raw 481 321

4) Final binary edge map (threshold in percent, e.g. 12.5):
  bin/hw2 sobel_raw data/p1_edge/Bird.raw out/p1_edge/sobel/bird_edge.raw 481 321 --thresh_pct 12.5 --binary

Repeat for Deer.raw similarly.

--------------------------------------------------
Problem 1b: Canny on JPG (Bird.jpg, Deer.jpg) [requires OpenCV]
  bin/hw2 canny_jpg data/p1_edge/Bird.jpg out/p1_edge/canny/bird_canny.raw --low 50 --high 150

If OpenCV is not detected at build time, canny_jpg is disabled.

--------------------------------------------------
Problem 2: Digital halftoning on Reflection.raw (1280x852, gray)
Fixed threshold:
  bin/hw2 ht_thresh data/p2_halftone/Reflection.raw out/p2_halftone/threshold/reflection_t128.raw 1280 852 --T 128

Random threshold:
  bin/hw2 ht_random data/p2_halftone/Reflection.raw out/p2_halftone/random/reflection_rand.raw 1280 852 --seed 1

Bayer (dithering matrix):
  bin/hw2 ht_bayer data/p2_halftone/Reflection.raw out/p2_halftone/bayer/reflection_bayer4.raw 1280 852 --n 4

Error diffusion:
  bin/hw2 ht_ed_fs    data/p2_halftone/Reflection.raw out/p2_halftone/ed_fs/reflection_fs.raw 1280 852 --serpentine 1
  bin/hw2 ht_ed_jjn   data/p2_halftone/Reflection.raw out/p2_halftone/ed_jjn/reflection_jjn.raw 1280 852
  bin/hw2 ht_ed_stucki data/p2_halftone/Reflection.raw out/p2_halftone/ed_stucki/reflection_stucki.raw 1280 852

--------------------------------------------------
Problem 3: Color halftoning on Flowers.raw (1280x853, RGB)
Separable CMY + FS:
  bin/hw2 color_sep_fs data/p3_color/Flowers.raw out/p3_color/separable_fs_cmy/flowers_sep.raw 1280 853

MBVQ + FS:
  bin/hw2 color_mbvq_fs data/p3_color/Flowers.raw out/p3_color/mbvq_fs/flowers_mbvq.raw 1280 853

==================================================
Notes:
==================================================
- Input images are expected under ./data (not included in submission).
- All generated outputs will be written to ./out.