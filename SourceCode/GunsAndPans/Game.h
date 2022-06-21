#pragma once

#include <vector>

#include "Objects.h"

namespace GunsAndPuns
{

    //================================================================================================

    class TGame
    {
    public:

        TGame();
        ~TGame();

        enum class TKeyCode : uint8_t
        {
            ENTER_KEY = 13U,
            ESC_KEY = 27,
            YES_KEY = 'y',
            YES_CAPS_KEY = 'Y'
        };

        enum class TSoundId
        {
            START,
            PLAY,
            SHOOT,
            TARGET,
            FINISH
        };

        enum class TGameState
        {
            START,
            PLAY,
            FINISH
        };

        void checkResources() const;
        void init();
        void display();
        void __fastcall resize(const GLsizei w, const GLsizei h);
        void __fastcall playSound(const TSoundId id);
        void __fastcall kbHit(const TGame::TKeyCode key);

        void __fastcall setXZAngle(const GLfloat angle) { gun.setXZAngle(angle); };
        void __fastcall setYZAngle(const GLfloat angle) { gun.setYZAngle(angle); };

        size_t getWinWidth() const { return winWidth; }
        size_t getWinHeight() const { return winHeight; }

        bool isPlaying() const { return (state == TGameState::PLAY); }
        bool isStarting() const { return (state == TGameState::START); }
        
        void onTimer();
        void move();
        void shoot();

    private:

        void drawPlayScreen() const;
        void reInit();
        void collisionCheck();
        void saveScore() const;

        // string type converter
        std::string __fastcall wstringToString(const std::wstring& wstr) const;

        TGameState state{ TGameState::START };

        std::vector<std::string> texturesNames;
        const size_t textureNumber{ 19U };

        std::vector<std::wstring> soundsNames;
        const size_t soundsNumber{ 5U };

        TGun gun;
        TGunAmunitions amun;
        TBullet bullet;
        TGround ground;
        TScene scene;
        TTarget appleTarget;
        TTarget smallTarget;
        TTarget bigTarget;

        TScreen startScr;
        TScreen finishScr;

        size_t winWidth, winHeight, scores;
        const size_t startScores{ 50U };
        const size_t bulletCost{ 5U };
        bool isDrawing;
        ULONGLONG dt{ 50U }; // delta time (ms) for every frame
        ULONGLONG lastTime;

        const std::string scoreFileName{"Score.txt"};
    };

}; // namespace GunsAndPuns

//================================================================================================
