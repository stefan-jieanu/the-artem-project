#pragma once

namespace ArtemEngine
{
	
	template<typename...> struct Vertex;

	template<typename T1>
	struct Vertex<T1>
	{
		T1 t1;
	};

	template<typename T1, typename T2>
	struct Vertex<T1, T2>
	{
		T1 t1;
		T2 t2;
	};

	template<typename T1, typename T2, typename T3>
	struct Vertex<T1, T2, T3>
	{
		T1 t1;
		T2 t2;
		T3 t3;
	};

	template<typename T1, typename T2, typename T3, typename T4>
	struct Vertex<T1, T2, T3, T4>
	{
		T1 t1;
		T2 t2;
		T3 t3;
		T4 t4;
	};

	template<typename T1, typename T2, typename T3, typename T4, typename T5>
	struct Vertex<T1, T2, T3, T4, T5>
	{
		T1 t1;
		T2 t2;
		T3 t3;
		T4 t4;
		T5 t5;
	};

}