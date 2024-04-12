#pragma once
#include "AbstractScene.h"
#include "../Object/BoxCollider.h"
#include "../Object/Stage.h"
#include "../Utility/KeyInput.h"

#define OBJECT_TYPE_NUM 9  //�z�u�ł���I�u�W�F�N�g�̎�ސ�
#define UI_OBJECT_TYPE_NUM 5  //�z�u�ł���I�u�W�F�N�g�̎�ސ�
#define WIDTH_BUTTON_POS_X 100  //�������߃{�^����X�ʒu
#define WIDTH_BUTTON_POS_Y 40  //�������߃{�^����Y�ʒu
#define HEIGHT_BUTTON_POS_X 180  //�c�����߃{�^����X�ʒu
#define HEIGHT_BUTTON_POS_Y 35 //�c�����߃{�^����Y�ʒu

//�G���A�敪
enum SelectErea
{
    STAGE_EDIT = 0,
    TOOL_BOX,
    SELECT_TYPE,
};

static char obj_string[UI_OBJECT_TYPE_NUM][256] =
{
    "��",
    "�n��",
    "��",
    "��",
    "��",
};

static int can_select_type[UI_OBJECT_TYPE_NUM][2] =
{
    {0,1},
    {1,5},
    {0,1},
    {0,1},
    {0,1},
};
static char block_type_string[UI_OBJECT_TYPE_NUM][5][256] =
{
    {"��"," "," "," "," ",},
    {"��","�D","��","��","��",},
    {"��"," "," "," "," ",},
    {"��"," "," "," "," ",},
    {"��"," "," "," "," ",},
};

class EditScene :
    public AbstractScene
{

private:
    int now_select_erea;                                  //���ݑI�𒆂̃G���A(0=�c�[���{�b�N�X 1=�X�e�[�W)
    int now_stage;                                        //���ݕҏW���̃X�e�[�W
    CURSOR cursor;                                        //�}�E�X�J�[�\��
    int stage_data[MAX_STAGE_HEIGHT][MAX_STAGE_WIDTH];    //�X�e�[�W�̃f�[�^�i�[�p
    int old_stage_data[MAX_STAGE_HEIGHT][MAX_STAGE_WIDTH];//�X�e�[�W�̕ύX�O�f�[�^�i�[�p
    Stage* stage[MAX_STAGE_HEIGHT][MAX_STAGE_WIDTH];      //���̃I�u�W�F�N�g
    int current_type;                                     //���I�΂�Ă���I�u�W�F�N�g�^�C�v
    int ui_current_type;                                  //���I�΂�Ă���I�u�W�F�N�g�^�C�v(������)
    Location width_button_location;                       //�X�e�[�W���ύX�p�{�^���̈ʒu
    Location height_button_location;                       //�X�e�[�W�����ύX�p�{�^���̈ʒu
    bool current_leftbutton_flg;                          //�X�e�[�W�T�C�Y�ύX�p�̍��{�^�����I�΂�Ă��邩
    bool current_rightbutton_flg;                         //�X�e�[�W�T�C�Y�ύX�p�̉E�{�^�����I�΂�Ă��邩
    bool current_upbutton_flg;                            //�X�e�[�W�T�C�Y�ύX�p�̏�{�^�����I�΂�Ă��邩
    bool current_downbutton_flg;                          //�X�e�[�W�T�C�Y�ύX�p�̉��{�^�����I�΂�Ă��邩
    int button_interval;                                  //�X�e�[�W���ύX�̃C���^�[�o��
    Location tool_location;                               //�c�[���{�b�N�X�̍�����W
    Erea tool_size;                                       //����̃c�[���{�b�N�X�̕�
    bool tool_pickup_flg;                                 //�c�[���{�b�N�X�������Ă��邩���f
    bool select_data[MAX_STAGE_HEIGHT][MAX_STAGE_WIDTH];  //���̃f�[�^�����ݑI�𒆂��ǂ���
    int current_type_select;                              //�u���b�N�̃^�C�v�I����ʂ��J����Ă��邩�ǂ���(-1=�����J���Ă��Ȃ� 0�ȍ~=���̐����̑I����ʂ��J���Ă���)
    int disp_num;                                         //���ݑI������Ă���u���b�N�̃^�C�v
    int now_current_type;                                 //���ݒu����u���b�N�̃^�C�v
    Location current_type_location;                       //�u���b�N�̃^�C�v��I������{�b�N�X�̍��W
    Erea current_type_erea;                               //�u���b�N�̃^�C�v��I������{�b�N�X�̑傫��

    int stage_width_num;                                  //�X�e�[�W�̃u���b�N�̉��̌� 
    int stage_height_num;                                 //�X�e�[�W�̃u���b�N�̏c�̌�
public:
    //�R���X�g���N�^
    EditScene(int _stage);
    //�f�X�g���N�^
    ~EditScene();

    // �`��ȊO�̍X�V������
    AbstractScene* Update() override;

    //�`��Ɋւ��邱�Ƃ�����
    void Draw() const override;

    //�X�e�[�W�𐶐�����
    void LoadStageData(int _stage);

    //�X�e�[�W�̃t�@�C�����X�V����
    void UpdateStageData(int _stage);

    //�X�e�[�W�̉����A�������X�V����
    void UpdateStage(int _width, int _height);

    //�ЂƂO�̃f�[�^�̕ێ�
    void SaveOldData();

    //�X�e�[�W�S�̂��c�ɂ��炷
    void StageShift(int _num);

    //���ǂ̃G���A�ɃJ�[�\�������邩
    int ChechSelectErea();

    //�c�[���{�b�N�X����ʊO�ɏo�Ȃ��悤�Ɉړ�����
    void MoveInsideScreen();

    //�ǂ̔����I�𒆂��̏������Z�b�g����
    void ResetSelectData();
};



