#include <SFML/Graphics.hpp>
// #include <iostream>
using namespace sf;
// using namespace std;

int main()
{
    Vector2f resolution;
    resolution.x = VideoMode::getDesktopMode().width;
    resolution.y = VideoMode::getDesktopMode().height;
    float x = VideoMode::getDesktopMode().width;

    VideoMode vm(resolution.x, resolution.y);
    RenderWindow window(vm, "The Timber Game");

    Texture backgroundTexture;
    Texture treeTexture;
    Texture branchTexture;
    Texture beeTexture;
    Texture cloudsTexture;
    backgroundTexture.loadFromFile("./Sprites/graphics/background.png");
    treeTexture.loadFromFile("./Sprites/graphics/tree.png");
    branchTexture.loadFromFile("./Sprites/graphics/branch.png");
    beeTexture.loadFromFile("./Sprites/graphics/bee.png");
    cloudsTexture.loadFromFile("./Sprites/graphics/cloud.png");


    Sprite backgroundSprite;
    Sprite treeSprite;
    Sprite branchSprite;
    Sprite beeSprite, beeSprite2, beeSprite3, beeSprite4;
    backgroundSprite.setTexture(backgroundTexture);
    backgroundSprite.setPosition(0, 0);

    treeSprite.setTexture(treeTexture);
    treeSprite.setPosition((resolution.x / 2) - 150, 0);

    branchSprite.setTexture(branchTexture);
    branchSprite.setPosition((resolution.x / 2) + 150, (resolution.y / 2) - 75);

    beeSprite.setTexture(beeTexture);
    beeSprite.setPosition((resolution.x / 2) + 300, (resolution.y / 2) - 65);

    beeSprite2.setTexture(beeTexture);
    beeSprite2.setPosition((resolution.x / 2) - 250, (resolution.y / 2) - 105);

    beeSprite3.setTexture(beeTexture);
    beeSprite3.setPosition((resolution.x / 2) - 200, (resolution.y / 2) + 45);

    while (window.isOpen())
    {
        if (Keyboard::isKeyPressed(Keyboard::Escape))
        {
            window.close();
        }
        Event event; // {Discreet Event Handing--------

        while (window.pollEvent(event))
        {
            if (event.type == Event::Closed)
            {
                window.close();
            }
        }
        //---------}

        window.clear();

        //
        window.draw(backgroundSprite);
        window.draw(treeSprite);

        // window.draw(branchSprite);
        // branchSprite.se
        // window.draw(branchSprite);

        window.draw(beeSprite);
        window.draw(beeSprite2);

        window.draw(beeSprite3);
        // window.draw(beeSprite);

        window.display();
    }
    return 0;
}
