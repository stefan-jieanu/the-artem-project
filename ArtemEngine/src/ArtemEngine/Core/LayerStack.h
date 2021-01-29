#pragma once

#include "Layer.h"

namespace ArtemEngine {

	class LayerStack
	{
	public:
		LayerStack();
		~LayerStack();

		// TODO: Change Shared to raw pointer
		// The layer stack should manage all the layers
		void PushLayer(Shared<Layer> layer);
		void PopLayer(Shared<Layer> layer);

		std::vector<Shared<Layer>>::iterator begin() { return layers_.begin(); }
		std::vector<Shared<Layer>>::iterator end() { return layers_.end(); }
	private:
		std::vector<Shared<Layer>> layers_;
	};

}

