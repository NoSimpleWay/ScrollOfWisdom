#include "EGabarite.h"

EGabarite::EGabarite(std::string _name, float _x, float _y, float _size_x, float _size_y)
{
	name = _name;

	*x = _x + 0.0001220703125f * 0.0f;//1 /  4096(texture atlas size) * 0.5(half_pixel))
	*y = _y + 0.0001220703125f * 0.0f;

	*uv_size_x = _size_x - 0.000244140625f * 0.0f;
	*uv_size_y = _size_y - 0.000244140625f * 0.0f;

	*x2 = _x + _size_x - 0.000244140625f * 0.00f;
	*y2 = _y + _size_y - 0.000244140625f * 0.10f;

	*size_x = _size_x * 4096.0f;
	*size_y = _size_y * 4096.0f;
}

EGabarite::EGabarite(std::string _name)
{
	name = _name;
}

EGabarite::~EGabarite()
{
	delete x;
	delete y;
	delete uv_size_x;
	delete uv_size_y;
	delete x2;
	delete y2;
	delete size_x;
	delete size_y;
}
