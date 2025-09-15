#include "Render2D.h"

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
#if 1
	clip_polygon = {
		Semiplane{ {-0.8, -0.4}, { 1,  0} }, 
		Semiplane{ { 0.8, -0.4}, {-1,  0} }, 
		Semiplane{ {-0.8, -0.4}, { 0,  1} }, 
		Semiplane{ { 0.8,  0.4}, { 0, -1} }
	};
#endif

	Vec2Col P[] = {
		{{-0.9, -0.3}, red     },
		{{-0.6, -0.2}, green   },
		{{-0.8, -0.8}, blue    },
		{{ 0.2, -0.6}, red     },
		{{ 0.9,  0.5}, yellow  },
		{{ 0.0,  0.0}, cyan    },
		{{-0.6,  0.2}, magenta },
		{{-0.4,  0.6}, brown   },
	};
	size_t n_verts = std::size(P);
	LineStrip L{n_verts};

	ImageRGB G(800, 800);
	G.fill(0xf5f5f5_rgb);

    Shader S;

	Render2D(P, L, S, G);
	
	G.save("output.png");
}
