#include "sorts.h"
#include "utilities.h"
#include <Windows.h>

void ExchangeSort(std::vector<sf::RectangleShape>& recHolder, sf::RenderWindow &window, bool skip)
{
	for(int i = 0; i < recHolder.size() - 1; i++)
	{
		for(int j = i + 1; j < recHolder.size(); j++)
		{
			skip = pollEvent(skip, window);
			if(recHolder[j].getSize().y < recHolder[i].getSize().y){
				swap(recHolder[j], recHolder[i]);
				sf::Vector2f pos = recHolder[j].getPosition();
				recHolder[j].setPosition(recHolder[i].getPosition().x, recHolder[j].getPosition().y);
				recHolder[i].setPosition(pos.x, recHolder[i].getPosition().y);
			}
			if(!skip){
				window.clear();
				printVector(window, recHolder);
				window.display();
			}
		}
	}
}

void BubbleSort(std::vector<sf::RectangleShape> &recHolder, sf::RenderWindow &window, bool skip)
{
	sf::RectangleShape tempRec;
	for(int i = 0; i < recHolder.size() - 1; i++){
		for(int j = 0; j < recHolder.size() - i - 1; j++){
			skip = pollEvent(skip, window);
			if(recHolder[j].getSize().y > recHolder[j + 1].getSize().y){
				swap(recHolder[j], recHolder[j + 1]);
				sf::Vector2f pos = recHolder[j].getPosition();
				recHolder[j].setPosition(recHolder[j + 1].getPosition().x, recHolder[j].getPosition().y);
				recHolder[j + 1].setPosition(pos.x, recHolder[j + 1].getPosition().y);
			}
			if(!skip){
				window.clear();
				printVector(window, recHolder);
				window.display();
			}
		}
	}
}

int partition (std::vector<sf::RectangleShape> &recHolder, int low, int high, sf::RenderWindow &window, bool skip)
{
    int pivot = recHolder[high].getSize().y; // pivot
    int i = (low - 1); // Index of smaller element and indicates the right position of pivot found so far
 
    for (int j = low; j <= high - 1; j++)
    {
        // If current element is smaller than the pivot
        if (recHolder[j].getSize().y < pivot)
        {
            i++; // increment index of smaller element
            swap(recHolder[i], recHolder[j]);
			sf::Vector2f pos = recHolder[i].getPosition();
			recHolder[i].setPosition(recHolder[j].getPosition().x, recHolder[i].getPosition().y);
			recHolder[j].setPosition(pos.x, recHolder[j].getPosition().y);
			if(!skip){
				window.clear();
				printVector(window, recHolder);
				window.display();
			}
        }
    }
    swap(recHolder[i + 1], recHolder[high]);
	sf::Vector2f pos = recHolder[i + 1].getPosition();
	recHolder[i + 1].setPosition(recHolder[high].getPosition().x, recHolder[i + 1].getPosition().y);
	recHolder[high].setPosition(pos.x, recHolder[high].getPosition().y);
	if(!skip){
		window.clear();
		printVector(window, recHolder);
		window.display();
	}
    return (i + 1);
}

void quickSort(std::vector<sf::RectangleShape> &recHolder, int low, int high, sf::RenderWindow &window, bool skip)
{
    if (low < high)
    {
        /* pi is partitioning index, arr[p] is now
        at right place */
        int pi = partition(recHolder, low, high, window, skip);
 
        // Separately sort elements before
        // partition and after partition
        quickSort(recHolder, low, pi - 1, window, skip);
        quickSort(recHolder, pi + 1, high, window, skip);
    }
}

void callQuickSort(std::vector<sf::RectangleShape> &recHolder, sf::RenderWindow &window, bool skip){
	quickSort(recHolder, 0, recHolder.size() - 1, window, skip);
}

void selectionSort(std::vector<sf::RectangleShape> &recHolder, sf::RenderWindow &window, bool skip) 
{ 
    int i, j, min_idx; 
  
    // One by one move boundary of unsorted subarray 
    for (i = 0; i < recHolder.size() - 1; i++) 
    { 
        // Find the minimum element in unsorted array 
        min_idx = i; 
        for (j = i+1; j < recHolder.size(); j++) 
        if (recHolder[j].getSize().y < recHolder[min_idx].getSize().y) 
            min_idx = j; 
  
        // Swap the found minimum element with the first element 
		//to remove
		Sleep(1);
        swap(recHolder[min_idx], recHolder[i]); 
		sf::Vector2f pos = recHolder[min_idx].getPosition();
		recHolder[min_idx].setPosition(recHolder[i].getPosition().x, recHolder[min_idx].getPosition().y);
		recHolder[i].setPosition(pos.x, recHolder[i].getPosition().y);
		if(!skip){
			window.clear();
			printVector(window, recHolder);
			window.display();
		}
    } 
} 