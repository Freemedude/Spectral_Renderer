#pragma once

#include "spectral/bitmap.hpp"

#include <exception>
#include <format>
#include <cassert>
#include <stdexcept>

#include "spectral/core_types.hpp"


namespace Spectral
{
	Bitmap::Bitmap(V2Sz size)
		: m_size(size)
	{
		Sz total_size_bytes = size.x * size.y * CHARS_PER_PIXEL;
		m_data = new UChar[total_size_bytes];
		memset(m_data, 0, total_size_bytes);
	}

	Bitmap::~Bitmap()
	{
		delete[] m_data;
	}

	V2Sz Bitmap::get_size() const
	{
		auto result = m_size;
		
		return result;
	}

	void Bitmap::set_pixel(V2Sz position, U8 r, U8 g, U8 b)
	{
		assert(is_in_bounds(position));

		Sz index = position_to_index(position);
		UChar* base = m_data + index;
		
		base[0] = r;
		base[1] = g;
		base[2] = b;
	}

	bool Bitmap::is_in_bounds(V2Sz position) const
	{
		bool result = (0 <= position.x && position.x <= m_size.x) && (0 <= position.y && position.y <= m_size.y);

		return result;
	}

	Sz Bitmap::position_to_index(V2Sz position) const
	{
		assert(is_in_bounds(position));

		Sz result = position.x * CHARS_PER_PIXEL + position.y * m_size.x * CHARS_PER_PIXEL;

		return result;
	}


	UChar* Bitmap::get_data_ptr()
	{
		return m_data;
	}
}