#include "aepch.h"
#include "LayerStack.h"

namespace ArtemEngine {

	LayerStack::LayerStack()
	{
	}

	LayerStack::~LayerStack()
	{
	}

	void LayerStack::PushLayer(std::shared_ptr<Layer> layer)
	{
		layers_.push_back(layer);
	}

	void LayerStack::PopLayer(std::shared_ptr<Layer> layer)
	{
		layers_.erase(std::remove(layers_.begin(), layers_.end(), layer), layers_.end());
	}

}