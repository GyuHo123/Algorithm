#include <bits/stdc++.h>
using namespace std;

vector<int> solution(vector<string> genres, vector<int> plays) {
    vector<int> answer;
    unordered_map<string, int> genrePlayCount;
    unordered_map<string, vector<pair<int, int>>> songsInGenre;

    for (int i = 0; i < genres.size(); i++) {
        genrePlayCount[genres[i]] += plays[i];
        songsInGenre[genres[i]].push_back({plays[i], i});
    }

    for (auto& [genre, songs] : songsInGenre) {
        sort(songs.begin(), songs.end(), [](const pair<int, int>& a, const pair<int, int>& b) {
            if (a.first == b.first) return a.second < b.second;
            return a.first > b.first;
        });
    }

    vector<pair<int, string>> sortedGenres;
    
    for (const auto& [genre, totalPlay] : genrePlayCount) {
        sortedGenres.push_back({totalPlay, genre});
    }
    
    sort(sortedGenres.rbegin(), sortedGenres.rend());

    for (const auto& [_, genre] : sortedGenres) {
        const auto& songs = songsInGenre[genre];
        int count = 0;
        for (const auto& [_, index] : songs) {
            if (count >= 2) break;
            answer.push_back(index);
            count++;
        }
    }

    return answer;
}
