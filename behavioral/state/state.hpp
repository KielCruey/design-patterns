class Mood;
class Boss;

// ======== State ========
// The base State class declares methods that all Concrete State should implement and 
// also provides a backreference to the Context object, associated with the State.
// This backreference can be used by States to transition the Context to another State.
class Mood
{
public:
	Mood(Boss * boss = nullptr);
	virtual ~Mood() = default;

	inline void setBoss(Boss * boss);

	virtual void helpMe() = 0;
	virtual void directMe() = 0;

protected:
	Boss * boss;
};

// ======== Context ========
// The Context defines the interface of interest to clients. 
// It also maintains a reference to an instance of a State subclass, which represents the current state of the Context.
class Boss
{
public:
	Boss(Mood * mood = nullptr);
	~Boss();

	// allows changing the Boss object at runtime.
	void TransitionMood(Mood* mood);

	// delegates part of its behavior to the current Mood object
	void helpMe();
	void directMe();
	
	inline Mood * getMood();
	inline void setMood(Mood * mood);

private:
	Mood * mood;
};

// ======== Concrete State ========
class BadMood : public Mood
{
public:
	BadMood() = default;
	~BadMood() = default;

	void helpMe() override;
	void directMe() override;
};

class OkMood : public Mood
{
public:
	OkMood() = default;
	~OkMood() = default;

	void helpMe() override;
	void directMe() override;
};

class GoodMood : public Mood
{
public:
	GoodMood() = default;
	~GoodMood() = default;

	void helpMe() override;
	void directMe() override;
};

#include "state.inl"