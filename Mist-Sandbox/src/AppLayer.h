#pragma once

#include <MistCore.h>
#include <MistCore.h>

class AppLayer : public MistCore::Layer
{
public:
	AppLayer();
	virtual ~AppLayer();

	virtual void OnAttach() override;
	virtual void OnDetach() override;
	virtual void OnEvent(MistCore::Event& event) override;
	virtual void OnUpdate(MistCore::Timestep ts) override;
	virtual void OnImGuiRender() override;
private:
};