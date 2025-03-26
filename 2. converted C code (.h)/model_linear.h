#pragma once
#include <cstdarg>
namespace Eloquent {
    namespace ML {
        namespace Port {
            class SVM {
            public:
                /**
                * Predict class for features vector
                */
                int predict(float* x) {
                    float kernels[3] = { 0 };
                    float decisions[1] = { 0 };
                    int votes[2] = { 0 };
                    kernels[0] = compute_kernel(x, 1.0, 1.0);
                    kernels[1] = compute_kernel(x, 2.0, 3.0);
                    kernels[2] = compute_kernel(x, 3.0, 2.0);
                    float decision = -1.6;
                    decision = decision - (+kernels[0] * -0.2 + kernels[1] * -0.8);
                    decision = decision - (+kernels[2] * 1.0);

                    return decision > 0 ? 0 : 1;
                }

                /**
                * Predict readable class name
                */
                const char* predictLabel(float* x) {
                    return idxToLabel(predict(x));
                }

                /**
                * Convert class idx to readable name
                */
                const char* idxToLabel(uint8_t classIdx) {
                    switch (classIdx) {
                    case 0:
                        return "0";
                    case 1:
                        return "1";
                    default:
                        return "Houston we have a problem";
                    }
                }

            protected:
                /**
                * Compute kernel between feature vector and support vector.
                * Kernel type: linear
                */
                float compute_kernel(float* x, ...) {
                    va_list w;
                    va_start(w, 2);
                    float kernel = 0.0;

                    for (uint16_t i = 0; i < 2; i++) {
                        kernel += x[i] * va_arg(w, double);
                    }

                    return kernel;
                }
            };
        }
    }
}