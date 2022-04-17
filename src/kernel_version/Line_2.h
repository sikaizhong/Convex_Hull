

#ifndef CARTESIAN_LINE_2_H
#define CARTESIAN_LINE_2_H

//#include <CGAL/array.h> remove it for now
//#include <CGAL/Handle_for.h>
//#include <CGAL/predicates/kernel_ftC2.h>
#include<array>
namespace SCGAL {

	template < class R_ >
	class LineC2
	{
		typedef typename R_::FT                   FT;
		typedef typename R_::Point_2              Point_2;
		typedef typename R_::Vector_2             Vector_2;


		typedef typename R_::Line_2               Line_2;

		typedef std::array<FT, 3>                 Rep;

		Rep base;

	public:
		typedef  R_                             R;
		LineC2() {}
		LineC2(const FT &a, const FT &b, const FT &c) {
			// although there is an efficiency problem 
			// I change it later in the future;
			base[0] = a;
			base[1] = b;
			base[2] = c;
		}

		bool operator==(const LineC2 &l) const;
		bool operator!=(const LineC2 &l) const;
		const FT & a() const
		{
			return base[0];
		}

		const FT & b() const
		{
			return base[1];
		}
		const FT & c() const
		{
			return base[2];
		}

	};

	template < class R >
	inline bool LineC2<R>::operator==(const LineC2 &l) const
	{

	}

	template < class R >
	inline bool LineC2<R>::operator!=(const LineC2 &l) const
	{
		return !(*this == l);
	}
}

#endif // CGAL_CARTESIAN_LINE_2_H
