#pragma once

class {
public:
	//�摜���i�[����萔���`
	int Blo1;
	int Blo2;
	int Sky;
	int Kuri;
	int Kuri1;
	int FlagPoal;
	int Flag;
	int Coin;

	int Mario;
	int MarioOpp;
	int MarioRev;
	int MarioRevOpp;
	int Mec;
	int MecOpp;
	int MecRev;
	int MecRevOpp;
	int Sci;
	int SciOpp;
	int SciRev;
	int SciRevOpp;

	int Title;
	int Hit;
	int Kicked;
	int Retire;
	int Goal;
	int test1;
	int test2;
	int test3;
	int PLAYER;
	

	void Read()
	{
		//��`�����萔��CP������摜��ǂݍ��݁A�i�[����
		 Blo1 = LoadGraph("C:/�}���I���C�N/block1.png");
		 Blo2 = LoadGraph("C:/�}���I���C�N/block2.png");
		 Sky = LoadGraph("C:/�}���I���C�N/sky-32.png");
		 FlagPoal= LoadGraph("C:/�}���I���C�N/frag-stick.png");
		 Flag = LoadGraph("C:/�}���I���C�N/frag-stick.png");
		 Coin= LoadGraph("C:/�}���I���C�N/coin.png");
		 Kuri = LoadGraph("C:/�}���I���C�N/enemy.png");

		 Kuri1 = LoadGraph("C:/�}���I���C�N/enemy.png");
		 Mario = LoadGraph("C:/�}���I���C�N/mario-32.png");
		 MarioOpp = LoadGraph("C:/�}���I���C�N/�}���I�t��.png");
		 MarioRev = LoadGraph("C:/�}���I���C�N/�}���I�t�i.png");
		 MarioRevOpp = LoadGraph("C:/�}���I���C�N/mario-32Reverse.png");
		 Mec = LoadGraph("C:/�}���I���C�N/���J�g����Y.png");
		 MecOpp = LoadGraph("C:/�}���I���C�N/���J�g����Y�t��.png");
		 MecRev = LoadGraph("C:/�}���I���C�N/���J�g����Y�t�i.png");
		 MecRevOpp = LoadGraph("C:/�}���I���C�N/���J�g����Yreverse.png");
		 Sci = LoadGraph("C:/�}���I���C�N/���w�n�N���i.png");
		 SciOpp = LoadGraph("C:/�}���I���C�N/���w�n�N�t��.png");
		 SciRev = LoadGraph("C:/�}���I���C�N/���w�n�N�t�i.png");
		 SciRevOpp = LoadGraph("C:/�}���I���C�N/���w�n�N�t�i�t��.png");

		 Title = LoadGraph("C:/�}���I���C�N/title-new.png");
		 Goal = LoadGraph("C:/�}���I���C�N/title-new.png");
		 Hit = LoadGraph("C:/�}���I���C�N/�G�l�~�[�q�b�g.png");
		 Kicked = LoadGraph("C:/�}���I���C�N/�G�l�~�[�L�b�N.png");
		 Retire = LoadGraph("C:/�}���I���C�N/���Ȃ��͗��N���܂���.png");

		 test1 = LoadGraph("C:/�}���I���C�N/test1.png");
		 test2 = LoadGraph("C:/�}���I���C�N/test2.png");
		 test3 = LoadGraph("C:/�}���I���C�N/test3.png");

		 PLAYER = Mario;
	}
private:
}Pic;
