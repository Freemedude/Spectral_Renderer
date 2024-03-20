#pragma once

#include "spectral/core_types.hpp"
#include "spectral/exported.hpp"

namespace Spectral
{

class EXPORTED Bitmap
{
public:
	explicit Bitmap (V2Sz size);
	~Bitmap();

public:
	V2Sz get_size() const;
	void set_pixel(V2Sz position, U8 r, U8 g, U8 b);
	UChar* get_data_ptr();

private:
	bool is_in_bounds(V2Sz position) const;
	Sz position_to_index(V2Sz position) const;

private:
	const Sz CHARS_PER_PIXEL = 3;

private:
	V2Sz m_size = {};
	UChar* m_data = nullptr;
};

}