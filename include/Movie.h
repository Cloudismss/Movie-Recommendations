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
  // Accessors
  string getTitle() const { return title; }
  string getGenre() const { return genre; }
  string getRating() const { return rating; }
  bool getFamousDirector() const { return famousDirector; }
  bool getLongDuration() const { return longDuration; }
};

#endif // MOVIE_H