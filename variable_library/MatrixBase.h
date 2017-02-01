#ifndef MATRIXBASE
#define MATRIXBASE

//////////////////////////////////////////////////////////////////
//�N���X���F MatrixBase
//�쐬�� �F��R�@�� 
//�T�v  �F�s��̐����̌��ɂȂ�N���X�@�l�X�ȑ傫���̍s��Ɍp���A�h��������
//�X�V  �FH29/01/30/ �N���X�̍쐬
/////////////////////////////////////////////////////////////////

namespace variableNS {

	class MatrixBase {

	public:

		MatrixBase() {};
		virtual ~MatrixBase() = 0;

		///////////////////////////////////////
		//�}�g���N�X�̒P�ʉ��@�قƂ�ǂ̍s��v�Z�̑O�ɕK�v�ȏ���
		///////////////////////////////////////
		virtual void Identity() = 0;

		///////////////////////////////////////
		//�}�g���N�X���ʒu�s��ɕς���
		///////////////////////////////////////
		virtual void ToPositionMatrix() = 0;

		///////////////////////////////////////
		//�}�g���N�X���k���g��s��ɕς���
		///////////////////////////////////////
		virtual void ToScaleMatrix() = 0;

		///////////////////////////////////////
		//�}�g���N�X����]�s��ɕς���
		///////////////////////////////////////
		virtual void ToRotateMatrix() = 0;

		//�e�I�y���[�^
		virtual MatrixBase operator +(MatrixBase) = 0;
		virtual MatrixBase operator -(MatrixBase) = 0;
		virtual MatrixBase operator *(MatrixBase) = 0;
		virtual void operator +=(MatrixBase) = 0;
		virtual void operator -=(MatrixBase) = 0;
		virtual void operator *=(MatrixBase) = 0;

	};

}

#endif