#pragma once

#include <vector>
#include "Image.h"
#include "Primitives.h"
#include "rasterization.h"
#include "Clip2D.h"

template<class VertexAttrib, class Prims, class Shader>
struct Render2D{
	using Varying = typename Shader::Varying;

	Shader& shader;
	ImageRGB& image;

	Render2D(const VertexAttrib& V, const Prims& p, Shader& shader, ImageRGB& image) 
		: shader{shader}, image{image}
	{
		// Pipeline de renderização
		for(auto primitive: clip(assemble(p, transform(V)))) 
			draw(primitive);
	}

	std::vector<Varying> transform(const VertexAttrib& V){
		std::vector<Varying> PV(std::size(V)); 
		for(unsigned int i = 0; i < std::size(V); i++)
			shader.vertexShader(V[i], PV[i]);
		return PV;
	}

	void draw(Line<Varying> line){
		vec2 P[] = { get2DPosition(line[0]), get2DPosition(line[1]) };
		vec2 L[] = { toScreen(P[0]), toScreen(P[1]) };
			
		for(Pixel p: rasterizeLine(L)){
			float t = find_mix_param(toVec2(p), L[0], L[1]);
			Varying vi = mix_line(t, line);
			paint(p, vi);
		}
	}
	
	void draw(Triangle<Varying> tri){
		/* TAREFA - AULA 09 */
	}

	vec2 toScreen(vec2 P) const{
		return {
			((P[0] + 1)*image.width() - 1)/2,
			((P[1] + 1)*image.height() - 1)/2
		};
	}

	void paint(Pixel p, Varying v){
		if(p.x >= 0 && p.y >= 0 && p.x < image.width() && p.y < image.height())
			shader.fragmentShader(v, image(p.x,p.y));
	}
};
