#include <stdio.h>

int main () {

    // Increasing 0s to stress test the loop. Checking when it fails.
    for (float x = 0.000000; x < 0.000001; x = x + 0.0000001) {
		printf("Lopp Stress Test: %f\n", x);
    }   

    return 0;
}