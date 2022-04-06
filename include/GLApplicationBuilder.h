#ifndef GLAPPLICATIONBUILDER_H
#define GLAPPLICATIONBUILDER_H

#include <memory>
#include <vector>
#include <functional>

#include "GLApplication.h"

namespace GLFramework
{
	class GLApplicationBuilder
	{

#pragma region Fields

	private:
		std::shared_ptr<std::vector<std::shared_ptr<void>>> services;

#pragma endregion

#pragma region Methods

	public:
		const GLApplication build() const;

		
		void registerServices();


#pragma endregion

	};
}
#endif