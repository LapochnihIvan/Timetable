#include "GUI.h"

GUI::GUI() :
    window(sf::VideoMode(800, 600), ""),
    grey(169, 169, 169),
    darkGrey(99, 99, 99)
{
    screanSize = window.getSize();
    location = Locations::MainMenu;
}

void
GUI::run()
{
    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed) window.close();
            else if (event.type == sf::Event::KeyReleased
                && event.key.code == sf::Keyboard::Enter)
                    swapTextBox();
            else {
                for (Button &butt : buttons) butt.actionListener(event);
                for (TextBox &textBox : textBoxes) textBox.actionListener(event);
            }
        }
        window.clear(sf::Color::White);
        for (Button &butt : buttons) butt.draw();
        for (RectWithText &rectWithText : rectsWithTexts) rectWithText.draw();
        for (TextBox &textBox : textBoxes) textBox.draw();
        for (sf::RectangleShape &rect : rects) window.draw(rect);
        window.draw(text);
        window.display();
    }
}

void
GUI::startMainMenu()
{
    float buttonX = screanSize.x / 2.f - screanSize.x / 8.f - 10.f;
    float buttY[] = { screanSize.y / 8.f, screanSize.y / 24.f, -(screanSize.y / 22.f) };
    sf::Vector2f size(screanSize.x / 4.f, screanSize.y / 16.f);
    sf::String texts[] = { L"Показать таблицу", L"Ввести занятие", L"" };
    void (GUI::*actions[])() = { &GUI::generateTable, &GUI::inputLesson, &GUI::startMainMenu };
    for (unsigned countButt = 0; countButt < 3; countButt++)
    {
        sf::Vector2f position(buttonX, screanSize.y / 2.f - buttY[countButt]);
        std::function<void()> action = std::bind(actions[countButt], &*this);
        buttons.emplace_back(Button(texts[countButt], position, size, action, window));
        buttons[countButt].enable();
    }
    font.loadFromFile("arial.ttf");
    run();
}

void
GUI::generateTable()
{
    for (Button &butt : buttons) butt.disable();
    static std::vector<std::vector<std::basic_string<unsigned char>>> strings/* = {
        {"26.12.1991", "00:00:00", "207", L"Фёдоров Александр Сергеевич"},
        {"26.12.1991", "00:00:00", "207", L"Фёдоров Александр Сергеевич"},
        {"26.12.1991", "00:00:00", "207", L"Фёдоров Александр Сергеевич"},
        {"26.12.1991", "00:00:00", "207", L"Фёдоров Александр Сергеевич"}
    }*/;
    if (strings.empty())
    {
        Reader reader;
        reader.read(strings);
    }
    sf::Vector2u tSize = sf::Vector2u(strings.size() + 1, strings[0].size());
    std::vector<std::vector<RectWithText>> table(tSize.x);
    std::vector<sf::String> titlesStrs = { L"Дата и Время", L"Кабинет", L"Преподаватель" };
    std::vector<float> titlesPos = { 0.f, 160.f, 300.f };
    std::vector<float> titlesWidths = { 160.f, 140.f, 500.f };
    for (unsigned short countTitles = 0U; countTitles < 3; countTitles++)
        table[0].emplace_back(RectWithText(titlesStrs[countTitles],
            sf::Vector2f(titlesPos[countTitles], 0.f),
            sf::Vector2f(titlesWidths[countTitles], 50.f),
            sf::Color(169, 169, 169),
            window,
            25U));
    std::vector<float> tdX = { 0.f, 80.f, 160.f, 300.f };
    std::vector<float> tdY = { 50.f, 100.f, 150.f, 200.f };
    std::vector<float> widths = { 80.f, 80.f, 140.f, 500.f };
    for (unsigned short numTr = 1U; numTr < tSize.x; numTr++)
    {
        for (unsigned short numTd = 0U; numTd < tSize.y; numTd++)
        {
            std::basic_string<unsigned int> value;
            sf::Utf8::toUtf32(strings[numTr - 1][numTd].begin(), strings[numTr - 1][numTd].end(), std::back_inserter(value));
            table[numTr].emplace_back(RectWithText(value,
                sf::Vector2f(tdX[numTd], tdY[numTr - 1]),
                sf::Vector2f(widths[numTd], 50.f),
                sf::Color::White, window, 15U));

        }
    }
    for (std::vector<RectWithText> &tr : table)
    {
        for (RectWithText &td : tr)
        {
            td.enable();
            rectsWithTexts.emplace_back(td);
        }
    }
}

void
GUI::inputLesson()
{
    for (Button& butt : buttons) butt.disable();
    for (unsigned short count = 0; count < 3; count++)
        textBoxes.emplace_back(TextBox(60.f, TextBox::Type::Numeric, window));
    textBoxes.emplace_back(TextBox(60.f, TextBox::Type::Text, window));
    textBoxes[0].enable();
    text = sf::Text(L"Введите дату", font, 22);
    text.setFillColor(darkGrey);
}

void
GUI::swapTextBox()
{
    static std::wstring strings[] = {
        L"Введите дату", L"Введите время",
        L"Введите номер кабитета", L"Введите ФИО педагога"
    };
    static unsigned short numTextBox = 0;
    textBoxes[numTextBox].write();
    textBoxes[numTextBox].disable();
    if (numTextBox <= 2)
    {
        numTextBox++;
        text.setString(strings[numTextBox]);
        textBoxes[numTextBox].enable();
    }
    else window.close();
}