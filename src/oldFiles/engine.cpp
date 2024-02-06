#include <iostream>
#include <vector>
#include <string>
#include "textgenereator.cpp"
#include <termios.h>
#include <stdio.h>
#include <chrono>
using namespace std;
static struct termios old, current;

/* Initialize new terminal i/o settings */
void initTermios(int echo)
{
    tcgetattr(0, &old);         /* grab old terminal i/o settings */
    current = old;              /* make new settings same as old settings */
    current.c_lflag &= ~ICANON; /* disable buffered i/o */
    if (echo)
    {
        current.c_lflag |= ECHO; /* set echo mode */
    }
    else
    {
        current.c_lflag &= ~ECHO; /* set no echo mode */
    }
    tcsetattr(0, TCSANOW, &current); /* use these new terminal i/o settings now */
}

/* Restore old terminal i/o settings */
void resetTermios(void)
{
    tcsetattr(0, TCSANOW, &old);
}

/* Read 1 character - echo defines echo mode */
char getch_(int echo)
{
    char ch;
    initTermios(echo);
    ch = getchar();
    resetTermios();
    return ch;
}

/* Read 1 character without echo */
char getch(void)
{
    return getch_(0);
}

/* Read 1 character with echo */
char getche(void)
{
    return getch_(1);
}
void play(){
vector<string> words;
    words = generate_words();

    string passage = generate_passage(words);
   cout<<"PRESS ANY KEY TO START THE GAME-----"<<endl;
   
    getch();
    getch();

    cout << "\033[33m" << passage << endl
         << "\033[m";

    char entered;
    char actual;
    auto t_start = std::chrono::high_resolution_clock::now();
    int correct = 0;
    for (int i = 0; i < passage.size(); i++)
    {

        entered = getch();
        if (entered == 127)
        {
            --i;
            continue;
        }
        actual = passage[i];
        if (entered != actual)
        {
            cout << "\033[31m" << actual << "\033[m";
        }
        else
        {   correct++;
            cout << "\033[32m" << entered << "\033[m";
        }
    }
    auto t_end = std::chrono::high_resolution_clock::now();
    cout << endl;
    std::chrono::seconds seconds = std::chrono::duration_cast<std::chrono::seconds>(t_end-t_start);

    double elapsed_time_s = std::chrono::duration<double>(seconds).count();
    double elapsed_time_minutes = ((elapsed_time_s)/60.00);
    int accuracy = ((double)correct/(double)passage.size())*100;
    int wpm = (((double)passage.size())/5.00)/elapsed_time_minutes;
    cout<<"WPM : "<<wpm<<endl;
    cout<<"ACCURACY : "<< accuracy<<endl;  
}
int main()
{
    play();
    return 0;
}
