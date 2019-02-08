/*===
lab1-skeleton.cc

Abstract: Skeleton for Lab 1
===*/

#include <stdlib.h>
#include <iostream>
#include <vector>
#include "image.h"
#define round(x) ((int)((int)x + (int)(2*(x-(int)x))))
using namespace std;

int main (int argc, char* argv[])
{	
	int height;
	int width;
	float sumVal;

	// check parameters' correctness
	if (argc != 3) 
	{
		cerr << "Usage: lab1 in.png out.png" << endl;
		return 1;
	}

	// load the image
	Image image;
	image.LoadPng (argv[1]);
	
	cout << "image height and width:" << image.Height() << image.Width() << endl;
	height = image.Height();
	width = image.Width();
	// The first 2 for loops are to iterate through the outer blocks and the last loops are to iterate through in the inner blocks 
	for( int i = 0; i < 128; i++){
		for( int j = 0; j< 128; j++){
			//Iterate the 1st time to calculate the average val
			sumVal = 0;
			for (int x = 0; x < 4;x ++){
				for( int y =0; y <4; y++){
					sumVal = sumVal + image.Pixel(4*i + x, 4*j + y);
				}
			}
			//Iterate the 2nd time to set the pixels to the average val
			sumVal = sumVal/16;
			round(sumVal);
			for (int x = 0; x < 4;x ++){
				for( int y =0; y <4; y++){
					image.Pixel(4*i + x, 4*j + y) = sumVal;
				}
			}
		}
	}
	// save it
	image.SavePng (argv[2]);
	
	return 0;
}
