#include "Image.h"

float G(float x, float y, float cx, float cy, float s){
	float dx = x - cx;
	float dy = y - cy;
	return 100*exp(-(dx*dx + dy*dy)/(s*s));
}

float G1(float x, float y, float cx, float cy, float s){
	float dx = x - cx;
	float dy = y - cy;
	return 100*exp(-(5*dx*dx + dy*dy)/(s*s));
}

float G2(float x, float y, float cx, float cy, float s){
	float dx = x - cx;
	float dy = y - cy;
	return 100*exp(-(dx*dx + 5*dy*dy)/(s*s));
}

float F(float x, float y){
	return 50 
		- G2(x, y, 250, 300, 150)
		- G1(x, y, 180, 220, 50)
		- G1(x, y, 310, 220, 50)
		- G(x, y, 350, 370, 40)
		- G2(x, y, 400, 350, 30)
		- G(x, y, 140, 340, 10);
}

int main(){
	ImageRGB img(600, 600);
	img.fill(white);
	for(int y = 0; y < img.height(); y++)
		for(int x = 0; x < img.width(); x++)
			if(F(x,y) <= 0)
				img(x,y) = brown;
		

	img.save("output.png");
}