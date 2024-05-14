#pragma once
#include "stdafx.h"

enum Element {
	TITLE,
	GENRE,
	SINGER,
};

class MusicInfo
{
public:
	wstring title;
	wstring singer;
	wstring genre;
	wstring releaseData;
	wstring playing;

public:
	MusicInfo();
	~MusicInfo() {};

	wstring getTitle();
	wstring getSinger();
	wstring getGenre();
	wstring getReleaseData();
	wstring getPlaying();
	
	void Play();
	void Display();
};

