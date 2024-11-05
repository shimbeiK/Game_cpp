//�w�b�_�[�t�@�C���̓ǂݍ���
#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <vector>

//�萔���`
#define F_WIDE (80)
#define F_HIGHT (21)
#define LIMIT (50)
#define FPS (3)
#define INTER (1000/FPS)
#define INTER2 (100/FPS)
#define Grav (3)

//�萔�𖼑O�Œ�`�c�񋓒萔
enum
{
	CHARACTER_PLAYER,
	CHARACTER_KURIBO,
	CHARACTER_KURIBO2,
	CHARACTER_MAX
};

//�}���I�A�N���{�[�̍��W���܂Ƃ߂Ē�`
typedef struct
{
	int x, y;
}VEC2;

//�}���I�A�N���{�[�̌��݁A�ߋ��A�������W���`
typedef struct
{
	const VEC2 defaultPosition;
	VEC2 position;
	VEC2 lastPosition;
}CHARACTER;

//�w�i���i�[����ϐ����`
char maze[F_HIGHT][F_WIDE + 1];

//�w�i�𕶎��Œ�`
char defaultMaze[F_HIGHT][F_WIDE + 1] =
{
"$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$oo$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$",

"$$$$$$$$$$$$$$$$$$$$$$$$$$$$$oooo$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$",
"$$$$$$$$$$$$$$$$$$$$$$$$$$$$$ooo$$$$$$$$$$$$$$$oooo$$$$$$$$$$$$$$$$$$$$$$$$$$$$$",
"$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$oo$$$$$$$$$$$$$$$$$$$$$$$$$$$$",
"$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$ooo$$$$$$$$$$$$$$$$$$$$$$$$$$$$$",
"$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$ooo$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$",

"$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$o$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$",
"$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$oooo$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$",
"$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$oooo$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$f$$$",
"$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$ooooo$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$ff$$$",
"$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$o$$$$$$$$$$$$$$$$$$$$$$$$$$#$$$$$$$$fff$$$",

"$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$o$$$$$$$$$$$$$$$$$$$$$$$$$##$$$$$$$$$ff$$$",
"$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$o$$$$$$$$$$$$$$$$$$$$$$$$###$$$$$$$$$$f$$$",
"$$$$$$$c$c$$$$$$$$$$$$$$$$$$$$$$$$$$$$o$$$$$$$$$$$$$$$$$$$$$$$####$$$$$$$$$$f$$$",
"$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$#####$$$$$$$$$$f$$$",
"$$$$$$bbbbb$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$######$$$$$$$$$$f$$$",

"$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$#######$$$$$$$$$$f$$$",
"$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$########$$$$$$$$$$f$$$",
"$$$$$$$$$$$$$$$$$$$$$$$$$$$$$#####$$$$$$$$$$$$$$$$$$$$$$$#########$$$$$$$$$$f$$$",
"#####################$$###############$#########################################",
"$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$"
};

//�}���I�A�N���{�[�̏������W�݂̂����炩���ߑ��
CHARACTER characters[CHARACTER_MAX] =
{
	{
		{3,18},
		{},
		{},

	},
	{
		{15,18},
		{},
		{},
	},
		{
		{40,18},
		{},
		{},
	},

};


//�w�i�̏����f�[�^���R�s�[�imaze�𒼐ڕύX����ƌ��ɖ߂�Ȃ��Ȃ邽�߁j
char screen[F_HIGHT][F_WIDE + 1];


//��ԍŏ��ɍs���v���O������ݒ�
void Init()
{
	//�z��maze�ɔw�i�̏����z��DefaultMaze���R�s�[������A
	memcpy(maze, defaultMaze, sizeof(maze));

	//�}���I�A�N���{�[�̌��݁A�ߋ����W�ɏ������W����
	for (int i = 0; i < CHARACTER_MAX; i++)
	{
		characters[i].position = characters[i].lastPosition = characters[i].defaultPosition;
	}
}

//�}�b�v�ƃL�����N�^�[��`�悷��
void D_MAP()
{
	//�����𐔎��ɕϊ�
	memcpy(screen, maze, sizeof maze);
	for (int i = 0; i < CHARACTER_MAX; i++)
	{
		screen[characters[i].position.y][characters[i].position.x] = i;
	}
	system("cls");  //��ʂ��N���A

	for (int y = 0; y < F_HIGHT; y++)
	{
		for (int x = 0; x < F_WIDE; x++)
		{
			//�}�b�v�̕����̎�ނɉ����ĕ`�悷��A�X�L�[�A�[�g��`�悷��
			switch (screen[y][x]) {
			case CHARACTER_PLAYER:printf("a"); break;
			case CHARACTER_KURIBO:printf("b"); break;
			case CHARACTER_KURIBO2:printf("b"); break;
			case 'c':printf("h"); break;
			case 'o':printf(" "); break;
			case '$':printf(" "); break;
			case '#':printf("f"); break;
			case 'f':printf("g"); break;
			case 'b':printf("h"); break;
			}
		}printf("\n");
	}
}


//���W�̓����蔻����s��
bool Equal(VEC2 _v0, VEC2 _v1)
{
	return
		(_v0.x == _v1.x) && (_v0.y == _v1.y);
}

bool EqualKick(VEC2 _v0, VEC2 _v1)
{
	return
		(_v0.x == _v1.x || _v0.x + 1 == _v1.x || _v0.x - 1 == _v1.x) && (_v0.y + 1 == _v1.y);
}

