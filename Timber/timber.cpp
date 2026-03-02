#include <SFML/Graphics.hpp>
#include <iostream>
using namespace sf;
using namespace std;

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
    Sprite cloudsSprite,cloudsSprite2;
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

    cloudsSprite.setTexture(cloudsTexture);
    cloudsSprite.setPosition((resolution.x / 2) - 500,(resolution.y / 2)-345);

    cloudsSprite2.setTexture(cloudsTexture);
    cloudsSprite2.setPosition((resolution.x /2)+200,(resolution.y / 2)-345);
    
    int pause = 0;
    // Vector2f position = beeSprite3.getPosition();

    while (window.isOpen())
    {

        if (Keyboard::isKeyPressed(Keyboard::Escape))
        {
            window.close();
        }
        if (Keyboard::isKeyPressed(Keyboard::Enter))
        {
            pause= !pause;
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

        Vector2f position = beeSprite.getPosition();
        Vector2f position2 = beeSprite2.getPosition();
        Vector2f position3 = beeSprite3.getPosition();
        Vector2f cloudPosition = cloudsSprite.getPosition();
        Vector2f cloudPosition2 = cloudsSprite2.getPosition();

        int j = 100;
        if (pause == 0)
        {
            if (position.x < 0)
            {
                beeSprite.setPosition(resolution.x - 100, (resolution.y / 2));

                // cout<<"Hello"<<endl;
            }

            else
            {

                beeSprite.setPosition(position.x - 0.10, position.y);
            }
            if (position2.x < 0)
            {
                beeSprite2.setPosition(resolution.x - 100, (resolution.y / 2));
            }
            else
            {
                beeSprite2.setPosition(position2.x - 0.20, position2.y);
            }
            if (position3.x < 0)
            {
                beeSprite3.setPosition(resolution.x - 100, (resolution.y / 2));
            }
            else
            {
                beeSprite3.setPosition(position3.x - 0.30, position3.y);
            }
            if(cloudPosition.x>resolution.x){
                cloudsSprite.setPosition(100,cloudPosition.y);
            }
            else{
                cloudsSprite.setPosition(cloudPosition.x+0.08,cloudPosition.y);
            }
             if(cloudPosition2.x>resolution.x){
                cloudsSprite2.setPosition(100,cloudPosition2.y);
            }
            else{
                cloudsSprite2.setPosition(cloudPosition2.x+0.09,cloudPosition2.y);
            }
        }

        //
        window.draw(backgroundSprite);
        window.draw(treeSprite);

        // window.draw(branchSprite);
        // branchSprite.se
        // window.draw(branchSprite);

        window.draw(beeSprite);
        window.draw(beeSprite2);

        window.draw(beeSprite3);
        window.draw(cloudsSprite);
        window.draw(cloudsSprite2);


        // window.draw(beeSprite);
        // cout<<i<<j<<endl;
        window.display();
    }
    return 0;
}
