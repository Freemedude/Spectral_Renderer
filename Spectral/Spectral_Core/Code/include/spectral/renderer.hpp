#pragma once


#include <memory>

#include "spectral/bitmap.hpp"
#include "spectral/exported.hpp"
#include "spectral/scene.hpp"


namespace Spectral
{

	class IRenderer
	{
	public:
		virtual std::shared_ptr<Bitmap> render_scene(const std::shared_ptr<IScene> scene) = 0;
	};

	class EXPORTED Software_Renderer : public IRenderer
	{
	public:
		explicit Software_Renderer();

	public:
		std::shared_ptr<Bitmap> render_scene(const std::shared_ptr<IScene> scene) override;
	};


}