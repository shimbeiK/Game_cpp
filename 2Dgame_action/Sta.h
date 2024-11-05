#pragma once

class Stage
{
public:

	struct
	{
		//�v�Z�p�ƕ`��p�Ŕz����g��������
		int Type[STAGE_MAX_X+1][STAGE_MAX_Y];
		int Type_Exp[POS_MAX_X+1][POS_MAX_Y]; //�v�Z�p
	}Blo;

	void Read()
	{
		//�|�C���^�^�Ŕw�i�̔z������i�[����ϐ����`
		FILE* fp_stage_1_1;
		//FILE* fp_block_exp;

		//CP���̃e�L�X�g�t�@�C������X�e�[�W���𕶎��œǂݍ��ށB
		fp_stage_1_1 = fopen("C:/�}���I���C�N/UTF-O.txt", "r");
		//���l�̎菇�ŕ`����s��

		//�ǂݍ��񂾕������ŏ��ɒ�`�����z��Ɋi�[����
		for (int y = 0; y < STAGE_MAX_Y; y++)
		{
			for (int x = 0; x < STAGE_MAX_X + 1; x++)
			{
				(void)fscanf(fp_stage_1_1, "%d", &Blo.Type[x][y]);
			}
		}
		//�t�@�C�������
		fclose(fp_stage_1_1);

		//�|�C���^�^�ł͕s�ւȂ̂ŕ��ʂ̔z��imaze�j�Ɋi�[���Ȃ���
	for (int x = 0; x < STAGE_MAX_X + 1; x++)
		{	
			for (int y = 0; y < STAGE_MAX_Y; y++)
			{
				maze[x][y] = Blo.Type[x][y];
			}
		}	
}

	//�ǂݍ��񂾃e�L�X�g�t�@�C���̕����ɂ���ă}�b�v���P���`��
	void Out(int *PosX)
	{
		int pic = 0;
		for (int x = 0; x < STAGE_MAX_X+1 ; x++)
		{
			for (int y = 0; y < STAGE_MAX_Y ; y++)
			{
				switch (maze[x][y])
				{
				case 0: pic = Pic.Sky;
					break;
				case 1: pic = Pic.Blo1;
					break;
				case 2: pic = Pic.Blo2;
					break;
				case 3: pic = Pic.Flag;
					break;
				case 4: pic = Pic.FlagPoal;
					break;
				case 5: pic = Pic.Coin;
					break;
				case 6: pic = Pic.Blo1;
					break;
				case 7: pic = Pic.Blo1;
					break;


				}
				DrawGraph(CELL * x + *PosX, CELL * y, pic, TRUE);
			}
		}
	}

private:
};

Stage Sta;