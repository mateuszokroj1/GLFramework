

#ifndef GLSERVICE_H
#define GLSERVICE_H

namespace GLFramework
{
	class GLService
	{
		//friend class;

	private:
		GLServiceProvider _serviceProvider;

	public:
		constexpr const GLServiceProvider GetServiceProvider() { return _serviceProvider; }
	};
}

#endif