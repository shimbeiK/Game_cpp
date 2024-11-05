#pragma once
class ACTION
{
public:
	//���Z�b�g�p�̃t���b�O
	void NumberReset() 
	{
		Flag.Xpl = 0;
		Flag.Xmi = 0;
		Flag.Jum = 0;
		Flag.Rev = 0;
		Flag.Fly = 0;
		Flag.Kuri = 0;
		Flag.Kuri1 = 0;
		Flag.Destroy = 0;
		Flag.Dead = 0;
		Flag.Dcount = 0;
		Flag.Mec = 0;
		Flag.Sci = 0;
		Flag.Change = 0;
		Flag.SleepOut = 0;

		//�K�v�ȃ}���I�ƃN���{�[�̊�b�\�͂���W���`
		OLD_X = 0;
		OLD_Y = 0;
		OLD_STAGE_X = 0;
		 no = 0;

		MoveX = 3;
		MoveY = 0;
		WalkCount = 0;;
		WalkRevCount = 0;

		KuriMove = 1;
		KuriMove1 = 2;
		KuriX = 500;
		Kuri1X = 300;
		KuriY = WIN_MAX_Y - 3 * CELL;
		Kuri1Y = WIN_MAX_Y - 10 * CELL;
		KuriCount = 0;

		
		Mar.Pos.x = 0;
		Mar.Pos.y = POS_MAX_Y - 3 * CELL;
		Mar.Pos.lastY = POS_MAX_Y - 3 * CELL;
		Mar.Pos.X_cal = 0;


		Sta_Pos_X = 0;

		count = 0;
		Time = 0.0;

	}//�����̂݃��Z�b�g


	struct
	{
		bool Xpl = 0;
		bool Xmi = 0;
		bool Jum = 0;
		bool Rev = 0;
		bool Fly = 0;
		bool Kuri = 0;
		bool Kuri1 = 0;
		bool Destroy = 0;
		bool Dead = 0;
		byte Dcount = 0;
		bool Mec = 0;
		bool Sci = 0;
		bool Change = 0;
		bool SleepOut = 0;
	}Flag;


	//�K�v�ȃ}���I�ƃN���{�[�̊�b�\�͂���W���`
	int OLD_X = 0;
	int OLD_Y = 0;
	int OLD_STAGE_X = 0;
	int no = 0;

	int MoveX = 3;
	int MoveY = 0;
	int WalkCount = 0;;
	int WalkRevCount = 0;

	int KuriMove = 1;
	int KuriMove1 = 2;
	int KuriX = 500;
	int Kuri1X = 300;
	int KuriY = WIN_MAX_Y - 3 * CELL;
	int Kuri1Y = WIN_MAX_Y - 10 * CELL;
	int KuriCount = 0;

	struct
	{
		struct
		{
			int x = 0;
			int y = POS_MAX_Y - 3 * CELL;
			int lastY = POS_MAX_Y - 3 * CELL;
			int X_cal = 0;
		}Pos;

	}Mar;

	//�Q�̕��̂̍��W���d�Ȃ��Ă��邩���f����֐�
	int CheckHit(int x1, int y1, int h1, int i1, 
				  int x2, int y2, int h2, int i2) 
	//������@1�ڂ̕��̂̍��[�@��ڂ̕��̂̉E�[�@�P�ڂ̕��̂̏�[�@��ڂ̕��̂̉��[�@
	//�Q�ڂ̕��̂̍��[�@�Q�ڂ̕��̂̉E�[�@�Q�ڂ̕��̂̏�[�@�Q�ڂ̕��̂̉��[�@
	{                                                                          
		int L1 = x1;
		int R1 = y1;

		//�X�e�[�W�̈ړ����l��
		int L2 = x2 + Sta_Pos_X;
		int R2 = y2 + Sta_Pos_X;

		int O1 = h1;
		int U1 = i1;
		int O2 = h2;  //h2:h1+CELL
		int U2 = i2;

		if (R1 < L2) return 0;  //�������Ă��Ȃ�����
		if (R2 < L1) return 0;

		if (U1 < O2) return 0;
		if (U2 < O1) return 0;

		return 1;//����ȊO�͂������Ă���
	}


