#include "MusicList.h"

MusicList::MusicList()
{
	/*music = nullptr;
	dataMax = 0;*/
}

MusicList::~MusicList()
{
	//delete[] music;
}

//void MusicList::initMusicList(string filename)
//{
//	ifstream file(filename);
//	if (!file.is_open()) {
//		cerr << "failed to open file : " << filename << endl;
//		return;
//	}
//
//	int i = 0;
//	string list;
//	while (getline(file, list))
//	{
//		i++;
//	}
//	cout << i << "개의 음악 리스트 발견." << endl;
//
//	dataMax = i;
//	//music 리스트 동적 할당
//	music = new Music[dataMax];
//
//	file.close();
//}
//
//void MusicList::getDataFromFile(string filename)
//{
//	initMusicList(filename);
//	ifstream file(filename);
//	string list;
//
//	//리스트 탐색용 이터레이터
//	int listNum = 0;
//
//	if (!file.is_open()) {
//		cerr << "failed to open file : " << filename << endl;
//		return;
//	}
//	while (getline(file, list))
//	{
//		//각 줄을 쉼표(,)로 분할
//		stringstream ss(list);
//		string field;
//		//데이터 구별을 위한 이터레이터
//		Element i = TITLE;
//		//쉼표로 분할한 데이터 읽기
//		while (getline(ss, field, ','))
//		{
//			//분할 데이터 에러 처리
//			int error = 0;
//			switch (i)
//			{
//			case TITLE:
//				(music + listNum)->setTitle(field);
//				break;
//			case GENRE:
//				(music + listNum)->setGenre(field);
//				break;
//			case SINGER:
//				(music + listNum)->setSinger(field);
//				break;
//			default:
//				error = -1;
//				break;
//			}
//			//분할 데이터가 범위 바깥
//			if (error == -1)
//				break;
//			//분할 데이터 다음으로 이동 title -> genre -> singer -> title -> ...
//			i = (Element)(i + 1);
//		}
//		//분할 데이터 저장 이후, setPlaying 마무리
//		(music + listNum)->setPlaying();
//		//다음 *music 배열 요소로 이동
//		listNum++;
//		//list overflow error
//		if (listNum > dataMax+1) {
//			cout << "리스트 범위 오류. 범위 밖 데이터 손실을 피할 수 없습니다." << endl;
//			break;
//		}
//	}
//	file.close();
//}

void MusicList::loadData(string filename)
{
	util.LoadMusicData(filename, music);
}

void MusicList::DisplayAll()
{
	cout << "\t곡명\t\t장르\t\t부른이\t\t출시일\t\t가사" << endl << endl;
	for (int i = 0; i < music.size(); i++) {
		cout << i + 1 << "\t"; music[i].Display();
	}
}

void MusicList::SearchByGenre(wstring genre)
{
	bool founded = false;

	cout << "\t곡명\t\t장르\t\t부른이\t\t출시일\t\t가사" << endl << endl;
	for (int i = 0; i < music.size(); i++) {
		if (music[i].getGenre() == genre) {
			cout << i + 1 << "\t"; music[i].Display();
			founded = true;
		}
	}
	if (!founded)
		cout << "검색하는 장르의 음악이 존재하지 않습니다." << endl;
}

void MusicList::SearchBySinger(wstring singer)
{
	bool founded = false;

	cout << "\t곡명\t\t장르\t\t부른이" << endl << endl;
	for (int i = 0; i < music.size(); i++) {
		if (music[i].getSinger() == singer) {
			cout << i + 1 << "\t"; music[i].Display();
			founded = true;
		}
	}
	if (!founded)
		cout << "검색하는 가수의 음악이 존재하지 않습니다." << endl;
}

void MusicList::SearchAndPlay(wstring title)
{
	bool founded = false;

	for (int i = 0; i < music.size(); i++) {
		if (music[i].getTitle() == title) {
			music[i].Play();
			founded = true;
		}
	}
	if (!founded)
		cout << "검색하는 제목의 음악이 존재하지 않습니다." << endl;
}
