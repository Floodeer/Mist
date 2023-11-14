#include "MistCore.h"
#include "AppLayer.h"

using namespace Mist;

class Sandbox : public Application
{
public:
	Sandbox()
	{
		PushLayer(new AppLayer());
	}
};

int main()
{
	std::unique_ptr<Sandbox> app = std::make_unique<Sandbox>();
	app->Run();
}