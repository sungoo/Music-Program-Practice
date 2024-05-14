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
		CenterLetter('=', MAX, "���� ���� ���α׷�");
		break;
	case 1:
		CenterLetter('=', MAX, "���� ��ü ����Ʈ");
		break;
	case 2:
		CenterLetter('=', MAX, "���� �帣 �˻�");
		break;
	case 3:
		CenterLetter('=', MAX, "���� ���� �˻�");
		break;
	case 4:
		CenterLetter('=', MAX, "���� ���");
		break;
	case 5:
		CenterLetter('=', MAX, "����Ǿ����ϴ�.");
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
	cout << "�޴��� �����ϼ���." << endl;
	cout << "1. ���� ��ü ���    2. �帣�� �˻�   3. ������ �˻�   4. ���� ���   5.����" << endl;
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
	cout << "ã������ �帣�� �Է��ϼ��� : ";
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
	cout << "ã������ ������ �Է��ϼ��� : ";
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
	cout << "�������� �뷡�� �Է��ϼ��� : ";
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


