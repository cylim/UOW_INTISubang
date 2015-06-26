#include <ctime>
#include <iostream>
#include <algorithm>
#include <utility>

#include "maze.h"
#include "union.h"

maze::maze(int height, int width){
	if (height < 3 || width < 3){
		cout << "Invalid Maze size, generated with 10x10." << endl;
		this->width = 10;
		this->height = 10;
	} else {
		this->width = width;
		this->height = height;
	}
}

maze::~maze(){
}

void maze::Generate(){
	createEdges();
	//shuffleVector();
	kruskal();
	convertToPaintedPoint();
}

void maze::show(){
	int cpp = 0; // cur painted point

	// Top Border
	cout << "\t[]A ";
	for (int col = 0; col < (width * 2) - 1; ++col) {
		cout << "[]";
	}
	cout << endl;

	// Maze Formatting
	for (int row = 0; row < (height * 2) - 1; ++row) {
		cout << "\t[]"; // Left Border
		for (int col = 0; col < (width * 2) - 1; ++col) {
			// If it's an vertex position
			if ((row & 1) == 0 && (col & 1) == 0) {
				cout << "  ";
			}
			else {
				if (cpp < painted_points.size()
					&& painted_points[cpp].first == row
					&& painted_points[cpp].second == col) {
					cout << "  ";
					cpp++;
				}
				else {
					cout << "[]";
				}
			}
		}
		cout << "[]" << endl; // Right Border
	}

	// Bottom Border
	cout << "\t";
	for (int col = 0; col < (width * 2) - 1; ++col) {
		cout << "[]"
	}
	cout << " B[]" << endl;;
}

void maze::createEdges(){
	for (int row = 1; row < height; ++row) {
		for (int col = 1; col < width; ++col) {
			edges->push_back(std::pair<int, int>(
				Pos2Idx(row, col), Pos2Idx(row, col - 1)));
			edges->push_back(std::pair<int, int>(
				Pos2Idx(row, col), Pos2Idx(row - 1, col)));
		}
	}

	for (int col = 1; col < width; ++col) {
		edges->push_back(std::pair<int, int>(
			Pos2Idx(0, col), Pos2Idx(0, col - 1)));
	}

	for (int row = 1; row < height; ++row) {
		edges->push_back(std::pair<int, int>(
			Pos2Idx(row, 0), Pos2Idx(row - 1, 0)));
	}
}

void maze::shuffleVector(){
	cout << "bleck";
}

void maze::kruskal(){
	std::vector<std::pair<int, int> > * mst_edges) {
	Union uf;
	uf.Reset(width * height);
	for (int i = 0; i < all_edges.size(); ++i) {
		if (uf.Union(all_edges[i].first, all_edges[i].second)) {
			mst_edges->push_back(all_edges[i]);
		}
	}
}

void maze::convertToPaintedPoint(){
	std::vector<std::pair<int, int> > * painted_points);
	for (int i = 0; i < edges.size(); ++i) {
		std::pair<int, int> node_a = Idx2Pos(edges[i].first);
		std::pair<int, int> node_b = Idx2Pos(edges[i].second);

		node_a.first *= 2;
		node_a.second *= 2;
		node_b.first *= 2;
		node_b.second *= 2;

		std::pair<int, int> edge;
		edge.first = (node_a.first + node_b.first) / 2;
		edge.second = (node_a.second + node_b.second) / 2;

		painted_points->push_back(edge);
	}
	std::sort(painted_points->begin(), painted_points->end());
}


