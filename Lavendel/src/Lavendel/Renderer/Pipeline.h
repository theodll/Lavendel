#pragma once 

#include <string>
#include <vector>

namespace Lavendel {
	namespace RendererAPI {
		class Pipeline
		{
		public:
			Pipeline(const std::string& vertFilepath, const std::string& fragFilePath);
			~Pipeline() {}

		private:
			static std::vector<char> readFile(const std::string& filepath);
			void createGraphicsPipeline(const std::string& vertShaderPath, const std::string& fragShaderPath);
		};
	} 
} 