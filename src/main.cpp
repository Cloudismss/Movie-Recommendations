#include <fstream>
#include <iostream>
#include <string>
#include <map>
#include <vector>
#include <sstream>

#include "DecisionTree.h"
#include "Movie.h"

using std::cout;
using std::string;
using std::map;
using std::vector;

// Headers
void getMovieList(vector<Movie> &movieList);
void printFamousDirectorMovies(const map<string, bool> movieListFamousDirector);

int main()
{
  // Read data from file
  vector<Movie> movieList;
  getMovieList(movieList);

  // Populate famous director movies in a map
  map<string, bool> movieListFamousDirector;
  for (int i = 0; i < movieList.size(); ++i)
  {
    movieListFamousDirector.insert(std::make_pair(movieList[i].getTitle(), movieList[i].getFamousDirector()));
  }

  // Print famous director movies
  //printFamousDirectorMovies(movieListFamousDirector);

  DecisionTree tree;
  tree.buildTree();

  for (const auto &movie : movieList)
  {
    string recommend = tree.classify(tree.getRoot(), &movie);
    cout << "Movie: " << movie.getTitle() << " - " << recommend << std::endl;
  }
}


void getMovieList(std::vector<Movie> &movieList)
{
    std::ifstream file;
    try 
    {
      file.open("movies.txt");
      if (!file)
        throw "Error: Unable to open 'movies.txt'\n";
    } catch (const char *error) 
    {
      cout << error;
      return;
    }

    std::string line;
    std::getline(file, line); // Skip header
    while (std::getline(file, line))
    {
        if (line.empty()) continue;

        std::istringstream ss(line);
        std::string title, genre, rating, famousDirectorStr, longDurationStr;

        std::getline(ss, title, ',');
        std::getline(ss, genre, ',');
        std::getline(ss, rating, ',');
        std::getline(ss, famousDirectorStr, ',');
        std::getline(ss, longDurationStr);

        bool famousDirector = (famousDirectorStr == "1");
        bool longDuration = (longDurationStr == "1");

        movieList.emplace_back(title, genre, rating, famousDirector, longDuration);
    }
}

void printFamousDirectorMovies(const map<string, bool> movieListFamousDirector)
{
  cout << "Movies with famous directors: \n\n";
  for (auto iter = movieListFamousDirector.begin(); iter != movieListFamousDirector.end(); ++iter)
  {
    if (iter->second)
      cout << iter->first << "\n";
  }
  cout <<"\n";
}