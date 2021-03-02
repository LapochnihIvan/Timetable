#include "GUI.h"
#include <iostream>
#include <xstring>
#include <map>
#include "Button.h"
#include <iomanip>
#include <functional>
#include <thread>

GUI::GUI() :
    window(sf::VideoMode(800, 600), ""),
    grey(169, 169, 169),
    darkGrey(99, 99, 99),
    t(sf::Vector2f(0.f, 60.f), sf::Vector2f((float)window.getSize().x, 30.f), TextBox::Numeric, window),
    tt(sf::Vector2f(0.f, 60.f), sf::Vector2f((float)window.getSize().x, 30.f), TextBox::Text, window)
{
    screanSize = window.getSize();
}

void
GUI::run()
{
    std::map<unsigned short, wchar_t> keys = { {0, L'ф'},
                                     {1, L'и'},
                                     {2, L'с'},
                                     {3, L'в'},
                                     {4, L'у'},
                                     {5, L'а'},
                                     {6, L'п'},
                                     {7, L'р'},
                                     {8, L'ш'},
                                     {9, L'о'},
                                     {10, L'л'},
                                     {11, L'д'},
                                     {12, L'ь'},
                                     {13, L'т'},
                                     {14, L'щ'},
                                     {15, L'з'},
                                     {16, L'й'},
                                     {17, L'к'}, 
                                     {18, L'ы'},
                                     {19, L'е'},
                                     {20, L'г'},
                                     {21, L'м'},
                                     {22, L'ц'},
                                     {23, L'ч'},
                                     {24, L'н'},
                                     {25, L'я'},
                                     {54, L'ё'},
                                     {46, L'х'},
                                     {47, L'ъ'},
                                     {48, L'ж'},
                                     {51, L'э'},
                                     {49, L'б'},
                                     {50, L'ю'} };
    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed) window.close();
            else {
                for (Button& butt : buttons) butt.actionListener(event);
                t.actionListener(event);
            }
            /*else if (event.type == sf::Event::KeyPressed)
            {
                std::wstring textBoxValue = texts.back().getString();;
                if (event.key.code >= sf::Keyboard::Key::A
                    && event.key.code <= sf::Keyboard::Key::Num9
                    || event.key.code == sf::Keyboard::Key::Space
                    || event.key.code >= sf::Keyboard::Key::LBracket
                    && event.key.code <= sf::Keyboard::Key::Quote
                    || event.key.code <= sf::Keyboard::Key::Tilde)
                {
                    wchar_t key;
                    if (event.key.code >= sf::Keyboard::Key::Num0
                        && event.key.code <= sf::Keyboard::Key::Num9)
                        key = event.key.code + '0' - sf::Keyboard::Key::Z - 1;
                    else if (event.key.code == sf::Keyboard::Key::Space)
                        key = ' ';
                    else key = keys[event.key.code];
                    textBoxValue.push_back(key);
                }
                else if (event.key.code == sf::Keyboard::Key::BackSpace)
                    if (textBoxValue.size() != 0) textBoxValue.pop_back();
                texts.back().setString(textBoxValue);
            }*/
        }
        window.clear(sf::Color::White);
        for (Button& butt : buttons) butt.draw();
        t.draw();
        for (sf::RectangleShape& rect : rects) window.draw(rect);
        for (sf::Text& text : texts) window.draw(text);
        window.display();
    }
}

void
GUI::startMainMenu()
{
    float buttonX = screanSize.x / 2.f - screanSize.x / 8.f - 10;
    float buttY[] = { screanSize.y / 8.f, screanSize.y / 24.f, -(screanSize.y / 22.f) };
    sf::Vector2f size(screanSize.x / 4.f, screanSize.y / 16.f);
    sf::String texts[] = { L"Показать таблицу", L"Ввести занятие", L"" };
    void (GUI:: * actions[])() = { &GUI::generateTable, &GUI::inputLesson, &GUI::startMainMenu };
    for (unsigned countButt = 0; countButt < 3; countButt++)
    {
        sf::Vector2f position(buttonX, screanSize.y / 2.f - buttY[countButt]);
        std::function<void()> action = std::bind(actions[countButt], &*this);
        buttons.emplace_back(Button(position, size, texts[countButt], action, window));
        buttons[countButt].enable();
    }
    font.loadFromFile("arial.ttf");
    run();
}

