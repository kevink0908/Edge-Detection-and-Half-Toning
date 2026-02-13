% Name: Kevin Kim
% USC ID: 6656-3408-40
% USC Email: kkim8899@usc.edu
% Submission Date: February 22, 2026
% Description: this helper function generates a binary edge map by binarizing the probability edge map with a threshold.
function get_binary_edge_map(imgPath, name, model, outDir)

    I = imread(imgPath);

    % NOTE: for this project, we will apply the SE detector 
    %       directly to the RGB image.
    if size(I,3) == 1
        I = repmat(I, [1 1 3]);
    end

    % Run Structured Edge detector.
    [E, O] = edgesDetect(I, model); 

    % perform non-max suppression (thinning) if available. 
    if exist('edgesNms', 'file') == 2
        E = edgesNms(E, O, 1, 5, 1.01, 4);
    end

    % save probability edge map as PNG.
    E_vis = uint8(255 * mat2gray(E));
    imwrite(E_vis, fullfile(outDir, sprintf('%s_SE_prob.png', name)));

    % choose a threshold to get a binary map.
    edgePercent = 10;
    t = prctile(E(:), 100 - edgePercent);  % e.g., top 10% => threshold at 90th percentile

    BW = (E >= t);
    bin = uint8(255 * ~BW); 
    
    % save the binary edge map.
    imwrite(bin, fullfile(outDir, sprintf('%s_SE_edge.png', name)));

    fprintf('[SE] %s: saved prob + binary edge (edgePercent=%d, threshold=%.6f)\n', name, edgePercent, t);
end


