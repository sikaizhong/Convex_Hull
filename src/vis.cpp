#include"vis.h"
#include<fstream>
#include<iostream>
void show(std::string& path, std::vector<Vec>& tri_list) {
	int size = tri_list.size();
	std::ofstream out(path);
	for (unsigned i = 0; i < size; i++) {
		out << "v " << tri_list[i].x << " " << tri_list[i].y << " " << 0 << std::endl;
		std::cout<< tri_list[i].x << " " << tri_list[i].y<< std::endl;

	}
	out.close();
}