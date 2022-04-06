#ifndef GLSERVICE_H
#define GLSERVICE_H

#include "GLServiceProvider.h"
#include "GLApplicationBuilder.h"

namespace GLFramework
{
	class GLService
	{
		friend class GLApplicationBuilder;

	private:
		GLServiceProvider _serviceProvider;

	public:
		const inline GLServiceProvider GetServiceProvider() const { return _serviceProvider; }
	};
}

#endif