#include "Util.h"

void lineSeparator()
{
    std::cout << "\n----------------------------------------------------------------------------------------------------\n";
}

void Util::LoadMusicData(string filename, vector<MusicInfo>& musicInfos)
{
    std::wifstream file(filename);
    file.imbue(std::locale("ko_KR.utf8"));
    std::wstring line;
    std::getline(file, line);
    while (std::getline(file, line))
    {
        std::wistringstream ss(line);
        MusicInfo row;
        getline(ss, row.title, L',');
        getline(ss, row.singer, L',');
        getline(ss, row.genre, L',');
        getline(ss, row.releaseData, L',');
        getline(ss, row.playing , L',');
        musicInfos.push_back(row);
    }
    file.close();
}
//void Music::viewMusicList()
//{
//    int num = 1;
//    for (const auto& row : rows)
//    {
//        std::wcout << std::right << std::setw(3) << num << "\t" << row.title << std::endl;
//        num++;
//    }
//}
//void Music::setCategoryList()
//{
//    for (const auto& row : rows)
//    {
//        std::wistringstream ss(row.category);
//        std::wstring token;
//        while (std::getline(ss, token, L'/'))
//        {
//            categoryList.insert(token);
//        }
//    }
//}
//void Music::viewCategoryList()
//{
//    for (const auto& category : categoryList)
//    {
//        std::wcout << category << std::endl;
//    }
//}
//void Music::viewPickedMusic(int n)
//{
//    viewMusicInfo(n - 1);
//    viewMusicLyric(n - 1);
//}
//void Music::viewMusicInfo(int n)
//{
//    const auto& row = rows[n];
//    lineSeparator();
//    std::wcout << std::right << std::setw(15) << L"Title: " << row.title << std::endl;
//    std::wcout << std::right << std::setw(15) << L"Artist: " << row.artist << std::endl;
//    std::wcout << std::right << std::setw(15) << L"Category: " << row.category << std::endl;
//    std::wcout << std::right << std::setw(15) << L"Release Date: " << row.releaseDate << std::endl;;
//}
//void Music::viewMusicLyric(int n)
//{
//    const auto& row = rows[n];
//    std::wstring lyric = row.lyric;
//    std::replace(lyric.begin(), lyric.end(), L'|', L'\n');
//    std::wcout << L"\nLyric: \n" << lyric << std::endl;
//}