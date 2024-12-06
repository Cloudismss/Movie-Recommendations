#include <fstream>
#include <iostream>
#include <string>
#include <exception>
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
void testPrintMovies(const vector<Movie> &movieList);
void testPrintFamousDirectorMovies(const map<string, bool> movieListFamousDirector);

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


  DecisionTree tree;
  tree.buildTree();

  for (const auto &movie : movieList)
  {
    string recommend = tree.classify(tree.getRoot(), &movie);
    cout << "Movie: " << movie.getTitle() << " - " << recommend << std::endl;
  }

  // TODO: Print prediction results for each movie using binary tree logic

  // TODO: Remove these functions once tree print is complete
  //testPrintMovies(movieList);
  //testPrintFamousDirectorMovies(movieListFamousDirector);

  return 0;
}


void getMovieList(std::vector<Movie> &movieList)
{
    std::ifstream file("movies.txt");
    std::string line;

    if (!file.is_open())
    {
        std::cerr << "Error: Unable to open 'movies.txt'.\n";
        return;
    }

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

void testPrintMovies(const vector<Movie> &movieList)
{
  for (int i = 0; i < movieList.size(); ++i)
  {
    cout << "Title: " << movieList[i].getTitle() << "\n"
         << "Genre: " << movieList[i].getGenre() << "\n"
         << "Rating: " << movieList[i].getRating() << "\n"
         << "Famous Director: " << ((movieList[i].getFamousDirector()) ? "yes" : "no") << "\n"
         << "Long Duration: " << ((movieList[i].getLongDuration()) ? "yes" : "no") << "\n"
         << "\n";
  }
  
  cout << "\n";
}

void testPrintFamousDirectorMovies(const map<string, bool> movieListFamousDirector)
{
  cout << "Movies with famous directors: \n\n";
  for (auto iter = movieListFamousDirector.begin(); iter != movieListFamousDirector.end(); ++iter)
  {
    if (iter->second)
      cout << iter->first << "\n";
  }
}