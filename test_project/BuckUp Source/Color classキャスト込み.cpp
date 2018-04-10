#include <stdio.h>
#include <iostream>

enum class color {
	red,
	green,
	blue,
	alpha,
	Max
};



class color4c {
public:
	unsigned char red, green, blue, alpha;

	inline color4c SetColor(const color4c _values) {
		*this = _values;
	}
	inline color4c SetColor(const unsigned char _red, const unsigned char _green, const unsigned char _blue, const unsigned char _alpha) {
		this->red = _red;
		this->green = _green;
		this->blue = _blue;
		this->alpha = _alpha;
		return *this;
	}
};

class color4f {
public:
	float red, green, blue, alpha;
	inline color4f SetColor(const color4f _values) {
		*this = _values;
	}
	inline color4f SetColor(const float _red, const float _green, const float _blue, const float _alpha) {
		this->red = _red;
		this->green = _green;
		this->blue = _blue;
		this->alpha = _alpha;
		return *this;
	}
};

const color4c CastColor(const color4f _float_color) {
	color4c color;
	color.red = _float_color.red * 255;
	color.green = _float_color.green * 255;
	color.blue = _float_color.blue * 255;
	color.alpha = _float_color.alpha * 255;
	return color;
}

color4f CastColor(color4c _char_color) {
	color4f color;
	color.red = (float)_char_color.red / 255.0f;
	color.green = (float)_char_color.green / 255.0f;
	color.blue = (float)_char_color.blue / 255.0f;
	color.alpha = (float)_char_color.alpha / 255.0f;
	return color;
}

void DisplayValue(color4c &_color) {
	std::cout << "red:" << (int)_color.red << " green:" << (int)_color.green <<
		" blue:" << (int)_color.blue << " alpha:" << (int)_color.alpha << std::endl;
}

void DisplayValue(color4f &_color) {
	std::cout << "red:" << _color.red << " green:" << _color.green <<
		" blue:" << _color.blue << " alpha:" << _color.alpha << std::endl;
}

int main() {
	color4f maroon = { 0.5f, 0.0f, 0.0f, 1.0f };
	color4c castcolor = CastColor(maroon);
	DisplayValue(castcolor);

	color4f lime = { 0.0f,1.0f,0.0f };
	castcolor = CastColor(lime);
	DisplayValue(castcolor);

	getchar();
	return 0;
}