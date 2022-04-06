#include <type_traits>
#include <concepts>

namespace GLFramework
{
	template<class T, class Base>
	concept BasedOn = std::is_base_of<Base, T>::value;
}