#pragma once

#include "spectral/renderer.hpp"

#include "spectral_math.hpp"

namespace Spectral
{

Software_Renderer::Software_Renderer()
{
}

std::shared_ptr<Bitmap> Software_Renderer::render_scene(const std::shared_ptr<IScene> scene)
{
	// Dummy test
	const Sz width = 256 * 2;
	const Sz height = 256 * 2;
	const V2Sz size = { width, height };
	const std::shared_ptr<Bitmap> bitmap = std::make_shared<Bitmap>(size);
	
	F32 divisor_x = (F32)width / 255.0f;
	F32 divisor_y = (F32)height / 255.0f;

	// Write dummy image
	for (Sz y = 0; y < height; y++)
	{
		for (Sz x = 0; x < width; x++)
		{
			UChar red = (UChar)((F32)x / divisor_x);
			UChar green = (UChar)((F32)y / divisor_y);
			UChar blue = 64;
			bitmap->set_pixel({ x, y }, red, green, blue);

		}
	}
	return bitmap;
}

}