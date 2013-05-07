/*
 * base_math.c
 *
 *  Created on: 2013-5-7
 *      Author: gateman
 */

#include <stdio.h>
#include "base_math.h"

float bmath_round(float x, int decimal){
	if (0 > decimal){
		decimal = 0;
	}
	short i;
	if (0 < decimal){
		for (i=0; i < decimal; i++){
			x = x * 10;
		}
	}

	x = (int)(x + 0.5);

	if (0 < decimal){
		for (i=0; i < decimal; i++){
			x = x / 10;
		}
	}

	return x;
}

