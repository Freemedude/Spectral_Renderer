#pragma once

#include "spectral/exported.hpp"

namespace Spectral
{

class EXPORTED IScene
{
};

class EXPORTED Hardcoded_Scene : public IScene
{
public:
	Hardcoded_Scene() = default;

};

}