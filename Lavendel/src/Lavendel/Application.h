#pragma once
#include "Core.h"

namespace Lavendel
{

	class _declspec(dllexport) Application
	{
		public:
			Application();
			virtual ~Application();
			void Run();
	};

	// MUST BE DEFINED IN CLIENT
	Application* CreateApplication();

}
