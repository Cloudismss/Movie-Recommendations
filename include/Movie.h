#ifndef MOVIE_H
#define MOVIE_H

#include <string>

using std::string;

class Movie
{
private:
  string title;
  string genre;
  string rating;
  bool famousDirector;
  bool longDuration;

public:
  Movie(string title, string genre, string rating, bool famousDirector, bool longDuration)
    : title(title), genre(genre), rating(rating), famousDirector(famousDirector), longDuration(longDuration) { }

public:
  string getGenre() { return genre; }
};

#endif // MOVIE_H