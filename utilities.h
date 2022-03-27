#ifndef UTILITIES_H
#define UTILITIES_H

#include <iostream>
#include <vector>
#include <SFML/Graphics.hpp>
#include <ctime>
#include <unistd.h>

//Shuffles the vector using Fisher-Yates algorithm
void shuffle(std::vector<sf::RectangleShape>& recHolder, sf::RenderWindow &window, int wait);

//Show text infos and bindings
void showInfos(sf::RenderWindow &window);

//Fills the vector with random numbers
void FillVector(sf::RectangleShape rec, std::vector<sf::RectangleShape> &recHolder , sf::RenderWindow &window);

//Refreshes the vector on-screen
void printVector(sf::RenderWindow &window, std::vector<sf::RectangleShape> recHolder);

//Swap two elements in position
void swap(sf::RectangleShape &xp, sf::RectangleShape &yp);

//Checks if spacebar has been pressed during the sorting process
bool pollEvent(bool skip, sf::RenderWindow &window);

#endif //UTILITIES_H