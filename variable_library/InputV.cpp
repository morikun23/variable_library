#include"InputV.h"
using namespace variableNS;
using namespace std;

//DirectInput�Ɋ֘A���郉�C�u�����̃����N��錾  


//���̓f�o�C�X�o�^�̏���
void InputV::Init(HINSTANCE hInstance,HWND hwnd) {
	if (pInput == NULL) {
		//�C���^�[�t�F�C�X�̎擾
		HRESULT hr;
		hr = DirectInput8Create(
		
			hInstance,         // �\�t�g�̃C���X�^���X�n���h��  
			DIRECTINPUT_VERSION,    // DirectInput�̃o�[�W����  
			IID_IDirectInput8,      // �擾����C���^�[�t�F�C�X�̃^�C�v  
			(LPVOID*)&pInput,       // �C���^�[�t�F�C�X�̊i�[��  
			NULL                    // COM�W���̐���I�u�W�F�N�g�i�g��Ȃ��̂�NULL�j  
		);
		if (FAILED(hr)) {
			DXTRACE_MSG(_T("DirectInput�̏������Ɏ��s���܂���"));
			return;
		}

		hr = pInput->CreateDevice(
			GUID_SysKeyboard,   // �󂯕t������̓f�o�C�X  
			&pKeyDevice,        // IDirectInputDevice8�i�[��  
			NULL                // COM�W���̐���I�u�W�F�N�g�i�g��Ȃ��̂�NULL�j  
		);

		if (FAILED(hr)) {
			DXTRACE_MSG(_T("DirectInputDevice�̏������Ɏ��s���܂���"));
			return;
		}
		// �f�[�^�t�H�[�}�b�g�̐ݒ�  
		pKeyDevice->SetDataFormat(&c_dfDIKeyboard);

		////////////////////////////////////////////////////////////////
		//�擾����^�C�~���O
	    //DISCL_BACKGROUND	�E�B���h�E���A�N�e�B�u�ɂȂ��Ă��Ȃ��Ă���Ɏ擾
		//DISCL_FOREGROUND	�E�B���h�E���A�N�e�B�u�ɂȂ��Ă���Ƃ��̂ݎ擾
		//�擾�f�[�^�̒񋟐�
		//DISCL_EXCLUSIVE	DirectInput���Ăяo�����A�v���݂̂Ɍ���
		//DISCL_NONEXCLUSIVE	���ׂẴA�v���P�[�V�����ɒ�
		//Windows�L�[�̃��b�N
		//DISCL_NOWINKEY	�E�B���h�E�Y�L�[�����b�N���Ė����ɂ���
		////////////////////////////////////////////////////////////////

		pKeyDevice->SetCooperativeLevel(hwnd,DISCL_FOREGROUND | DISCL_NONEXCLUSIVE);

		// �L�[�o�b�t�@�̏�����  
		ZeroMemory(keydata, 256);
	}
}

void InputV::Unregister() {
	if (pKeyDevice)
	{
		pKeyDevice->Unacquire();
		pKeyDevice->Release();
		pKeyDevice = 0;
	}

	if (pInput)
	{
		pInput->Release();
		pInput = 0;
	}
}

//�f�o�C�X����̓��͏��̎擾�̏���
void InputV::Exec()
{
	if (pKeyDevice) {
		// ���͂̎󂯕t���J�n  
		pKeyDevice->Acquire();

		// �f�[�^���擾�i256�͎擾����f�[�^�̃T�C�Y�j  
		pKeyDevice->GetDeviceState(256, keydata);
	}
}

//�w�肵���L�[�������ꂽ�������Ԃ�
BOOL InputV::IsKeyDown(int key)
{
	if (pKeyDevice == NULL) return FALSE;

	return (keydata[key] & 0x80) ? TRUE : FALSE;
}
