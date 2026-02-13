% Name: Kevin Kim
% USC ID: 6656-3408-40
% USC Email: kkim8899@usc.edu
% Submission Date: February 22, 2026
% Description: this program applies the Structured Edge (SE) detector to extract edge segments from color images for Problem 1(c).

% 1) Add edges toolbox.
% NOTE: This program uses a pretrained model from pdollar/edges (https://github.com/pdollar/edges) to perform edge detection.
edgesDetectPath = which('edgesDetect');
if isempty(edgesDetectPath)
    error('edgesDetect not found. Please install pdollar/edges and ensure it is on the MATLAB path.');
end
edgesRoot = fileparts(edgesDetectPath);
addpath(genpath(edgesRoot));

% 2) Load pretrained model.
scriptDir = fileparts(mfilename('fullpath'));
modelPath = fullfile(scriptDir, 'modelBsds.mat');
if ~exist(modelPath, 'file')
    error('Cannot find model file: %s', modelPath);
end
S = load(modelPath, 'model');
model = S.model;

% 3) Use the provided input images.
birdPath = fullfile(scriptDir, 'Bird.jpg');
deerPath = fullfile(scriptDir, 'Deer.jpg');
if ~exist(birdPath, 'file') || ~exist(deerPath, 'file')
    error('Bird.jpg and/or Deer.jpg not found next to SE_detector.m.');
end

% 4) Output directory.
outDir = fullfile(scriptDir, 'out');
if ~exist(outDir, 'dir')
    mkdir(outDir);
end

% Helper to run Structured Edge detection and save outputs.
run_one = @(imgPath, name) get_binary_edge_map(imgPath, name, model, outDir);

run_one(birdPath, 'Bird');
run_one(deerPath, 'Deer');

disp('[SE_detector] Done.');
