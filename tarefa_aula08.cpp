#include "Render2D_v1.h"
#include "bezier.h"
#include "polygon_triangulation.h"
#include "transforms2d.h"

int main(){
   std::vector<vec2> CP = loadCurve("curva.txt");
   std::vector<vec2> P = sample_bezier_spline<3>(CP, 30);

   LineStrip L{P.size()};

   mat3 M1 = rotate_2d(1.57);
   mat3 M2 = scale(0.1,0.1);
  
   ImageRGB G(600, 500);
   G.fill(black);

    for (double i=0; i<200; i++){
        mat3 R = rotate_2d(i*M_PI/16);
        double p = (1+((i)/10));
        mat3 T = translate(p*cos(i*M_PI/16),p*sin(i*M_PI/16));
        render2d(M2*T*R*P, L, green, G);

    }

    

   G.save("output.png");
}
