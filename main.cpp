#include "stdafx.h"
#include "Util.h"
#include "MusicList.h"
#include "MusicManager.h"

int main() {
	wcin.imbue(locale("korean"));
	wcout.imbue(locale("korean"));

	MusicManager interMusic("MusicBaseData.csv");

	interMusic.Title();
	interMusic.Selection();

	return 0;
}