void
GUI::generateTable()
{
    for (Button& butt : buttons) butt.disable();
    std::vector<std::pair<sf::RectangleShape, sf::Text>> titles(3);
    titles[1].first.setPosition(160, 0);
    titles[2].first.setPosition(300, 0);
    titles[0].first.setSize({ 160, 50 });
    titles[1].first.setSize({ 140, 50 });
    titles[2].first.setSize({ 500, 50 });
    titles[0].second.setString(L"Время");
    titles[1].second.setString(L"Кабинет");
    titles[2].second.setString(L"Преподаватель");
    for (std::pair<sf::RectangleShape, sf::Text>& title : titles)
    {
        title.first.setFillColor(grey);
        title.first.setOutlineThickness(1);
        title.first.setOutlineColor(sf::Color::Black);
        title.second.setPosition(title.first.getPosition().x, 0);
        title.second.setFont(font);
        title.second.setCharacterSize(30);
        title.second.setFillColor(darkGrey);
        rects.emplace_back(title.first);
        texts.emplace_back(title.second);
    }
    
    for (sf::Text& text : texts) text.setFillColor(sf::Color::White);
    sf::Vector2u tSize = sf::Vector2u(3, 4);
    std::vector<std::vector<sf::RectangleShape>> tRects(3, std::vector<sf::RectangleShape>(4));
    std::vector<std::vector<sf::Text>> tTexts(3, std::vector<sf::Text>(4));
    std::vector<float> rWidths = { 80.f, 80.f, 140.f, 500.f };
    std::vector<float> rXPositions = { 0.f, 80.f, 160.f, 300.f };
    std::vector<float> rYPositions = { 50.f, 100.f, 150.f, 200.f };
    std::vector<std::vector<sf::String>> strings = {
        {"26.12.1991", "00:00:00", "207", L"Фёдоров Александр Сергеевич"},
        {"26.12.1991", "00:00:00", "207", L"Фёдоров Александр Сергеевич"},
        {"26.12.1991", "00:00:00", "207", L"Фёдоров Александр Сергеевич"},
        {"26.12.1991", "00:00:00", "207", L"Фёдоров Александр Сергеевич"}
    };
    for (unsigned short numTr = 0; numTr < tSize.x; numTr++)
    {
        for (unsigned short numTd = 0; numTd < tSize.y; numTd++)
        {
            tRects[numTr][numTd].setPosition(rXPositions[numTd], rYPositions[numTr]);
            sf::Vector2f tdPos = tRects[numTr][numTd].getPosition();
            tRects[numTr][numTd].setSize({ rWidths[numTd], 50.f });
            tRects[numTr][numTd].setOutlineColor(sf::Color::Black);
            tRects[numTr][numTd].setOutlineThickness(1);
            tTexts[numTr][numTd].setString(strings[numTr][numTd]);
            tTexts[numTr][numTd].setFont(font);
            tTexts[numTr][numTd].setCharacterSize(15);
            tTexts[numTr][numTd].setFillColor(darkGrey);
            tTexts[numTr][numTd].setPosition(tdPos.x, tdPos.y + 5);
            rects.emplace_back(tRects[numTr][numTd]);
            texts.emplace_back(tTexts[numTr][numTd]);
        }
    }
}

void
GUI::inputLesson()
{
    t.enable();
    for (Button& butt : buttons) butt.disable();
    for (sf::Text& text : texts) text.setFillColor(sf::Color::White);
    sf::Text title(L"Введите номер кабинета", font, 22);
    sf::RectangleShape border({ (float) window.getSize().x, 30.f });
    border.setPosition(0, 60);
    border.setOutlineColor(sf::Color::Black);
    border.setOutlineThickness(1);
    sf::Text textBox("", font, 22);
    textBox.setPosition(0, 60);
    title.setFillColor(darkGrey);
    textBox.setFillColor(darkGrey);
    rects.emplace_back(border);
    texts.emplace_back(title);
    texts.emplace_back(textBox);
}