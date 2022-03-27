#include "utilities.h"

void FillVector(sf::RectangleShape rec, std::vector<sf::RectangleShape> &recHolder , sf::RenderWindow &window)
{
	int xOffset = 350;
	while (xOffset < window.getSize().x)
	{
		int height = window.getSize().y;
		rec.setSize(sf::Vector2f(6, rand() % height - 50));
		if(rec.getSize().y < 5)
		{
			rec.setSize(sf::Vector2f(6, 5));
		}
		rec.setFillColor(sf::Color(rand() % 256, rand() % 256, rand() % 256));
		rec.setPosition(xOffset, window.getSize().y - rec.getSize().y);
		recHolder.push_back(rec);

		xOffset += 8;
	}
}

void FillVectorContinue(sf::RectangleShape rec, std::vector<sf::RectangleShape> &recHolder , sf::RenderWindow &window){
	int xOffset = 350;
	while (xOffset < window.getSize().x)
	{
		int height = window.getSize().y;
		rec.setSize(sf::Vector2f(6, 7.5 * ((xOffset - 350) / 8 + 1)));
		rec.setFillColor(sf::Color(rand() % 256, rand() % 256, rand() % 256));
		rec.setPosition(xOffset, window.getSize().y - rec.getSize().y);
		recHolder.push_back(rec);

		xOffset += 8;
	}
}

void printVector(sf::RenderWindow &window, std::vector<sf::RectangleShape> recHolder)
{

	for (int i = 0; i < recHolder.size(); i++)
	{
		window.draw(recHolder[i]);
	}
	
}

void swap(sf::RectangleShape &xp, sf::RectangleShape &yp){
	sf::RectangleShape temp = xp;
	xp = yp;
	yp = temp;
}

bool pollEvent(bool skip, sf::RenderWindow &window){
	sf::Event ev;
	while(window.pollEvent(ev))
		{
			if (ev.type == sf::Event::KeyReleased)
			{
				if(ev.key.code == sf::Keyboard::Space)
				{
					skip = true;
				}
			}	
		}
	return skip;
}

void shuffle(std::vector<sf::RectangleShape>& recHolder, sf::RenderWindow &window){
	for (int i = 0; i < recHolder.size() - 1; i++)
    {
        int j = i + rand() % (recHolder.size() - i);
		//usleep(wait);
		swap(recHolder[i], recHolder[j]);
		sf::Vector2f pos = recHolder[i].getPosition();
		recHolder[i].setPosition(recHolder[j].getPosition().x, window.getSize().y - recHolder[i].getSize().y);
		recHolder[j].setPosition(pos.x, window.getSize().y - recHolder[j].getSize().y);
		window.clear();
		printVector(window, recHolder);
		window.display();
    }
}