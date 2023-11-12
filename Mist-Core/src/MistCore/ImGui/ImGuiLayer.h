#pragma once

#include "MistCore/Core/Layer.h"

#include "MistCore/Events/ApplicationEvent.h"
#include "MistCore/Events/KeyEvent.h"
#include "MistCore/Events/MouseEvent.h"

namespace Mist {

	class ImGuiLayer : public Layer
	{
	public:
		ImGuiLayer();
		~ImGuiLayer() = default;

		virtual void OnAttach() override;
		virtual void OnDetach() override;

		void Begin();
		void End();

		virtual void ImGuiLayer::OnEvent(Event& event);
		bool ImGuiLayer::OnMouseButtonPressed(MouseButtonPressedEvent& e);
	private:
		float m_Time = 0.0f;
	};

}