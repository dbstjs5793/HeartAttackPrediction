#include <stdio.h>
#include <stdlib.h>
#include <stdarg.h>
#include <stdint.h>
#include <math.h>
#include <avr/io.h>

float compute_kernel(float* x, float data1, float data2)
{
    float kernel = 0.0;
    kernel += x[0] * data1;
    kernel += x[1] * data2;

    return pow((0.001 * kernel) + 0.0, 3);
}

int predict(float* x) {
    float kernels[6] = { 0 };
  kernels[0] = compute_kernel(x,   1.0  , 1.0 );
                        kernels[1] = compute_kernel(x,   1.0  , 2.0 );
                        kernels[2] = compute_kernel(x,   2.0  , 3.0 );
                        kernels[3] = compute_kernel(x,   3.0  , 1.0 );
                        kernels[4] = compute_kernel(x,   3.0  , 2.0 );
                        kernels[5] = compute_kernel(x,   4.0  , 3.0 );
                        float decision = -9.474001e-06;
                        decision = decision - ( + kernels[0] * -1.0  + kernels[1] * -1.0  + kernels[2] * -1.0 );
                        decision = decision - ( + kernels[3] * 1.0  + kernels[4] * 1.0  + kernels[5] * 1.0 );

                        return decision > 0 ? 0 : 1;
}

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

const char* predictLabel(float* x) {
    return idxToLabel(predict(x));
}

void init_port()
{
	DDRF = 0xf0;
	PORTF = 0x00;
}

int main()
{
	init_port();

    float x_sample[] = { 1,2 };
	char str[100] = {0,};
	strcpy(str, predictLabel(x_sample));

	while(1){
		if(str[0] == '0'){
			PORTF = 0x10;
		}
		else if(str[0] == '1'){
			PORTF = 0x80;
		}
		else
			PORTF = 0x60;
	}

    return 0;
}
