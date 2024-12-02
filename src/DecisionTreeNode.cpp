#include "DecisionTreeNode.h"

string DecisionTreeNode::classify(DecisionTreeNode *node, Movie *movie)
{
  if (!node->yes && !node->no)
    return node->recommendation; // Leaf node reached

  if (node->question == "Is the genre Action?")
    return (movie->getGenre() == "Action") ? classify(node->yes, movie) : classify(node->no, movie);

  // Add more conditions for other questions
}