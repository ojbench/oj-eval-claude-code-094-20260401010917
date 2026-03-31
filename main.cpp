#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

int main() {
    int m, n;
    cin >> m >> n;

    // Read the compressed image
    vector<vector<int>> compressed(m, vector<int>(n));
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            cin >> compressed[i][j];
        }
    }

    // Create the reconstructed image (3m x 3n)
    vector<vector<int>> result(3 * m, vector<int>(3 * n));

    // First, place all center pixels
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            result[3 * i + 1][3 * j + 1] = compressed[i][j];
        }
    }

    // Now calculate non-center pixels
    for (int i = 0; i < 3 * m; i++) {
        for (int j = 0; j < 3 * n; j++) {
            // Skip center pixels (already set)
            if (i % 3 == 1 && j % 3 == 1) continue;

            // Find type A and type B centers
            vector<int> typeA, typeB;

            // Check all possible center positions
            for (int ci = 0; ci < m; ci++) {
                for (int cj = 0; cj < n; cj++) {
                    int centerRow = 3 * ci + 1;
                    int centerCol = 3 * cj + 1;

                    int dist = abs(i - centerRow) + abs(j - centerCol);

                    if (dist == 1) {
                        typeA.push_back(compressed[ci][cj]);
                    } else if (dist == 2) {
                        typeB.push_back(compressed[ci][cj]);
                    }
                }
            }

            // Calculate gray value based on rules
            double gray = 0.0;
            if (typeA.empty() && !typeB.empty()) {
                // Only B exists
                double sum = 0;
                for (int val : typeB) sum += val;
                gray = sum / typeB.size();
            } else if (!typeA.empty() && typeB.empty()) {
                // Only A exists
                double sum = 0;
                for (int val : typeA) sum += val;
                gray = sum / typeA.size();
            } else if (!typeA.empty() && !typeB.empty()) {
                // Both A and B exist
                double sumA = 0, sumB = 0;
                for (int val : typeA) sumA += val;
                for (int val : typeB) sumB += val;
                double avgA = sumA / typeA.size();
                double avgB = sumB / typeB.size();
                gray = avgA * 0.8 + avgB * 0.2;
            }

            result[i][j] = (int)floor(gray);
        }
    }

    // Output the result
    for (int i = 0; i < 3 * m; i++) {
        for (int j = 0; j < 3 * n; j++) {
            cout << result[i][j];
            if (j < 3 * n - 1) cout << " ";
        }
        cout << endl;
    }

    return 0;
}
