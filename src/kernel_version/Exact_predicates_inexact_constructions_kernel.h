#ifndef EXACT_PREDICATES_INEXACT_CONSTRUCTIONS_KERNEL_H
#define EXACT_PREDICATES_INEXACT_CONSTRUCTIONS_KERNEL_H

#include<Simple_cartesian.h>

namespace SCGAL {

	class Epick : public Simple_cartesian<double> {};
	typedef Epick Exact_predicates_inexact_constructions_kernel;
}
#endif 