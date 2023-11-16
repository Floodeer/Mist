#pragma once

#include <MistCore.h>
#include <MistCoreUtils.h>

using namespace Mist;

class AppLayer : public Layer
{
public:
	AppLayer();
	virtual ~AppLayer();

	virtual void OnAttach() override;
	virtual void OnDetach() override;
	virtual void OnEvent(Event& event) override;
	virtual void OnUpdate(Timestep ts) override;
	virtual void OnImGuiRender() override;
private:
};