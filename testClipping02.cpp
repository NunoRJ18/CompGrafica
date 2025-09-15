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
#if 0
	clip_polygon = {
		Semiplane{ {-0.6, -0.4}, { 1,  0} }, 
		Semiplane{ { 0.6, -0.4}, {-1,  0} }, 
		Semiplane{ {-0.6, -0.4}, { 0,  1} }, 
		Semiplane{ { 0.6,  0.4}, { 0, -1} }
	};
#elif 1
	clip_polygon = {
		Semiplane{ {-0.3, -0.1}, { 0.16,  0.15} }, 
		Semiplane{ { 0.6, 0.2}, {-0.22,  0.23} }, 
		Semiplane{ { 0, 0.5}, { 0,  -1} }, 
	};
#endif

	Vec2Col P[] = {
		{{-0.4, -0.6}, red     },
		{{-0.2, -0.8}, green   },
		{{-0.8, -0.8}, blue    },
		
		{{-0.2,  0.0}, red     },
		{{ 0.2, -0.6}, yellow  },
		{{-0.8,  0.0}, cyan    },
		
		{{ 0.0,  0.0}, magenta },
		{{ 0.3, -0.2}, brown   },
		{{ 0.4, -0.6}, blue    },
		
		{{ 0.3,  0.0}, green   },
		{{ 0.7,  0.8}, yellow  },
		{{ 0.8, -0.8}, cyan    },
		
		{{ 0.0,  0.2}, orange  },
		{{ 0.2,  0.8}, green   },
		{{ 0.4,  0.6}, gray    },
		
		{{-0.4,  0.2}, red     },
		{{-0.2,  0.6}, brown   },
		{{-0.8,  0.1}, blue    },
	};
	size_t n_verts = std::size(P);
	Triangles L{n_verts};

	ImageRGB G(800, 800);
	G.fill(0xf5f5f5_rgb);

    Shader S;

	Render2D(P, L, S, G);
	
	G.savePNG("output.png");
}
