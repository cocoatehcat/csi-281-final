//
// Created by cocoa on 12/2/2024.
//

#include "diamondsquare.h"

// Random number generator
int DiamondSquareClass::randomNumber(int range) {
    std::default_random_engine generator;
    std::uniform_int_distribution<int> distribution(1, range);
    return (distribution(generator));
}

// main function that does it all
// Pseudocode referenced: https://www.youtube.com/watch?v=4GuAV1PnurU
void DiamondSquareClass::diamondSquare(int size) {

    // Array used
    int arr[size][size];

    // Populate Array
    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {
            arr[i][j] = 0;
        }
    }

    // Give the corners random values
    arr[0][0] = randomNumber(10);
    arr[0][size - 1] = randomNumber(10);
    arr[size - 1][0] = randomNumber(10);
    arr[size - 1][size - 1] = randomNumber(10);

    // Print original array
    std::cout << "Diamond Square Array Size: %d\n" << size << std::endl;
    std::cout << "Diamond Square Array Printed: " << std::endl;
    for (int i = 0; i < size; i++) {
        std::cout << std::endl;
        for (int j = 0; j < size; j++) {
            std::cout << arr[i][j] << " ";
        }
    }
    std::cout << std::endl;

    // Size of the chunks used for the diamond square operations
    int chunk = size - 1;

    // Doing the steps while there still are chunks
    while (chunk > 1) {
        int half = chunk / 2;

        // Steps
        // Square step
        for (int y = 0; y < size - 1; y += chunk) {
            for (int x = 0; x < size - 1; x += chunk) {
                arr[y + half][x + half] = round(arr[y][x] + arr[y][x + chunk] + arr[y + chunk][x] + arr[y + chunk][x + chunk] / 4 + randomNumber(5));
            }
        }

        // Diamond step
        for (int y = 0; y < size; y += half) {
            for (int x = (y + half) % chunk; x < size; x += chunk) {
                // Computing points in range in array
                int sum = 0;
                int count = 0;
                if (x - half > 0) { // Used if any of the points are out of bounds
                    sum += arr[y][x - half];
                    count++;
                }
                if (x + half <= size) {
                    sum += arr[y][x + half];
                    count++;
                }
                if (y - half > 0) {
                    sum += arr[y - half][x];
                    count++;
                }
                if (y + half <= size) {
                    sum += arr[y + half][x];
                    count++;
                }
                // Returns average of available points
                arr[y][x] = round(sum / count + randomNumber(5));
            }
        }

        // Make the chunk for the next iteration
        chunk /= 2;

        // Print out array during steps
        std::cout << "Diamond Square Array Printed: " << std::endl;
        for (int i = 0; i < size; i++) {
            std::cout << std::endl;
            for (int j = 0; j < size; j++) {
                std::cout << arr[i][j] << " ";
            }
        }
        std::cout << std::endl << std::endl;
    }

}
