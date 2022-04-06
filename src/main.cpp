#include<iostream>
#include<vector>
#include"vis.h"
#include"common.h"
using namespace std;
/*
Test 1

8 7 7 7 -7 -7 -7 -7 7 9 0 -9 0 0 9 0 -9

Test 2

16 7 7 7 -7 -7 -7 -7 7 9 0 -9 0 0 9 0 -9 0 0 1 2 -2 1 -1 -1 3 4 4 3 -5 4 6 5

Test 3

72 0 0 1 2 -2 1 -1 -1 3 4 4 3 -5 4 6 5 7 7 7 -7 -7 -7 -7 7 9 0 -9 0 0 9 0 -9 -8 0 8 0 -7 0 7 0 -6 0 6 0 -5 0 5 0 -4 0 4 0 -3 0 3 0 -2 0 2 0 -1 0 1 0 0 -8 0 8 0 -7 0 7 0 -6 0 6 0 -5 0 5 0 -4 0 4 0 -3 0 3 0 -2 0 2 0 -1 0 1 1 1 2 2 3 3 4 4 5 5 6 6 1 -1 2 -2 3 -3 4 -4 5 -5 6 -6 -1 1 -2 2 -3 3 -4 4 -5 5 -6 6 -1 -1 -2 -2 -3 -3 -4 -4 -5 -5 -6 -6

All answers are the same: 8 (0, -9) (7, -7) (9, 0) (7, 7) (0, 9) (-7, 7) (-9, 0) (-7, -7)


*/

/*
 This code is based on Junhui Deng's online class-computaional geometry;
 This code is a brutal force method to calculate the 2D convex hull;

*/

void test(double* data, int size) {
	vector<Vec> tri_list;
	for (unsigned i = 0; i < size; i++) {
		Vec vec(data[2 * i], data[2 * i + 1]);
		tri_list.push_back(vec);
	}
	std::string path_init = "init.obj";
	show(path_init, tri_list);
	std::vector<bool> is_extreme(size, true);
	for (unsigned i = 0; i < tri_list.size(); i++) {
		for (unsigned j = i + 1; j < tri_list.size(); j++) {
			for (unsigned k = j + 1; k < tri_list.size(); k++) {
				for (unsigned s = 0; s < tri_list.size(); s++) {
					// check whether s is an extreme point or not;
					if (s == i || s == j || s == k || !is_extreme[s]) continue;
					if (insideTriangle(tri_list[i], tri_list[j], tri_list[k], tri_list[s]))
						is_extreme[s] = false;
				}
			}
		}
	}

	vector<Vec> res;

	for (int i = 0; i < size; i++) {
		if (is_extreme[i]) res.push_back(tri_list[i]);
	}

	std::cout << "..........................." << std::endl;
	std::string path_res = "res.obj";
	show(path_res, res);
	//getchar();

}

int main(){
	double d1[16] = { 7, 7, 7, -7, -7, -7, -7, 7, 9, 0, -9, 0, 0, 9, 0, -9 };
	test(d1, 8);

	double d2[32] = { 7, 7, 7, - 7, - 7, - 7, - 7, 7, 9, 0,
		- 9, 0, 0, 9,0 ,- 9, 0, 0, 1, 2, - 2, 1, - 1, - 1, 3, 4, 4, 3, - 5, 4, 6, 5 };
	test(d2, 16);





    return 0;
}