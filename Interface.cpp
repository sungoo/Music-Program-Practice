#include "Interface.h"

MusicManager::MusicManager():selected(0), quitMusic(false)
{
	musics.loadData("MusicBaseData.csv");
}

void MusicManager::Title()
{
	system("cls");
	FillLine('=', MAX, true);
	FillLine('=', MAX, true);
	switch (selected)
	{
	case 0:
		CenterLetter('=', MAX, "음악 관리 프로그램");
		break;
	case 1:
		CenterLetter('=', MAX, "음악 전체 리스트");
		break;
	case 2:
		CenterLetter('=', MAX, "음악 장르 검색");
		break;
	case 3:
		CenterLetter('=', MAX, "음악 가수 검색");
		break;
	case 4:
		CenterLetter('=', MAX, "음악 듣기");
		break;
	case 5:
		CenterLetter('=', MAX, "종료되었습니다.");
		break;
	default:
		break;
	}
	
	FillLine('=', MAX, true);
	FillLine('=', MAX, true);
	cout << endl;
}

void MusicManager::Selection()
{
	int menu;
	cout << "메뉴를 선택하세요." << endl;
	cout << "1. 음악 전체 목록    2. 장르로 검색   3. 가수로 검색   4. 음악 듣기   5.종료" << endl;
	cin >> menu;
	if (cin.fail()) {
		cin.clear();
		cin.ignore();
	}
	selected = menu;
	switch (menu)
	{
	case 1:
		DisplayList();
		break;
	case 2:
		SearchByGenre();
		break;
	case 3:
		SearchBySinger();
		break;
	case 4:
		PlayMusic();
		break;
	case 5:
		QuitMusic();
		break;
	default:
		break;
	}
}

void MusicManager::DisplayList()
{
	Title();
	musics.DisplayAll();
	Selection();
}

void MusicManager::SearchByGenre()
{
	Title();
	string searching;
	cout << "찾으려는 장르를 입력하세요 : ";
	cin >> searching;
	wstring temp;
	temp.assign(searching.begin(), searching.end());
	musics.SearchByGenre(temp);
	Selection();
}

void MusicManager::SearchBySinger()
{
	Title();
	string searching;
	cout << "찾으려는 가수를 입력하세요 : ";
	cin >> searching;
	wstring temp;
	temp.assign(searching.begin(), searching.end());
	musics.SearchBySinger(temp);
	Selection();
}

void MusicManager::PlayMusic()
{
	Title();
	string searching;
	cout << "들으려는 노래를 입력하세요 : ";
	cin >> searching;
	wstring temp;
	temp.assign(searching.begin(), searching.end());
	musics.SearchAndPlay(temp);
	Selection();
}

void MusicManager::QuitMusic()
{
	Title();
	quitMusic = true;
}


