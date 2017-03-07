#include <iostream>
#include <iomanip>
#include <fstream>
#include <string>
#include <stdlib.h>
#include <stdio.h>
using namespace std;

void OpenInputFile(string filename, ifstream& inFile) {
	inFile.open(filename);
}

void LoadConstraints(ifstream& inFile, int& num, string& bstring, string& sstring) {
	string buffer;
	int count = 0;;
	for (int i = 0; i < 7; i++) {
		getline(inFile, buffer);
		if (i > 0) {
			if (buffer != "") {
				switch (count) {
				case 0: num = stoi(buffer);
					cout << buffer;
					count++;
					break;
				case 1: bstring = buffer;
					count++;
					break;
				case 2: sstring = buffer;
					count++;
					break;
				default: break;
				}
			}
		}
	}
}

void ParseRequirementsString(string requirements, int reqs[]) {
	int num;
	for (int i = 1; i < requirements.length(); i++) {
		reqs[requirements[i] - '0'] = 1;
	}
	for (int j = 0; j < 9; j++) {
		cout << reqs[j] << "  ";
	}
	cout << endl;
}

void LoadGrid(ifstream& inFile, int grid[][CMAX]) {
	string buffer;
	for (int k = 0; k < RMAX; k++) {
		for (int j = 0; j < CMAX-1; j++) {
			getline(inFile, buffer, ' ');
			grid[k][j] = stoi(buffer);
		}
		getline(inFile, buffer, '\n');
		grid[k][9] = stoi(buffer);
	}
}

void ComputeNextGrid(int current[][CMAX], int next[][CMAX], int birth[], int survival[]) {
	for (int i = 0; i < RMAX; i++) {
		for (int j = 0; j < CMAX; j++) {
			switch (current[i][j]) {
			case 1:
				if (survival[CountType1Neighbors(current, i, j)] == 1) {
					next[i][j] = 1;
				}
				else {
					next[i][j] = 0;
				}
				break;
			case 2:
				if (survival[CountType2Neighbors(current, i, j)] == 1) {
					next[i][j] = 2;
				}
				else {
					next[i][j] = 0;
				}
				break;
			case 0:
				if (birth[CountType1Neighbors(current, i, j)] = 1 && birth[CountType1Neighbors(current, i, j)] > birth[CountType2Neighbors(current, i, j)]) {
					next[i][j] = 1;
				}
				else if (birth[CountType2Neighbors(current, i, j)] = 1 && birth[CountType2Neighbors(current, i, j)] > birth[CountType1Neighbors(current, i, j)]) {
					next[i][j] = 2;
				}
				else {
					next[i][j] = 0;
				}
				break;
			}

		}
	}
}

int  CountType1Neighbors(int grid[][CMAX], int row, int col) {
	int count = 0;
	for(int i=-1; i<2;i++){
		for(int j=-1; j<2;j++){
			if(i==0 && j==0){}
			else if(grid[(row+i+RMAX)%RMAX][(col+j + CMAX)%CMAX]==1){
				count ++;
			}
		}
	}
	return count;
}

int  CountType2Neighbors(int grid[][CMAX], int row, int col) {
	int count = 0;
	for(int i=-1; i<2;i++){
		for(int j=-1; j<2;j++){
			if(i==0 && j==0){}
			else if(grid[(row+i+RMAX)%RMAX][(col+j + CMAX)%CMAX]==2){
				count ++;
			}
		}
	}
	return count;
}

void CopyGrid(const int source[][CMAX], int destination[][CMAX]) {
	for (int i = 0; i < RMAX; i++) {
		for (int j = 0; j < CMAX; j++) {
			destination[i][j] = source[i][j];
		}
	}
}