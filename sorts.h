#ifndef SORTS_H
#define SORTS_H

#include <iostream>
#include <vector>
#include <SFML/Graphics.hpp>
#include <ctime>
#include <unistd.h>

//Visualizes Bubble sort algorithm
void BubbleSort(std::vector<sf::RectangleShape> &recHolder, sf::RenderWindow &window, int wait, bool skip);

//Visualizes Exchange sort algorithm
void ExchangeSort(std::vector<sf::RectangleShape>& recHolder, sf::RenderWindow &window, int wait, bool skip);

#endif // SORTS_H