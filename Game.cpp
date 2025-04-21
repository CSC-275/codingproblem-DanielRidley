#include<iostream>
#include "Game.h"
#include <algorithm>
Game::Game()
{
    playGame();
}
void Game::printMatches(std::vector<int>playerPicks,std::vector<int>kenoNumbers){
    for (auto j :m_keno.getKenoNumbers())
    {
        for(auto i:m_player.getPlayerNumbers())
        {
        if (j==i)
        {
            m_matches.push_back(i);
        }
        }
    }
    std::sort(m_matches.begin(), m_matches.end());
    std::cout<<"you mached: ";
    for (auto i:m_matches) {
        std::cout << i << " ";
    }
    std::cout << std::endl;
if(m_matches.size()==10)
{
    std::cout<<"10 of 20 $25,000"<<std::endl;
}
    else if (m_matches.size()==9)
    {
        std::cout<<"9 of 20 $2,500"<<std::endl;
    }
    else if (m_matches.size()==8)
    {
        std::cout<<"8 of 20 $250"<<std::endl;
    }
    else if (m_matches.size()==7)
    {
        std::cout<<"7 of 20 $50"<<std::endl;
    }
    else if (m_matches.size()==6)
    {
        std::cout<<"6 of 20 $10"<<std::endl;
    }
    else if (m_matches.size()==5)
    {
        std::cout<<"5 of 20 $5"<<std::endl;
    }
}
void Game::displayResults(){
std::cout<<std::endl<<"----------------------------------Results----------------------------------"<<std::endl;
std::cout<<"Keno Numbers: ";
    m_keno.printKenoNumbers();
    std::cout<<"Player Picks: ";
    m_player.printPlayerNumbers();
    printMatches(m_player.getPlayerNumbers(),m_keno.getKenoNumbers());
}
void Game::playGame(){
    bool gameover = false;
    char playagain;
    while(gameover==false)
    {
        m_keno.generateNumbers();
        m_player.inputPlayerNumbers();
        displayResults();
        std::cout<<"Play again? (y/n):"<<std::endl;
        std::cin>>playagain;
        if (playagain == 'n'||playagain == 'N')
        {
            gameover = true;
        }
        else
        {
            m_player.clearPlayerNumbers();
            m_keno.clearKenoNumbers();
        }
    }
std::cout<<std::endl<<"THANKS FOR PLAYING!!"<<std::endl;
}

