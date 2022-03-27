#include "sorts.h"
#include "utilities.h"

void ExchangeSort(std::vector<sf::RectangleShape>& recHolder, sf::RenderWindow &window, int wait, bool skip)
{
	for(int i = 0; i < recHolder.size() - 1; i++)
	{
		for(int j = i + 1; j < recHolder.size(); j++)
		{
			skip = pollEvent(skip, window);
			if(recHolder[j].getSize().y < recHolder[i].getSize().y){
				usleep(wait);
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

void BubbleSort(std::vector<sf::RectangleShape> &recHolder, sf::RenderWindow &window, int wait, bool skip)
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