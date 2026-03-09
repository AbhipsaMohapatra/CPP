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
    Sprite cloudsSprite, cloudsSprite2,cloudsSprite3;
    backgroundSprite.setTexture(backgroundTexture);
    backgroundSprite.setPosition(0, 0);

    treeSprite.setTexture(treeTexture);
    treeSprite.setPosition((resolution.x / 2) - 150, 0);

    branchSprite.setTexture(branchTexture);
    branchSprite.setPosition((resolution.x / 2) + 150, (resolution.y / 2) - 75);

    beeSprite.setTexture(beeTexture);
    beeSprite.setPosition((resolution.x) + 300, (resolution.y / 2) - 65);

    beeSprite2.setTexture(beeTexture);
    beeSprite2.setPosition((resolution.x) + 250, (resolution.y / 2) - 105);

    beeSprite3.setTexture(beeTexture);
    beeSprite3.setPosition((resolution.x) + 200, (resolution.y / 2) + 45);

    cloudsSprite.setTexture(cloudsTexture);
    cloudsSprite.setPosition(0,150);

    cloudsSprite2.setTexture(cloudsTexture);
    cloudsSprite2.setPosition(0,300);

    cloudsSprite3.setTexture(cloudsTexture);
    cloudsSprite3.setPosition(0,450);

    float bspeed = 0.0f;
    float bspeed2 = 0.0f;
    float bspeed3 = 0.0f;

    float bheight = 0.0f;
    float bheight2 = 0.0f;
    float bheight3 = 0.0f;
    

    bool beeActive = false;
    bool beeActive2 = false;
    bool beeActive3 = false;

    bool cloudActive=false;
    bool cloudActive2=false;
    bool cloudActive3=false;

    float cloudSpeed=0.0;
    float cloudSpeed2=0.0;
    float cloudSpeed3=0.0;

    float cloudHeight=0.0f;
    float cloudHeight2=0.0f;
    float cloudHeight3=0.0f;

    RectangleShape timeBar;
    float timeBarWidth = 400.0f;
    float timeBarHeight = 80.0f;

    timeBar.setSize(Vector2f(timeBarWidth, timeBarHeight));
    timeBar.setFillColor(Color::Red);
    timeBar.setPosition((resolution.x / 2.0 - timeBarWidth / 2.0f), resolution.y - 100);

    Clock clock;
    float timeRemaining = 10.0f;
    float timeBarWidthPerSecond = timeBarWidth / timeRemaining;

    bool pause = true;

    //message Text

    Font font;
    font.loadFromFile("./Sprites/fonts/KOMIKAP_.ttf");

    Text messageText;
    messageText.setFont(font);
    messageText.setFillColor(Color::Yellow);
    messageText.setCharacterSize(100);
    messageText.setString("Press Enter To Start");

    FloatRect textRect=messageText.getLocalBounds();
    

    // Vector2f position = beeSprite3.getPosition();

    while (window.isOpen())
    {

        if (Keyboard::isKeyPressed(Keyboard::Escape))
        {
            window.close();
        }
        if (Keyboard::isKeyPressed(Keyboard::Enter))
        {
            pause = false;
            timeRemaining = 9.0f;
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
        if (!pause)
        {

            Time dt = clock.restart();
            timeRemaining-=dt.asSeconds();
            if(timeRemaining<=0.0){
                pause=true;
                
            }
            timeBar.setSize(Vector2f(timeBarWidthPerSecond*timeRemaining,timeBarHeight));
            

           

            if (!beeActive)
            {
                srand(time(0) * 10);
                bspeed = rand() % 200 + 200;
                srand(time(0) * 20);
                bheight = rand() % 500 + 500;
                beeSprite.setPosition(2000, bheight);
                beeActive = true;
            }
            else
            {
                beeSprite.setPosition(beeSprite.getPosition().x - (bspeed * dt.asSeconds()), beeSprite.getPosition().y);
                if (beeSprite.getPosition().x < (-100))
                {
                    beeActive = false;
                }
            }

            if (!beeActive2)
            {
                srand(time(0) * 20);
                bspeed2 = rand() % 200 + 200;
                srand(time(0) * 30);
                bheight2 = rand() % 500 + 500;
                beeSprite2.setPosition(2000, bheight2);
                beeActive2 = true;
            }
            else
            {
                beeSprite2.setPosition(beeSprite2.getPosition().x - (bspeed2 * dt.asSeconds()), beeSprite2.getPosition().y);
                if (beeSprite2.getPosition().x < (-100))
                {
                    beeActive2 = false;
                }
            }

            if (!beeActive3)
            {
                srand(time(0) * 20);
                bspeed3 = rand() % 200 + 200;
                srand(time(0) * 30);
                bheight3 = rand() % 500 + 500;
                beeSprite3.setPosition(2000, bheight3);
                beeActive3 = true;
            }
            else
            {
                beeSprite3.setPosition(beeSprite3.getPosition().x - (bspeed3 * dt.asSeconds()), beeSprite3.getPosition().y);
                if (beeSprite3.getPosition().x < (-100))
                {
                    beeActive3 = false;
                }
            }
            if(!cloudActive){
                srand(time(0)*10);
                cloudSpeed=rand()%200+10;
                srand(time(0)*20);
                cloudHeight=rand()%150;
                cloudsSprite.setPosition(-200,cloudHeight);
                cloudActive=true;
                

            }
            else{
                cloudsSprite.setPosition(cloudsSprite.getPosition().x+(cloudSpeed*dt.asSeconds()),cloudsSprite.getPosition().y);
                if(cloudsSprite.getPosition().x>resolution.x+100){
                    cloudActive=false;
                }
            }
            if(!cloudActive2){
               srand(time(0)*10);
                cloudSpeed2=rand()%200+10;
                srand(time(0)*20);
                cloudHeight2=rand()%300+150;
                cloudsSprite2.setPosition(-200,cloudHeight2);
                cloudActive2=true;
                

            }
            else{
                cloudsSprite2.setPosition(cloudsSprite2.getPosition().x+(cloudSpeed2*dt.asSeconds()),cloudsSprite2.getPosition().y);
                if(cloudsSprite2.getPosition().x>resolution.x+100){
                    cloudActive2=false;
                }
            }

            if(!cloudActive3){
                srand(time(0)*10);
                cloudSpeed3=rand()%200+20;
                srand(time(0)*20);
                cloudHeight3=rand()%300+150;
                cloudsSprite3.setPosition(-200,cloudHeight3);
                cloudActive3=true;
              

            }
            else{
                cloudsSprite3.setPosition(cloudsSprite3.getPosition().x+(cloudSpeed3*dt.asSeconds()),cloudsSprite3.getPosition().y);
                if(cloudsSprite3.getPosition().x>resolution.x+100){
                    cloudActive3=false;
                }
            }
        }
        window.clear();

        window.draw(backgroundSprite);
        window.draw(cloudsSprite);
        window.draw(cloudsSprite2);
        window.draw(cloudsSprite3);
        window.draw(treeSprite);

        // window.draw(branchSprite);
        // branchSprite.se
        // window.draw(branchSprite);

        window.draw(beeSprite);
        window.draw(beeSprite2);

        window.draw(beeSprite3);
        window.draw(timeBar);
        // window.draw(cloudsSprite);
        // window.draw(cloudsSprite2);

        // window.draw(beeSprite);
        // cout<<i<<j<<endl;
        window.display();
    }
    return 0;
}
