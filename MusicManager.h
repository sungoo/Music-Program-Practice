#pragma once
#define MAX 80
#include "Line.h"
#include <cstdlib>
#include "MusicList.h"

class MusicManager
{
	MusicList musics;
	int selected;
	
public:
	bool quitMusic;

	MusicManager(string filename);
	void Title();
	void Selection();
private:
	void DisplayList();
	void SearchByGenre();
	void SearchBySinger();
	void PlayMusic();
	void QuitMusic();
};

