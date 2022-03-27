#include "sorts.h"
#include "utilities.h"

void sum (int a, int b){
	int c = a + b;
}

int main()
{

	srand(time(NULL));

	int i = 0;

	int slowValues[5] = {0, 50, 100, 200, 500};

	int width = 1200;
	int hight = 800;

	bool skip = false;

	bool bs = true, es = false;
	bool spaceIspressed = false;
	bool needsShuffle = false;

	sf::RenderWindow window(sf::VideoMode(width, hight), "Bubble Sort");
	sf::Event ev;

	sf::RectangleShape rectangle;
	std::vector<sf::RectangleShape> rectangleVector;

	FillVector(rectangle, rectangleVector, window);
	
	rectangle.setOutlineColor(sf::Color::White);
	rectangle.setOutlineThickness(3);
	rectangle.setFillColor(sf::Color::Transparent);
	rectangle.setSize(sf::Vector2f(300, 750));
	rectangle.setPosition(sf::Vector2f(25, 25));

	window.setFramerateLimit(30);
	//window.setVerticalSyncEnabled(true);

	sf::Font font;

	if(!font.loadFromFile("/System/Library/Fonts/HelveticaNeue.ttc")){
        std::cout << "Error while loading font" << std::endl;
        return -1;
	}

	sf::Text exSort;
	exSort.setFont(font);
    exSort.setString("E - Exchange Sort");
    exSort.setCharacterSize(28);
	exSort.setStyle(sf::Text::Bold);
	exSort.setPosition(sf::Vector2f(35, 35));
    exSort.setFillColor(sf::Color::White);

	sf::Text bubbleSort;
	bubbleSort.setFont(font);
    bubbleSort.setString("B - Bubble Sort");
    bubbleSort.setCharacterSize(28);
	bubbleSort.setStyle(sf::Text::Bold);
	bubbleSort.setPosition(sf::Vector2f(35, 70));
    bubbleSort.setFillColor(sf::Color::White);

	while (window.isOpen())
	{
		while(window.pollEvent(ev))
		{
			if (ev.type == sf::Event::Closed)
			{
				window.close();
			}
			if (ev.type == sf::Event::KeyReleased)
			{
				if(ev.key.code == sf::Keyboard::Space)
				{
					if(!spaceIspressed && !needsShuffle)
						spaceIspressed = true;
					else if (needsShuffle){
						shuffle(rectangleVector, window, slowValues[i]);
						needsShuffle = false;
					}
				}
				if(ev.key.code == sf::Keyboard::S)
				{
	
					if(i == 5)
						i = 0;
					else
						i++;
					std::cout << "SleepValue = " << slowValues[i] << " next = ";
					std::cout << ((i == 5) ? slowValues[0] : slowValues[i + 1]) << std::endl;
				}
				if(ev.key.code == sf::Keyboard::B)
				{
					bs = true;
					es = false;
					window.setTitle("Bubble Sort");
				}
				if(ev.key.code == sf::Keyboard::E)
				{
					es = true;
					bs = false;
					window.setTitle("Exchange Sort");
				}
			}
		}

		window.clear();

		//showInfos(info);

		window.draw(exSort);
		window.draw(bubbleSort);
		window.draw(rectangle);

		if(spaceIspressed)
		{
			if(bs){		
				BubbleSort(rectangleVector, window, slowValues[i], skip);
			}
			else if(es)
				ExchangeSort(rectangleVector, window, slowValues[i], skip);
			spaceIspressed = false;
			needsShuffle = true;
		}
		
		printVector(window, rectangleVector);
		window.display();
	}

	return 0;
}