	//�L�����N�^�[���ǂ�u���b�N�ɂ����������𔻒f����
	void CHECK_HIT()
	{
		for (int x = 0; x < STAGE_MAX_X; x++)
		{
			for (int y = 0; y < STAGE_MAX_Y; y++)
			{
				no = maze[x][y];
				if(no != 0 && no != 3 && no != 4)
				{
					if (CheckHit(Mar.Pos.x, Mar.Pos.x + CELL, 
						Mar.Pos.y,Mar.Pos.y + CELL, 
						x * CELL + 5, x * CELL + CELL -5,
						y * CELL + 5, y * CELL + CELL))
					{
						Kuribo();
						//�����ړ���ɕǂ�u���b�N������Έړ����Ȃ�
						Mar.Pos.x = OLD_X;
						Sta_Pos_X = OLD_STAGE_X;
						Mar.Pos.y = OLD_Y;
					}
				}
				if (CheckHit(Mar.Pos.x, Mar.Pos.x + CELL,
					Mar.Pos.y, Mar.Pos.y + CELL,
					KuriX, KuriX + CELL,
					KuriY, KuriY + CELL))
				{
					if (Mar.Pos.y + CELL - 5 < KuriY)
					{
						//Sce = Menu::Menu_03_TITLE;
						KuriX = -CELL;
						Flag.Kuri = 1;
					}
					else
					{
						Flag.Dead = 1;
					}
				}

				if (CheckHit(Mar.Pos.x, Mar.Pos.x + CELL,
					Mar.Pos.y, Mar.Pos.y + CELL,
					Kuri1X + 5, Kuri1X + CELL - 5,
					Kuri1Y, Kuri1Y + CELL))
				{
					if (Mar.Pos.y + CELL - 5 < KuriY)
					{
						Kuri1X = -CELL;
						Flag.Kuri1 = 1;
					}
					else
					{
						Flag.Dead = 1;
					}
				}
			}
		}
	}

	//�G�����ɗ�����֐�
	void DropKuri()  
	{
		KuriCount += 1;
		Time = TIME_K * (double)KuriCount / 60.0;  //���Ԃ̌v��

		MoveY = (int)(pow(Time, 2.0)); //MoveY=Time^2 2��̌v�Z
		for (int y = 1; y <= MoveY; y++)
		{
			//�G�̍��W�����ɂP�ړ�������
			KuriY += 1;			
		}
	}

	//�G�����ɗ�����֐�
	void DropKuri1() 
	{
		KuriCount += 1;
		Time = TIME_K * (double)KuriCount / 60.0;  //���Ԃ̌v��

		MoveY = (int)(pow(Time, 2.0)); //MoveY=Time^2 2��̌v�Z
		for (int y = 1; y <= MoveY; y++)
		{
			Kuri1Y += 1;
		}
	}

	//�L�����N�^�[�̉��Ƀu���b�N�����邩���f����
	void UNDER_BROCK_HIT()  
	{
		for (int x = 0; x < STAGE_MAX_X; x++)
		{
			for (int y = 0; y < STAGE_MAX_Y; y++)
			{
				no = maze[x][y];
				if (no == 0 && Flag.Jum == 0)  //���ɕ����Ă�����
				{
					//�v���C���[�̍��W�m�F
					if (Flag.Rev != 1
						&& CheckHit(Mar.Pos.x, Mar.Pos.x + CELL,
						Mar.Pos.y, Mar.Pos.y + CELL,
						x * CELL + 5, x * CELL + CELL - 5,
						y * CELL + 5, y * CELL + CELL)
						&& maze[x][y + 1] != 0)
					{
						Flag.Rev = 1;
						//Flag.Jum = 1;
					}
					//�G�̍��W�m�F
					if (CheckHit(KuriX, KuriX + CELL,
						KuriY, KuriY + CELL, 
						x * CELL + 5, x * CELL + CELL - 5,
						y * CELL + 5, y * CELL + CELL) 
						&& maze[x][y + 1] == 0)
					{
						DropKuri();
					}
					//�N���{�[�̍��W�m�F
					if (CheckHit(Kuri1X, Kuri1X + CELL,
						Kuri1Y, Kuri1Y + CELL,
						x * CELL + 5, x * CELL + CELL - 5,
						y * CELL + 5, y * CELL + CELL)
						&& maze[x][y + 1] != 0)
					{
						DropKuri1();
					}
				}
			}
		}
	}
	

