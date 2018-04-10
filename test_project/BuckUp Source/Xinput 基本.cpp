#include <stdio.h>
#include <iostream>
#include <Windows.h>
#include <Xinput.h>

class DwordResult {
private:
	bool mb_is_assigned;
	DWORD dw_result;

public:
	DwordResult();
	inline void SetIsAssigned(const bool _flug) {
		mb_is_assigned = _flug;
	}
	inline void SetResult(const DWORD _dw) {
		dw_result = _dw;
	}
	inline DWORD GetResult() const {
		return dw_result;
	}
};

DwordResult::DwordResult() {
	mb_is_assigned = false;
}

class GamePad {
private:
	DwordResult mdw_result[4];
	XINPUT_STATE m_state;

public:
	GamePad();
};

GamePad::GamePad() {
	for (DWORD dw = 0; dw < 4; ++dw) {
		ZeroMemory(&m_state, sizeof(XINPUT_STATE));
		mdw_result[dw].SetResult(XInputGetState(dw, &m_state));
		if (mdw_result[dw].GetResult() == ERROR_SUCCESS) {
			std::cout << "GamePad‚Í" << dw << "”Ô–Ú‚ÉÚ‘±‚³‚ê‚Ä‚¢‚Ü‚·B" << std::endl;
		}
		else {
			std::cout << "dw" << dw << "”Ô‚ÍÚ‘±‚³‚ê‚Ä‚¢‚Ü‚¹‚ñB" << std::endl;
		}
	}
}


int main() {

	GamePad *gamepad = new GamePad;

	getchar();
	return 0;
}