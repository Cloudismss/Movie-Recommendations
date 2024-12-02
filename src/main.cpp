#include <fstream>
#include <iostream>
#include <string>
#include <vector>

#include "DecisionTreeNode.h"
#include "Movie.h"

using std::string;
using std::vector;

// Headers
vector<Movie> getMovieList();

int main()
{
  return 0;
}

vector<Movie> getMovieList()
{
  try
  {
    std::ifstream file("movies.txt");

    if (!file.is_open())
      throw runtime_error("File not found");
    
    vector<Movie> movieList = nullptr;

    string title, genre, rating;
    bool famousDirector, longDuration;

    while (file >> title >> genre >> rating >> famousDirector >> longDuration)
    {
      movieList->push_back(Movie(title, genre, rating, famousDirector, longDuration));
    }

    file.close();

    return movieList;
  }
  catch (const exception &e)
  {
    std::cout << "Error: " << e.what() << "\n";
  }

  return nullptr;
}