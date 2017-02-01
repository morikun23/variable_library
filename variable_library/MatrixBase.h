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

		///////////////////////////////////////
		//�}�g���N�X�̒P�ʉ��@�قƂ�ǂ̍s��v�Z�̑O�ɕK�v�ȏ���
		///////////////////////////////////////
		virtual void Identity();

		///////////////////////////////////////
		//�}�g���N�X���ʒu�s��ɕς���
		///////////////////////////////////////
		virtual void ToPositionMatrix();

		///////////////////////////////////////
		//�}�g���N�X���k���g��s��ɕς���
		///////////////////////////////////////
		virtual void ToScaleMatrix();

		///////////////////////////////////////
		//�}�g���N�X����]�s��ɕς���
		///////////////////////////////////////
		virtual void ToRotateMatrix();

		//�e�I�y���[�^
		virtual MatrixBase operator +(MatrixBase);
		virtual MatrixBase operator -(MatrixBase);
		virtual MatrixBase operator *(MatrixBase);
		virtual void operator +=(MatrixBase);
		virtual void operator -=(MatrixBase);
		virtual void operator *=(MatrixBase);

	};

}

#endif