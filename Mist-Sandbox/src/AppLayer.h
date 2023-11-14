#pragma once

#include <MistCore.h>
#include <MistCore.h>

class AppLayer : public Mist::Layer
{
public:
	AppLayer();
	virtual ~AppLayer();

	virtual void OnAttach() override;
	virtual void OnDetach() override;
	virtual void OnEvent(Mist::Event& event) override;
	virtual void OnUpdate(Mist::Timestep ts) override;
	virtual void OnImGuiRender() override;
private:
};