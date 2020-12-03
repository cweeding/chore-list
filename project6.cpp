//  Created by Frank M. Carrano and Timothy M. Henry.
//  Copyright (c) 2017 Pearson Education, Hoboken, New Jersey.

#include <iostream>
#include <fstream>
#include <string>
#include "LinkedList.h" // ADT list operations

using namespace std;

/*************************************************************************
* Function: getList()
*
* Description: Reads in the correct answers from a file and stores to
*              an array called key
* @Pre: key array
* @Post: key arry is updated in main
*************************************************************************/
void getList(ListInterface<std::string>* listPtr, string docName)
{
  // Variables
  ifstream inFile;
  string chores[100];
  int i = 0;

  // Opens the file
  inFile.open(docName.c_str());

  if(inFile)  // Enters if file opens correctly
  {
    while(inFile)
    {
      getline(inFile, chores[i]);
      listPtr->insert(i + 1, chores[i]);
      i++;
    }
  }
  else  // Enters if file does not open correctly and exits program
  {
    cout << "File Error" << endl;
    exit(0);
  }

  // Closes the file
  inFile.close();
}


/*************************************************************************
* Function: getKey()
*
* Description: Reads in the correct answers from a file and stores to
*              an array called key
* @Pre: key array
* @Post: key arry is updated in main
*************************************************************************/

void printList(ListInterface<string>* listPtr)
{
  cout << "***** Today's List *****" << endl;
  for (int pos = 1; pos < listPtr->getLength(); pos++)
  {
    try
    {
      cout << pos << ". " << listPtr->getEntry(pos) << endl;
    }
    catch(PrecondViolatedExcep except)
    {
      cout << "Exception thrown getting entry inserted at position " << pos << endl;
      cout << except.what() << endl;
    }
  } // end for
  cout << endl;
}  // end printList





/*************************************************************************
* Function: main()
*************************************************************************/
int main()
{
  ListInterface<string>* listPtr = new LinkedList<string>();
  string docName = "choreList.txt";
  int position = 0;
  bool itemWasRemoved = false;
  string addItem = "yes";
  bool itemWasAdded = false;
  string newItem;

  getList(listPtr, docName);
  cout << "\nThere are " << listPtr->getLength() << " items on the chore list." << endl;
  printList(listPtr);

  while (position != -999)
  {
    cout << "\nWhich item do you want to delete? Use -999 for no change. -> ";
    cin >> position;
    itemWasRemoved = listPtr->remove(position);
    if (itemWasRemoved)
      printList(listPtr);
    // else
    //   cout << "Item could not be removed." << endl;
  }

  while (addItem != "no")
  {
    cout << "\nAdd an item to your list? yes or no -> ";
    cin >> addItem;
    if (addItem == "yes")
    {
      cout << "Position -> ";
      cin >> position;
      cout << "Item -> ";
      getline(cin, newItem);
      itemWasAdded = listPtr->insert(position, newItem);
      if (itemWasAdded)
        printList(listPtr);
      // else
      //   cout << "Item could not be added." << endl;
    }
  }

  cout << endl;
  printList(listPtr);
  return 0;
}  // end main
