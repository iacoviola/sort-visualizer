#include "sorts.h"
#include "utilities.h"

int main()
{

	srand(time(NULL));

	int i = 0;

	//int slowValues[5] = {0, 50, 100, 200, 500};

	int width = 1150;
	int height = 800;

	bool skip = false;

	bool bs = true, es = false, qs = false, ss = false;
	bool spaceIspressed = false;
	bool needsShuffle = false;

 	sf::VideoMode mode = sf::VideoMode::getDesktopMode();

	sf::RenderWindow window(sf::VideoMode(/*mode.width, mode.height, mode.bitsPerPixel*/width, height), "Sort Visualizer");
	sf::Event ev;

	sf::RectangleShape rectangle;
	std::vector<sf::RectangleShape> rectangleVector;

	FillVectorContinue(rectangle, rectangleVector, window);
	shuffle(rectangleVector, window);
	
	rectangle.setOutlineColor(sf::Color::White);
	rectangle.setOutlineThickness(3);
	rectangle.setFillColor(sf::Color::Transparent);
	rectangle.setSize(sf::Vector2f(300, 750));
	rectangle.setPosition(sf::Vector2f(25, 25));

	sf::Font font;

	if(!font.loadFromFile("../assets/calibri.ttf")){
        std::cout << "Error while loading font" << std::endl;
        return -1;
	}

	sf::Text infos[5][2];

	int y = 35;

	infos[0][0].setString("E");
	infos[0][1].setString("Exchange Sort");
    infos[1][0].setString("B");
	infos[1][1].setString("Bubble Sort");
	infos[2][0].setString("Q");
	infos[2][1].setString("Quick Sort");
	infos[3][0].setString("S");
	infos[3][1].setString("Selection Sort");
	infos[4][0].setString("Spacebar");
	infos[4][1].setString("Start/Skip/Shuffle");

	for(int i = 0; i < 5; i++){
		for(int j = 0; j < 2; j++){
			infos[i][j].setFont(font);
			infos[i][j].setCharacterSize(20);
			infos[i][j].setStyle(sf::Text::Bold);
			if(j == 0)
				infos[i][j].setPosition(sf::Vector2f(35, + y));
			else
				infos[i][j].setPosition(sf::Vector2f(35 + infos[i][j - 1].getString().getSize() * 10 + 20, + y));
			infos[i][j].setFillColor(sf::Color::White);
		}
		y += 35;
	}
	
	//Selecting Bubble sort
	infos[1][0].setFillColor(sf::Color::Red);

	sf::Image image = sf::Image{};
	if (image.loadFromFile("../assets/sort.png"))
	{
		window.setIcon(image.getSize().x, image.getSize().y, image.getPixelsPtr());
	}

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
						shuffle(rectangleVector, window);
						needsShuffle = false;
					}
				}
				/*if(ev.key.code == sf::Keyboard::S)
				{
	
					if(i == 5)
						i = 0;
					else
						i++;
					std::cout << "SleepValue = " << slowValues[i] << " next = ";
					std::cout << ((i == 5) ? slowValues[0] : slowValues[i + 1]) << std::endl;
				}*/
				if(ev.key.code == sf::Keyboard::B)
				{
					bs = true;
					es = false;
					qs = false;
					ss = false;
					infos[1][0].setFillColor(sf::Color::Red);
					infos[2][0].setFillColor(sf::Color::White);
					infos[3][0].setFillColor(sf::Color::White);
					infos[0][0].setFillColor(sf::Color::White);
				}
				if(ev.key.code == sf::Keyboard::E)
				{
					es = true;
					bs = false;
					qs = false;
					ss = false;
					infos[1][0].setFillColor(sf::Color::White);
					infos[2][0].setFillColor(sf::Color::White);
					infos[3][0].setFillColor(sf::Color::White);
					infos[0][0].setFillColor(sf::Color::Red);
				}
				if(ev.key.code == sf::Keyboard::Q)
				{
					bs = false;
					es = false;
					qs = true;
					ss = false;
					infos[1][0].setFillColor(sf::Color::White);
					infos[2][0].setFillColor(sf::Color::Red);
					infos[3][0].setFillColor(sf::Color::White);
					infos[0][0].setFillColor(sf::Color::White);
				}
				if(ev.key.code == sf::Keyboard::S)
				{
					bs = false;
					es = false;
					qs = false;
					ss = true;
					infos[1][0].setFillColor(sf::Color::White);
					infos[2][0].setFillColor(sf::Color::White);
					infos[3][0].setFillColor(sf::Color::Red);
					infos[0][0].setFillColor(sf::Color::White);
				}
			}
		}

		window.clear();

		for(int i = 0; i < 5; i++)
			for(int j = 0; j < 2; j++)
				window.draw(infos[i][j]);
		window.draw(rectangle);

		if(spaceIspressed)
		{
			if(bs)
				BubbleSort(rectangleVector, window, skip);
			else if(es)
				ExchangeSort(rectangleVector, window, skip);
			else if(qs)
				callQuickSort(rectangleVector, window, skip);
			else if(ss)
				selectionSort(rectangleVector, window, skip);
			spaceIspressed = false;
			needsShuffle = true;
		}
		
		printVector(window, rectangleVector);
		window.display();
	}

	return 0;
}