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
	wcout << playing << endl;
}

void MusicInfo::Display()
{
	wcout << title << "\t\t\t" << genre << "\t" << singer << "\t" << releaseData << endl;
}

