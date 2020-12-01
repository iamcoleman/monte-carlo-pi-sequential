//
// Created by Coleman on 12/1/2020.
//

#include <iostream>
#include <cmath>
#include <random>
#include <ctime>

//#define POINTS 12800000
#define POINTS 10000000
#define TRUE_PI 3.141593

using namespace std;

// uses monte carlo method to estimate the value of pi
long double estimate_pi(long points) {
    long double hits = 0;

    // init random number gen
    auto rng = std::default_random_engine(std::random_device{}());
    std::uniform_real_distribution<long double> dist(-1, 1);

    for (auto i = 0; i < points; i++) {
        auto x = dist(rng);
        auto y = dist(rng);

        if (sqrt(pow(x, 2) + pow(y, 2)) <= 1) {
            hits++;
        }
    }

    // hits \ n * (area of square)
    return (hits / points) * 4;
}

int main() {
    cout << "Monte Carlo Estimation of Pi - Sequential" << endl;
    cout << "=========================================" << endl << endl;
    cout << "Estimating Pi on CPU (i7-10700k)" << endl << endl;

    cout << "Using " << POINTS << " points on a unit circle\n\n";

    clock_t c_start = clock();
    auto pi = estimate_pi(POINTS);
    clock_t c_end = clock();
    long double time_elapsed_ms = 1000.0 * (c_end - c_start) / CLOCKS_PER_SEC;
    cout << "CPU result:     " << pi << endl;
    cout << "Expected:       " << TRUE_PI << endl;
    cout << "Absolute Error: " << abs(TRUE_PI - pi) << endl;
    cout << "Relative Error: " << abs(TRUE_PI - pi) / TRUE_PI << endl << endl;
    cout << "Time        = " << time_elapsed_ms << "(ms)" << endl;
    cout << "Performance = " << (POINTS / time_elapsed_ms) * 1000.0 << " points/s" << endl;
    return 0;
}
