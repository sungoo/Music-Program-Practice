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
//	cout << i << "���� ���� ����Ʈ �߰�." << endl;
//
//	dataMax = i;
//	//music ����Ʈ ���� �Ҵ�
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
//	//����Ʈ Ž���� ���ͷ�����
//	int listNum = 0;
//
//	if (!file.is_open()) {
//		cerr << "failed to open file : " << filename << endl;
//		return;
//	}
//	while (getline(file, list))
//	{
//		//�� ���� ��ǥ(,)�� ����
//		stringstream ss(list);
//		string field;
//		//������ ������ ���� ���ͷ�����
//		Element i = TITLE;
//		//��ǥ�� ������ ������ �б�
//		while (getline(ss, field, ','))
//		{
//			//���� ������ ���� ó��
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
//			//���� �����Ͱ� ���� �ٱ�
//			if (error == -1)
//				break;
//			//���� ������ �������� �̵� title -> genre -> singer -> title -> ...
//			i = (Element)(i + 1);
//		}
//		//���� ������ ���� ����, setPlaying ������
//		(music + listNum)->setPlaying();
//		//���� *music �迭 ��ҷ� �̵�
//		listNum++;
//		//list overflow error
//		if (listNum > dataMax+1) {
//			cout << "����Ʈ ���� ����. ���� �� ������ �ս��� ���� �� �����ϴ�." << endl;
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
	cout << "\t���\t\t�帣\t\t�θ���\t\t�����\t\t����" << endl << endl;
	for (int i = 0; i < music.size(); i++) {
		cout << i + 1 << "\t"; music[i].Display();
	}
}

void MusicList::SearchByGenre(wstring genre)
{
	bool founded = false;

	cout << "\t���\t\t�帣\t\t�θ���\t\t�����\t\t����" << endl << endl;
	for (int i = 0; i < music.size(); i++) {
		if (music[i].getGenre() == genre) {
			cout << i + 1 << "\t"; music[i].Display();
			founded = true;
		}
	}
	if (!founded)
		cout << "�˻��ϴ� �帣�� ������ �������� �ʽ��ϴ�." << endl;
}

void MusicList::SearchBySinger(wstring singer)
{
	bool founded = false;

	cout << "\t���\t\t�帣\t\t�θ���" << endl << endl;
	for (int i = 0; i < music.size(); i++) {
		if (music[i].getSinger() == singer) {
			cout << i + 1 << "\t"; music[i].Display();
			founded = true;
		}
	}
	if (!founded)
		cout << "�˻��ϴ� ������ ������ �������� �ʽ��ϴ�." << endl;
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
		cout << "�˻��ϴ� ������ ������ �������� �ʽ��ϴ�." << endl;
}
