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

	//�޸��忡 �ִ� ������ �� ��ŭ �������� �迭 ����
//private:
//	void initMusicList(string filename);
//public:
//	void getDataFromFile(string filename);

	//�� �Լ� : ����Ʈ �ҷ�����
	void loadData(string filename);
	//��ü ����Ʈ ���
	void DisplayAll();
	//�帣�� �˻�
	void SearchByGenre(wstring genre);
	//���� �̸� �˻�
	void SearchBySinger(wstring singer);
	//���� �˻��� �÷���
	void SearchAndPlay(wstring title);
};

