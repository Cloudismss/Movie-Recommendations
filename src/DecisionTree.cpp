#include "DecisionTree.h"

#include <iostream>

using std::cout;

//Constructor Definition
DecisionTree::DecisionTree() : rootPtr(nullptr) {}

//Destructor Definition
DecisionTree::~DecisionTree() 
{
  deleteTree(rootPtr);
}

void DecisionTree::deleteTree(DecisionTreeNode* tmpnode)
{
  if(tmpnode)
  {
    deleteTree(tmpnode->yes);
    deleteTree(tmpnode->no);
    delete tmpnode;
  }
}

void DecisionTree::buildTree()
{
  rootPtr = new DecisionTreeNode("Is the genre Action?");
  rootPtr->yes = new DecisionTreeNode("Is the director famous?");
  rootPtr->yes->yes = new DecisionTreeNode("Recommended");
  rootPtr->yes->yes->recommendation = "Recommended";
  rootPtr->yes->no->no = new DecisionTreeNode("Not Recommended");
  rootPtr->yes->no->recommendation = "Not Recommended";

  rootPtr->no = new DecisionTreeNode("Is the rating PG-13 or lower?");
  rootPtr->no->yes = new DecisionTreeNode("Not Recommended");
  rootPtr->no->yes->recommendation = "Not Recommended";
  rootPtr->no->no = new DecisionTreeNode("Is the duration long?");
  rootPtr->no->no->yes = new DecisionTreeNode("Recommended");
  rootPtr->no->no->yes->recommendation = "Recommended";
  rootPtr->no->no->no = new DecisionTreeNode("Not Recommended");
  rootPtr->no->no->no->recommendation = "Not Recommended";

}


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

  printTreeHelper(rootPtr, 0);  
}

void DecisionTree::printTreeHelper(DecisionTreeNode *node, int level) const
{
  if (node)
  {
    for (int i = 0; i < level; i++)
    {
      cout << " ";
    }
    if(!node->yes && !node->no)
      cout << "Leaf: " << node->recommendation << std::endl;
    else
      cout << "Question: " << node->question << std::endl;

    printTreeHelper(node->yes, level+1);
    printTreeHelper(node->no, level+1);
  }
}