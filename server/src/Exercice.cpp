#include <iostream>
#include <string>
#include "Exercice.hpp"
/*
String Exercice::sendExercice(string path){

	DIR *dir;
	struct dirent *ent;
	char tab[1024];

	string line,name;
	strcpy(tab, _path.c_str());

	if( (dir = opendir( tab )) != NULL ){

		while ((ent = readdir (dir)) != NULL){
			if( strcmp(&ent->d_name[0],".") == 0 || strcmp(&ent->d_name[1],".") == 0 ){
				continue;
			}
			

			name = "../exercices/";
			name += ent->d_name;

			ifstream exo ( name );
			
			if (exo.is_open()){
			    while ( getline (exo,line) )
			    {
			      cout << line << '\n';
			    }
			    exo.close();
			}
			else cout << "Unable to open file" << endl; 
			exo.close();
	  	}
	  	closedir (dir);
	}
}
*/

string sendExercice(string path){
	string line, exercice="";

	ifstream exo ( path );

	if( !exo.good() ){
		return 
	}
	
	if( exo.is_open() ){
	    while( getline (exo,line) ){
	    	cout << line << endl;
			exercice.append(line);
		}
	}
	exo.close();
	return exercice;
}
