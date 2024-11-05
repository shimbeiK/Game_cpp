#pragma once

class TITLE
{
public:
	int FontHandle;
	int FontHandle2;

	int GameFinishTime;
	int sec ;
	int POKA;

	void Read() 
	{
		FontHandle = CreateFontToHandle(NULL, 80, 6);
	}

	//���񂾂Ƃ��ɏ���Delay��݂���
	void Sleeper() 
	{
		while (sec < 2) 
		{
			POKA = 0;
			sec = (GetNowCount() - GameFinishTime) / 1000;
		}
	}

	void out() 
	{
		//�`�悷�镶���̃t�H���g�������
		FontHandle = CreateFontToHandle(NULL, 80, 6);
		FontHandle2 = CreateFontToHandle(NULL, 80, 10);

		//�^�C�g����ʂ�`��A�hPress�@Enter Key�I�h��`��
		DrawGraph(0, 0, Pic.Title, TRUE);
		
		//Enter�L�[�������ꂽ���ʏo�͂�ύX
		if(CheckHitKey(KEY_INPUT_NUMPADENTER)==1)
		{
			Sce = Menu::Menu_01_TITLE;
			GameStartTime = GetNowCount();
		}
	}

	//�Q�[���I�[�o�[�ɂȂ����Ƃ��̉�ʂ�ݒ�A�`��
	void GameOverEfect() 
	{
		DrawGraph(0, 0, Pic.Hit, TRUE);
	//	DrawGraph(270, 0, Pic.Title, TRUE);a
		sec = 50 - (GetNowCount() - GameFinishTime) / 1000;
		if (sec < 48) 
		{
			if (POKA == 0) 
			{
				PlaySoundA("C:/�}���I���C�N/poka.wav", SND_ASYNC);
				POKA = 1;
			}
			DrawGraph(0, 0,Pic.Retire, TRUE);
		}
	}

	//�G�𓥂񂾎��̏���
	void EnemyKickEfect() 
	{
		DrawGraph(0, 0, Pic.Kicked, TRUE);
	//	DrawGraph(0, 0, Pic.Title, TRUE);
		sec = 50 - (GetNowCount() - GameFinishTime) / 1000;
		if (sec < 48) 
		{
			if (POKA == 0) 
			{
				PlaySoundA("C:/�}���I���C�N/poka.wav", SND_ASYNC);
				POKA = 1;
			}
			DrawGraph(0, 0, Pic.Retire, TRUE);
		}
	}
	//�^�C���I�[�o�[���̏���
	void TimeOverEfect() 
	{
		Sleeper();

		DrawGraph(0, 0, Pic.Hit, TRUE);
		if (POKA == 0) 
		{
			//����炷����
			POKA = 1;
			PlaySoundA("C:/�}���I���C�N/poka.wav", SND_ASYNC);
		}
		DrawFormatString(130, 300, Col.Bla, "You Overed!!");
	}

	//�S�[���������̉�ʂ̐ݒ�A�`��
	void GoalEfect()
	{
		Sleeper();

		DrawGraph(0, 0, Pic.Goal, TRUE);
		DrawFormatString(30, 300, Col.Bla, "Yooouuu GOAAAAAAAALED!!");
	}
private:
};

TITLE Tit;