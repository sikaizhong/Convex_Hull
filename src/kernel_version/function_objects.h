#ifndef KERNEL_FUNCTION_OBJECTS_H
#define KERNEL_FUNCTION_OBJECTS_H
namespace SCGAL{
	namespace CommonKernelFunctors {
		enum Sign{ 
			NEGATIVE = -1, ZERO = 0, POSITIVE = 1,
			LEFT_TURN = 1, RIGHT_TURN = -1, COLLINEAR = 0
		};
		/*template < typename T, typename U >
		inline
			T enum_cast(const U& u)
		{
			return static_cast<T>(u);
		}*/


		template < class FT >
		inline
			bool
			compare_lexicographically_xyC2(const FT &px, const FT &py,
				const FT &qx, const FT &qy)
		{
			if (px <= qx) return true;
			else if (px == qx && py < qy) return true;
			return false;
		}
		////kernel_ftC2
		template < class FT >
		bool
			collinear_are_ordered_along_lineC2(const FT &px, const FT &py,
				const FT &qx, const FT &qy,
				const FT &rx, const FT &ry)
		{
			if (px < qx) return !(rx < qx);
			if (qx < px) return !(qx < rx);
			if (py < qy) return !(ry < qy);
			if (qy < py) return !(qy < ry);
			return true; // p==q
		}


		template <typename K>
		class Collinear_are_ordered_along_line_2
		{
			typedef typename K::Point_2         Point_2;
		public:
			typedef bool         result_type;

			result_type
				operator()(const Point_2& p, const Point_2& q, const Point_2& r) const
			{
				//CGAL_kernel_exactness_precondition(collinear(p, q, r));
				return collinear_are_ordered_along_lineC2
				(p.x(), p.y(), q.x(), q.y(), r.x(), r.y());
			}
		};


		template <typename K>
		class Compare_xy_2
		{
			typedef typename K::Point_2            Point_2;
		public:
			typedef bool  result_type;

			result_type
				operator()(const Point_2& p, const Point_2& q) const
			{
				return compare_lexicographically_xyC2(p.x(), p.y(), q.x(), q.y());
			}
		};

		template <class RT>
		inline 
			Sign sign_of_determinant(const RT& a00, const RT& a01,
				const RT& a10, const RT& a11) {
			RT res = a00 * a11 - a10 * a01;
			if (res > 0) return POSITIVE;
			if (res == 0) return ZERO;
			return NEGATIVE;
			//return enum_cast<RT,Sign>(a00*a11 - a10 * a01);
		}
		template <class FT>
		inline Sign
			orientationC2(const FT& ux, const FT& uy, const FT&vx, const FT&vy) {
			return sign_of_determinant(ux, uy, vx, vy);
		}

		template < class FT >
		inline
			Sign
			orientationC2(const FT &px, const FT &py,
				const FT &qx, const FT &qy,
				const FT &rx, const FT &ry)
		{
			return sign_of_determinant(qx - px, qy - py, rx - px, ry - py);
		}

		template <typename K>// Kernel
		class Orientation_2 {
			typedef typename K::Point_2                  Point_2;
			typedef typename K::Vector_2                 Vector_2;
		public:
			Sign operator()(const Point_2& p, const Point_2& q, const Point_2& r) const {
				return orientationC2(p.x(), p.y(), q.x(), q.y(), r.x(), r.y());
			}

			Sign
				operator()(const Vector_2& u, const Vector_2& v) const
			{
				return orientationC2(u.x(), u.y(), v.x(), v.y());
			}

		};

		template <typename K>
		class Left_turn_2
		{
			typedef typename K::Point_2        Point_2;
			typedef typename K::Orientation_2  Orientation_2;
			Orientation_2 o;
		public:

			Left_turn_2() {}
			Left_turn_2(const Orientation_2& o_) : o(o_) {}

			bool
				operator()(const Point_2& p, const Point_2& q, const Point_2& r) const
			{
				return o(p, q, r) == LEFT_TURN;
			}
		};

		template <typename K>
		class Less_rotate_ccw_2 {
			typedef typename K::Point_2                Point_2;
			typedef typename K::Orientation_2          Orientation_2;

			typedef typename K::Point_2        Point_2;
			typedef typename K::Orientation_2  Orientation_2;
			Collinear_are_ordered_along_line_2<K> co;
			Orientation_2 o;
		public:
			Less_rotate_ccw_2() {}

			bool operator()(const Point_2&r, const Point_2&p, const Point_2&q) const {
				Sign ori = o(r, p, q);
				if (ori == LEFT_TURN)
					return true;
				else if (ori == RIGHT_TURN)
					return false;
				else
				{
					if (p == r) return false;
					if (q == r) return true;
					if (p == q) return false;
					return co(r, q, p);
				}

			}

		};

		template <typename K>
		class Less_xy_2 {
			typedef typename K::Point_2                Point_2;
			typedef typename K::Compare_xy_2           Compare_xy_2;
			Compare_xy_2 c;
		public:
			Less_xy_2() {}
			Less_xy_2(const Compare_xy_2& c_) : c(c_) {}

			bool
				operator()(const Point_2& p, const Point_2& q) const
			{
				return c(p, q) ==true;// SMALLER;
			}
		};

	}
};
#endif