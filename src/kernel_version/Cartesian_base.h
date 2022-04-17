#ifndef CARTESIAN_BASE_H
#define CARTESIAN_BASE_H
#include<array>
#include<point_2.h>
#include<vector_2.h>
#include<function_objects.h>
// Since we want kernels extensiable, we need a base class for them
// and defer the instantiation;
namespace SCGAL {

	template <typename K_, typename FT_>// This is input
	struct Cartesian_base {
	//private:
		typedef K_                         Kernel;// kernel=k_;
		typedef FT_                        FT;
		typedef Cartesian_base<K_, FT_>    Self; // self;

		typedef PointC2<Kernel>            Point_2;

		typedef VectorC2<Kernel>           Vector_2;

		typedef std::array<FT, 2>          Rep;
		Rep                                base;
	public:
		typedef typename CommonKernelFunctors::Less_rotate_ccw_2<Kernel>      Less_rotate_ccw_2;
		typedef typename CommonKernelFunctors::Orientation_2<Kernel>          Orientation_2;
		typedef typename CommonKernelFunctors::Less_xy_2<Kernel>              Less_xy_2;
		typedef typename CommonKernelFunctors::Compare_xy_2<Kernel>           Compare_xy_2;
		typedef typename CommonKernelFunctors::Left_turn_2<Kernel>           Left_turn_2;

		


		Less_rotate_ccw_2   Less_rotate_ccw_2_Object() const { return Less_rotate_ccw_2(); }
		Orientation_2   Orientation_2_Object() const { return Orientation_2(); }
		Less_xy_2   Less_xy_2_Object() const { return Less_xy_2(); }
		Compare_xy_2   Compare_xy_2_Object() const { return Compare_xy_2(); }
		Left_turn_2   Left_turn_2_Object() const { return Left_turn_2(); }


	};

}



#endif