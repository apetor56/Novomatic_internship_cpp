#include <iostream>
#include <chrono>
#include <cmath>
#include <vector>
#if _WIN32
#include <windows.h>
#endif


using namespace std;

class Screen
{
public:
        Screen()
        {
#ifdef _WIN32
                _hConsole= GetStdHandle(STD_OUTPUT_HANDLE);
#endif
                hideCursor();
                saveCursorPosition();
        }


        void clear()
        {
                for(int i = 0; i < height; i++)
                {
                        for(int j = 0; j < width; j++)
                        {
                                _screen[i][j]='x';
                        }
                }
        }


        void draw(char value, float x, float y)
        {
                int xPos = lround(x);
                int yPos = lround(y);
                if(xPos < width && yPos < height)
                {
                        _screen[yPos][xPos]=value;
                }
        }


        void flush()
        {
                restoreCursorPosition();


                for(int i = 0; i < height; i++)
                {
                        for(int j = 0; j < width; j++)
                        {
                                if(_screen[i][j]!='x')
                                {
                                        setRedFont();
                                }
                                else
                                {
                                        setWhiteFont();
                                }
                                cout << _screen[i][j];
                        }
                        cout << "\n";
                }
        }


private:
        void hideCursor()
        {
#ifdef _WIN32
                CONSOLE_CURSOR_INFO cursorInfo; 
                GetConsoleCursorInfo(_hConsole, &cursorInfo);
                cursorInfo.dwSize = 1;
                cursorInfo.bVisible = FALSE;
                SetConsoleCursorInfo(_hConsole, &cursorInfo);
#else
                cout << "\33[?25l";//disable cursor
#endif


        }


        void saveCursorPosition()
        {
#ifdef _WIN32
                CONSOLE_SCREEN_BUFFER_INFO coninfo;
                GetConsoleScreenBufferInfo(_hConsole, &coninfo);
                _prevPos = coninfo.dwCursorPosition;
#else
                cout << "\33[s";
#endif
                
        }


        void restoreCursorPosition()
        {
#ifdef _WIN32
                SetConsoleCursorPosition(_hConsole, _prevPos);
#else
                cout << "\338";
#endif
        }


        void setRedFont()
        {
#ifdef _WIN32
                WORD attributes = FOREGROUND_RED;
                SetConsoleTextAttribute(_hConsole, attributes);
#else
                cout << "\33[31m";//red color
#endif
        }


        void setWhiteFont()
        {
#ifdef _WIN32
                WORD attributes = FOREGROUND_RED|FOREGROUND_GREEN|FOREGROUND_BLUE;
                SetConsoleTextAttribute(_hConsole, attributes);
#else
                cout << "\33[37m";//white color
#endif
        }


        static constexpr int width{60};
        static constexpr int height{20};
        char _screen[height][width];
#ifdef _WIN32
        HANDLE _hConsole;
        COORD _prevPos;
#endif
};


struct Position
{
        float x;
        float y;
};


using Pixel = char;


class Engine
{
public:
        void update(const chrono::milliseconds deltaTime)
        {       
                static bool first = true;
                static std::vector<Position> path;
                static int i = 0;

                if(i == 5) {
                        exit(1);
                }

                if(first) {
                        path.push_back(getPoint(deltaTime));
                        if(path.rbegin()->x == 0 && path.begin()->x == 0 && path.size() != 1) {
                                first = false;
                                i++;
                        }
                }
                else {
                        static auto it = path.begin();
                        if(it == path.end()) {
                                it = path.begin();
                                i++;
                        }
                        position = *(it);
                        it++;
                }
        }

        Position getPoint(const chrono::milliseconds deltaTime) {
                static bool back = false;
                static double x = 0.0f;
                static double y = 0.0f;

                switch(back) {
                        case false:
                                if(position.x < 40) {
                                        x += static_cast<double>((deltaTime).count()) / 50;
                                        position.x = static_cast<int>(std::min(40.0, x));
                                }
                                else if (position.y < 10) {
                                        y += static_cast<double>(deltaTime.count()) / 300;
                                        position.y = static_cast<int>(std::min(10.0, y));
                                }
                                else {
                                        back = true;
                                        x = 40;
                                        y = 10;
                                        break;
                                }

                        break;

                        case true:
                                if(position.y > 0) {
                                        y -= static_cast<double>(deltaTime.count()) / 20;
                                        if(y < 0) {
                                                x -= static_cast<double>(deltaTime.count()) / 20;
                                                position.x = x;
                                                position.y = 0;   
                                        }
                                        else {
                                                position.y = y;
                                        }
                                }
                                else if(position.x > 0) {
                                        x -= static_cast<double>(deltaTime.count()) / 20;
                                        position.x = static_cast<int>(std::max(0.0, x));
                                }
                                else {
                                        back = false;
                                        x = 0;
                                        y = 0;
                                        break;
                                }

                        break;
                };

                return position;
        }


        void render(Screen& screen)
        {
                screen.draw(pixel, position.x, position.y);
        }
private:
        Pixel pixel{1};
        Position position{0.0f, 0.0f};
};


int main()
{
        Engine engine;
        Screen screen;

        auto startTime = chrono::high_resolution_clock::now();

        while(1)
        {
                auto now = chrono::high_resolution_clock::now();
                auto deltaTime = chrono::duration_cast<chrono::milliseconds>(now - startTime);

                if( deltaTime >= 20ms)
                {       
                        screen.clear();
                        engine.update(deltaTime);
                        engine.render(screen);
                        screen.flush();
                        startTime = now;
                }
        }    

        return 0;
}