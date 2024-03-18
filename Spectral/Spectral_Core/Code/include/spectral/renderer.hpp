
#include <memory>

class IScene_Source;

namespace Spectral
{

class Renderer
{
public:
    Renderer();

public:
    void render(std::shared_ptr<IScene_Source> scene);
};

   
}