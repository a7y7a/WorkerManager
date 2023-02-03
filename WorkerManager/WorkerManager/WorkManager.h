#pragma once
#include<iostream>
using namespace std;
#include<string>
#include"Worker.h"
#include<fstream>
#define FILENAME "mfile.txt"

class WorkManager
{
public:
	WorkManager();
	void menu();
	void mexit();
	void madd();
	void msave();
	int getnum();
	void minit();
	void mshow();
	int isexit(int id);
	void mdel();
	void mmod();
	void mfind();
	void msort();
	void mclean();
	~WorkManager();

	int mnum;
	Worker** marry;
	bool mfile;
};