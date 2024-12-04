#include <fstream>
#include <iostream>
#include <string>
#include <exception>
#include <map>
#include <vector>

#include "DecisionTreeNode.h"
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

  // TODO: Print prediction results for each movie using binary tree logic

  // TODO: Remove these functions once tree print is complete
  testPrintMovies(movieList);
  testPrintFamousDirectorMovies(movieListFamousDirector);

  return 0;
}

void getMovieList(vector<Movie> &movieList)
{
  try
  {
    std::ifstream file("movies.txt");

    if (!file.is_open())
      throw std::runtime_error("File not found");

    string title, genre, rating;
    bool famousDirector = false, longDuration = false;

    // Skip the first line in the read
    string buffer = "";
    getline(file, buffer);

    while (!file.eof())
    {
      getline(file, title, ',');
      getline(file, genre, ',');
      getline(file, rating, ',');
      getline(file, buffer, ',');
      famousDirector = stoi(buffer);
      file >> longDuration;
      file.ignore();
      movieList.push_back(Movie(title, genre, rating, famousDirector, longDuration));
    }

    file.close();
  }
  catch (const std::exception &e)
  {
     std::cout << "Error reading file: " << e.what() << "\n";
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