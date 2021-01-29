#include "aepch.h"
#include "LayerStack.h"

namespace ArtemEngine {

	LayerStack::LayerStack()
	{
	}

	LayerStack::~LayerStack()
	{
	}

	void LayerStack::PushLayer(Shared<Layer> layer)
	{
		layers_.push_back(layer);
	}

	void LayerStack::PopLayer(Shared<Layer> layer)
	{
		layers_.erase(std::remove(layers_.begin(), layers_.end(), layer), layers_.end());
	}

}