#pragma once

#include <iostream>
#include <vector>
#include <fstream>
#include <filesystem>
#include <string>
#include <sstream>
#include <algorithm>

using namespace std;

class HighScores {
private:
  vector<pair<string, int>> scores;
  string fileName;

public:
  // Constructor
  HighScores(string fileName) {
    this->fileName = fileName;
    this->parseFile();
  }

  // Methods
  void parseFile() {
    if (!filesystem::exists(this->fileName)) {
      filesystem::path path(this->fileName);
      filesystem::create_directories(path.parent_path());
      ofstream file(this->fileName);
      file.close();
    }

    ifstream file(this->fileName);
    if (!file) {
      cerr << "Unable to open file: " << this->fileName << endl;
      return;
    }

    string line;
    while (getline(file, line)) {
      stringstream ss(line);
      string name;
      int score;
      if (getline(ss, name, ',') && ss >> score) {
        this->scores.emplace_back(name, score);
      }
    }

    file.close();
  }

  void update(string& name, int points) {
    this->scores.push_back({name, points});
    this->sortHighScores();
    this->writeToFile();
  }

  void show() {
    for (int i = 0; i < this->scores.size(); ++i) {
      cout << i + 1 << ". " << this->scores[i].first << " : " << this->scores[i].second << endl;
    }
    cout << endl;
  }

private:
  void sortHighScores() {
    sort(
      this->scores.begin(),
      this->scores.end(),
      [](pair<string, int>& a, pair<string, int>& b) {
        return a.second > b.second;
      });
    if (this->scores.size() > 10) this->scores.pop_back();
  }

  void writeToFile() {
    ofstream file(this->fileName);
    if (!file) {
      cout << "Unable to open file: " << this->fileName << endl;
      return;
    }

    for (const auto& score : this->scores) {
      file << score.first << "," << score.second << endl;
    }

    file.close();
  }

};
