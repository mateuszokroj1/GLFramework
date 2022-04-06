#ifndef GLSERVICEPROVIDER_H
#define GLSERVICEPROVIDER_H

#include "GLService.h"
#include "types.h"

namespace GLFramework
{
	class GLServiceProvider
	{
	public:
		template<BasedOn<GLService> T>
		T Import();
	};
}

#endif