#include "inputsystem.h"
#include "../Utils/ConsoleControl.h"

InputSystem::KeyBinding::KeyBinding(int key, OnKeyPrest onKeyPrest)
{
	_key = key;
	_onKeyPrest = onKeyPrest;
}

InputSystem::KeyBinding::~KeyBinding()
{
}

InputSystem::InputSystem()
{

}

InputSystem::~InputSystem()
{
	for (std::pair<int, KeyBindingList> pair : _keyBindingMap) { //iterem en tots els seus valors un per un
		KeyBindingList bindingList = pair.second; //agafem la llista que te realcionada a la tecla
		for (KeyBinding* binding : bindingList) {
			delete binding; //borrem les accions asignades a la tecla,
		}

		bindingList.clear();
	}
	_keyBindingMap.clear();

}

InputSystem::KeyBinding* InputSystem::addListener(int key, KeyBinding::OnKeyPrest onKeyPrest)
{
	_classMutex.lock();

	if(_keyBindingMap.find(key) == _keyBindingMap.end()){
		_keyBindingMap[key] = KeyBindingList();


	}

	KeyBinding* keyBinding = new KeyBinding( key, onKeyPrest);

	_keyBindingMap[key].push_back(keyBinding);

	_classMutex.unlock();


	return keyBinding;
}

void InputSystem::RemoveAndDeleteListener(KeyBinding* KeyBining)
{
	int key = KeyBining->_key;

	_classMutex.lock();
	if (_keyBindingMap.find(key) != _keyBindingMap.end()) {
		
		KeyBindingList list = _keyBindingMap[key];
		
		
		list.remove(KeyBining);
		delete KeyBining;


		if (list.size() <= 0) {
			_keyBindingMap.erase(key);
		}
	}

	
	_classMutex.unlock();



}

void InputSystem::StartListener()
{
	_classMutex.lock();

	if (_State != Stoped) {

		_classMutex.unlock();
		return;
	}

	_State = Starting;

	std::thread* listenLoopThread = new std::thread(&InputSystem::ListenLoop, this);
	listenLoopThread->detach();

	_classMutex.unlock();
}

void InputSystem::StopListener()
{
	_classMutex.lock();
	if (_State != Listening) {
		_classMutex.unlock();
		return;
	}

	_State = Stopping;


	_classMutex.unlock();

}

void InputSystem::ListenLoop()
{
	_classMutex.lock();


	_State = Listening;

	State currentState = _State;
	CC::clearKeyBufer();
	_classMutex.unlock();


	while (currentState == Listening) {

		int key = CC::ReadNextKey(); //primer llegim la tecla

		if (key != 0) {
			_classMutex.lock();
			if (_keyBindingMap.find(key) != _keyBindingMap.end()) {
				KeyBindingList list = _keyBindingMap[key];

				for (KeyBinding* binding : list) {
					std::thread* onKeyPresdThread = new std::thread(binding->_onKeyPrest);
					onKeyPresdThread->detach(); //per el ipotetic cas de que eliminem un keybinding de la llista programada. (asincrona)

				}
			}
			_classMutex.unlock();
		}


		_classMutex.lock();
		currentState = _State;
		_classMutex.unlock();
	}


	_classMutex.lock();
	if (_State == Stopping) {
		_State = Stoped;
	}
	_classMutex.unlock();

}
