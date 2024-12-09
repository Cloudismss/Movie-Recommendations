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


    int linenum = 1;  //used for tracking errors 
    while (std::getline(file, line))
    {
        linenum++;

        if (line.empty()) continue;

        std::istringstream ss(line);
        std::string title, genre, rating, famousDirectorStr, longDurationStr;

        try
        {
          std::getline(ss, title, ',');
          std::getline(ss, genre, ',');
          std::getline(ss, rating, ',');
          std::getline(ss, famousDirectorStr, ',');
          std::getline(ss, longDurationStr);
          //makes sure all the parts of the entry are included
          if (title.empty() || genre.empty() || rating.empty() || famousDirectorStr.empty() || longDurationStr.empty())
            throw std::invalid_argument("Missing movie input");

          bool famousDirector = (famousDirectorStr == "1");
          bool longDuration = (longDurationStr == "1");

          movieList.emplace_back(title, genre, rating, famousDirector, longDuration);
    }

    catch (const std::exception &ex)
    {
      std::cerr << "Error on line input " << linenum << ": " << ex.what() << std::endl;
      std::cerr << "Skipping line: " << line << std::endl;
    }
  }

  if (movieList.empty())
    throw std::runtime_error("Error: No valid movies could be read");
}