	void DropChar() //�d�͂ɂ���ăL�����N�^�[�𗎂Ƃ��֐�
	{
		count += 1;
		Time = TIME_K * (double)count / 60.0;  //���Ԃ̌v��

		MoveY = (int)(pow(Time, 2.0)); //MoveY=Time^2 2��̌v�Z
		for (int y = 1; y <= MoveY; y++)
		{
			Mar.Pos.y += 1;


			if (CheckHit(Mar.Pos.x, Mar.Pos.x + CELL,
				Mar.Pos.y, Mar.Pos.y + CELL,
				KuriX, KuriX + CELL,
				KuriY, KuriY + CELL))
			{
				if (Mar.Pos.y + CELL - 5 < KuriY)
				{
					//Sce = Menu::Menu_03_TITLE;
					KuriX = -CELL;
					Flag.Kuri = 1;
				}
				else
				{
					Flag.Dead = 1;
				}
			}

			if (CheckHit(Mar.Pos.x, Mar.Pos.x + CELL,
				Mar.Pos.y, Mar.Pos.y + CELL,
				Kuri1X + 5, Kuri1X + CELL - 5,
				Kuri1Y, Kuri1Y + CELL))
			{
				if (Mar.Pos.y + CELL - 5 < KuriY)
				{
					Kuri1X = -CELL;
					Flag.Kuri1 = 1;
				}
				else
				{
					Flag.Dead = 1;
				}
			}
		}

		for (int x = 0; x < STAGE_MAX_X; x++)
		{
			for (int y = 0; y < STAGE_MAX_Y; y++)
			{
				no = maze[x][y];
				if (no != 0)
				{
					//�}���I�̍��W���ǂ�u���b�N�łȂ���Ώd�͗��������s����
					if (CheckHit(Mar.Pos.x, Mar.Pos.x + CELL, 
						Mar.Pos.y, Mar.Pos.y + CELL,
						x * CELL + 5, x * CELL + CELL - 5,
						y * CELL + 5, y * CELL + CELL))
					{
						Mar.Pos.x = OLD_X;
						Sta_Pos_X = OLD_STAGE_X;
						Mar.Pos.y = OLD_Y;
						Flag.Rev = 0;
						//Flag.Jum = 0;
						Flag.Fly = 0;
						MoveY = 0;
						count = 0;
						break;
					}
				}
			}
		}
	}

	void Out()
	{
		Cal();
		Cha();
	}

private:

	//Act.h�w�b�_�[�t�@�C�����ł̂ݎg�p����ϐ����`
	const int	MoveY_max = CELL * 5;
	int Sta_Pos_X = 0;

	int count = 0;
	double Time = 0.0;
	const double TIME_K = 3.5;

