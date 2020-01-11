#include "rcontroller.h"

RController::RController() :
    m_game(nullptr)
  , m_gameClient(nullptr)
{

}

void RController::createGame(QString pGameName, bool pIsPaired, QString pGamer1, QString pGamer2, QString pGamer3, QString pGamer4)
{
    setGame(new RGameObject());

    game()->init(pGameName, pIsPaired);

    if(pGamer1 != "")
        game()->addGamer(pGamer1);
    if(pGamer2 != "")
        game()->addGamer(pGamer2);
    if(pGamer3 != "")
        game()->addGamer(pGamer3);
    if(pGamer4 != "")
        game()->addGamer(pGamer4);
}
