#include <iostream>

const int MINVOLUME = 0;
const int MAXVOLUME = 10;
const int MINCHANNEL = 0;
const int MAXCHANNEL = 100;


// ============ Receiver ============
// Receiver contains the business logic when it receives a concrete command.
// Receiver figures out how to handle the command.
class TV
{
public:
	TV(bool isPowered = false,
	   int channel = NULL,
	   int volume = NULL);
	~TV() = default;

	// commands (from invoker) that the TV responds to
	void powerOn();
	void powerOff();
	void volumeUp();
	void volumeDown();
	void channelUp();
	void channelDown();

	// getters/setters
	inline bool getIsPowered() const;
	inline int getChannel() const;
	inline int getVolume() const;

	inline void setIsPowered(bool isPowered);
	inline void setChannel(bool channel);
	inline void setVolume(bool volume);

private:
	bool isPowered;
	int channel;
	int volume;
};

// ============ Abstract Command ============
class TVCommand 
{
public:
	virtual ~TVCommand() = default;
	virtual void execute() = 0;
};

// ============ Concrete Commands ============
// Concrete commands implements the requests.
// The concrete commands aren't supposed to do work, but pass on the logic to the receiver.
class PowerOn : public TVCommand
{
public:
	PowerOn(TV * tv = nullptr);
	~PowerOn() = default;

	virtual void execute() override;

	inline void setTV();
	inline TV * getTV();

protected:
	TV * tv;
};

class PowerOff : public TVCommand
{
public:
	PowerOff(TV * tv = nullptr);
	~PowerOff() = default;

	virtual void execute() override;

	inline void setTV();
	inline TV * getTV();

protected:
	TV * tv;
};

class VolumeUp : public TVCommand
{
public:
	VolumeUp(TV * tv = nullptr);
	~VolumeUp() = default;

	virtual void execute() override;

	inline void setTV();
	inline TV * getTV();

protected:
	TV * tv;
};

class VolumeDown : public TVCommand
{
public:
	VolumeDown(TV * tv = nullptr);
	~VolumeDown() = default;

	virtual void execute() override;

	inline void setTV();
	inline TV * getTV();

protected:
	TV * tv;
};

class ChannelUp : public TVCommand
{
public:
	ChannelUp(TV * tv = nullptr);
	~ChannelUp() = default;

	virtual void execute() override;

	inline void setTV();
	inline TV * getTV();

protected:
	TV * tv;
};

class ChannelDown : public TVCommand
{
public:
	ChannelDown(TV * tv = nullptr);
	~ChannelDown() = default;

	virtual void execute() override;

	inline void setTV();
	inline TV * getTV();

protected:
	TV * tv;
};

// ============ Invoker ============
// The invoker is responsible for initiating requests. 
// The invoker must have a field for storing a reference to a command object.
// The invoker sends a command object eventually to the receiver class.
class TVRemote
{
public:
	TVRemote(TVCommand* tvCommand = nullptr);
	~TVRemote() = default;

	TVCommand * getTVCommand() const;
	void setCommand(TVCommand * tvCommand);

	void command() const;

	inline void setTVCommand(TVCommand* tvCommand);
	inline TVCommand * getTVCommand();

protected:
	TVCommand * tvCommand;
};

#include "command.inl"