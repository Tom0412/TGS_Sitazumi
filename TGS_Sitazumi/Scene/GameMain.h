#pragma once
#include "AbstractScene.h"
#include "../Object/BoxCollider.h"
#include "../Object/Player.h"


class Player;

class GameMain :
    public AbstractScene
{
private:

public:

    //�R���X�g���N�^(_stage���ǂݍ��ރX�e�[�W)
    GameMain(int _stage);

    //�f�X�g���N�^
    ~GameMain();

    // �`��ȊO�̍X�V������
    AbstractScene* Update() override;

    //�`��Ɋւ��邱�Ƃ�����
    void Draw() const override;

    
};

