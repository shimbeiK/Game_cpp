#pragma once

class FUNCTION
{
public: 

	struct 
	{
		byte Turbo;

	}Flag;

	int FontHandle;
	int sec = 0;

	//�������Ԃ̊Ǘ����s��
	void TimeKeep() {
		FontHandle = CreateFontToHandle(NULL, 30, 6);

		//�������Ԃ��T�O����J�E���g�_�E�����Ă���
		sec =50 - (GetNowCount() - GameStartTime) / 1000;
		DrawFormatString(10, 10, Col.Whi, "%d", sec);

		//50�b�o������Q�[���I�[�o�[��ʂɈڂ�
		if (sec < 0) 
		{
			Sce = Menu::Menu_04_TITLE;
		}
	}

	//�ړ����x��ω�������@���J�R�X�`���[���̏�ԂŁuarduino�v�ƑłƑ��x�㏸
	void Turbo_Mec() 
	{
		if (CheckHitKey(KEY_INPUT_A) != 0)
		{
			Flag.Turbo = 1;
		}
		else if (CheckHitKey(KEY_INPUT_R) != 0 && Flag.Turbo == 1)
		{
			Flag.Turbo++;
		}
		else if (CheckHitKey(KEY_INPUT_D) != 0 && Flag.Turbo == 2)
		{
			Flag.Turbo++;
		}
		else if (CheckHitKey(KEY_INPUT_U) != 0 && Flag.Turbo == 3)
		{
			Flag.Turbo++;
		}
		else if (CheckHitKey(KEY_INPUT_I) != 0 && Flag.Turbo == 4)
		{
			Flag.Turbo++;
		}
		else if (CheckHitKey(KEY_INPUT_N) != 0 && Flag.Turbo == 5)
		{
			Flag.Turbo++;
		}
		else if (CheckHitKey(KEY_INPUT_O) != 0 && Flag.Turbo == 6)
		{
			Flag.Turbo = 0;
			Act.MoveX += 1;
		}
	}

	//�ړ����x��ω�������@�Ȋw�R�X�`���[���̏�ԂŁuH�@E�@L�@B�@O�@C�@N�@F�@N�v�i�������[�x�\�l�̑D�j�ƑłƑ��x�㏸
	void Turbo_Sci()
	{
		if (CheckHitKey(KEY_INPUT_H) != 0)
		{
			Flag.Turbo = 1;
		}
		else if (CheckHitKey(KEY_INPUT_E) != 0 && Flag.Turbo == 1)
		{
			Flag.Turbo++;
		}
		else if (CheckHitKey(KEY_INPUT_L) != 0 && Flag.Turbo == 2)
		{
			Flag.Turbo++;
		}
		else if (CheckHitKey(KEY_INPUT_B) != 0 && Flag.Turbo == 3)
		{
			Flag.Turbo++;
		}
		else if (CheckHitKey(KEY_INPUT_O) != 0 && Flag.Turbo == 4)
		{
			Flag.Turbo++;
		}
		else if (CheckHitKey(KEY_INPUT_C) != 0 && Flag.Turbo == 5)
		{
			Flag.Turbo++;
		}
		else if (CheckHitKey(KEY_INPUT_N) != 0 && Flag.Turbo == 6)
		{
			Flag.Turbo++;
		}
		else if (CheckHitKey(KEY_INPUT_F) != 0 && Flag.Turbo == 7)
		{
			Flag.Turbo++;
		}
		else if (CheckHitKey(KEY_INPUT_N) != 0 && Flag.Turbo == 8)
		{
			Flag.Turbo = 0;
			Act.MoveX += 2;
		}
	}


	void NewFunc()
	{
		Cal();
		Cha();
	}

private:

	void Cal();
	void Cha();
};


FUNCTION Func;

void FUNCTION::Cal() 
{
	//����̏����ŉ����ꂽ�瑬�x��ύX
	if (Pic.PLAYER == Pic.Mec)
	{
		Turbo_Mec();
	}
	else if (Pic.PLAYER == Pic.Sci) 
	{
		Turbo_Sci();
	}
}

void FUNCTION::Cha()
{
}
