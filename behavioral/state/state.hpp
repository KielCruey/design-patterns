class Mood;
class Boss;

// ======== State ========
// The base State class declares methods that all Concrete State should
// implement and also provides a backreference to the Context object, associated
// with the State. This backreference can be used by States to transition the
// Context to another State.
class Mood {
public:
  Mood(Boss *boss = nullptr);
  virtual ~Mood() = default;

  virtual void helpMe() = 0;
  virtual void directMe() = 0;

protected:
  Boss *boss;
};

// ======== Context ========
// The Context defines the interface of interest to clients.
// It also maintains a reference to an instance of a State subclass, which
// represents the current state of the Context.
class Boss {
public:
  explicit Boss(Mood *mood = nullptr);
  ~Boss();

  // special memeber functions
  Boss(const Boss &boss);            // copy constructor
  Boss &operator=(const Boss &boss); // assignment copy constructor

  // allows changing the Boss object at runtime.
  void TransitionMood(Mood *mood);

  // delegates part of its behavior to the current Mood object
  void helpMe();
  void directMe();

  inline Mood *getMood();
  inline void setMood(Mood *mood);

private:
  Mood *mood;
};

// ======== Concrete State ========
class BadMood : public Mood {
public:
  BadMood() = default;
  ~BadMood() override = default;

  void helpMe() override;
  void directMe() override;
};

class OkMood : public Mood {
public:
  OkMood() = default;
  ~OkMood() override = default;

  void helpMe() override;
  void directMe() override;
};

class GoodMood : public Mood {
public:
  GoodMood() = default;
  ~GoodMood() override = default;

  void helpMe() override;
  void directMe() override;
};

#include "state.inl"