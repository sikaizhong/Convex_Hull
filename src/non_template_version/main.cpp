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

void extreme_points(double* data, int size) {
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

void checkEdge(double* data, int size, int p, int q, std::vector<bool>& extreme) {
	bool lEmpty = true;
	bool rEmpty = true;
	for (unsigned i = 0; i < size && (lEmpty || rEmpty); i++) {
		if (i != p && i != q) {
			Vec p1(data[2 * p], data[2 * p + 1]);
			Vec q1(data[2 * q], data[2 * q + 1]);
			Vec s(data[2 * i], data[2 * i + 1]);
			toTheLeft(p1, q1, s) ? lEmpty = false : rEmpty = false;
		}
	}

	if (lEmpty || rEmpty) {// on the same side;
		extreme[p] = extreme[q] = true;
	}
}

void extreme_edges(double* data, int size) {
	vector<Vec> tri_list;
	for (unsigned i = 0; i < size; i++) {
		Vec vec(data[2 * i], data[2 * i + 1]);
		tri_list.push_back(vec);
	}
	std::string path_init = "init.obj";
	show(path_init, tri_list);

	std::vector<bool> is_extreme(size, false);

	for (unsigned i = 0; i < tri_list.size(); i++) {
		for (unsigned j = i + 1; j < tri_list.size(); j++) {
			// enumerate all edges p_i p_j and check the left size-2 points;
			checkEdge(data, size, i, j, is_extreme);
		}

	}

	vector<Vec> res;

	for (int i = 0; i < size; i++) {
		if (is_extreme[i]) res.push_back(tri_list[i]);
	}

	std::cout << "..........................." << std::endl;
	std::string path_res = "res.obj";
	show(path_res, res);

}

int main(){
	double d1[16] = { 7, 7, 7, -7, -7, -7, -7, 7, 9, 0, -9, 0, 0, 9, 0, -9 };
	//extreme_points(d1, 8);
	//extreme_edges(d1, 8);
	double d2[32] = { 7, 7, 7, - 7, - 7, - 7, - 7, 7, 9, 0,
		- 9, 0, 0, 9,0 ,- 9, 0, 0, 1, 2, - 2, 1, - 1, - 1, 3, 4, 4, 3, - 5, 4, 6, 5 };
	//extreme_points(d2, 16);
	//extreme_edges(d2, 16);

	Vec v1(d1[0], d1[1]);
	Vec v2(d1[2], d1[3]);
	Vec v3(d1[4], d1[5]);
	Vec v4((v1.x+v2.x+v3.x)/3, (v1.y + v2.y + v3.y) / 3);

	vector<Vec> res;
	res.push_back(v1);
	res.push_back(v2);
	res.push_back(v3);
	//res.push_back(v4);

	//std::string path_res = "res.obj";
	//show(path_res, res);



	bool inside=insideTriangle(v1, v2, v3, v4);
	std::cout << inside << std::endl;


    return 0;
}