	//�G�̏���
	void Kuribo()
	{
		//������G�ɓ��������ꍇ
		if (Flag.Dead == 1) 
		{
			Mar.Pos.x = KuriX;
			Mar.Pos.y = KuriY;
			Tit.GameFinishTime = GetNowCount();
			Flag.Change = 1;
			if (Flag.SleepOut == 0)
			{
				PlaySoundA("C:/�}���I���C�N/Punch.wav", SND_ASYNC);
			}
		//	DrawGraph(Mar.Pos.x, Mar.Pos.y, Pic.PLAYER, TRUE);
		//	Tit.Sleeper();
			if (Flag.SleepOut == 1) 
			{
				Sce = Menu::Menu_02_TITLE;
			}
		//	Flag.Dead = 0;
		}
		
		//��������G�𓥂񂾏ꍇ
		if(Flag.Kuri == 1)
		{
			Mar.Pos.x = KuriX;
			Mar.Pos.y = KuriY;
			Tit.GameFinishTime = GetNowCount();
			Flag.Change = 1;
			PlaySoundA("C:/�}���I���C�N/BigBomb.wav", SND_ASYNC);
		//	{
			Sce = Menu::Menu_05_TITLE;
		//	}
		//	KuriX = 0;
		}

		//�펞��1�̖ڂ̓G�̏���
		else if (Flag.Kuri == 0)
		{
			KuriX -= KuriMove;
			KuriX += Sta_Pos_X;
			if (KuriX < 0 && Flag.Change != 1)
			{
				KuriX = -CELL;
			}
		}

		//�펞�̂Q�̖ڂ̓G�̏���
		if (Flag.Kuri1 == 0) 
		{
			Kuri1X -= KuriMove1;
			Kuri1X += Sta_Pos_X;
			if (Kuri1X < 0) 
			{
				Kuri1X = -CELL;
			}
		}
		else if (Kuri1X < 0 && Flag.Change!= 1)
		{
			Kuri1X = -CELL;
		}
	}

	void Cal();
	void Cha();
};

ACTION Act;


