#include "Image.h"
#include <algorithm>


void over(RGB& Bg, RGBA C){
   vec4 vc = toVec(C);
   float alpha = vc[3];
   vec3 col = lerp(alpha, toVec(Bg), toVec3(vc));
   Bg = toColor(col);
}


int main(){
      ImageRGBA BG("BG.png");
      ImageRGB BG1("BG.png");

      int w = BG.width();
      int h = BG.height();


      ImageRGBA T0("0.png");
      ImageRGBA T1("1.png");
      ImageRGBA T2("2.png");
      ImageRGBA T3("3.png");
      ImageRGBA T4("4.png");
      ImageRGBA T5("5.png");
      ImageRGBA T6("6.png");
      ImageRGBA T7("7.png");
      ImageRGBA T8("8.png");
      ImageRGBA T13("13.png");
      ImageRGBA T14("14.png");
      ImageRGBA T15("15.png");
      ImageRGBA T17("17.png");
      ImageRGBA T18("18.png");

      ImageRGBA I1("Idle (1).png");
      ImageRGBA I2("Walk (18).png");
      ImageRGBA I3("Dead (15).png");

      ImageRGBA B3("Bush (3).png");
      ImageRGBA S1("Sign_2.png");
      ImageRGBA MU("mushroom_2.png");

      ImageRGBA M1[5][7] = {
            {S1, I2, T0, T0, T0, T0, T0},
            {T13, T15, T0, T0, I1, B3, T0},
            {T0, MU, I3, B3, T1, T3, T0},
            {T0, T1, T2, T7, T8, T6, T0},
            {T0, T4, T5, T5, T5, T6, T0}};

      ImageRGBA M2[5][7] = {
            {T0, T0, T0, T0, T0, T0, T0},
            {T0, T0, T0, T0, T0, T0, T0},
            {T0, T0, T0, T0, T0, T0, T0},
            {T17, T17, T0, T0, T0, T17, T17},
            {T18, T18, T0, T0, T0, T18, T18}};


      ImageRGB H(w-104, h-110);

      for (int y = 0; y < h-110; y++){
            for (int x = 0; x < w-104; x++){
                        H(x,y) = BG1(x,y);
            }
      }

      for (int i = 0; i < 5; i++){
            for (int j = 0; j < 7; j++){
                        for (int y = i*128; y < (i*128)+128; y++){
                              for (int x = j*128; x < (j*128)+128; x++){
                                    over( H(x, y), M2[4-i][j](x-(j*128),y-(i*128)));
                              }
                        }
            }
            
      }

      for (int i = 0; i < 5; i++){
            for (int j = 0; j < 7; j++){
                        for (int y = i*128; y < (i*128)+128; y++){
                              for (int x = j*128; x < (j*128)+128; x++){
                                    over( H(x, y), M1[4-i][j](x-(j*128),y-(i*128)));
                              }
                        }
            }
            
      }

      

     H.save("output.png");
     std::cout << w << "\n";
     std::cout << h;

     int exit;
     std::cin.get();
}
