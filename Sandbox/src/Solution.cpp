#include <Lavendel.h>

class ExampleLayer : public Lavendel::Layer
{
	public:
	ExampleLayer() : Layer("Example") {}
	void OnUpdate() override
	{
		LV_CORE_INFO("ExampleLayer::Update");
	}
	void OnEvent(Lavendel::Event& event) override
	{
		LV_CORE_INFO("{0}", event.ToString());
	}
}; 

class Sandbox : public  Lavendel::Application
{
public: 
		Sandbox() 
		{
			PushLayer(new ExampleLayer());
		}
		~Sandbox() {}
};


Lavendel::Application* Lavendel::CreateApplication()
{
	return new Sandbox();
}