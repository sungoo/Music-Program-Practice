#pragma once
#include "Music.h"
#include "Util.h"

class MusicList
{
	Util util;
	vector<MusicInfo> music;
	//int dataMax;

public:
	MusicList();
	~MusicList();

	//메모장에 있는 데이터 수 만큼 동적으로 배열 생성
//private:
//	void initMusicList(string filename);
//public:
//	void getDataFromFile(string filename);

	//새 함수 : 리스트 불러오기
	void loadData(string filename);
	//전체 리스트 출력
	void DisplayAll();
	//장르로 검색
	void SearchByGenre(wstring genre);
	//가수 이름 검색
	void SearchBySinger(wstring singer);
	//제목 검색과 플레이
	void SearchAndPlay(wstring title);
};