bool FlagKick;
int STRAGE;
int Count = 0;

//�}���I���N���{�[�𓥂񂾂��`�F�b�N����֐�
void KickCheck()
{
	for (int i = CHARACTER_PLAYER + 1; i < CHARACTER_MAX; i++)
	{
		if (EqualKick(characters[CHARACTER_PLAYER].position, characters[i].position) == 1)
		{
			FlagKick = 1;
			STRAGE = i;
			break;
		}
	}
}

//�}���I���N���{�[�ɂ����������`�F�b�N
void E_CHECK()
{
	for (int i = CHARACTER_PLAYER + 1; i < CHARACTER_MAX; i++)
	{
		if (Equal(characters[CHARACTER_PLAYER].position, characters[i].position) == 1)
		{
			printf("%d\n", FlagKick);
			if (FlagKick == 0)
			{
				system("cls");
				printf("You Dead");
				exit(0);
			}
			else
			{
				characters[STRAGE + 1].position.x = -1;
				STRAGE = 0;
				if (Count > 2)
				{
					FlagKick = 0;
					Count = 0;
				}
				break;
			}
		}
	}
}

//�}���I�A�N���{�[�̉��̃}�b�v�������ۂ��`�F�b�N
void F_CHECK()
{
	for (int i = 0; i < CHARACTER_MAX; i++)
	{
		if (maze[characters[i].position.y + 1][characters[i].position.x] == '$' ||
			maze[characters[i].position.y + 1][characters[i].position.x] == 'o')
		{
			characters[i].position.y++;
		}
	}
}

//�}���I���S�[���t���b�O�ɂ����������`�F�b�N
void G_CHECK()
{s
	if (maze[characters[CHARACTER_PLAYER].position.y][characters[CHARACTER_PLAYER].position.x] == 'f')
	{
		system("cls");
		printf("You Got Goal!!!!!!");
		exit(0);
	}
}

//�}���I����ʊO�ɏo�����`�F�b�N
void OUT_CHECK()
{
	if (0 > characters[CHARACTER_PLAYER].position.y ||
		F_HIGHT - 2 < characters[CHARACTER_PLAYER].position.y ||
		0 > characters[CHARACTER_PLAYER].position.x ||
		F_WIDE + 1 < characters[CHARACTER_PLAYER].position.x)
	{
		system("cls");
		printf("You Dead!");
		exit(0);
	}
}

//main�֐�
int main()
{
	Init();
	D_MAP();

	//���Ԃ��擾����ϐ����`
	time_t lastClock = clock();
	int Keyget;

	Keyget = _getch();
	if (Keyget == 's') {

		//�hE"���������A�}���I�����ʂ������̓S�[������܂ŌJ��Ԃ�
		while (1)
		{
			time_t newClock = clock();

			//��莞�Ԃ��o�߂�����
			if (newClock > lastClock + INTER)
			{
				lastClock = newClock;

				//�N���{�[���ړ�������
				for (int i = CHARACTER_PLAYER + 1; i < CHARACTER_MAX; i++)
				{
					VEC2 newPosition = characters[i].position;
					switch (i)
					{
					case CHARACTER_KURIBO:if (newPosition.x >= 0) { newPosition.x--; }; break;
					case CHARACTER_KURIBO2:if (newPosition.x >= 0) { newPosition.x--; }; break;
					}
					characters[i].lastPosition = characters[i].position;
					characters[i].position = newPosition;
				}

				//�e�֐��̎��s
				F_CHECK();
				G_CHECK();
				OUT_CHECK();
				D_MAP();
			}

			//�L�[�{�[�h�������ꂽ���̏���
			if (_kbhit())
			{
				//�K�v�ȕϐ����`
				int i = 0;
				VEC2 lastPosition;
				VEC2 lastPosition2;
				VEC2 newPosition = lastPosition = lastPosition2 = characters[CHARACTER_PLAYER].position;

				lastPosition2.y -= 3;

				//�����ꂽ�L�[�ɂ���ă}���I�̍��W��ω�������
				switch (_getch())
				{
				case 'd':newPosition.x++; break;

				case 'a':newPosition.x--; break;

				case 'w':if (maze[newPosition.y + 1][newPosition.x] != '$' &&
					maze[newPosition.y + 1][newPosition.x] != 'o')
				{
					while (newPosition.y == lastPosition.y && i < 5)
					{
						newPosition.y--;
						i++;
						if (maze[newPosition.y - 1][newPosition.x] == '$')
						{
							if (maze[newPosition.y][newPosition.x] == 'b')
							{
								maze[newPosition.y][newPosition.x] = '$';
								newPosition.y++;
								break;
							}

						}lastPosition.y--;
					}
				}	break;
				case 's':newPosition.y++; break;

					//�o�O�h�~�̂��߁A�hE�h�������ꂽ�狭���I��
				case 'e':exit(0); break;
				}

				//�}���I�̈ړ��悪�ǂł��u���b�N�ł�������Έړ��A�����łȂ���Έړ����Ȃ�
				if (maze[newPosition.y][newPosition.x] != '#' &&
					maze[newPosition.y][newPosition.x] != 'b')
				{
					characters[CHARACTER_PLAYER].position = newPosition;
				}
				else
				{
					newPosition = lastPosition;
				}
				D_MAP();


			};
			E_CHECK();
			KickCheck();
		}
	}
}