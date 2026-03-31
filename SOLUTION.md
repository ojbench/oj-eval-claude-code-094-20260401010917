# Solution Summary

## Problem: 马赛克侦探 (Mosaic Detective) - Problem 2379

### Problem Description
Reconstruct a mosaic image where:
- Input: m×n compressed image (each pixel represents average of 3×3 area)
- Output: 3m×3n reconstructed image
- Reconstruction rules:
  - Center pixels of each 3×3 block get the compressed pixel value
  - Non-center pixels calculated based on Manhattan distance to centers:
    - Type A: distance = 1
    - Type B: distance = 2
  - Gray value calculation:
    - Only B: average of B
    - Only A: average of A
    - Both A and B: 0.8 × average of A + 0.2 × average of B
  - Results rounded down (floor)

### Algorithm
1. Read compressed m×n image
2. Create 3m×3n result matrix
3. Place center pixels at positions (3i+1, 3j+1) for each compressed pixel (i,j)
4. For each non-center pixel:
   - Find all center pixels at Manhattan distance 1 (Type A)
   - Find all center pixels at Manhattan distance 2 (Type B)
   - Calculate gray value using the rules above
5. Output the reconstructed image

### Complexity Analysis
- Time Complexity: O(m × n × (3m) × (3n) × (m × n)) = O(m³ × n³) in worst case
  - For each of the 9mn output pixels, we check all mn centers
- Space Complexity: O(m × n) for storage
- Given constraints: m, n ∈ [1, 40], this is acceptable

### Test Results
- **Submission ID**: 766680
- **Score**: 100/100
- **Status**: Accepted
- **All test cases passed** (8/8):
  - test1: 10 points ✓
  - test2: 10 points ✓
  - test3: 10 points ✓
  - test4: 10 points ✓
  - test5: 20 points ✓
  - test6: 10 points ✓
  - test7: 20 points ✓
  - test8: 10 points ✓
- Maximum memory: 48.4 MB
- Maximum time: 721 ms (well within 1000 ms limit)

### Files
- `main.cpp`: C++ solution implementation
- `CMakeLists.txt`: Build configuration
- `.gitignore`: Git ignore rules for build artifacts
- `test_input.txt`: Sample test case
- `expected_output.txt`: Expected output for validation

### Submission Count
1 out of 5 attempts used (achieved 100% on first submission)
