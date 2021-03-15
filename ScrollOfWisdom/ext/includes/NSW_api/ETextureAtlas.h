#pragma once
//#include 
#include "EGraphicCore.h"
#include <iostream>

class ETextureAtlas
{
public:
	unsigned int framebuffer;
	unsigned int colorbuffer;
	unsigned int rbo;

	float size_x;
	float size_y;

	bool free_space[1024][1024];

	bool can_place_here(int _x, int _y, int _w, int _h);

	static EGabarite* put_texture_to_atlas(std::string _name, ETextureAtlas* _ta);
	static void active_this_texture_atlas(ETextureAtlas* _ta, ETextureAtlas* _ta2);
	static void active_this_texture_atlas(ETextureAtlas* _ta, ETextureAtlas* _ta2, ETextureAtlas* _ta3);
	static void return_to_this_texture_atlas(ETextureAtlas* _ta);

	ETextureAtlas(int _x, int _y);
	~ETextureAtlas();

	static EGabarite* get_supermap_from_regular_texture_path(std::string _s, ETextureAtlas* _a);
};