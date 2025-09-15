#include "Render2D.h"
#include "matrix.h"
#include "transforms2d.h"

struct Vec2Col{
    vec2 position;
    RGB color;
 };
 
 
struct Shader{
    struct Varying{
        vec2 position;
        vec3 color;
    };

    void vertexShader(Vec2Col input, Varying& output){
        output.position = input.position;
        output.color = toVec(input.color);
    }

    void fragmentShader(Varying V, RGB& color){
        color =  toColor(V.color);
    }
};
 

int main(){
    Vec2Col P[] = {
        { { 0.0,  0.0}, red    },
        { { 0.6,  0.2}, green  },
        { {-0.4,  0.6}, blue   },
        { {-0.8, -0.4}, yellow },
        { { 0.4, -0.8}, cyan   },
        { { 0.8, -0.2}, orange },
    };
    
    LineStrip L{6};
    //Triangles L{6};

    Shader S;
    
    ImageRGB I(400, 400);
    I.fill(white);
    Render2D(P, L, S, I);
    I.save("output.png");
    
}