#include<Exact_predicates_inexact_constructions_kernel.h>
#include<iostream>
#include<fstream>
#include<string>
#include<vector>
#include<stack>
#include<deque>

using namespace std;
using namespace SCGAL;
typedef  Exact_predicates_inexact_constructions_kernel    Kernel;
typedef  Kernel::Point_2                                  Point_2;
//typedef  Exact_predicates_inexact_constructions_kernel::Point_2       Point_2;                           Point_2;


template <class InputIterator, class OutputIterator, class Traits>
OutputIterator
ch_graham_anderson(InputIterator  first, InputIterator  beyond,
	OutputIterator result, const Traits&  ch_traits) {
	typedef typename Traits::Point_2               Point_2;
	typedef typename Traits::Less_xy_2             Less_xy_2;
	typedef typename Traits::Less_rotate_ccw_2  Less_rotate_ccw_2;
	typedef typename Traits::Left_turn_2  Left_turn_2;

	

	if (first == beyond) return result;
	std::vector<Point_2> V(first, beyond);
	typename std::vector<Point_2>::iterator it =
		std::min_element(V.begin(), V.end(), Less_xy_2());// find its left lowest point;
	const Point_2 p = *it;
	std::cout << "v " << p.x() << " " << p.y() << " 0" << std::endl;

	// sort based on the 
	std::sort(V.begin(), V.end(), [&p](const Point_2& p1, const Point_2& p2) {return Less_rotate_ccw_2()(p, p1, p2); });
	/*int size = V.size();
	for (unsigned i = 0; i < size; i++) {
		std::string filename = "ch" + to_string(i) + ".obj";
		std::ofstream out(filename);
		for (unsigned j = 0; j <= i; j++) {
			out << "v " << V[j].x() << " " << V[j].y() << " 0" << std::endl;
		}
		out.close();

	}*/

	deque<Point_2> S;
	deque<Point_2> T;
	S.push_back(*(V.end() - 1));// after sorting,  the left-most is at the back;
	S.push_back(*(V.begin()));// after sorting,  the left-most is at the back;
	typename std::vector<Point_2>::iterator itrs = V.begin() + 1;
	while (itrs != (V.end() - 1)) {
		T.push_back(*(itrs));
		itrs++;
	}
	//std::cout << p.x() << " " << p.y() << std::endl;
	Left_turn_2  toLeft;// = Traits.Less_rotate_ccw_2_object();
	//toLeft(S[1], S[0], S[0]);
	while(!T.empty()) {
		int size = S.size();
		if (toLeft(S[size-2], S[size-1], T.front())) {
			S.push_back(T.front());
			T.pop_front();
		}
		else if(S.size()>2)
			S.pop_back();
	}
	/*std::string filename = "ch.obj";
	std::ofstream out(filename);
	int sizex = S.size();
	for (unsigned i = 0; i < sizex; i++) {
		out << "v " <<S[i].x() << " " << S[i].y() << " 0" << std::endl;
	}
	for (unsigned i = 0; i < sizex; i++) {
		out << "e " << i+1 << " " << i+2<< std::endl;
	}

	out.close();*/
	//int sizex = S.size();
	//for (unsigned i = 0; i < sizex; i++) {
	//	result << S[i].x() << S[i].y();
	//}
	copy(S.begin(), S.end(), result);
	//result = S.begin();
	return result;
}


int main() {

	//typedef Kernel::Less_rotate_ccw_2  Less_rotate_ccw_2;
	//Less_rotate_ccw_2 toLeft;// = Traits.Less_rotate_ccw_2_object();

	std::vector<Point_2> data{ Point_2(152, 4513),Point_2(5887, 415)
		, Point_2(3001, 7410), Point_2(1424, 5645),
		 Point_2(3309, 92)
		, Point_2(2056, 5013), Point_2(2867, 5103),
		Point_2(2130, 2112) };
	//toLeft(data[0], data[1], data[2]);
	//int size = data.size();
	for (auto p : data) {
		//std::cout << p.x() << " " << p.y() << std::endl;
	}
	auto in_start = data.begin();
	auto in_end = data.end();
	//std::ostream_iterator< Point_2 >  out(std::cout, "\n");
	std::vector<Point_2> res;
	int size = data.size();
	res.resize(size);
	std::vector<Point_2>::iterator out=res.begin();
	ch_graham_anderson(in_start, in_end, out, Kernel());



	return 0;

	//std::vector<char> res;
	//std::string str = "back";
	//copy(crbegin(str), crend(str), std::ostream_iterator<char>{std::cout,"\n"});






}