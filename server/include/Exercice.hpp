#ifndef __EXERCICE_HPP__
#define __EXERCICE_HPP__

#include <iostream>
#include <fstream>
#include <map>
#include <dirent.h>
#include <string.h>
#include <string>
#include <stdio.h>
#include <sys/stat.h>
#include <vector>
#include <sstream>
#include <iostream>


using namespace std;

string sendExercice(string path);

void prepareHomework(string path, string exo);

/*
class Exercice{
	private:
		string _path;

	public:
		Exercice(string path):_path(path){};
		~Exercice();

		void sendExercice();
	
};*/

#endif