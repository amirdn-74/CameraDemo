#pragma once

#include <string>
#include <memory>

#include "MeshProvider.h"





class ResourceProvider
{
public:
	template<typename T, typename... Args>
	static const std::shared_ptr<T> Load(Args&&... data)
	{
		std::shared_ptr<T> provider = std::make_shared<T>(std::forward<Args>(data)...);
		return provider;
	}
};