#ifndef SORTS_H
#define SORTS_H

#include <iostream>
#include <vector>
#include <SFML/Graphics.hpp>
#include <ctime>

//Visualizes Bubble sort algorithm
void BubbleSort(std::vector<sf::RectangleShape> &recHolder, sf::RenderWindow &window, bool skip);

//Visualizes Exchange sort algorithm
void ExchangeSort(std::vector<sf::RectangleShape>& recHolder, sf::RenderWindow &window, bool skip);

/* This function takes last element as pivot, places
the pivot element at its correct position in sorted
array, and places all smaller (smaller than pivot)
to left of pivot and all greater elements to right
of pivot */
int partition (std::vector<sf::RectangleShape> &recHolder, int low, int high, sf::RenderWindow &window, bool skip);

/* The main function that implements QuickSort
arr[] --> Array to be sorted,
low --> Starting index,
high --> Ending index */
void quickSort(std::vector<sf::RectangleShape> &recHolder, int low, int high, sf::RenderWindow &window, bool skip);

//calls the quick sort function
void callQuickSort(std::vector<sf::RectangleShape> &recHolder, sf::RenderWindow &window, bool skip);

//Visualizes Selection sort algorithm
void selectionSort(std::vector<sf::RectangleShape> &recHolder, sf::RenderWindow &window, bool skip);


#endif // SORTS_H