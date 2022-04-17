#ifndef CARTESIAN_POINT_2_H
#define CARTESIAN_POINT_2_H

#include<array>

namespace SCGAL {

	template <class R_> // It represents Kernel
	class PointC2 {
		typedef PointC2<R_>                       Self;// Self=VectorC2<R_>;
		typedef typename R_::FT                            FT;

		typedef typename R_::Vector_2             Vector_2_;
		//typedef typename R_::Point_2              Point_2;

		Vector_2_ base;// use vector to store mem, weired;
		
	public:
		typedef R_                                R;
		PointC2() {};
		PointC2(const FT &x, const FT &y)
			: base(x, y) {}
		const FT& x() const
		{
			return base.x();
		}

		const FT& y() const
		{
			return base.y();
		}

		bool operator==(const Self &l) const {
			return (x() == l.x() && y() == l.y());
		}

	};


};



#endif