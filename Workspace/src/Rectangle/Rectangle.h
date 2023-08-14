#pragma once
#include <NormalEngine.h>

namespace Normal {

	class Rectangle : public Level
	{
	public:
		explicit Rectangle();
		virtual ~Rectangle();

		virtual void OnUpdate(float deltaTime) override;

	private:
		std::vector<float> m_Data;
		std::vector<NRuint> m_Indices;

		std::shared_ptr<VertexArray> m_VertexArray;
		std::shared_ptr<Shader> m_Shader;

		NR_SET_NAME("Rectangle");
	};


}


