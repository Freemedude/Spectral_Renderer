#include "spectral/spectral.hpp"
#include "bmp_exporter.hpp"

#include <Windows.h>
#include <memory>

int main()
{
	using namespace Spectral;

	// Setup scene
	const std::shared_ptr<IScene> scene = std::make_shared<Hardcoded_Scene>();

	// Render image
	const std::shared_ptr<IRenderer> renderer = std::make_shared<Software_Renderer>();

	const std::shared_ptr<Bitmap> bitmap = renderer->render_scene(scene);
	
	// Export to BMP
	Bmp_Exporter exporter(bitmap);
	exporter.write_to_file("../../data/get_there.bmp");
	return 0;
}