#ifndef SIMPLE_CARTESIAN_
#define SIMPLE_CARTESIAN_
#include<Cartesian_base.h>
#include<function_objects.h>
//#include <Kernel/Type_equality_wrapper.h>

namespace SCGAL {

	template <typename FT_, typename Kernel_>
	struct Cartesian_base_no_ref_count//haven't implemented;
		:public Cartesian_base< Kernel_, FT_ > { // 

		typedef Kernel_                                K;

		


	};

	template <typename FT_>
	struct Simple_cartesian
		:public Cartesian_base_no_ref_count<FT_, Simple_cartesian<FT_>>// who is the kernel;
	{

	};
	

	// This class alos contains functors;
	/*template < typename FT_, typename Kernel_ >
	struct Cartesian_base_no_ref_count// haven't implemented;
		:public Cartesian_base< Kernel_, FT_ > {



		typedef Kernel_ K;

		typedef typename CartesianKernelFunctors::Less_xy_2<K>         Less_xy_2;
		Less_xy_2 Less_xy_2_Object() const { return Less_xy_2(); }

		typedef typename CartesianKernelFunctors::Less_rotate_ccw_2<K>         Less_rotate_ccw_2;
		Less_rotate_ccw_2 Less_rotate_ccw_2_Object() const { return Less_rotate_ccw_2(); }

		typedef typename CartesianKernelFunctors::Compare_xy_2<K>         Compare_xy_2;
		Compare_xy_2 Compare_xy_2_Object() const { return Compare_xy_2(); }


		typedef typename CartesianKernelFunctors::Orientation_2<K>         Orientation_2;
		Orientation_2 Orientation_2_Object() const { return Orientation_2(); }

		

	};



	template <typename FT_>
	struct Simple_cartesian
		:public Cartesian_base_no_ref_count<FT_, Simple_cartesian<FT_> >
	    {};*/

}

#endif