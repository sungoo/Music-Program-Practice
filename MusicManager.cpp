#include "MusicManager.h"

MusicManager::MusicManager(string filename):selected(0), quitMusic(false)
{
	musics.loadData(filename);
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
	wstring searching;
	cout << "ã������ �帣�� �Է��ϼ��� : ";
	wcin >> searching;
	musics.SearchByGenre(searching);
	Selection();
}

void MusicManager::SearchBySinger()
{
	Title();
	wstring searching;
	cout << "ã������ ������ �Է��ϼ��� : ";
	wcin >> searching;
	musics.SearchBySinger(searching);
	Selection();
}

void MusicManager::PlayMusic()
{
	Title();
	wstring searching;
	cout << "�������� �뷡�� �Է��ϼ��� : ";
	wcin >> searching;
	musics.SearchAndPlay(searching);
	Selection();
}

void MusicManager::QuitMusic()
{
	Title();
	quitMusic = true;
}


