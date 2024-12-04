#include "DecisionTree.h"

#include <iostream>

using std::cout;

string DecisionTree::classify(DecisionTreeNode *node, Movie *movie)
{
  if (!node->yes && !node->no)
    return node->recommendation; // Leaf node reached

  // Recommend condition 1
  if (node->question == "Is the genre Action?")
    return (movie->getGenre() == "Action") ? classify(node->yes, movie) : classify(node->no, movie);
  if (node->question == "Is the rating PG-13 or lower?")
    return (movie->getRating() != "R") ? classify(node->yes, movie) : classify(node->no, movie);

  // Recommend condition 2
  if (node->question == "Is the director famous?")
    return (movie->getFamousDirector()) ? classify(node->yes, movie) : classify(node->no, movie);
  if (node->question == "Is the duration long?")
    return (movie->getLongDuration()) ? classify(node->yes, movie) : classify(node->no, movie);

  // Don't recommend
  return "Not Recommended";
}

void DecisionTree::printTree() const
{
  if (!rootPtr)
  {
    cout << "No movies provided!\n";
    return;
  }

  printTreeHelper(rootPtr);  
}

void DecisionTree::printTreeHelper(DecisionTreeNode *node) const
{
  if (node)
  {

  }
  
}