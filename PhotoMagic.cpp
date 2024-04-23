/*Copyright [2022] <Michael Chagnon>*/
#include "FibLFSR.h"
#include <iostream>
#include <SFML/System.hpp>
#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>

void transform(sf::Image& image, FibLFSR* reg) { // NOLINT
    // function takes image and seed for LFSR and
    // scrambles the image using particular seed
    sf::Color p;
    sf::Uint8 red;
    sf::Uint8 green;
    sf::Uint8 blue;

    sf::Vector2u size = image.getSize();  // stores the size of the image

    for (unsigned int x = 0; x < size.x; x++) {
        for (unsigned int y = 0; y < size.y; y++) {
            p = image.getPixel(x, y);
            // gets pixel from image at (x, y) coordinates specified

            red = p.r ^(reg->generate(20));
            // generates red color based on seed from main

            green = p.g ^(reg->generate(20));
            // generates green color

            blue = p.b ^(reg->generate(20));
            // generates blue color

            sf::Color newPixel(red, green, blue);
            // creates new color using red, green and blue parameters

            image.setPixel(x, y, newPixel);
            // sets pixel to new encoded color
        }
    }
}

int main(int argc, char* argv[]) {
    std::string inputFile(argv[1]);
    // takes input file from terminal

    std::string outputFile(argv[2]);
    // stores output file specified in terminal

    std::string seed(argv[3]);
    // stores seed given from terminal

    FibLFSR l(seed);

    sf::Image image;
    if (!image.loadFromFile(inputFile))  // loads file from input as image
        return -1;

        sf::Texture texture;
    texture.loadFromImage(image);  // changes image to texture

        sf::Sprite sprite;
    sprite.setTexture(texture);  // sets texture to sprite

    transform(image, &l);  // transforms image to encoded version using seed

    if (!image.saveToFile(outputFile))
    // saves new encoded image to computer using specified name
        return -1;

        sf::Texture texture2;
    texture2.loadFromImage(image);
    // creates new texture based on transformed image

        sf::Sprite sprite2;
    sprite2.setTexture(texture2);  // sets texture to sprite

    sf::Vector2u size = image.getSize();  // gets size of image

    sf::RenderWindow window1(sf::VideoMode(size.x, size.y), "Input File");
    // render windows
    sf::RenderWindow window2(sf::VideoMode(size.x, size.y), "Output File");

    while (window1.isOpen() && window2.isOpen()) {
        sf::Event event;
        while (window1.pollEvent(event)) {  // closes window
            if (event.type == sf::Event::Closed)
                window1.close();
        }
        while (window2.pollEvent(event)) {
            if (event.type == sf::Event::Closed)
                window2.close();
        }

        window1.clear();
        window1.draw(sprite);  // draws inputted file onto window one
        window1.display();

        window2.clear();
        window2.draw(sprite2);  // draws encrypted version of file on window two
        window2.display();
    }
return 0;
}