void ACTION::Cal()   //�v�Z�p�֐�
{
	if (CheckHitKey(KEY_INPUT_X) != 0) 
	{
		while (CheckHitKey(KEY_INPUT_Q) == 0);
	}

	//�ړ��O�̍��W��ʖ��ŕۑ����Ă���
	OLD_X = Mar.Pos.x;
	OLD_STAGE_X = Sta_Pos_X;
	OLD_Y = Mar.Pos.y;

	UNDER_BROCK_HIT();

	if (Flag.Change == 1) {
		Tit.Sleeper();
		Flag.SleepOut = 1;
	}

	//�����ꂽ�L�[�ɂ���ď����𕪊�
	//D�������ꂽ��}���I���E�ړ�
	if (CheckHitKey(KEY_INPUT_D) != 0)
	{
		Flag.Xpl = 1;
	}
	else
	{
		Flag.Xpl = 0;
	}
	//A�������ꂽ��}���I�����ړ�
	if (CheckHitKey(KEY_INPUT_A) != 0)
	{
		Flag.Xmi = 1;
	}
	else 
	{
		Flag.Xmi = 0;
	}
	//W�������ꂽ��}���I���W�����v
	if (CheckHitKey(KEY_INPUT_W) != 0 && Flag.Fly == 0)
	{
		Flag.Jum = 1;
		Flag.Fly = 1;
		PlaySoundA("C:/�}���I���C�N/Jump.wav",  SND_ASYNC);
		Mar.Pos.lastY = Mar.Pos.y;//�W�����v�O�̃}���I�̂����W��ۑ�
	}

	//M(S)�������ꂽ��L�����N�^�[�̃f�U�C��������
	if (CheckHitKey(KEY_INPUT_M) == 1)
	{
		Pic.PLAYER = Pic.Mec;
		Pic.MarioOpp = Pic.MecOpp;
		Pic.MarioRev = Pic.MecRev;
		Pic.MarioRevOpp = Pic.MecRevOpp;
		Flag.Mec = 1;
		Flag.Sci = 0;
		Pic.Mario = Pic.PLAYER;
	}
	else if (CheckHitKey(KEY_INPUT_S) != 0) 
	{
		Pic.PLAYER = Pic.Sci;
		Pic.MarioOpp = Pic.SciOpp;
		Pic.MarioRev = Pic.SciRev;
		Pic.MarioRevOpp = Pic.SciRevOpp;
		Flag.Sci = 1;
		Flag.Mec = 0;
		Pic.Mario = Pic.PLAYER;
	}

	//�}���I��x���W�ɉ�ʈړ����l������
	Mar.Pos.X_cal = Mar.Pos.x + abs(Sta_Pos_X);//abs:��Βl

	//�����ꂽ�L�[�ɂ���čs���鏈���~�R�iD,A,W�j
	if (Flag.Xpl == 1) 
	{
		WalkCount++;
		if (WalkCount > 40)
		{
			Pic.PLAYER = Pic.MarioOpp;
			WalkCount = 0;
		}
		else if (WalkCount > 20)
		{
			Pic.PLAYER = Pic.Mario;
		}
		if (Flag.Rev == 1)
		{
			DropChar();
		}
		if (Sta_Pos_X == 0 || Sta_Pos_X == -POS_MAX_X + WIN_MAX_X)
		{
			Mar.Pos.x += MoveX;
		}
		if (Mar.Pos.x >= WIN_MAX_X / 2 && Mar.Pos.x <= WIN_MAX_X / 2 + 6 )
		{
			Sta_Pos_X -= MoveX;
		}

		CHECK_HIT();
	}

	//�����̏���
	else if (Flag.Xmi == 1)
	{
		WalkRevCount++;
		if (WalkRevCount > 40)
		{
			Pic.PLAYER = Pic.MarioRevOpp;
			WalkRevCount = 0;
		}
		else if(WalkRevCount > 20)
		{
			Pic.PLAYER = Pic.MarioRev;
		}

		if (Flag.Rev == 1)
		{
			DropChar();
		}
		if (Sta_Pos_X == 0 || Sta_Pos_X == -POS_MAX_X + WIN_MAX_X)
		{
			Mar.Pos.x -= MoveX;
		}
		if (Mar.Pos.x >= WIN_MAX_X / 2 && Mar.Pos.x <= WIN_MAX_X / 2 + 6)
		{
			Sta_Pos_X += MoveX;
		}
		CHECK_HIT();
	}

	 //�W�����v�̏���
	 if (Flag.Rev == 0 && Flag.Jum == 1) {
		count += 1;
		Time = TIME_K * (double)count / 60.0;  //���Ԃ̌v��

		MoveY = (int)(pow(Time, 2.0)); //MoveY=Time^2 2��̌v�Z
		for (int y = 1; y <= MoveY; y++) 
		{
			Mar.Pos.y -= 1;
		
			if (MoveY_max <= Mar.Pos.lastY - Mar.Pos.y)
			{
				MoveY = 0;

				Flag.Jum = 0;
				Flag.Rev = 1;
				count = 0;
				break;
			}
			
			for (int x = 0; x < STAGE_MAX_X; x++)
			{
				for (int y = 0; y < STAGE_MAX_Y; y++)
				{
					no = maze[x][y];
					if (no != 0)
					{
						if (CheckHit(Mar.Pos.x, Mar.Pos.x + CELL, 
							Mar.Pos.y, Mar.Pos.y + CELL,
							x * CELL + 5, x * CELL + CELL - 5,
							y * CELL + 5, y * CELL + CELL))
						{
							Mar.Pos.x = OLD_X;
							Mar.Pos.y = OLD_Y;

							if (OLD_X, OLD_X + CELL,
								OLD_Y,OLD_Y + CELL,
								x * CELL + 5, x * CELL + CELL - 5,
								y * CELL + 5, y * CELL + CELL &&
								no == 2
								)
							{
								if (Flag.Mec == 1 || Flag.Sci == 1) 
								{
									maze[x][y] = 0;
								}								
							}

							Flag.Jum = 0;
							MoveY = 0;
							Flag.Rev = 1;
							count = 0;
							break;
						}
					}
				}
			}
		}
	}
	
	 //�L�����N�^�[�����ɕ����Ă�����d�͂��l��
	else if (Flag.Rev == 1 ) 
	{
		DropChar();
	}

	 Kuribo();
	// CHECK_HIT();
}

void ACTION::Cha()   //�`��p�֐�
{
	Sta.Out(&Sta_Pos_X);
	DrawGraph(Mar.Pos.x, Mar.Pos.y, Pic.PLAYER, TRUE);
	if (Flag.Kuri == 0) {
		DrawGraph(KuriX, KuriY, Pic.Kuri, TRUE);
	}
	/*
	if (Flag.Kuri1 == 0) {
		DrawGraph(Kuri1X, Kuri1Y, Pic.Kuri1, TRUE);
	}
	*/
}