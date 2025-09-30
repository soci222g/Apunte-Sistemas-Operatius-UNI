#pragma once
#include"InputsConsts.h"
#include<list>
#include<map>
#include<mutex>
#include<thread>
#include<functional>

class InputSystem
{
public:

	class KeyBinding
	{
		friend class  InputSystem;
	public:
		typedef std::function<void()> OnKeyPrest;

	private:
		int _key;
		OnKeyPrest _onKeyPrest; //guardem la funcio lamda que li pasem al codi. 

		KeyBinding(int key, OnKeyPrest onKeyPrest);
		~KeyBinding();
	};
	typedef std::list<KeyBinding*> KeyBindingList;
	typedef std::map<int, KeyBindingList> KeyBindingMap;
public:

	InputSystem();
	~InputSystem();

	KeyBinding* addListener(int key, KeyBinding::OnKeyPrest onKeyPrest);
	void RemoveAndDeleteListener(KeyBinding* KeyBining);


	void StartListener();
	void StopListener();

private:
	enum State
	{
		Starting = 0,Listening = 1,
		Stopping = 2,
		Stoped = 3
	};
	State _State = Stoped;

	std::mutex _classMutex;
	KeyBindingMap _keyBindingMap;

	void ListenLoop();

};

