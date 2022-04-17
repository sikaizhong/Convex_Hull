#ifndef CGAL_DETERMINANT_H
#define CGAL_DETERMINANT_H
namespace SCGAL {
	template <class RT>
	inline RT determinant(
		const RT& a00, const RT& a01,
		const RT& a10, const RT& a11) {
		// First compute the det2x2
		const RT m01 = a00 * a11 - a10 * a01;
		return m01;
	}

	template <class RT>
	inline
		RT
		determinant(
			const RT& a00, const RT& a01, const RT& a02,
			const RT& a10, const RT& a11, const RT& a12,
			const RT& a20, const RT& a21, const RT& a22)
	{
		// First compute the det2x2
		const RT m01 = a00 * a11 - a10 * a01;
		const RT m02 = a00 * a21 - a20 * a01;
		const RT m12 = a10 * a21 - a20 * a11;
		// Now compute the minors of rank 3
		const RT m012 = m01 * a22 - m02 * a12 + m12 * a02;
		return m012;
	}
}





#endif;