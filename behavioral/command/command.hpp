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
	explicit TV(bool isPowered = false,
	   int channel = 0,
	   int volume = 0);
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
	explicit PowerOn(TV * tv = nullptr);
	~PowerOn() override = default ;

	virtual void execute() override;

	inline TV * getTV();

protected:
	TV * tv;
};

class PowerOff : public TVCommand
{
public:
	explicit PowerOff(TV * tv = nullptr);
	~PowerOff() override = default;

	virtual void execute() override;

	inline TV * getTV();

protected:
	TV * tv;
};

class VolumeUp : public TVCommand
{
public:
	explicit VolumeUp(TV * tv = nullptr);
	~VolumeUp() override = default;

	virtual void execute() override;

	inline TV * getTV();

protected:
	TV * tv;
};

class VolumeDown : public TVCommand
{
public:
	explicit VolumeDown(TV * tv = nullptr);
	~VolumeDown() override = default;

	virtual void execute() override;

	inline TV * getTV();

protected:
	TV * tv;
};

class ChannelUp : public TVCommand
{
public:
	explicit ChannelUp(TV * tv = nullptr);
	~ChannelUp() override = default;

	virtual void execute() override;

	inline TV * getTV();

protected:
	TV * tv;
};

class ChannelDown : public TVCommand
{
public:
	explicit ChannelDown(TV * tv = nullptr);
	~ChannelDown() override = default;

	virtual void execute() override;

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
	explicit TVRemote(TVCommand* tvCommand = nullptr);
	~TVRemote() = default;

	TVCommand * getTVCommand() const;
	void setCommand(TVCommand * tvCommand);

	void command() const;

	inline TVCommand * getTVCommand();

protected:
	TVCommand * tvCommand;
};

#include "command.inl"