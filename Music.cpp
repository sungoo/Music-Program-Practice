#include "Music.h"

MusicInfo::MusicInfo() :title(L"unknown"), genre(L"x"), singer(L"unknown"), playing(L"no data"), releaseData(L" ")
{
}

wstring MusicInfo::getTitle()
{
	return title;
}

wstring MusicInfo::getSinger()
{
	return singer;
}

wstring MusicInfo::getGenre()
{
	return genre;
}

wstring MusicInfo::getReleaseData()
{
	return releaseData;
}

wstring MusicInfo::getPlaying()
{
	return playing;
}

void MusicInfo::Play()
{
	string temp;
	temp.assign(playing.begin(), playing.end());

	cout << temp.c_str() << endl;
}

void MusicInfo::Display()
{
	string temp;
	temp.assign(title.begin(), title.end());
	cout << temp.c_str() << "\t\t";
	temp.assign(genre.begin(), genre.end());
	cout << temp.c_str() << "\t\t";
	temp.assign(singer.begin(), singer.end());
	cout << temp.c_str() << "\t\t";
	temp.assign(releaseData.begin(), releaseData.end());
	cout << temp.c_str() << endl;
}

